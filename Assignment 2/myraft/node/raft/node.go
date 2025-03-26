package raft

import (
	"log"
	"math/rand"
	"net/rpc"
	"sync"
	"time"
)

type RaftNode struct {
	mu sync.Mutex

	// Persistent state:
	CurrentTerm int
	VotedFor    int
	Log         []LogEntry

	// Volatile state:
	CommitIndex int
	LastApplied int

	// Leader state:
	NextIndex  []int
	MatchIndex []int

	// Key-value store for committed entries
	KVStore map[string]string

	// Cluster info
	Peers []string
	Me    int // index in Peers

	// Node state
	Role           string
	ElectionTimer  *time.Timer
	HeartbeatTimer *time.Timer

	ElectionTimeout time.Duration
	HeartbeatDur    time.Duration

	// Channels to stop goroutines
	KillCh chan bool
}

// For RequestVote RPC
type RequestVoteArgs struct {
	Term         int
	CandidateID  int
	LastLogIndex int
	LastLogTerm  int
}

type RequestVoteReply struct {
	Term        int
	VoteGranted bool
}

// For AppendEntries RPC
type AppendEntriesArgs struct {
	Term         int
	LeaderID     int
	PrevLogIndex int
	PrevLogTerm  int
	Entries      []LogEntry
	LeaderCommit int
}

type AppendEntriesReply struct {
	Term    int
	Success bool
}

// ========== Initialization ==========

func NewRaftNode(peers []string, me int) *RaftNode {
	rn := &RaftNode{
		VotedFor:        -1,
		Log:             make([]LogEntry, 0),
		KVStore:         make(map[string]string),
		Role:            Follower,
		Peers:           peers,
		Me:              me,
		ElectionTimeout: randomElectionTimeout(),
		HeartbeatDur:    120 * time.Millisecond,
		KillCh:          make(chan bool),
	}
	// Start timers
	rn.ElectionTimer = time.NewTimer(rn.ElectionTimeout)
	go rn.electionTicker()

	rn.HeartbeatTimer = time.NewTimer(rn.HeartbeatDur)
	go rn.heartbeatTicker()

	return rn
}

// ========== RPC Handlers ==========

// RequestVote is the RPC for election.
func (rn *RaftNode) RequestVote(args *RequestVoteArgs, reply *RequestVoteReply) error {
	rn.mu.Lock()
	defer rn.mu.Unlock()

	if args.Term > rn.CurrentTerm {
		rn.becomeFollower(args.Term)
	}

	reply.Term = rn.CurrentTerm
	reply.VoteGranted = false

	// Check if candidate’s term < ours
	if args.Term < rn.CurrentTerm {
		return nil
	}

	// Check if we have voted for someone else already
	// and if candidate’s log is at least as up to date as ours
	lastTerm, lastIndex := rn.lastLogTermIndex()
	upToDate := (args.LastLogTerm > lastTerm) ||
		(args.LastLogTerm == lastTerm && args.LastLogIndex >= lastIndex)

	if (rn.VotedFor == -1 || rn.VotedFor == args.CandidateID) && upToDate {
		rn.VotedFor = args.CandidateID
		reply.VoteGranted = true
		rn.resetElectionTimer()
	}

	return nil
}

// AppendEntries is the heartbeat / replication RPC.
func (rn *RaftNode) AppendEntries(args *AppendEntriesArgs, reply *AppendEntriesReply) error {
	rn.mu.Lock()
	defer rn.mu.Unlock()

	reply.Term = rn.CurrentTerm
	reply.Success = false

	// If term < currentTerm: reject
	if args.Term < rn.CurrentTerm {
		return nil
	}

	// If leader has a newer term, become follower
	if args.Term > rn.CurrentTerm {
		rn.becomeFollower(args.Term)
	}
	// Reset election timer
	rn.Role = Follower
	rn.resetElectionTimer()

	// Check log matching
	if args.PrevLogIndex >= 0 {
		if args.PrevLogIndex >= len(rn.Log) {
			return nil
		}
		if rn.Log[args.PrevLogIndex].Term != args.PrevLogTerm {
			return nil
		}
	}

	// Accept entries
	rn.Log = rn.Log[:args.PrevLogIndex+1]
	rn.Log = append(rn.Log, args.Entries...)
	reply.Success = true

	// Update commit index
	if args.LeaderCommit > rn.CommitIndex {
		lastIndex := len(rn.Log) - 1
		if args.LeaderCommit < lastIndex {
			rn.CommitIndex = args.LeaderCommit
		} else {
			rn.CommitIndex = lastIndex
		}
	}

	return nil
}

