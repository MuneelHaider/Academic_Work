#include <iostream>
#include "pch.h"
#include "Sequence.h"
using namespace std;


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