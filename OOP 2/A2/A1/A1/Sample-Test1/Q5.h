#pragma once
#include "Q2.h"
#include <iostream>
using namespace std;

class Person {

	string name;
	char gender;
	Date dob;
	int noOfChildren;

public:

	Person** children = new Person * [3];

	Person() {

		name = "";
		gender = '\0';
		noOfChildren = 0;
	}
	Person(string n, char g, int d, int m, int y){

		name = n;
		gender = g;
		dob.setDay(d);
		dob.setMonth(m);
		dob.setYear(y);
		noOfChildren = 0;

		for (int i = 0; i < 3; i++) {

			children[i] = new Person[3];
		}
	}

	string getName() {

		return name;
	}
	void setName(string n) {

		name = n;
	}

	int getChildren() {

		return noOfChildren;
	}
	void setChildren() {

		noOfChildren++;
	}
	void setCHILD(int c) {

		noOfChildren = c;
	}

	char getGender() {

		return gender;
	}
	void setGender(char g) {

		gender = g;
	}

	void displayData() {

		cout << "Name:\t" << name << endl;
		cout << "Gender:\t";

		if (gender == 'm' || gender == 'M') {

			cout << "Male" << endl;
		}
		else {

			cout << "Female" << endl;
		}

		cout << "Date of Birth:\t" << dob.getDay() << " / " << dob.getMonth() << " / " << dob.getYear() << endl;
		cout << "No. of children:\t" << noOfChildren << endl;
	}
	int calcAge() {

		int age = 0;

		int d = 20;
		int m = 10;
		int y = 2022;

		age = y - dob.getYear();

		if (m < dob.getMonth()) {

			age--;
		}
		else if (m == dob.getMonth()){
			
			if (d < dob.getDay()) {

				age--;
			}
		}

		return age;
	}
};


class FamilyTree {

	Person* foreFather;

public:

	FamilyTree(Person* ff) {

		foreFather = ff;
		foreFather->setCHILD(0);
	}

	void registerChild(Person& p, Person& child) {

		p.children[p.getChildren()][0] = child;
		p.setChildren();
	}

	Person findYoungestChildOf(Person& p) {

		int max = 2000;

		for (int i = 0; i < 3; i++) {

			if (max > p.children[i][0].calcAge()) {

				max = p.children[i][0].calcAge();
			}
		}

		for (int i = 0; i < 3; i++) {

			if (max == p.children[i][0].calcAge()) {

				return p.children[i][0];
			}
		}
	}

	void displayFamilyOf(Person p) {

		cout << "CHILDREN INFORMATION" << endl;

		for (int i = 0; i < 3; i++) {

			cout << "Name:\t" << p.children[i][0].getName() << endl;
			cout << "Age:\t" << p.children[i][0].calcAge() << endl;
			cout << "Gender:\t" << p.children[i][0].getGender() << endl;
			cout << "No. of children:\t" << p.children[i][0].getChildren() << endl << endl;
		}
	}

	Person* FindEldestGrandsonOf(Person* grandfather) {

		int max = 0;
		Person* answer = new Person;

		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++) {

				if (max <= grandfather->children[i][0].children[j][0].calcAge() && grandfather->children[i][0].children[j][0].calcAge() != 2022) {

					max = grandfather->children[i][0].children[j][0].calcAge();
					*answer = grandfather->children[i][0].children[j][0];
				}
			}
		}
		return answer;
	}
};
