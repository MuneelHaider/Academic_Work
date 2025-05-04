package crypto

import (
	"crypto/sha256"
)

type Accumulator struct {
	value [32]byte
}

func NewAccumulator() *Accumulator {
	return &Accumulator{}
}

func (a *Accumulator) Add(data string) {
	a.value = sha256.Sum256(append(a.value[:], []byte(data)...))
}

func (a *Accumulator) Get() []byte {
	return a.value[:]
}
