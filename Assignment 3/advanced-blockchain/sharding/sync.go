package sharding

import (
	"crypto/sha256"
	"encoding/hex"
)

type StateTransfer struct {
	DataChunk []string
	FromShard int
	ToShard   int
	Commitment string // SHA256 commitment
}

func CreateStateTransfer(from *Shard, to *Shard, count int) StateTransfer {
	if len(from.Data) < count {
		count = len(from.Data)
	}
	dataToTransfer := from.Data[:count]
	from.Data = from.Data[count:]
	from.RecalculateMerkleRoot()

	// Append to receiving shard
	to.Data = append(to.Data, dataToTransfer...)
	to.RecalculateMerkleRoot()

	// Create commitment hash
	commitHash := hashCommitment(dataToTransfer)

	return StateTransfer{
		DataChunk:  dataToTransfer,
		FromShard:  from.ID,
		ToShard:    to.ID,
		Commitment: commitHash,
	}
}

func VerifyCommitment(transfer StateTransfer) bool {
	expected := hashCommitment(transfer.DataChunk)
	return expected == transfer.Commitment
}

func hashCommitment(data []string) string {
	combined := ""
	for _, d := range data {
		combined += d
	}
	h := sha256.Sum256([]byte(combined))
	return hex.EncodeToString(h[:])
}
