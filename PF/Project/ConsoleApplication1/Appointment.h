#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Appointment {

	Patient patient_app;
	Doctor doctor_app;
	Date date_app;
	bool mode_of_appointment;
	bool confirmation_of_appointment;

public:
	
	Appointment() {

	}

	Appointment(Patient p, Doctor doctor, Date date,
		bool mVal = false, bool coaVal = false) {

		setPatient(p);
		setDoctor(doctor);
		setDate(date);

		mode_of_appointment = mVal;
		confirmation_of_appointment = coaVal;
	}

	void setPatient(Patient p) {

		patient_app = p;
	}
	Patient getPatient() {

		return patient_app;
	}

	void setDoctor(Doctor d) {

		doctor_app = d;
	}
	Doctor getDoctor() {

		return doctor_app;
	}

	void setDate(Date d) {

		date_app = d;
	}
	Date getDate() {

		return date_app;
	}

	void setmoa(bool moa) {

		mode_of_appointment = moa;
	}
	bool getmoa() {

		return mode_of_appointment;
	}

	void setcoa(bool coa) {

		confirmation_of_appointment = coa;
	}
	bool getcoa() {

		return confirmation_of_appointment;
	}

	Appointment operator=(Appointment a) {

		setPatient(a.patient_app);
		setDoctor(a.doctor_app);
		setDate(a.date_app);

		mode_of_appointment = a.mode_of_appointment;
		confirmation_of_appointment = a.confirmation_of_appointment;
	}

};