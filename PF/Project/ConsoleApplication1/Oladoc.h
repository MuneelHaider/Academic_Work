#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Oladoc {

	Patient* patient_oladoc;
	Doctor* doctor_oladoc;
	Admin* admin_oladoc;

	int countPatients;
	int countDoctors;
	int countAdmin;

	managing_system appointment;
	bool program;

public:

	Oladoc() {}

	void FirstDisplay() {

		int choice = 0;
		int choice_2 = 0;

		cout << "Welcome to OLADOC." << endl << "Please choose your account type." << endl << endl;
		cout << endl << "1. Admin" << endl << "2. Doctor" << endl << "3. Patient" << endl << endl;

		cin >> choice;

		if (choice == 1) {

			cout << "Would you like to: " << endl << endl;
			cout << "1. Login" << endl;
			cout << "2. Register" << endl << endl;

			cin >> choice_2;

			if (choice_2 == 1) {

				Adminlogin();
			}
			else if (choice_2 == 2) {

				AdminRegister();
			}
		}

		else if (choice == 2) {

			cout << "Would you like to: " << endl << endl;
			cout << "1. Login" << endl;
			cout << "2. Register" << endl << endl;
		
			cin >> choice_2;

			if (choice_2 == 1) {

				Doctorlogin();
			}
			else if (choice_2 == 2) {

				DoctorRegister();
			}
		}

		else if (choice == 3) {

			cout << "Would you like to: " << endl << endl;
			cout << "1. Login" << endl;
			cout << "2. Register" << endl << endl;

			cin >> choice_2;

			if (choice_2 == 1) {

				Patientlogin();
			}
			else if (choice_2 == 2) {

				PatientRegister();
			}
		}
	}

	
	void Adminlogin() {

		Admin A;
		string username, password;
		bool usercheck = false, passcheck = false;

		cout << "ADMIN LOGIN MENU" << endl << endl;

		cout << endl << "Enter username: ";
		cin >> username;

		cout << endl << "Enter password: ";
		cin >> password;

		ifstream File("Admin.bin", ios::app, ios::binary);

		while (File.read((char*)&A, sizeof(A))) {

			if (A.getID() == username) {

				usercheck = true;
			}

			if (A.getPassword() == password) {

				passcheck = true;
			}
		}

		File.close();

		if (usercheck == true || passcheck == true) {

			// PatientMenu();
		}
		else {

 		}
	}
	void Patientlogin() {

		Patient P;
		string username, password;
		bool usercheck = false, passcheck = false;

		cout << "PATIENT LOGIN MENU" << endl << endl;

		cout << endl << "Enter username: ";
		cin >> username;

		cout << endl << "Enter password: ";
		cin >> password;

		ifstream File("Patient.bin", ios::app, ios::binary);

		while (File.read((char*)&P, sizeof(P))) {

			if (P.getID() == username) {

				usercheck = true;
			}

			if (P.getPassword() == password) {

				passcheck = true;
			}
		}

		File.close();

		if (usercheck == true || passcheck == true) {

			// PatientMenu();
		}
		else {

		}
	}
	void Doctorlogin() {

		Doctor D;
		string username, password;
		bool usercheck = false, passcheck = false;

		cout << "DOCTOR LOGIN MENU" << endl << endl;

		cout << endl << "Enter username: ";
		cin >> username;

		cout << endl << "Enter password: ";
		cin >> password;

		ifstream File("Doctor.bin", ios::app, ios::binary);

		while (File.read((char*)&D, sizeof(D))) {

			if (D.getID() == username) {

				usercheck = true;
			}

			if (D.getPassword() == password) {

				passcheck = true;
			}
		}

		File.close();

		if (usercheck == true || passcheck == true) {

			// PatientMenu();
		}
		else {

		}
	}


	void AdminRegister() {

		string name, id, password;
		int type = 0;

		cout << endl << "ADMIN REGISTRATION MENU" << endl;

		cout << endl << "Enter Name:		";
		cin >> name;

		cout << endl << "Enter ID:		";
		cin >> id;

		cout << endl << "Enter Password:		";
		cin >> password;

		Admin A(name, id, password, type);

		A.write_admin(A);

		cout << endl << endl << "You have been registered successfully. You will now return to the main menu." << endl << endl;

		FirstDisplay();
	}
	void PatientRegister() {

		string name, id, password, cnic, phone;
		int type = 2;

		cout << endl << "PATIENT REGISTRATION MENU" << endl;

		cout << endl << "Enter Name:	";
		cin >> name;

		cout << endl << "Enter ID:	";
		cin >> id;

		cout << endl << "Enter Password:	";
		cin >> password;

		cout << endl << "Enter CNIC:	";
		cin >> cnic;

		cout << endl << "Enter phone:	";
		cin >> phone;

		Patient  p(name, id, password, type, cnic, phone);

		p.write_patient(p);

		cout << endl << endl << "You have been registered successfully. You will now return to the main menu." << endl << endl;

		FirstDisplay();
	}
	void DoctorRegister() {

		string name, id, password, cnic, email, specilization, location, hospital;
		int experience, usertype = 1;
		float hourly_charge;

		cout << endl << "DOCTOR REGISTRATION MENU" << endl << endl;

		cout << "Enter Name:	";
		cin >> name;

		cout << endl << "Enter ID:	";
		cin >> id;

		cout << endl << "Enter Password:	";
		cin >> password;

		cout << endl << "Enter CNIC:	";
		cin >> cnic;

		cout << endl << "Enter email:	";
		cin >> email;

		cout << endl << "Enter specilization:	";
		cin >> specilization;

		cout << endl << "Enter location:	";
		cin >> location;

		cout << endl << "Ener hospital:		";
		cin >> hospital;

		cout << endl << "Enter experience:	";
		cin >> experience;

		cout << endl << "Enter hourly charge:	";
		cin >> hourly_charge;

		Doctor D(name, id, password, 1, cnic, email, specilization, location, hospital, experience, hourly_charge);

		D.write_doctor(D);

		cout << endl << endl << "You have been registered successfully. You will now return to the main menu." << endl << endl;

		FirstDisplay();
	}


	// Must Check
	void read_data_Admin() {

		Admin A;

		ifstream File("Admin.bin", ios::app, ios::binary);

		while (File.read((char*)&A, sizeof(A))) {

			admin_oladoc[countAdmin] = A;
			countAdmin++;
		}

		File.close();
	}
	void read_data_doctor() {

		Doctor D;

		ifstream File("Doctor.bin", ios::app, ios::binary);

		while (File.read((char*)&D, sizeof(D))) {

			doctor_oladoc[countDoctors++] = D;
		}

		File.close();
	}
	void read_data_patients() {

		Patient P;

		ifstream File("Patient.bin", ios::app, ios::binary);

		while (File.read((char*)&P, sizeof(P))) {

			patient_oladoc[countPatients++] = P;
		}

		File.close();
	}


	// JUST MEANT FOR CHECKING
	void shit() {

		for (int i = 0; i < 3; i++) {

			cout << patient_oladoc[i].getName();
		}
	}


};