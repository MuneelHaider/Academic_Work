package raft

import (
	"log"
	"net"
	"net/http"
	"net/rpc"
)

// StartRPCServer registers the RaftNode for RPC, listens on addr, and serves forever.
func StartRPCServer(rn *RaftNode, addr string) {
	rpc.Register(rn)
	rpc.HandleHTTP()
	l, err := net.Listen("tcp", addr)
	if err != nil {
		log.Fatalf("Listen error on %s: %v", addr, err)
	}
	go http.Serve(l, nil)
	log.Printf("Raft RPC server running at %s\n", addr)
}
