#pragma once


class Sequence {

	int length = 0;
	int* pseq = NULL;

public:

	Sequence(int l = 10);
	Sequence(int lengthVal, int n1 = 0, int n2 = 0, int n3 = 0,
		int n4 = 0, int n5 = 0, int n6 = 0, int n7 = 0,
		int n8 = 0, int n9 = 0, int n10 = 0);
	Sequence(Sequence& s);
	~Sequence();
	int getLength();
	int* getSeq();
	void Sort(int);
	int RemoveDuplicates();
	void Rotate(int);
};