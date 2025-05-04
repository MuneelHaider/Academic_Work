package bft

import (
	"crypto/ecdsa"
	"crypto/elliptic"
	"crypto/rand"
	"crypto/sha256"
	"math/big"
)

type Node struct {
	ID          string
	Reputation  float64
	TrustScore  float64
	IsMalicious bool

	PrivateKey *ecdsa.PrivateKey
	PublicKey  ecdsa.PublicKey
}

func (n *Node) GenerateKeys() {
	priv, _ := ecdsa.GenerateKey(elliptic.P256(), rand.Reader)
	n.PrivateKey = priv
	n.PublicKey = priv.PublicKey
}

func (n *Node) AdjustReputation(success bool) {
	if success {
		n.Reputation += 0.05
	} else {
		n.Reputation -= 0.1
	}
	if n.Reputation < 0 {
		n.Reputation = 0
	}
	n.TrustScore = n.Reputation
}

type Vote struct {
	NodeID     string
	Message    string
	SignatureR *big.Int
	SignatureS *big.Int
}

func (n *Node) SignVote(message string) Vote {
	hash := sha256.Sum256([]byte(message))
	r, s, _ := ecdsa.Sign(rand.Reader, n.PrivateKey, hash[:])
	return Vote{
		NodeID:     n.ID,
		Message:    message,
		SignatureR: r,
		SignatureS: s,
	}
}

func VerifyVote(v Vote, pubKey ecdsa.PublicKey) bool {
	hash := sha256.Sum256([]byte(v.Message))
	return ecdsa.Verify(&pubKey, hash[:], v.SignatureR, v.SignatureS)
}
