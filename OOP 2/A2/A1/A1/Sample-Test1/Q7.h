#pragma once
#include <iostream>
using namespace std;

struct SavingAccount {

	char* name = new char[10];
	float annualInterestRate;
	double savingBalance;
	char* accountNum = new char[2];

	SavingAccount() {

		name = new char[10];
		name = "";
		annualInterestRate = 0;
		savingBalance = 0;
		accountNum = new char[2];
		accountNum = "";
	}
	SavingAccount(char* n, float ann, double sb, char* an) {

		name = new char[10];
		name = n;
		annualInterestRate = ann;
		savingBalance = sb;
		accountNum = new char[2];
		accountNum = "";
	}

	char* getName() {

		return name;
	}
	void setName(char* n) {

		name = n;
	}

	float getRate() {

		return annualInterestRate;
	}
	void setRate(float a) {

		annualInterestRate = a;
	}

	double getBalance() {

		return savingBalance;
	}
	void setBalance(double sb) {

		savingBalance = sb;
	}

	char* getAccount() {

		return accountNum;
	}
	void setAccount(char* a) {

		accountNum = a;
	}
};

char* Tostring(int acc) {

	int number = 0;
	int temp = 0;
	int counter = 1;
	char* lmao = new char[2];

	while (acc != 0) {

		number = acc % 10;
		acc /= 10;

		lmao[counter--] = char(number + 48);
	}

	if (counter == 0) {

		lmao[counter] = '0';
	}

	return lmao;
}
int ToInt(char* acc) {

	int number = 0;
	int temp = 0;

	number = acc[0] - 48;

	number *= 10;

	number += acc[1] - 48;

	return number;

}
int accountsOpen = 0;

void OpenCustomerAccount(SavingAccount* savers[], int accountsOpen, char* NameVal, double balance) {

	SavingAccount* result = new SavingAccount;

	result[accountsOpen].setName(NameVal);
	result[accountsOpen].setBalance(balance);
	result[accountsOpen].setRate(0);
	result[accountsOpen].setAccount(Tostring(balance));

	savers[accountsOpen] = result;

	accountsOpen++;
}

float calculateMonthlyInterest(SavingAccount* saver) {

	float result = 1;
	result = (saver->getBalance() * saver->getRate()) / 12;
	
	return result;
}

void modifyInterestRate(SavingAccount* saver, float newValue) {

	saver->setRate(newValue);
}

int SearchCustomer(SavingAccount* savers[], int accountsOpen, char* accountNum) {

	for (int i = 0; i < 99; i++) {

		if (i == ToInt(accountNum)) {

			return i;
		}
	}

	return -1;
}

bool UpdateAccountBalance(SavingAccount* savers[], int accountsOpen, char* accountNumVal, double balanceVal) {

	bool updated = false;

	for (int i = 0; i < accountsOpen; i++) {

		if (savers[i]->getAccount() == accountNumVal) {

			savers[i]->setBalance(balanceVal);
			updated = true;
		}
	}

	return updated;
}