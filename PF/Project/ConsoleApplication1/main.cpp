#include <iostream>
#include "Person.h"
#include "Date.h"
#include "Payment.h"
#include "Feedback.h"
#include "Doctor.h"
#include "More_Doctors.h"
#include "Patient.h"
#include "Appointment.h"
#include "Managing_system.h"
#include "Admin.h"
#include "Oladoc.h"

using namespace std;

int main() {



	Oladoc obj;

//	obj.read_data_Admin();
//	obj.read_data_doctor();
//	obj.read_data_patients();

	obj.FirstDisplay();

/*	oladoc.readdoctordata();
	oladoc.readpatient();
	oladoc.readadmin();

	ask for user type;

	1. adminpanel();
	2. Doctorpanel();
	3. Patientpanel();

	admin{

		1. login

				input username and password
				compare with data from file handling
				oladoc.adminPanel();

		2. register

				input all atributes
				write all data into file
				oladoc.adminpanel();
		}

			doctor{

			1.login
			2.register	
		}
			patient{

			1.login
			2.register
		}

*/


	return 0;
}