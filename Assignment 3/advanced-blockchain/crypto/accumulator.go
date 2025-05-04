package crypto

import (
	"math/big"
)

type RSAAccumulator struct {
	N     *big.Int // RSA modulus
	Value *big.Int // Current accumulator state
}

// SetupRSAAccumulator initializes with a modulus N and generator g = 3
func SetupRSAAccumulator() *RSAAccumulator {

	N, _ := new(big.Int).SetString("2519590847565789349402718324004839857142928212620403202777713783604366202070"+
		"7595556264018525880784406918290641249515082189298559149176184502808489127"+
		"3708415850201891341899081692616597350754371658823504513341165521611494748"+
		"3592079521937238845146914293441793085557430547462198957689991538538330396"+
		"2031598358569835935723133177486651363172117601667914609342821152745612290"+
		"2196086403441815981362977477130996051870721134999999837297804995105973173", 10)

	return &RSAAccumulator{
		N:     N,
		Value: big.NewInt(1),
	}
}

// Add adds a new value (element as prime) to the accumulator
func (a *RSAAccumulator) Add(x *big.Int) {
	a.Value.Exp(a.Value, x, a.N) // Acc = Acc^x mod N
}

// Get returns the current accumulator value
func (a *RSAAccumulator) Get() *big.Int {
	return new(big.Int).Set(a.Value)
}

// GenerateWitness computes witness for x: product of all other elements
func GenerateWitness(elements []*big.Int, x *big.Int, acc *RSAAccumulator) *big.Int {
	product := big.NewInt(1)
	for _, e := range elements {
		if e.Cmp(x) != 0 {
			product.Mul(product, e)
		}
	}
	// witness = g^product mod N
	witness := new(big.Int).Exp(big.NewInt(3), product, acc.N)
	return witness
}

// Verify checks that witness^x mod N = accumulator value
func Verify(witness, x, accValue, N *big.Int) bool {
	left := new(big.Int).Exp(witness, x, N)
	return left.Cmp(accValue) == 0
}
