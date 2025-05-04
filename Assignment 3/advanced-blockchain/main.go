package main

import (
	"fmt"
	"time"
	"math/big"

	"advanced-blockchain/sharding"
	"advanced-blockchain/state"
	"advanced-blockchain/crypto"
	"advanced-blockchain/cap"
	"advanced-blockchain/bft"
	"advanced-blockchain/consensus"
	"advanced-blockchain/merkle"
)

var blockchain []state.Block

func main() {
	// ---- Shard Setup ----
	fmt.Println("\nShard Setup:")
	manager := sharding.NewShardManager(3)
	entries := []string{"tx1", "tx2", "tx3", "tx4", "tx5"}
	for _, entry := range entries {
		manager.AddData(entry)
	}

	// ---- AMQ ----
	fmt.Println("\nApproximate Membership Query (Bloom Filter):")
	amq := state.NewAMQ(1000, 5)
	for _, entry := range entries {
		amq.Add(entry)
	}
	fmt.Println("Might contain 'tx2'?", amq.MightContain("tx2"))
	fmt.Println("Might contain 'tx999'?", amq.MightContain("tx999"))

	// ---- Merkle Proof ----
	fmt.Println("\nMerkle Proof:")
	leaves := []string{"tx1", "tx2", "tx3", "tx4"}
	root := merkle.BuildMerkleTree(leaves)
	proof := merkle.GenerateMerkleProof(leaves, 2)
	verified := merkle.VerifyMerkleProof("tx3", proof, root.Hash)
	fmt.Println("Merkle Proof Verified (tx3):", verified)

	// ---- RSA Accumulator ----
	fmt.Println("\nRSA Accumulator:")
	acc := crypto.SetupRSAAccumulator()
	x1 := big.NewInt(3)
	x2 := big.NewInt(5)
	x3 := big.NewInt(7)
	x4 := big.NewInt(11)
	acc.Add(x1)
	acc.Add(x2)
	acc.Add(x3)
	acc.Add(x4)
	fmt.Println("Accumulator Value:", acc.Get())
	witness := crypto.GenerateWitness([]*big.Int{x1, x2, x3, x4}, x3, acc)
	verifiedAcc := crypto.Verify(witness, x3, acc.Get(), acc.N)
	fmt.Println("Membership Proof for x=7:", verifiedAcc)

	// ---- Cross-Shard Transfer ----
	fmt.Println("\nCross-Shard Transfer:")
	if len(manager.Shards) >= 2 {
		transfer := sharding.CreateStateTransfer(manager.Shards[0], manager.Shards[1], 2)
		fmt.Printf("Transferred from Shard %d to %d: %v\n", transfer.FromShard, transfer.ToShard, transfer.DataChunk)
		fmt.Println("Merkle Root:", transfer.RootHash)
		fmt.Println("Proof Verified:", sharding.VerifyMerkleProofs(transfer))
	}

	// ---- CAP Theorem Orchestration ----
	fmt.Println("\nCAP Theorem Orchestration:")
	orch := cap.NewOrchestrator()
	simulated := []cap.NetworkTelemetry{
		{LatencyMs: 50, PartitionProbability: 0.1},
		{LatencyMs: 180, PartitionProbability: 0.3},
		{LatencyMs: 70, PartitionProbability: 0.9},
	}
	for i, telemetry := range simulated {
		orch.AdjustBasedOnNetwork(telemetry)
		fmt.Printf("Scenario %d:\n", i+1)
		fmt.Printf("Latency: %dms, Partition Probability: %.2f\n", telemetry.LatencyMs, telemetry.PartitionProbability)
		fmt.Println("Selected Consistency:", orch.CurrentLevel)
		fmt.Println("Retry Timeout:", orch.RetryTimeout)
		fmt.Println()
	}

	// ---- Vector Clocks ----
	fmt.Println("\nVector Clock Causality:")
	v1 := cap.NewVectorClock()
	v2 := cap.NewVectorClock()
	v1.Tick("A")
	v2.Tick("B")
	v1.Merge(v2)
	v1.Tick("A")
	fmt.Println("v1 Clock:", v1.Clock)
	fmt.Println("v2 Clock:", v2.Clock)
	fmt.Println("v2 Happens Before v1?", v2.HappensBefore(v1))
	fmt.Println("v1 Happens Before v2?", v1.HappensBefore(v2))

	// ---- BFT Voting ----
	fmt.Println("\nByzantine Fault Tolerance (Signed Voting):")
	nodes := []*bft.Node{
		{ID: "NodeA", Reputation: 0.9},
		{ID: "NodeB", Reputation: 0.8},
		{ID: "NodeC", Reputation: 0.3},
	}
	for _, n := range nodes {
		n.GenerateKeys()
		n.AdjustReputation(!n.IsMalicious)
	}
	message := "block_hash_abc123"
	votes := []bft.Vote{}
	for _, n := range nodes {
		vote := n.SignVote(message)
		votes = append(votes, vote)
		fmt.Printf("Node %s signed vote.\n", vote.NodeID)
	}
	for i, v := range votes {
		for _, n := range nodes {
			if n.ID == v.NodeID {
				isValid := bft.VerifyVote(v, n.PublicKey)
				fmt.Printf("Vote %d from %s is valid? %v\n", i+1, v.NodeID, isValid)
			}
		}
	}

	// ---- Proof of Work ----
	fmt.Println("\nProof of Work:")
	start := time.Now()
	hash, nonce := consensus.Mine("block data", 3)
	elapsed := time.Since(start)
	fmt.Printf("PoW Result: %s (Nonce: %d, Time: %s)\n", hash, nonce, elapsed)

	// ---- dBFT Delegates ----
	fmt.Println("\ndBFT Delegate Selection:")
	delegates := consensus.SelectDelegates(nodes, 2)
	for _, d := range delegates {
		fmt.Printf("Delegate %s (TrustScore: %.2f)\n", d.ID, d.TrustScore)
	}

	// ---- Node Authentication ----
	fmt.Println("\nNode Authentication Score:")
	auth := consensus.AuthFactors{
		PublicKeyValid:  true,
		RecentActivity:  true,
		LocationTrusted: false,
	}
	score := consensus.MultiFactorScore(auth)
	fmt.Println("Authentication Score:", score)

	// ---- Blockchain ----
	fmt.Println("\nBlockchain State:")
	genesis := state.NewBlock(0, []string{"tx1", "tx2"}, "0")
	block2 := state.NewBlock(1, []string{"tx3", "tx4", "tx5"}, genesis.Hash)
	blockchain = append(blockchain, genesis, block2)
	for _, blk := range blockchain {
		fmt.Printf("\nBlock %d\n", blk.Index)
		fmt.Println("PrevHash:", blk.PrevHash)
		fmt.Println("Hash:", blk.Hash)
		fmt.Println("MerkleRoot:", blk.MerkleRoot)
		fmt.Println("Accumulator:", blk.Accumulator)
		fmt.Println("Entropy Score:", blk.EntropyScore)
	}

	// ---- Pruning ----
	fmt.Println("\nState Pruning:")
	for i := range blockchain {
		blockchain[i].Data = nil
	}
	fmt.Println("Pruning complete.")

	// ---- Zero-Knowledge Proof (ZKP) ----
	fmt.Println("\nZero-Knowledge Proof (Schnorr Protocol):")
	params, secret, public := crypto.SetupZKP()
	zkpProof := crypto.ProveZKP(params, secret)
	validZKP := crypto.VerifyZKP(params, zkpProof, public)
	fmt.Println("Public Params: P =", params.P, "G =", params.G)
	fmt.Println("Public Key (g^x mod p):", public)
	fmt.Println("Commitment:", zkpProof.Commitment)
	fmt.Println("Response:", zkpProof.Response)
	fmt.Println("Proof Valid?", validZKP)

	// ---- Verifiable Random Function (VRF) ----
	fmt.Println("\nVerifiable Random Function (VRF):")
	msg := "random-selection-round-42"
	vrfKey := crypto.GenerateKeyPair()
	vrfOut := crypto.EvaluateVRF(msg, vrfKey)
	validVRF := crypto.VerifyVRF(msg, vrfOut, vrfKey.PublicKey)
	fmt.Println("Message:", msg)
	fmt.Printf("VRF Hash: %x\n", vrfOut.Hash)
	fmt.Println("Signature R:", vrfOut.SignatureR.Text(16))
	fmt.Println("Signature S:", vrfOut.SignatureS.Text(16))
	fmt.Println("Proof Verified?", validVRF)

	// ---- Multi-Party Computation (MPC) ----
	fmt.Println("\nMulti-Party Computation (Additive Sharing):")
	mod := big.NewInt(97)
	originalSecret := big.NewInt(42)
	shares := crypto.SplitSecret(originalSecret, 3, mod)
	fmt.Println("Original Secret:", originalSecret)
	for i, s := range shares {
		fmt.Printf("Share %d: %s\n", i+1, s.String())
	}
	reconstructed := crypto.ReconstructSecret(shares, mod)
	fmt.Println("Reconstructed Secret:", reconstructed)
}
