package consensus

import (
	"advanced-blockchain/bft"
	"sort"
)

func SelectDelegates(nodes []*bft.Node, count int) []*bft.Node {
	sort.Slice(nodes, func(i, j int) bool {
		return nodes[i].TrustScore > nodes[j].TrustScore
	})

	if count > len(nodes) {
		count = len(nodes)
	}
	return nodes[:count]
}
