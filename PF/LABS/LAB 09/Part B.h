#pragma once
#include "pch.h"
#include <iostream>
using namespace std;

class Student {

	string name;
	int id;
	int semester;
	double cgpa;

public:

	Student(string nameVal = " ", int idVal = 0, int semesterVal = 0, int cgpaVal = 0) {

		name = nameVal;
		id = idVal;
		semester = semesterVal;
		cgpa = cgpaVal;
	}

	friend istream& operator>>(istream& in, Student& s);
	friend ostream& operator<<(ostream& out, const Student& s);
};

istream& operator>>(istream& in, Student& s) {

	in >> s.name;
	in >> s.id;
	in >> s.semester;
	in >> s.cgpa;

	return in;
}

ostream& operator<<(ostream& out, const Student& s) {

	out << s.name << endl;
	out << s.id << endl;
	out << s.semester << endl;
	out << s.cgpa;

	return out;
}