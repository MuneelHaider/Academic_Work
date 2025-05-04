package bft

func CalculateConsensusThreshold(nodes []*Node) float64 {
	var totalTrust float64
	for _, n := range nodes {
		totalTrust += n.TrustScore
	}

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

func CountVerifiedVotes(votes []Vote, nodes []*Node) int {
	valid := 0
	for _, v := range votes {
		for _, n := range nodes {
			if n.ID == v.NodeID && VerifyVote(v, n.PublicKey) {
				valid++
			}
		}
	}
	return valid
}
