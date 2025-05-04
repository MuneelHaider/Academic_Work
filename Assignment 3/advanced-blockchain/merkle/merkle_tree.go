package merkle

import (
	"crypto/sha256"
	"encoding/hex"
)

type Node struct {
	Hash  string
	Left  *Node
	Right *Node
}

func hash(data string) string {
	h := sha256.Sum256([]byte(data))
	return hex.EncodeToString(h[:])
}

func BuildMerkleTree(leaves []string) *Node {
	var nodes []*Node
	for _, data := range leaves {
		nodes = append(nodes, &Node{Hash: hash(data)})
	}

	for len(nodes) > 1 {
		var nextLevel []*Node
		for i := 0; i < len(nodes); i += 2 {
			if i+1 == len(nodes) {
				nextLevel = append(nextLevel, nodes[i])
			} else {
				combined := nodes[i].Hash + nodes[i+1].Hash
				nextLevel = append(nextLevel, &Node{
					Hash:  hash(combined),
					Left:  nodes[i],
					Right: nodes[i+1],
				})
			}
		}
		nodes = nextLevel
	}
	return nodes[0]
}
