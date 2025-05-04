package state

import (
	"github.com/willf/bloom"
)

type AMQ struct {
	filter *bloom.BloomFilter
}

func NewAMQ(size uint, hashes uint) *AMQ {
	return &AMQ{
		filter: bloom.New(size, hashes),
	}
}

func (a *AMQ) Add(data string) {
	a.filter.Add([]byte(data))
}

func (a *AMQ) MightContain(data string) bool {
	return a.filter.Test([]byte(data))
}
