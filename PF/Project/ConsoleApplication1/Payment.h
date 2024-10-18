#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Payment {

	float balance;

public:

	Payment(float bVal = 0) {

		balance = bVal;
	}

	void setbalance(float bVal) {

		balance = bVal;
	}
	float getbalance() {

		return balance;
	}

	Payment operator=(Payment P) {

		this->balance = P.balance;

		return *this;
	}

};