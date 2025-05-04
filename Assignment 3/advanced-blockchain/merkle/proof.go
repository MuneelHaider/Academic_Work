package merkle

import (
	"crypto/sha256"
	"encoding/hex"
)

type MerkleProof struct {
	Hashes []string 
	Index  int      
}

// GenerateMerkleProof generates the Merkle proof path for a leaf at given index
func GenerateMerkleProof(leaves []string, index int) MerkleProof {
	var hashes []string
	var nodes []*Node

	for _, data := range leaves {
		nodes = append(nodes, &Node{Hash: hashStr(data)})
	}

	i := index
	for len(nodes) > 1 {
		var nextLevel []*Node
		for j := 0; j < len(nodes); j += 2 {
			if j+1 == len(nodes) {
				nextLevel = append(nextLevel, nodes[j])
			} else {
				combined := nodes[j].Hash + nodes[j+1].Hash
				parent := &Node{Hash: hashStr(combined)}
				nextLevel = append(nextLevel, parent)

				if j == i || j+1 == i {
					sibling := j
					if i == j {
						sibling = j + 1
					}
					hashes = append(hashes, nodes[sibling].Hash)
					i = len(nextLevel) - 1
				}
			}
		}
		nodes = nextLevel
	}

	return MerkleProof{
		Hashes: hashes,
		Index:  index,
	}
}

// VerifyMerkleProof verifies a Merkle proof for a given leaf, proof path and expected root
func VerifyMerkleProof(leaf string, proof MerkleProof, expectedRoot string) bool {
	computedHash := hashStr(leaf)
	index := proof.Index

	for _, siblingHash := range proof.Hashes {
		if index%2 == 0 {
			computedHash = hashStr(computedHash + siblingHash)
		} else {
			computedHash = hashStr(siblingHash + computedHash)
		}
		index = index / 2
	}
	return computedHash == expectedRoot
}

func hashStr(data string) string {
	h := sha256.Sum256([]byte(data))
	return hex.EncodeToString(h[:])
}
