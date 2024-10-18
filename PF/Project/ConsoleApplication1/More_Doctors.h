#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class gynecologist : public Doctor{

public:

	gynecologist(string dname = "", string dID = "", string dpassword = "", int dusertype = 1, string dcnic = "", string demail = "", string dspecilization = "",
		string dlocation = "", string dhospital = "", int dexperience = 0, float dhour_charge = 0,
		string dateday = "", string datemonth = "", string dateyear = "", string datehour = "", bool DateUsed = false,
		float feedbackrating = 0, string feedbackreview = "",
		float paymentbalance = 0) : Doctor(dname, dID, dpassword, dusertype, dcnic, demail, dspecilization, dlocation, dhospital, dexperience, dhour_charge, 
			dateday, datemonth, dateyear, datehour, DateUsed, 
			feedbackrating, feedbackreview) {

	}
};

class dermatologist : public Doctor {

public:

	dermatologist(string dname = "", string dID = "", string dpassword = "", int dusertype = 1, string dcnic = "", string demail = "", string dspecilization = "",
		string dlocation = "", string dhospital = "", int dexperience = 0, float dhour_charge = 0,
		string dateday = "", string datemonth = "", string dateyear = "", string datehour = "", bool DateUsed = false,
		float feedbackrating = 0, string feedbackreview = "",
		float paymentbalance = 0) : Doctor(dname, dID, dpassword, dusertype, dcnic, demail, dspecilization, dlocation, dhospital, dexperience, dhour_charge,
			dateday, datemonth, dateyear, datehour, DateUsed,
			feedbackrating, feedbackreview) {

	}
};

class oncologist : public Doctor {

public:

	oncologist(string dname = "", string dID = "", string dpassword = "", int dusertype = 1, string dcnic = "", string demail = "", string dspecilization = "",
		string dlocation = "", string dhospital = "", int dexperience = 0, float dhour_charge = 0,
		string dateday = "", string datemonth = "", string dateyear = "", string datehour = "", bool DateUsed = false,
		float feedbackrating = 0, string feedbackreview = "",
		float paymentbalance = 0) : Doctor(dname, dID, dpassword, dusertype, dcnic, demail, dspecilization, dlocation, dhospital, dexperience, dhour_charge,
			dateday, datemonth, dateyear, datehour, DateUsed,
			feedbackrating, feedbackreview) {

	}
};

class orthopedic : public Doctor {

public:

	orthopedic(string dname = "", string dID = "", string dpassword = "", int dusertype = 1, string dcnic = "", string demail = "", string dspecilization = "",
		string dlocation = "", string dhospital = "", int dexperience = 0, float dhour_charge = 0,
		string dateday = "", string datemonth = "", string dateyear = "", string datehour = "", bool DateUsed = false,
		float feedbackrating = 0, string feedbackreview = "",
		float paymentbalance = 0) : Doctor(dname, dID, dpassword, dusertype, dcnic, demail, dspecilization, dlocation, dhospital, dexperience, dhour_charge,
			dateday, datemonth, dateyear, datehour, DateUsed,
			feedbackrating, feedbackreview) {

	}
};