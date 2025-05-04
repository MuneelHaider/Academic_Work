package main

import (
	"fmt"
	"time"
	"advanced-blockchain/sharding"
	"advanced-blockchain/state"
	"advanced-blockchain/crypto"
	"advanced-blockchain/cap"
	"advanced-blockchain/bft"
	"advanced-blockchain/consensus"
)

func main() {
	// Existing shard setup
	manager := sharding.NewShardManager(3)
	entries := []string{"tx1", "tx2", "tx3", "tx4", "tx5"}
	for _, entry := range entries {
		manager.AddData(entry)
	}

	// ---- AMQ Test ----
	amq := state.NewAMQ(1000, 5)
	for _, entry := range entries {
		amq.Add(entry)
	}
	fmt.Println("Might contain 'tx2'? ", amq.MightContain("tx2"))
	fmt.Println("Might contain 'tx999'? ", amq.MightContain("tx999"))

	// ---- Accumulator Test ----
	acc := crypto.NewAccumulator()
	for _, entry := range entries {
		acc.Add(entry)
	}
	fmt.Printf("Accumulator state: %x\n", acc.Get())

	// ---- Cross-Shard Transfer ----
	if len(manager.Shards) >= 2 {
		transfer := sharding.CreateStateTransfer(manager.Shards[0], manager.Shards[1], 2)
		fmt.Printf("Transferred from Shard %d to %d: %v\n", transfer.FromShard, transfer.ToShard, transfer.DataChunk)
		fmt.Printf("Commitment: %s\n", transfer.Commitment)
		fmt.Println("Verified: ", sharding.VerifyCommitment(transfer))
	}

	// ---- CAP Orchestration ----
	orch := cap.NewOrchestrator()
	simulated := []cap.NetworkTelemetry{
		{LatencyMs: 50, PartitionProbability: 0.1},
		{LatencyMs: 180, PartitionProbability: 0.3},
		{LatencyMs: 70, PartitionProbability: 0.9},
	}

	for i, telemetry := range simulated {
		orch.AdjustBasedOnNetwork(telemetry)
		fmt.Printf("\n[CAP Scenario %d]\n", i+1)
		fmt.Printf("Latency: %dms, Partition Probability: %.2f\n", telemetry.LatencyMs, telemetry.PartitionProbability)
		fmt.Printf("Selected Consistency: %s\n", orch.CurrentLevel)
		fmt.Printf("Retry Timeout: %s\n", orch.RetryTimeout)
	}

	// ---- BFT Simulation ----
	nodes := []*bft.Node{
		{ID: "NodeA", Reputation: 0.9, IsMalicious: false},
		{ID: "NodeB", Reputation: 0.7, IsMalicious: false},
		{ID: "NodeC", Reputation: 0.4, IsMalicious: true},
		{ID: "NodeD", Reputation: 0.6, IsMalicious: false},
	}

	for _, n := range nodes {
		n.AdjustReputation(!n.IsMalicious)
		fmt.Printf("Node %s: Reputation=%.2f, TrustScore=%.2f\n", n.ID, n.Reputation, n.TrustScore)
	}

	totalTrust := bft.CalculateConsensusThreshold(nodes)
	votes := bft.CountTrustedVotes(nodes)
	fmt.Printf("\nTotal Trust Needed for Consensus: %.2f\n", totalTrust)
	fmt.Printf("Current Trusted Votes: %.2f\n", votes)
	if votes >= totalTrust {
		fmt.Println("✅ Consensus Achieved")
	} else {
		fmt.Println("❌ Consensus Failed")
	}

	// ---- PoW Simulation ----
	data := "block data"
	fmt.Println("\n⛏️ Mining...")
	start := time.Now()
	hash, nonce := consensus.Mine(data, 3)
	elapsed := time.Since(start)
	fmt.Printf("✅ PoW Result: %s (Nonce: %d, Time: %s)\n", hash, nonce, elapsed)

	// ---- dBFT Delegate Selection ----
	delegates := consensus.SelectDelegates(nodes, 2)
	fmt.Println("\n👥 Selected Delegates:")
	for _, d := range delegates {
		fmt.Printf("Delegate %s (TrustScore: %.2f)\n", d.ID, d.TrustScore)
	}

	// ---- Node Authentication ----
	auth := consensus.AuthFactors{
		PublicKeyValid:  true,
		RecentActivity:  true,
		LocationTrusted: false,
	}
	authScore := consensus.MultiFactorScore(auth)
	fmt.Printf("\n🔐 Node Authentication Score: %.2f\n", authScore)

	// ---- Blockchain Block Composition ----
	chain := []state.Block{}
	genesis := state.NewBlock(0, []string{"tx1", "tx2"}, "0")
	chain = append(chain, genesis)

	block2 := state.NewBlock(1, []string{"tx3", "tx4", "tx5"}, genesis.Hash)
	chain = append(chain, block2)

	fmt.Println("\n📦 Blockchain State:")
	for _, blk := range chain {
		fmt.Printf("\nBlock %d\n", blk.Index)
		fmt.Printf("PrevHash: %s\n", blk.PrevHash)
		fmt.Printf("Hash: %s\n", blk.Hash)
		fmt.Printf("MerkleRoot: %s\n", blk.MerkleRoot)
		fmt.Printf("Accumulator: %s\n", blk.Accumulator)
		fmt.Printf("Entropy Score: %d\n", blk.EntropyScore)
	}

	// ---- State Pruning (Simulated) ----
	fmt.Println("\n🧹 Pruning block data for archival...")
	for i := range chain {
		chain[i].Data = nil
	}
}
