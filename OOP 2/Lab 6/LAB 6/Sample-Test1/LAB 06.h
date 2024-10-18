#pragma once
#include <iostream>
using namespace std;

/*	Muneel Haider	
	21i-0640		
	LAB 06			*/

// TASK 1
struct Account {

	int accountNumber = 1210;
	string accountHolderName;
	int accountBalance = 0;
	int holderAge;

	Account(string Name, int age) {

		accountHolderName = Name;
		holderAge = age;

		if (age < 18 && age > 60) {

			delete this;
		}
	}

	void func1(Account&);
	void func2(Account&);
	void func3(Account);
	bool func4(Account*, int);
};

void func1(Account& account) {

	cout << "Account Details:" << endl;
	cout << account.accountHolderName << endl;
	cout << account.accountNumber << endl;
	cout << account.holderAge << endl;
	cout << account.accountBalance << endl;
}
void func2(Account& account) {

	if (account.holderAge >= 22 && account.holderAge <= 40) {

		cout << "Age Accounts:" << endl;
		cout << account.accountHolderName << endl;
	}
}
void func3(Account account) {

	if (account.accountNumber % 2 == 0) {

		cout << "Account Balance:" << endl;
		cout << account.accountBalance << endl;
	}
}
bool func4(Account* array, int accNumber) {

	if (array->accountNumber == accNumber) {

		cout << "Account FOUND:" << endl;
		cout << array->accountHolderName << endl;
		cout << array->accountNumber << endl;
		cout << array->holderAge << endl;
		cout << array->accountBalance << endl;

		return true;
	}
	else {

		cout << "Account NOT FOUND" << endl;
		return false;
	}
}

//---Task02---//
struct Marks {

	string name;
	int* array = new int[4];
};

string getName(Marks& obj) {

	return obj.name;
}
bool assignMarks(string name, Marks& obj, float numbers[]) {

	int i = 0;

	for (i = 0; i < 4; i++) {

		obj.array[i] = numbers[i];
		obj.name = name;
	}

	if (i == 4) {

		return true;
	}
}
short getTotal(Marks& obj) {

	int sum = 0;

	for (int i = 0; i < 4; i++) {

		sum += obj.array[i];
	}

	return sum;
}
float getPercentage(Marks& obj) {

	float sum = 0;
	for (int i = 0; i < 4; i++) {

		sum += obj.array[i];
	}

	float percentage = (sum / 400) * 100;

	return percentage;
}

//---Task03---//
struct Time {

	int hours;
	int minutes;
	int seconds;
};

bool initialize(Time& obj, short h, short m, short s) {

	if (h < 24 && m < 60 && s < 60) {
		
		obj.hours = h;
		obj.minutes = m;
		obj.seconds = s;
	
		return true;
	}
	else {

		return false;
	}
}
Time difference(Time& obj1, Time& obj2) {

	Time C;

	C.hours = obj1.hours - obj2.hours;
	C.minutes = obj1.minutes - obj2.minutes;
	C.seconds = obj1.seconds - obj2.seconds;

	C.minutes = abs(C.minutes);
	C.seconds = abs(C.seconds);

	return C;
}