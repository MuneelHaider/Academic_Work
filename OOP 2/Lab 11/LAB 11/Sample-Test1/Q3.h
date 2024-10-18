#pragma once
#include <iostream>
using namespace std;

class Accountt {

	float* balance;
	float* service_fee;

public:

	Accountt() {

		balance = new float;
		service_fee = new float;
		balance = 0;
		service_fee = 0;
	}
	Accountt(float b, float sf) {

		balance = new float;
		service_fee = new float;
		*balance = b;
		*service_fee = sf;
	}

	Accountt(Accountt& obj, bool flag) {

		Accountt temp;

		temp.balance = obj.balance;
		temp.service_fee = obj.service_fee;

		this->balance = temp.balance;
		this->service_fee = temp.service_fee;
	}
	float getBalance() {

		return *balance;
	}
	void setBalance(float b) {

		*balance = b;
	}
	float getservicefee() {

		return *service_fee;
	}
	void setServiceFee(float sf) {

		*service_fee = sf;
	}

	float operator--() {

		*balance -= *service_fee;
		return *balance;
	}

	float operator+=(float amount) {

		*balance += amount;
		return *balance;
	}

	float operator-=(float amount) {

		*balance -= amount;
		return *balance;
	}

	float operator~() {

		cout << "Account Balance:\t" << *balance << endl;
		cout << "Service Fee:\t" << *service_fee << endl;

		return *balance;
	}
};