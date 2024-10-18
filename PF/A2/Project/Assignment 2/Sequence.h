#pragma once


class Sequence {

	int length = 0;
	int* pseq = NULL;

public:

	Sequence(int l = 10) {

		length = l;

		pseq = new int[l];

		for (int i = 0; i < length; i++) {
			*(pseq + i) = 0;
		}
	}

	Sequence(int lengthVal, int n1 = 0, int n2 = 0, int n3 = 0,
		int n4 = 0, int n5 = 0, int n6 = 0, int n7 = 0,
		int n8 = 0, int n9 = 0, int n10 = 0) {

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

	Sequence(Sequence& s) {

		length = s.length;

		pseq = new int[length];

		for (int i = 0; i < length; i++) {

			pseq[i] = s.pseq[i];

		}
	}

	int getLength();
	int* getSeq();
	void Sort(int n);
	int RemoveDuplicates();
	void Rotate(int steps);
};