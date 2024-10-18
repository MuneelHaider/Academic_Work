#pragma once
#include <iostream>
using namespace std;

class Person {

protected:

	string type;
	int age;
	string address;

public:

	Person(string t = "", int a = 0, string add = "") {

		type = t;
		age = a;
		address = add;
	}

	void setType(string t) {

		type = t;
	}
	string getType() {

		return type;
	}

	void setAge(int a) {

		age = a;
	}
	int getAge() {

		return age;
	}

	void setAddress(string add) {

		address = add;
	}
	string getAddress() {

		return address;
	}

	void display() {

		cout << "Type:\t" << type << endl;
		cout << "Age:\t" << age << endl;
		cout << "Address:\t" << address << endl;
	}

	~Person(){}
};

class Employee : public Person {

protected:

	int empNum;
	float hireDate;
	int hours;

public:

	Employee(string t = "", int ag = 0, string add = "", int e = 0, float hr = 0, int h = 0) {

		type = t;
		age = ag;
		address = add;
		empNum = e;
		hireDate = hr;
		hours = h;
	}

	void setEmpNum(int e) {

		empNum = e;
	}
	int getEmpNum() {

		return empNum;
	}

	void setHours(int h) {

		hours = h;
	}
	int getHours() {

		return hours;
	}

	void setHireDate(float hr) {

		hireDate = hr;
	}
	float getHireDate() {

		return hireDate;
	}

	void display() {

		Person::display();
		cout << "EmpNum:\t" << empNum << endl;
		cout << "Hire Date:\t" << hireDate << endl;
		cout << "Hours:\t" << hours << endl;
	}

	~Employee(){}
};

class productionWorker : public Employee {

protected:

	int shift;
	double hourlyPayRate;

public:

	productionWorker(string t = "", int ag = 0, string add = "", int e = 0, float hr = 0, int h = 0, int s = 0, double hrpay = 0) {

		type = t;
		age = ag;
		address = add;
		empNum = e;
		hireDate = hr;
		hours = h;
		shift = s;
		hourlyPayRate = hr;
	}

	void setShift(int s) {

		shift = s;
	}
	int getShift() {

		return shift;
	}

	void setHourlyRate(double hr) {

		hourlyPayRate = hr;
	}
	double getHourlyRate() {

		return hourlyPayRate;
	}

	void display() {

		Person::display();
		cout << "Shift:\t" << shift << endl;
		cout << "Hourly Rate:\t" << hourlyPayRate << endl;
	}

	float calculatePay() {

		float result = hours * hourlyPayRate;
		return result;
	}

	~productionWorker(){}
};