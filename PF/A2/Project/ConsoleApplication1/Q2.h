#pragma once
#include <iostream>
using namespace std;

class Employee {

	string name, address;
	static int count;
	int age = 0;
	int salary = 0;
	int	cnic = 0;

public:

	Employee(string s, string a, int a1, int sal, int c) {

		name = s;
		address = a;
		age = a1;
		salary = sal;
		cnic = c;

		++count;

		print_employee();
	}

	string getName() {

		return name;
	}

	static int getTotalEmployee() {

		return count;
	}

	void print_employee();
};

int Employee::count = 0;

void Employee::print_employee() {

	cout << "Name:    " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Age:     " << age << endl;
	cout << "Salary:  " << salary << endl << endl;
}