package bft

type Node struct {
	ID           string
	Reputation   float64  // 0 to 1
	TrustScore   float64  // Derived score
	IsMalicious  bool
}

func (n *Node) AdjustReputation(success bool) {
	if success {
		n.Reputation += 0.05
	} else {
		n.Reputation -= 0.1
	}

	// Clamp between 0 and 1
	if n.Reputation > 1 {
		n.Reputation = 1
	}
	if n.Reputation < 0 {
		n.Reputation = 0
	}

	// Update trust score
	n.TrustScore = n.Reputation * (1.0 - boolToFloat(n.IsMalicious))
}

func boolToFloat(b bool) float64 {
	if b {
		return 1
	}
	return 0
}
