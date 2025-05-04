package sharding

import (
	"advanced-blockchain/merkle"
)

type Shard struct {
	ID        int
	Data      []string
	MerkleRoot string
}

func (s *Shard) Add(data string) {
	s.Data = append(s.Data, data)
	s.RecalculateMerkleRoot()
}

func (s *Shard) RecalculateMerkleRoot() {
	root := merkle.BuildMerkleTree(s.Data)
	s.MerkleRoot = root.Hash
}

func (s *Shard) GetMerkleTree() *merkle.Node {
	return merkle.BuildMerkleTree(s.Data)
}
