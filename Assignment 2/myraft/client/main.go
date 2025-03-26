package main

import (
	"fmt"
	"log"
	"net/rpc"
	"os"

	"myraft/node/raft"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Fprintf(os.Stderr, "Usage: %s <peerAddr1> <peerAddr2>...\n", os.Args[0])
		os.Exit(1)
	}
	peers := os.Args[1:]

	leader := findLeader(peers)
	if leader == "" {
		log.Fatal("❌ No leader found!")
	}
	fmt.Printf("✅ Leader is: %s\n", leader)

	// Send a Put request
	putCmd := raft.Command{Op: "Put", Key: "foo", Value: "bar"}
	doCommand(leader, putCmd)

	// Append to the same key
	appendCmd := raft.Command{Op: "Append", Key: "foo", Value: "123"}
	doCommand(leader, appendCmd)

	// Retrieve the value
	getCmd := raft.Command{Op: "Get", Key: "foo"}
	doCommand(leader, getCmd)
}

func findLeader(peers []string) string {
	testCmd := raft.Command{Op: "Get", Key: "leader_probe"}
	for _, p := range peers {
		reply, err := startCommandRPC(p, testCmd)
		if err == nil && reply.Index >= 0 {
			return p
		}
	}
	return ""
}

func doCommand(peer string, cmd raft.Command) {
	reply, err := startCommandRPC(peer, cmd)
	if err != nil {
		fmt.Printf("❌ Error from %s: %v\n", peer, err)
		return
	}
	if reply.Index < 0 {
		fmt.Printf("⚠️  Node %s is not the leader.\n", peer)
	} else {
		if cmd.Op == "Get" {
			fmt.Printf("📦 Get %q => %q (leader: %s, index: %d)\n", cmd.Key, reply.Value, peer, reply.Index)
		} else {
			fmt.Printf("✅ Command %v committed at index %d (leader %s)\n", cmd, reply.Index, peer)
		}
	}
}

func startCommandRPC(peer string, cmd raft.Command) (*raft.CommandReply, error) {
	client, err := rpc.DialHTTP("tcp", peer)
	if err != nil {
		return nil, err
	}
	defer client.Close()

	var reply raft.CommandReply
	err = client.Call("RaftNode.StartCommand", &cmd, &reply)
	return &reply, err
}
