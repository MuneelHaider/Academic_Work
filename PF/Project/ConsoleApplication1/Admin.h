#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Admin : public Person {

	Appointment* appointment;

public:

	Admin(string aname = "", string aID = "", string ausername = "", int dusertype = 0) : Person(aname, aID, ausername, dusertype) {


	}

	void operator=(Admin A) {

		this->setName(A.getName());
		this->setID(A.getID());
		this->setPassword(A.getPassword());
		this->setUserType(A.getUserType());
	}

	void write_admin(Admin A) {

		ofstream File("Admin.bin", ios::app, ios::binary);

		File.write((char*)&A, sizeof(A));

		File.close();
	}

};