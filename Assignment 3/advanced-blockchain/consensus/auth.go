package consensus

type AuthFactors struct {
	PublicKeyValid bool
	RecentActivity bool
	LocationTrusted bool
}

func MultiFactorScore(f AuthFactors) float64 {
	score := 0.0
	if f.PublicKeyValid {
		score += 0.5
	}
	if f.RecentActivity {
		score += 0.3
	}
	if f.LocationTrusted {
		score += 0.2
	}
	return score
}
