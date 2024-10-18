#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class student {

	int studentID = 0;
	string studentName = " ";
	double* studentGPA = new double[4];
	double CGPA;

public:

	int getID() {

		return studentID;
	}
	void setID(int ID) {

		studentID = ID;
	}

	string getName() {

		return studentName;
	}
	void setName(string name) {

		studentName = name;
	}

	void generateGPA() {

		double number = 0;

		for (int i = 0; i < 4; i++) {

			number = (rand() % 4) + 1;

			this->studentGPA[i] = number;

			cout << i << " semester GPA: " << this->studentGPA[i];
		}
	}

	void CGPA() {

		double numbers = 0;
		double* total = new double[4];
		int counter = 0;

		for (int i = 0; i < 4; i++) {

			numbers += this->studentGPA[i];
		}
		
		numbers /= 4;
		CGPA = numbers;

		cout << "CGPA: " << numbers;
	}

	void printingCGPA(student* ptr) {

		student temp;

		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 4; j++) {

				if (ptr[j].CGPA > ptr[i].CGPA) {

					temp = ptr[i];
					ptr[i] = ptr[j];
					ptr[j] = temp;
				}
			}
		}

		for (int i = 0; i < 4; i++) {

			cout << "Name: " << ptr[i].getName() << endl;
			cout << "ID:   " << ptr[i].getID() << endl;
			cout << "CGPA: " << ptr[i].CGPA << endl;
		}
	}
};