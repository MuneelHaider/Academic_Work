#pragma once
#include <iostream>
using namespace std;	

class Account {

	float balance;
	float service_fee;

public:

	Account() {

		balance = 0;
		service_fee = 0;
	}
	Account(float b, float sf) {

		balance = b;
		service_fee = sf;
	}

	float getBalance() {

		return balance;
	}
	void setBalance(float b) {

		balance = b;
	}
	float getservicefee() {

		return service_fee;
	}
	void setServiceFee(float sf) {

		service_fee = sf;
	}

	float operator--() {

		this->balance -= this->service_fee;
		return this->balance;
	}

	float operator+=(float amount) {

		this->balance += amount;
		return this->balance;
	}

	float operator-=(float amount) {

		this->balance -= amount;
		return this->balance;
	}

	float operator~() {

		cout << "Account Balance:\t" << this->balance << endl;
		cout << "Service Fee:\t" << this->service_fee << endl;

		return this->balance;
	}

	friend void iAmCustomersFriend() {

		Account obj;

		cout << obj.getBalance() << endl;
		cout << obj.getservicefee() << endl;
	}

	friend Account sumAccountsIntoNewAccount(Account obj1, Account obj2) {

		Account obj3;

		obj3.balance = obj1.balance + obj2.balance;

		return obj3;
	}
};