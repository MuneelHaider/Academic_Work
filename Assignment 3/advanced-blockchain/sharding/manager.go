package sharding

type ShardManager struct {
	Shards []*Shard
	Threshold int
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

	newShard := &Shard{
		ID:   len(sm.Shards),
		Data: []string{data},
	}
	newShard.RecalculateMerkleRoot()
	sm.Shards = append(sm.Shards, newShard)
}
