#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Person {

	string name;
	string ID;
	string password;
	int userType;

public:

	Person(string nVal = "", string IDval = "", string pVal = "", int uVal = 0) {

		name = nVal;
		ID = IDval;
		password = pVal;
		userType = uVal;
	}

	void setName(string nameVal) {

		name = nameVal;
	}
	string getName() {

		return name;
	}

	void setID(string IDVal) {

		ID = IDVal;
	}
	string getID() {

		return ID;
	}

	void setPassword(string pVal) {

		password = pVal;
	}
	string getPassword() {

		return password;
	}

	void setUserType(int uVal) {

		userType = uVal;
	}
	int getUserType() {

		return userType;
	}

};