package crypto

import (
	"crypto/ecdsa"
	"crypto/elliptic"
	"crypto/rand"
	"crypto/sha256"
	"math/big"
)

type VRFKeyPair struct {
	PrivateKey *ecdsa.PrivateKey
	PublicKey  ecdsa.PublicKey
}

type VRFOutput struct {
	Hash      []byte
	SignatureR *big.Int
	SignatureS *big.Int
}

// GenerateKeyPair creates ECDSA keys for VRF
func GenerateKeyPair() VRFKeyPair {
	priv, _ := ecdsa.GenerateKey(elliptic.P256(), rand.Reader)
	return VRFKeyPair{
		PrivateKey: priv,
		PublicKey:  priv.PublicKey,
	}
}

// EvaluateVRF generates output + proof from msg
func EvaluateVRF(msg string, key VRFKeyPair) VRFOutput {
	hash := sha256.Sum256([]byte(msg))
	r, s, _ := ecdsa.Sign(rand.Reader, key.PrivateKey, hash[:])

	return VRFOutput{
		Hash:      hash[:],
		SignatureR: r,
		SignatureS: s,
	}
}

// VerifyVRF checks that the VRF output was signed by the holder of the private key
func VerifyVRF(msg string, output VRFOutput, pub ecdsa.PublicKey) bool {
	hash := sha256.Sum256([]byte(msg))
	return ecdsa.Verify(&pub, hash[:], output.SignatureR, output.SignatureS)
}
