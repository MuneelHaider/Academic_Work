#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class managing_system {

	Patient* patient_system;
	Doctor* doctor_system;
	Appointment* appointment_system = new Appointment[100];

public:

	managing_system() {}

	managing_system(Patient* p, Doctor* d) {

		patient_system = p;
		doctor_system = d;
	}

	void setPatient(Patient p) {

		patient_system = &p;
	}
	void setDoctor(Doctor d) {

		doctor_system = &d;
	}
	void setAppointment(Appointment a) {

		appointment_system = &a;
	}

};