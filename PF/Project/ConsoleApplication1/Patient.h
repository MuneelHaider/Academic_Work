#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Patient : public Person{

	string CNIC;
	string phone_no;
	Feedback* feedback;
	Payment account;

public:

	Patient(string pname = "", string pID = "", string password = "", int pusertype = 2, string cnicVal = "", string phone = "", float balanceVal = 0) : Person(pname, pID, password, pusertype) {

		account.setbalance(balanceVal);
		CNIC = cnicVal;
		phone_no = phone;

	}

	void write_patient(Patient P) {

		ofstream File("Patient.bin", ios::binary);

		File.write((char*)&P, sizeof(P));

		File.close();
	}

	void setCNIC(string cVal) {

		CNIC = cVal;
	}
	string getCNIC() {

		return CNIC;
	}

	void setPhone(string p) {

		phone_no = p;
	}
	string getPhone() {

		return phone_no;
	}

	void setFeedback(Feedback* fVal) {

		feedback = fVal;
	}
	Feedback getFeedback() {

		return *feedback;
	}

	void setPayment(Payment acc) {

		account = acc;
	}
	Payment getPayment() {

		return account;
	}

	Patient operator=(Patient p) {

		this->setName(p.getName());
		this->setID(p.getID());
		this->setPassword(p.getPassword());
		this->setCNIC(p.getCNIC());
		this->setFeedback(p.feedback);
		this->setUserType(p.getUserType());
		this->setPayment(p.getPayment());
		this->setPhone(p.getPhone());

		return *this;
	}

	void editPatient() {

		int choice = 0;
		string temp;

		cout << "Which detail would you like to change?" << endl << endl;

		cout << "1. Name" << endl << "2. ID" << endl << "3. Password" << endl << "4. CNIC" << endl;
		cout << "5. Phone No." << endl << endl;
		
		cin >> choice;

		cout << "Enter: " << endl;

		switch (choice)
		{
		case 1:

			cin >> temp;
			setName(temp);
			break;

		case 2:

			cin >> temp;
			setID(temp);
			break;

		case 3:

			cin >> temp;
			setPassword(temp);
			break;

		case 4:

			cin >> temp;
			setCNIC(temp);
			break;

		case 5:

			cin >> temp;
			setPhone(temp);
			break;

		default:
			
			cout << "Chosen incorrect option. Please try again." << endl << endl;
			editPatient();
			break;
		}
	}
	void viewPatient() {

		cout << "Name:		" << getName() << endl;
		cout << "Username:	" << getID() << endl;
		cout << "CNIC:		" << getCNIC() << endl;
		cout << "Phone No:	" << getPhone() << endl;
		cout << "Balance:	" << account.getbalance() << endl;
	}

};