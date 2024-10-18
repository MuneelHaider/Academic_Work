#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Doctor : public Person{

	string CNIC;
	string email;
	string specilization;
	string location;
	string hospital;
	int experience;
	float hourly_charge;

	Date Available_Date;
	Feedback feedback;
	Payment account;

public:

	Doctor(string dname = "", string dID = "", string dpassword = "", int dusertype = 1, string dcnic = "", string demail = "", string dspecilization = "",
		string dlocation = "", string dhospital = "", int dexperience = 0, float dhour_charge = 0,
		string dateday = "", string datemonth = "", string dateyear = "", string datehour = "", bool DateUsed = false,
		float feedbackrating = 0, string feedbackreview = "",
		float paymentbalance = 0) : Person(dname, dID, dpassword, dusertype) {
		
		this->setName(dname);
		this->setID(dID);
		this->setPassword(dpassword);
		this->setUserType(dusertype);
		CNIC = dcnic;
		email = demail;
		specilization = dspecilization;
		location = dlocation;
		hospital = dhospital;
		experience = dexperience;
		hourly_charge = dhour_charge;
		
		feedback.setrating(feedbackrating);
		feedback.setreview(feedbackreview);
		Available_Date.setDate(dateday, datemonth, dateyear, datehour, DateUsed);
		account.setbalance(paymentbalance);

	}

	void setCNIC(string cVal) {

		CNIC = cVal;
	}
	string getCNIC() {

		return CNIC;
	}
	
	void setEmail(string eVal) {

		email = eVal;
	}
	string getEmail() {

		return email;
	}

	void setSp(string SpVal) {

		specilization = SpVal;
	}
	string getSp() {

		return specilization;
	}

	void setLocation(string lVal) {

		location = lVal;
	}
	string getLocation() {

		return location;
	}

	void setHospital(string hVal) {

		hospital = hVal;
	}
	string getHospital() {

		return hospital;
	}

	void setExperience(int eVal) {

		experience = eVal;
	}
	int getExperience() {

		return experience;
	}

	void setCharge(float cVal) {

		hourly_charge = cVal;
	}
	float getCharge() {

		return hourly_charge;
	}

	Doctor operator=(Doctor d) {

		this->setName(d.getName());
		this->setID(d.getID());
		this->setPassword(d.getPassword());
		this->setUserType(d.getUserType());
		this->setCNIC(d.getCNIC());
		this->setEmail(d.getEmail());
		this->setSp(d.getSp());
		this->setLocation(d.getLocation());
		this->setHospital(d.getHospital());
		this->setExperience(d.getExperience());
		this->setCharge(d.getCharge());
		
		this->feedback = d.feedback;
		this->Available_Date.setDate(d.Available_Date.getDay(), d.Available_Date.getMonth(), d.Available_Date.getYear(), d.Available_Date.getHour(), d.Available_Date.getUsed());
		this->account.setbalance(d.account.getbalance());

		return *this;
	}

	void write_doctor(Doctor D) {

		ofstream File("Doctor.bin", ios::app, ios::binary);

		File.write((char*)&D, sizeof(D));

		File.close();
	}




};