// ========== Raft Mechanics ==========

func (rn *RaftNode) becomeFollower(newTerm int) {
	rn.Role = Follower
	log.Printf("[Node %d] 🔵 Became Follower for term %d\n", rn.Me, newTerm)

	rn.CurrentTerm = newTerm
	rn.VotedFor = -1
}

func (rn *RaftNode) becomeCandidate() {
	rn.Role = Candidate
	log.Printf("[Node %d] 🗳️ Became Candidate for term %d\n", rn.Me, rn.CurrentTerm)
	rn.CurrentTerm++
	rn.VotedFor = rn.Me
}

func (rn *RaftNode) becomeLeader() {
	rn.Role = Leader
	log.Printf("[Node %d] 🟢 Became Leader for term %d\n", rn.Me, rn.CurrentTerm)
	rn.NextIndex = make([]int, len(rn.Peers))
	rn.MatchIndex = make([]int, len(rn.Peers))
	next := len(rn.Log)
	for i := range rn.Peers {
		rn.NextIndex[i] = next
		rn.MatchIndex[i] = -1
	}
}

func (rn *RaftNode) lastLogTermIndex() (int, int) {
	if len(rn.Log) == 0 {
		return -1, -1
	}
	i := len(rn.Log) - 1
	return rn.Log[i].Term, i
}

func randomElectionTimeout() time.Duration {
	return time.Duration(5000+rand.Intn(1000)) * time.Millisecond // 5.0–6.0 seconds
}

func (rn *RaftNode) resetElectionTimer() {
	rn.ElectionTimeout = randomElectionTimeout()
	if !rn.ElectionTimer.Stop() {
		select {
		case <-rn.ElectionTimer.C:
		default:
		}
	}
	rn.ElectionTimer.Reset(rn.ElectionTimeout)
}

// ========== Timers ==========

// electionTicker checks if election timer has expired.
func (rn *RaftNode) electionTicker() {
	for {
		select {
		case <-rn.KillCh:
			return
		case <-rn.ElectionTimer.C:
			rn.mu.Lock()
			if rn.Role == Follower {
				rn.becomeCandidate()
				rn.startElection()
			} else if rn.Role == Candidate {
				// start a new election
				rn.becomeCandidate()
				rn.startElection()
			}
			rn.mu.Unlock()
		}
	}
}

// heartbeatTicker sends heartbeats if we’re leader.
func (rn *RaftNode) heartbeatTicker() {
	for {
		select {
		case <-rn.KillCh:
			return
		case <-time.After(rn.HeartbeatDur):
			rn.mu.Lock()
			if rn.Role == Leader {
				rn.sendHeartbeats()
			}
			rn.mu.Unlock()
		}
	}
}

// startElection broadcasts RequestVote to all peers.
func (rn *RaftNode) startElection() {
	_, lastIndex := rn.lastLogTermIndex()
	lastTerm := -1
	if lastIndex >= 0 {
		lastTerm = rn.Log[lastIndex].Term
	}
	votes := 1 // self-vote

	log.Printf("[Node %d] 🗳️ Requesting votes for term %d\n", rn.Me, rn.CurrentTerm)

	for i, p := range rn.Peers {
		if i == rn.Me {
			continue
		}
		go func(i int, addr string) {
			args := RequestVoteArgs{
				Term:         rn.CurrentTerm,
				CandidateID:  rn.Me,
				LastLogIndex: lastIndex,
				LastLogTerm:  lastTerm,
			}
			var reply RequestVoteReply
			ok := callRPC(addr, "RaftNode.RequestVote", &args, &reply)
			if !ok {
				log.Printf("[Node %d] ⚠️ RPC to Node %d failed\n", rn.Me, i)
				return
			}

			rn.mu.Lock()
			defer rn.mu.Unlock()

			if rn.Role != Candidate || args.Term != rn.CurrentTerm {
				return
			}
			if reply.Term > rn.CurrentTerm {
				rn.becomeFollower(reply.Term)
				return
			}
			if reply.VoteGranted {
				log.Printf("[Node %d] ✅ Got vote from Node %d for term %d\n", rn.Me, i, rn.CurrentTerm)
				votes++
				if votes*2 > len(rn.Peers) {
					log.Printf("[Node %d] 🟢 Elected as Leader for term %d with %d votes\n", rn.Me, rn.CurrentTerm, votes)
					rn.becomeLeader()
					rn.sendHeartbeats()
				}
			}
		}(i, p)
	}
}

