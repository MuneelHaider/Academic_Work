#include <iostream>
using namespace std;

class Employee {

	string name;
	int salary;
	int experience;
	string designation;

public:

	string getname() {

		return name;

	}

	void setname(string text) {

		name = text;

	}

	int getsalary() {

		return salary;
	}

	void setsalary(int n) {

		salary = n;
	}

	int getexperience() {

		return experience;
	}

	void setexperience(int n) {

		experience = n;
	}

	string getdesig() {

		return designation;
	}

	void setdesig(string text) {

		designation = text;
	}
};

int main() {

	Employee c[3];

	c[0].setname("Muneel");
	c[1].setname("Haider");
	c[2].setname("FAST");

	c[0].setsalary(20000);
	c[1].setsalary(10000);
	c[2].setsalary(50000);

	c[0].setexperience(4);
	c[1].setexperience(2);
	c[2].setexperience(3);

	c[0].setdesig("PMO");
	c[1].setdesig("NUCES");
	c[2].setdesig("FAST");

	int max = c[0].getsalary(), min = c[0].getexperience();

	for (int i = 0; i < 3; i++) {

		if (c[i].getsalary() > max) {

			max = c[i].getsalary();
		}

		if (c[i].getexperience() < min) {

			min = c[i].getexperience();
		}
	}

	for (int i = 0; i < 3; i++) {

		if (max == c[i].getsalary()) {

			cout << "HIGHEST SALARY EMPLOYEE" << endl;
			cout << c[i].getname() << " " << c[i].getsalary() << " " << c[i].getexperience() << " " << c[i].getdesig() << endl;
		}

		if (min == c[i].getexperience()) {

			cout << "LOWEST EXPERIENCE EMPLOYEE" << endl;
			cout << c[i].getname() << " " << c[i].getsalary() << " " << c[i].getexperience() << " " << c[i].getdesig() << endl;
		}
	}
}