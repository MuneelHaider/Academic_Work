#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Registration {

	Patient* patient_register;
	Doctor* doctor_register;
	Date* date_register;
	bool success_register;

public:

	Registration() {

		success_register = false;
	}

	void setRegister(bool flag) {

		success_register = flag;
	}
	bool getRegister() {

		return success_register;
	}
};