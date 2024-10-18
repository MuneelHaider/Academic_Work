#pragma once
#include <iostream>
using namespace std;

class Professor {

	string profName;
	string specialization;
	string degree;
	static int amount_of_profs;

public:

	Professor(string pn, string s, string d): profName(pn), specialization(s), degree(d) {
	
		amount_of_profs++;
	}

	void setName(string n) {

		profName = n;
	}
	string getName() {

		return profName;
	}

	void setSpecial(string s) {

		specialization = s;
	}
	string getSpecial() {

		return specialization;
	}

	void setDegree(string d) {

		degree = d;
	}
	string getDegree() {

		return degree;
	}
	int getNumberofProfs() {

		return amount_of_profs;
	}

	friend ostream& operator<<(ostream& output, Professor& obj) {

		output << obj.profName << " has done " << obj.degree << " in " << obj.specialization << "." << endl;
		
		return output;
	}
	friend istream& operator>>(istream& input, Professor& obj) {

		cout << "Enter Professor Name:\t";
		input >> obj.profName;

		cout << endl << "Enter Specialization:\t";
		input >> obj.specialization;

		cout << endl << "Enter Degree:\t";
		input >> obj.degree;

		return input;
	}
};

class Laboratory {

	int labID;
	int experimentNo;
	static int number_of_labs;
	
public:

	Laboratory(int l = 0, int e = 0) :labID(l), experimentNo(e) {
	
		number_of_labs++;
	}

	void setLabID(int l) {

		labID = l;
	}
	int getLabID() {

		return labID;
	}

	void setEx(int e) {

		experimentNo = e;
	}
	int getEx() {

		return experimentNo;
	}
	int getNumberOfLabs() {

		return number_of_labs;
	}
};

class Department {

	string deptID;
	string deptName;
	Laboratory* Laboratories;
	Professor* professors;

public:

	Department(string id, string n, Laboratory* l, Professor* p):deptID(id), deptName(n), Laboratories(l), professors(p) {}
	
	void setProfessor(Professor* p) {

		professors = p;
	}
	Professor* getProfessor() {

		return professors;
	}

	void setLab(Laboratory* l) {

		Laboratories = l;
	}
	Laboratory* getLab() {

		return Laboratories;
	}

	string getID() {

		return deptID;
	}
	string getName() {

		return deptName;
	}
	void setID(string i) {

		deptID = i;
	}
	void setName(string n) {

		deptName = n;
	}

	void display() {

		cout << "Department ID:\t" << deptID << endl;
		cout << "Department Name:\t" << deptName << endl;
		cout << "Professors Included:" << endl << endl;

		for (int i = 0; i < professors->getNumberofProfs(); i++) {

			cout << "Name:\t" << professors[i].getName() << endl;
			cout << "Degree:\t" << professors[i].getDegree() << endl;
			cout << "Specialization:\t" << professors[i].getSpecial() << endl << endl;
		}

		cout << endl << "Laboratories Included:" << endl << endl;

		for (int i = 0; i < Laboratories->getNumberOfLabs(); i++) {

			cout << "Lab ID:\t" << Laboratories[i].getLabID() << endl;
			cout << "Lab Experiment:\t" << Laboratories[i].getEx() << endl << endl;
		}
	}

	Professor operator[](int i) {

		return professors[i];
	}
};

class University {

	string universityName;
	string location;
	Department* depts;
	static int number_of_depts;

public:

	University(string un, string l, Department* d) : universityName(un), location(l) {
	
		depts = d;
	}

	Department operator[](int i){
	
		return depts[i];
	}
};

int Professor::amount_of_profs = 0;
int Laboratory::number_of_labs = 0;
int University::number_of_depts = 0;