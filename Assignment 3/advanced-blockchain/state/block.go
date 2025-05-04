package state

import (
	"advanced-blockchain/crypto"
	"advanced-blockchain/merkle"
	"crypto/sha256"
	"encoding/hex"
)

type Block struct {
	Index        int
	Data         []string
	MerkleRoot   string
	Accumulator  string
	EntropyScore int
	PrevHash     string
	Hash         string
}

func NewBlock(index int, data []string, prevHash string) Block {
	root := merkle.BuildMerkleTree(data)
	acc := crypto.NewAccumulator()
	for _, d := range data {
		acc.Add(d)
	}

	block := Block{
		Index:        index,
		Data:         data,
		MerkleRoot:   root.Hash,
		Accumulator:  hex.EncodeToString(acc.Get()),
		EntropyScore: calcEntropy(data),
		PrevHash:     prevHash,
	}

	block.Hash = block.generateHash()
	return block
}

func (b *Block) generateHash() string {
	raw := b.MerkleRoot + b.Accumulator + b.PrevHash
	sum := sha256.Sum256([]byte(raw))
	return hex.EncodeToString(sum[:])
}

// Naive entropy: unique character count from combined data
func calcEntropy(data []string) int {
	unique := make(map[rune]bool)
	for _, d := range data {
		for _, ch := range d {
			unique[ch] = true
		}
	}
	return len(unique)
}
