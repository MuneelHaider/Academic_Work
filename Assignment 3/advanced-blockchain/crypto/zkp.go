package crypto

import (
	"crypto/rand"
	"crypto/sha256"
	"math/big"
)

type SchnorrPublicParams struct {
	P *big.Int // large prime
	G *big.Int // generator
}

type SchnorrProof struct {
	Commitment *big.Int
	Response   *big.Int
}

// SetupZKP generates group parameters and key pair
func SetupZKP() (params SchnorrPublicParams, secret *big.Int, public *big.Int) {
	
	p, _ := new(big.Int).SetString("115792089237316195423570985008687907853269984665640564039457584007913129639937", 10)
	g := big.NewInt(2)

	x, _ := rand.Int(rand.Reader, p)      // secret
	y := new(big.Int).Exp(g, x, p)        // public

	params = SchnorrPublicParams{P: p, G: g}
	return params, x, y
}

func ProveZKP(params SchnorrPublicParams, secret *big.Int) SchnorrProof {
	r, _ := rand.Int(rand.Reader, params.P)
	commitment := new(big.Int).Exp(params.G, r, params.P)

	// Create hash-based challenge: H(commitment || g)
	hashInput := append(commitment.Bytes(), params.G.Bytes()...)
	cHash := sha256.Sum256(hashInput)
	c := new(big.Int).SetBytes(cHash[:])
	c.Mod(c, params.P) // ensure challenge < p

	// Response: s = r + c·x mod p
	s := new(big.Int).Mul(c, secret)
	s.Add(s, r)
	s.Mod(s, params.P)

	return SchnorrProof{
		Commitment: commitment,
		Response:   s,
	}
}

func VerifyZKP(params SchnorrPublicParams, proof SchnorrProof, public *big.Int) bool {
	hashInput := append(proof.Commitment.Bytes(), params.G.Bytes()...)
	cHash := sha256.Sum256(hashInput)
	c := new(big.Int).SetBytes(cHash[:])
	c.Mod(c, params.P)

	// left = g^s
	left := new(big.Int).Exp(params.G, proof.Response, params.P)

	// right = commitment · y^c
	yToC := new(big.Int).Exp(public, c, params.P)
	right := new(big.Int).Mul(proof.Commitment, yToC)
	right.Mod(right, params.P)

	return left.Cmp(right) == 0
}
