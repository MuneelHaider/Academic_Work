package sharding

type ShardManager struct {
	Shards []*Shard
	Threshold int // Max items per shard before splitting
}

func NewShardManager(threshold int) *ShardManager {
	return &ShardManager{
		Threshold: threshold,
	}
}

func (sm *ShardManager) AddData(data string) {
	for _, shard := range sm.Shards {
		if len(shard.Data) < sm.Threshold {
			shard.Data = append(shard.Data, data)
			shard.RecalculateMerkleRoot()
			return
		}
	}
	// All shards full, create new one
	newShard := &Shard{
		ID:   len(sm.Shards),
		Data: []string{data},
	}
	newShard.RecalculateMerkleRoot()
	sm.Shards = append(sm.Shards, newShard)
}
