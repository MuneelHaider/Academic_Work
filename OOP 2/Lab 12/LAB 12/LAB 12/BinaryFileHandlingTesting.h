#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char* fileName = "Binaries.bin";

class Student {

	int rollNumber;
	char studentName[100];

public:

	Student(int rollNumber = 0, string studentName = "") {

		this->rollNumber = rollNumber;
		strcpy_s(this->studentName, studentName.c_str());
		//Copying in CStyle string-char[]
	}

	void display() {

		cout << "Roll Number: " << rollNumber << endl;
		cout << "Student Name : " << studentName << endl << endl;
	}

	int getRollNumber() {

		return rollNumber;
	}

	char* getStudentName() {

		return studentName;
	}
};

void insertObject(Student object) {

	ofstream myFile(fileName, ios::binary | ios::app);
	
	if (myFile.write((char*)&object, sizeof(object))) {

		cout << "Object Successfully Inserted!" << endl;
	}
	else {

		cout << "Object Insertion Failed" << endl;

		myFile.close();
	}
}

Student retrieveObject(int rollNumber) {

	Student temp;
	ifstream myFile(fileName, ios::binary);
	
	while (myFile.read((char*)&temp, sizeof(temp))) {

		if (temp.getRollNumber() == rollNumber) {

			return temp;
		}
	}
}