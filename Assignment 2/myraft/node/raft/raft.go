package raft

// Roles in Raft
const (
	Follower  = "Follower"
	Candidate = "Candidate"
	Leader    = "Leader"
)

// A single command in the log (like Put, Append, Get).
type Command struct {
	Op    string // "Put", "Append", "Get"
	Key   string
	Value string
}

// A single log entry in the replicated log.
type LogEntry struct {
	Term  int
	Op    string
	Key   string
	Value string
}

type CommandReply struct {
	Index int
	Value string // Only filled for Get
}