// sendHeartbeats sends AppendEntries (empty) to all peers.
func (rn *RaftNode) sendHeartbeats() {
	for i, p := range rn.Peers {
		if i == rn.Me {
			continue
		}
		go rn.sendAppendEntries(i, p)
	}
}

// sendAppendEntries tries to replicate new entries to peer i.
func (rn *RaftNode) sendAppendEntries(i int, peerAddr string) {
	prevIndex := rn.NextIndex[i] - 1
	var prevTerm int
	if prevIndex >= 0 && prevIndex < len(rn.Log) {
		prevTerm = rn.Log[prevIndex].Term
	} else {
		prevTerm = -1
	}

	entries := []LogEntry{}
	if rn.NextIndex[i] < len(rn.Log) {
		entries = rn.Log[rn.NextIndex[i]:]
	}
	args := AppendEntriesArgs{
		Term:         rn.CurrentTerm,
		LeaderID:     rn.Me,
		PrevLogIndex: prevIndex,
		PrevLogTerm:  prevTerm,
		Entries:      entries,
		LeaderCommit: rn.CommitIndex,
	}

	var reply AppendEntriesReply
	callRPC(peerAddr, "RaftNode.AppendEntries", &args, &reply)

	rn.mu.Lock()
	defer rn.mu.Unlock()

	if reply.Term > rn.CurrentTerm {
		rn.becomeFollower(reply.Term)
		return
	}
	if rn.Role != Leader || args.Term != rn.CurrentTerm {
		return
	}

	if reply.Success {
		rn.NextIndex[i] = prevIndex + 1 + len(entries)
		rn.MatchIndex[i] = rn.NextIndex[i] - 1
		// Advance commit index if needed
		for N := len(rn.Log) - 1; N > rn.CommitIndex; N-- {
			cnt := 1
			for idx := 0; idx < len(rn.Peers); idx++ {
				if rn.MatchIndex[idx] >= N && rn.Log[N].Term == rn.CurrentTerm {
					cnt++
				}
			}
			if cnt*2 > len(rn.Peers) {
				rn.CommitIndex = N
				break
			}
		}
	} else {
		if rn.NextIndex[i] > 0 {
			rn.NextIndex[i]--
		}
	}
}

// ========== Helpers & RPC ==========

func callRPC(addr, rpcName string, args, reply interface{}) bool {
	client, err := rpc.DialHTTP("tcp", addr)
	if err != nil {
		return false
	}
	defer client.Close()

	err = client.Call(rpcName, args, reply)
	if err != nil {
		return false
	}
	return true
}

// StartCommand is used by the leader to replicate a new command.
func (rn *RaftNode) StartCommand(cmd Command, reply *int) error {
	rn.mu.Lock()
	defer rn.mu.Unlock()

	if rn.Role != Leader {
		*reply = -1
		return nil
	}

	newEntry := LogEntry{
		Term:  rn.CurrentTerm,
		Op:    cmd.Op,
		Key:   cmd.Key,
		Value: cmd.Value,
	}
	rn.Log = append(rn.Log, newEntry)
	*reply = len(rn.Log) - 1
	return nil
}

// ApplyCommittedEntries applies newly committed logs to the KV store.
func (rn *RaftNode) ApplyCommittedEntries() {
	rn.mu.Lock()
	defer rn.mu.Unlock()

	for rn.LastApplied < rn.CommitIndex {
		rn.LastApplied++
		entry := rn.Log[rn.LastApplied]
		switch entry.Op {
		case "Put":
			rn.KVStore[entry.Key] = entry.Value
		case "Append":
			rn.KVStore[entry.Key] = rn.KVStore[entry.Key] + entry.Value
			// "Get" doesn’t modify the store.
		}
	}
}

// Stop the node’s goroutines
func (rn *RaftNode) Stop() {
	close(rn.KillCh)
	rn.ElectionTimer.Stop()
	rn.HeartbeatTimer.Stop()
	log.Println("Raft node stopped.")
}
