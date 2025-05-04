package sharding

import (
	"advanced-blockchain/merkle"
)

type StateTransfer struct {
	FromShard int
	ToShard   int
	DataChunk []string
	Proofs    []merkle.MerkleProof
	RootHash  string
}

func CreateStateTransfer(from *Shard, to *Shard, count int) StateTransfer {
	if count > len(from.Data) {
		count = len(from.Data)
	}

	chunk := from.Data[:count]
	tree := from.GetMerkleTree()

	proofs := []merkle.MerkleProof{}
	for _, entry := range chunk {
		idx := indexOf(entry, from.Data)
		if idx == -1 {
			continue
		}
		proofs = append(proofs, merkle.GenerateMerkleProof(from.Data, idx))
	}

	return StateTransfer{
		FromShard: from.ID,
		ToShard:   to.ID,
		DataChunk: chunk,
		Proofs:    proofs,
		RootHash:  tree.Hash,
	}
}

func VerifyMerkleProofs(transfer StateTransfer) bool {
	for i, entry := range transfer.DataChunk {
		if !merkle.VerifyMerkleProof(entry, transfer.Proofs[i], transfer.RootHash) {
			return false
		}
	}
	return true
}

func indexOf(target string, arr []string) int {
	for i, v := range arr {
		if v == target {
			return i
		}
	}
	return -1
}
