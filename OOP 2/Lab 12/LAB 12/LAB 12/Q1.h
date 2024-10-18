#pragma once
#include <iostream>
using namespace std;

class Processor {

	string processName;
	float price;

public:

	Processor(string n, float p) : processName(""), price(0) {}
};

class MainMemory {

	int size;
	float price;

public:

	MainMemory(int s = 0, int p = 0) {

		size = s;
		price = p;
	}
};

class MotherBoard {

	string compName;

public:

	MotherBoard() {

		compName = "Intel";
	}
};

class Computer {

	Processor proc;
	MainMemory memory;
	MotherBoard board;

public:

	Computer(Processor p, MainMemory m) : proc(p), memory(m) {

	}
};