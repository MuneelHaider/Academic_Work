#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class student {

	int rollNumber;
	string studentName;

public:

	student(int rolln = 0, string sName = "") : rollNumber(0), studentName("") {

		rollNumber = rolln;
		studentName = sName;
	}

	void display() {

		cout << "Roll Number:  " << rollNumber << endl;
		cout << "Student Name: " << studentName << endl << endl;
	}

	int& getRollNumber() {

		return rollNumber;
	}
	string getStudentName() {

		return studentName;
	}

	void setStudentName(string n) {

		studentName = n;
	}

	void retrieveObject(int roll);
	void retrieveAll();
	void updateObject(int roll, string sName);
	void deleteObject(int roll);
};

void insertObject(student& obj) {

	ofstream myFile("LAB13.bin", ios::binary | ios::app);
	if (myFile.write((char*)& obj, sizeof(obj))) {

		cout << "Object Successfully Inserted!" << endl;
	}
	else {

		cout << "Object Insertion Failed!" << endl;
	}

	myFile.close();
}

void student::retrieveObject(int roll) {

	student result;
	ifstream myFile("LAB13.bin", ios::binary);

	while (myFile.read((char*)&result, sizeof(result))) {

		if (result.getRollNumber() == rollNumber) {

			result.display();
			myFile.close();
		}
	}
}

void student::retrieveAll() {

	student result;
	ifstream myFile("LAB13.bin", ios::binary);

	while (myFile.read((char*)&result, sizeof(result))) {

		result.display();
	}
}

void student::updateObject(int roll, string sName) {

	student result;
	fstream myFile("LAB13.bin", ios::in | ios::out | ios::binary);

	while (myFile.read((char*)&result, sizeof(result))) {

		if (result.getRollNumber() == rollNumber) {

			result.setStudentName(sName);
		}
	}
}

void student::deleteObject(int roll) {

	student result;
	fstream myFile("LAB13.bin", ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);

	while (myFile.read((char*)&result, sizeof(result))) {

		if (result.getRollNumber() != rollNumber) {

			myFile_temp.write((char*)&result, sizeof(result));
		}
	}

	myFile.close();
	myFile_temp.close();
	rename("temp.bin", "LAB13.bin");
	remove("LAB13.bin");
}

int main()
{

	ofstream myfile;

	myfile.open("example.txt", ios::trunc);

	myfile << "Writing this to a file, \n";
	myfile << "And this one too. \n";
	
	myfile.close();

	string line;
	ifstream myFile;

	myFile.open("example.txt", ios::in);

	while (myFile) {

		getline(myFile, line);
		cout << line << endl;
	}

	myFile.close();

	return 0;
}