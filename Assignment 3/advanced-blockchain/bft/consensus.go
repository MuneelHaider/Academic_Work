package bft

func CalculateConsensusThreshold(nodes []*Node) float64 {
	var totalTrust float64
	for _, n := range nodes {
		totalTrust += n.TrustScore
	}

	// Require 2/3 of total trust for consensus
	return (2.0 / 3.0) * totalTrust
}

func CountTrustedVotes(nodes []*Node) float64 {
	var votes float64
	for _, n := range nodes {
		if n.TrustScore > 0.5 {
			votes += n.TrustScore
		}
	}
	return votes
}
