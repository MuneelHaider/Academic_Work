package crypto

import (
	"crypto/rand"
	"math/big"
)

// SplitSecret splits a secret into n shares (additive modulo sharing)
func SplitSecret(secret *big.Int, n int, mod *big.Int) []*big.Int {
	shares := make([]*big.Int, n)
	sum := big.NewInt(0)

	for i := 0; i < n-1; i++ {
		r, _ := rand.Int(rand.Reader, mod)
		shares[i] = r
		sum.Add(sum, r)
		sum.Mod(sum, mod)
	}
	last := new(big.Int).Sub(secret, sum)
	last.Mod(last, mod)
	shares[n-1] = last

	return shares
}

// ReconstructSecret adds all shares modulo mod
func ReconstructSecret(shares []*big.Int, mod *big.Int) *big.Int {
	total := big.NewInt(0)
	for _, s := range shares {
		total.Add(total, s)
	}
	return total.Mod(total, mod)
}
