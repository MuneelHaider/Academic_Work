package sharding

import (
	"advanced-blockchain/merkle"
)

type Shard struct {
	ID       int
	Data     []string
	MerkleRoot *merkle.Node
}

func (s *Shard) RecalculateMerkleRoot() {
	s.MerkleRoot = merkle.BuildMerkleTree(s.Data)
}
