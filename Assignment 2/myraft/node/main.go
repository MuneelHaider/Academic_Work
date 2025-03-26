package main

import (
	"fmt"
	"log"
	"math/rand"
	"os"
	"strconv"
	"time"

	"myraft/node/raft"
)

func main() {
	if len(os.Args) < 3 {
		fmt.Fprintf(os.Stderr, "Usage: %s <myIndex> <peer1Addr> <peer2Addr>...\n", os.Args[0])
		os.Exit(1)
	}

	myIndex, err := strconv.Atoi(os.Args[1])
	if err != nil {
		log.Fatalf("Invalid node index: %v", err)
	}

	peers := os.Args[2:]
	if myIndex < 0 || myIndex >= len(peers) {
		log.Fatalf("myIndex out of range.")
	}

	myAddr := peers[myIndex]
	rand.Seed(time.Now().UnixNano() + int64(myIndex))

	// Add startup delay for Node 0 and Node 1 to allow Node 2 to boot first
	if myIndex == 0 || myIndex == 1 || myIndex == 2 {
		log.Printf("Delaying startup for Node %d by 5 seconds...\n", myIndex)
		time.Sleep(5 * time.Second)
	}

	rn := raft.NewRaftNode(peers, myIndex)
	raft.StartRPCServer(rn, myAddr)

	ticker := time.NewTicker(50 * time.Millisecond)
	defer ticker.Stop()

	log.Printf("Raft node (index=%d) started, listening at %s, peers=%v\n", myIndex, myAddr, peers)

	for {
		select {
		case <-rn.KillCh:
			return
		case <-ticker.C:
			rn.ApplyCommittedEntries()
		}
	}
}
