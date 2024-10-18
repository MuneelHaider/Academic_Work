#include <iostream>
#include "pch.h"
#include "CustomerAccount.h"
using namespace std;



CustomerAccount* customers[100];
int accountsOpen = 0;

void OpenCustomerAccount( CustomerAccount* customers[], int& accountsOpen, char* nameVal, 
						char* addVal, char* cityVal, char* stateVal, int zipcodeVal, 
						long long phoneVal, float balanceVal) {

	customers[accountsOpen] = new CustomerAccount;
	char* account = new char[6];

	customers[accountsOpen]->name = nameVal;
	
	customers[accountsOpen]->address.address = addVal;
	customers[accountsOpen]->address.city = cityVal;
	customers[accountsOpen]->address.state = stateVal;
	customers[accountsOpen]->address.zip_code = zipcodeVal;

	customers[accountsOpen]->phoneNum = phoneVal;
	customers[accountsOpen]->balance = balanceVal;

	if (accountsOpen < 100) {

		account[0] = 'P';
		account[1] = 'K';

		if (accountsOpen < 10) {

			account[2] = '0';
			account[3] = '0';
			account[4] = char(accountsOpen + 49);
		}
		else if (accountsOpen < 100) {

			account[2] = '0';
			account[3] = char((accountsOpen / 10) + 49);
			account[4] = char((accountsOpen % 10) + 49);
		}
		else if (accountsOpen == 100) {

			account[2] = '1';
			account[3] = '0';
			account[4] = '0';
		}
	}
	customers[accountsOpen]->accountNum = account;
	accountsOpen++;

}

int SearchCustomer(CustomerAccount* customers[], int accountsOpen, char* accountNum) {

	char* array = new char[3];

	char num1 = *(accountNum + 2);
	char num2 = *(accountNum + 3);
	char num3 = *(accountNum + 4);

	*(array) = num1;
	*(array + 1) = num2;
	*(array + 2) = num3;

	int account = 0;

	for (int i = 0; i < 3; i++) {

		account = account * 10 + (int(*(array + i) - 48));
	}

	if (account <= accountsOpen) {

		return account - 1;
	}
	else {

		return -1;
	}
	
}

bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char
	*accountNumVal, Address addressVal) {

	int account = SearchCustomer(customers, accountsOpen, accountNumVal);

	if (account != -1) {

		customers[account]->address = addressVal;
		return true;
	}

	return false;
}

bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen,
	char* accountNumVal, long long phoneVal) {

	int account = SearchCustomer(customers, accountsOpen, accountNumVal);

	if (account != -1) {

		customers[account]->phoneNum = phoneVal;
		return true;
	}

	return false;
}

bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char
	* accountNumVal, float balanceVal) {

	int account = SearchCustomer(customers, accountsOpen, accountNumVal);

	if (account != -1) {

		customers[account]->balance = balanceVal;
		return true;
	}

	return false;
}

void DisplayAllCustomers(CustomerAccount* customers[], int accountsOpen) {

	for (int i = 0; i < accountsOpen; i++) {

		cout << customers[i]->name << endl;
		cout << customers[i]->address.address << endl;
		cout << customers[i]->address.city << endl;
		cout << customers[i]->address.state << endl;
		cout << customers[i]->address.zip_code << endl;

		cout << customers[i]->phoneNum << endl;
		cout << customers[i]->balance << endl;
		cout << customers[i]->accountNum << endl;
	}
}