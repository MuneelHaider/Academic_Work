package merkle

type MerkleProof struct {
	Hashes []string
	Index  int
}

// GenerateMerkleProof builds a Merkle proof for a leaf at given index
func GenerateMerkleProof(leaves []string, index int) MerkleProof {
	var hashes []string
	var nodes []*Node

	for _, data := range leaves {
		nodes = append(nodes, &Node{Hash: hash(data)})
	}

	i := index
	for len(nodes) > 1 {
		var nextLevel []*Node
		for j := 0; j < len(nodes); j += 2 {
			if j+1 == len(nodes) {
				nextLevel = append(nextLevel, nodes[j])
			} else {
				combined := nodes[j].Hash + nodes[j+1].Hash
				parent := &Node{
					Hash:  hash(combined),
					Left:  nodes[j],
					Right: nodes[j+1],
				}
				nextLevel = append(nextLevel, parent)

				// if index is in this pair, capture sibling hash
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
