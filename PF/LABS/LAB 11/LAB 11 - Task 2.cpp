#include <iostream>
using namespace std;

class Professor {

	string p_name;
	string employeeID;
	string designation;

public:

	Professor() {

		p_name = "";
		employeeID = "";
		designation = "";
	}

	Professor(string nameVal, string emVal, string deVal) {


		p_name = nameVal;
		employeeID = emVal;
		designation = deVal;
	}

	void setProfessor(string nameVal, string emVal, string deVal) {


		p_name = nameVal;
		employeeID = emVal;
		designation = deVal;
	}

	void setP_name(string nameVal) {

		p_name = nameVal;
	}

	void setP_employee(string emVal) {

		employeeID = emVal;
	}

	void setP_designation(string deVal) {

		designation = deVal;
	}

	string getP_name() {

		return p_name;
	}

	string getP_employee() {

		return employeeID;
	}

	string getP_designation() {

		return designation;
	}

	void operator+(Professor obj) {

		p_name = obj.p_name;
		employeeID = obj.employeeID;
		designation = obj.designation;
	}
};

class Department {

	string d_name;
	string deptID;
	Professor* profList;
	int no_professors;

public:

	Department() {

		d_name = "";
		deptID = "";
		no_professors = 0;
	}

	Department(string nameVal, string depVal, Professor* array, int noVal) {

		d_name = nameVal;
		deptID = depVal;

		profList = array;

		no_professors = noVal;
	}

	void setd_name(string nameVal) {

		d_name = nameVal;
	}

	void setd_deptID(string depVal) {

		deptID = depVal;
	}

	void setd_profList(Professor* array) {

		profList = array;
	}

	void setd_noprofessors(int noVal) {

		no_professors = noVal;
	}

	string getd_name() {

		return d_name;
	}

	string getd_deptID() {

		return deptID;
	}

	Professor* getd_profList() {

		return profList;
	}

	int getd_int() {

		return no_professors;
	}

	void operator+(Department obj) {

		d_name = obj.d_name;
		deptID = obj.deptID;
		profList = obj.profList;
		no_professors = obj.no_professors;
	}
};

class University {

	string u_name;
	Department* dept;
	int no_departments;

public:

	University() {

		u_name = "";
		no_departments = 0;
	}

	University(string nameVal, Department* array, int noVal) {

		u_name = nameVal;
		dept = array;
		no_departments = noVal;
	}

	void setu_name(string nameVal) {

		u_name = nameVal;
	}
	void setu_dept(Department* array) {

		dept = array;
	}
	void setu_int(int noVal) {

		no_departments = noVal;
	}

	string getu_name() {

		return u_name;
	}
	Department* getu_dept() {

		return dept;
	}
	int getu_int() {

		return no_departments;
	}

	void addDepartment(Department* D) {


	}
}; 

int main() {

	return 0;
}