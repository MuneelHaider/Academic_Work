#pragma once
#include <iostream>
#include <fstream>

using namespace std;

void create_doctor() {

	string name, id, password, cnic, location, hospital, specilization, email;
	float charge;
	int experience;

	cout << "Enter name of doctor:  ";
	cin >> name;

	cout << endl << "Enter password u want to set: ";
	cin >> password;

	cout << endl << "Enter CNIC: ";
	cin >> cnic;

	cout << endl << "Enter location: ";
	cin >> location;

	cout << endl << "Enter hospital: ";
	cin >> hospital;

	cout << endl << "Enter specilization field: ";
	cin >> specilization;

	cout << endl << "Enter email: ";
	cin >> email;

	cout << endl << "Enter hourly charge: ";
	cin >> charge;

	cout << endl << "Enter years of experience: ";
	cin >> experience;

	Doctor D(name, id, password, 1, cnic, email, specilization, location, hospital, experience, charge);

	ofstream File("Doctor.bin", ios::app, ios::binary);
	
	File.write((char*)&D, sizeof(D));

	File.close();
}