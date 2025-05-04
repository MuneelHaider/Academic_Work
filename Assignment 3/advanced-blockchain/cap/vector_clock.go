package cap

type VectorClock struct {
	Clock map[string]int
}

func NewVectorClock() *VectorClock {
	return &VectorClock{
		Clock: make(map[string]int),
	}
}

// Advance increases the local counter
func (vc *VectorClock) Tick(nodeID string) {
	vc.Clock[nodeID]++
}

// Merge combines two vector clocks (max of each)
func (vc *VectorClock) Merge(other *VectorClock) {
	for id, ts := range other.Clock {
		if vc.Clock[id] < ts {
			vc.Clock[id] = ts
		}
	}
}

// HappensBefore checks if vc < other (causal order)
func (vc *VectorClock) HappensBefore(other *VectorClock) bool {
	atLeastOneLess := false
	for id := range vc.Clock {
		if vc.Clock[id] > other.Clock[id] {
			return false
		}
		if vc.Clock[id] < other.Clock[id] {
			atLeastOneLess = true
		}
	}
	return atLeastOneLess
}
