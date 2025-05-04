package consensus

import (
	"crypto/sha256"
	"encoding/hex"
	"fmt"
)

func Mine(data string, difficulty int) (string, int) {
	nonce := 0
	prefix := ""
	for i := 0; i < difficulty; i++ {
		prefix += "0"
	}

	var hash string
	for {
		hash = calculateHash(data, nonce)
		if hash[:difficulty] == prefix {
			break
		}
		nonce++
	}
	return hash, nonce
}

func calculateHash(data string, nonce int) string {
	input := fmt.Sprintf("%s:%d", data, nonce)
	hash := sha256.Sum256([]byte(input))
	return hex.EncodeToString(hash[:])
}
