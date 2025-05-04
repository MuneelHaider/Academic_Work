package cap

import (
	"time"
)

type ConsistencyLevel int

const (
	Strong ConsistencyLevel = iota
	Eventual
	Causal
)

func (c ConsistencyLevel) String() string {
	return [...]string{"Strong", "Eventual", "Causal"}[c]
}

type NetworkTelemetry struct {
	LatencyMs   int
	PartitionProbability float64
}

type CAPOrchestrator struct {
	CurrentLevel ConsistencyLevel
	RetryTimeout time.Duration
}

func NewOrchestrator() *CAPOrchestrator {
	return &CAPOrchestrator{
		CurrentLevel: Strong,
		RetryTimeout: 100 * time.Millisecond,
	}
}

func (o *CAPOrchestrator) AdjustBasedOnNetwork(t NetworkTelemetry) {
	if t.PartitionProbability > 0.7 {
		o.CurrentLevel = Eventual
		o.RetryTimeout = 500 * time.Millisecond
	} else if t.LatencyMs > 150 {
		o.CurrentLevel = Causal
		o.RetryTimeout = 300 * time.Millisecond
	} else {
		o.CurrentLevel = Strong
		o.RetryTimeout = 100 * time.Millisecond
	}
}
