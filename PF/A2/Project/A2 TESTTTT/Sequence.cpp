#include <iostream>
#include "pch.h"
#include "Sequence.h"
using namespace std;

Sequence::Sequence(int l) {

	length = l;

	pseq = new int[l];

	for (int i = 0; i < length; i++) {
		*(pseq + i) = 0;
	}
}

Sequence::Sequence(int lengthVal, int n1, int n2, int n3,
	int n4, int n5, int n6, int n7,
	int n8, int n9, int n10) {

	int count = 0;

	length = lengthVal;

	pseq = new int[10];

	*(pseq + count++) = n1;
	*(pseq + count++) = n2;
	*(pseq + count++) = n3;
	*(pseq + count++) = n4;
	*(pseq + count++) = n5;
	*(pseq + count++) = n6;
	*(pseq + count++) = n7;
	*(pseq + count++) = n8;
	*(pseq + count++) = n9;
	*(pseq + count) = n10;
}

Sequence::Sequence(Sequence& s) {

	length = s.length;

	pseq = new int[length];

	for (int i = 0; i < length; i++) {

		pseq[i] = s.pseq[i];

	}
}

Sequence::~Sequence() {

	delete[] pseq;
}

int Sequence::getLength() {

	return length;
}

int* Sequence::getSeq() {

	return pseq;
}

void Sequence::Sort(int n) {

	int i = 0;
	int index = 0;
	int x = 0;

	for (i = 0; i < n - 1; i++) {

		x = i;
		for (int j = i + 1; j < n; j++) {

			if (*(pseq + j) < *(pseq + x)) {

				x = j;
			}
		}

		int temp = *(pseq + x);
		*(pseq + x) = *(pseq + i);
		*(pseq + i) = temp;
	}
}

int Sequence::RemoveDuplicates() {

	Sort(length);

	if (length == 0 || length == 1) {

		return length;
	}
			

	int* temp = new int[length];

	int j = 0;
	for (int i = 0; i < length - 1; i++) {

		if (pseq[i] != pseq[i + 1]) {

			temp[j++] = pseq[i];
		}
	}
		
	temp[j++] = pseq[length - 1];

	for (int i = 0; i < j; i++) {

		pseq[i] = temp[i];
	}

	return j;
}

void Sequence::Rotate(int steps) {

	for (int i = 0; i < steps; i++) {

		int index = *(pseq);
		int counter = 0;

		for (int i = 0; i < steps - 1; i++) {

			*(pseq + i) = *(pseq + i + 1);

		}

		*(pseq + steps - 1) = index;
	}
}