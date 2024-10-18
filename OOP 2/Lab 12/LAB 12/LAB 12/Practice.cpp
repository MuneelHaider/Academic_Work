#include <iostream>
using namespace std;

class Course {

public:
	virtual void Pro1() {
		cout << "prioritize ";
	}
	virtual void Pro2() {
		cout << "your ";
	}
	virtual void Pro3() {
		cout << "work ";
	}
	virtual void Con1() {
		cout << "not fun ";
	}


};


class Programming :public Course {

public:
	virtual void Pro1() {
		cout << "programming ";
	}
	virtual void Pro2() {
		cout << "is ";
	}
	void Pro3() const {
		cout << "fun. ";
	}
	virtual void Con1() {
		cout << "you have to do it ";
	}


};



class AdvProgramming :public Programming {

public:
	virtual void Pro1() {
		cout << "com prog 1 ";
	}
	virtual void Pro2() {
		cout << "Com Prog 2 ";
	}
	void Pro3() {
		cout << "Com Prog 3. ";
	}
	virtual void Con1() {
		cout << "Com Prog 4 ";
	}


};

class DS :public AdvProgramming {

public:
	virtual void Pro1() {
		cout << "hass been ";
	}
	virtual void Pro2() {
		cout << "the best. ";
		Programming::Con1();
	}
	void Pro3() {
		cout << "DS 3 ";
	}
	virtual void Con1() {
		cout << "DS 4 ";
	}


};

class Algo :public AdvProgramming {

public:
	virtual void Pro1() {
		cout << "Algo 1 ";
	}
	virtual void Pro2() {
		cout << "Algo 2 ";
	}
	void Pro3() {
		cout << "Algo 3 ";
	}
	virtual void Con1() {
		cout << "Algo 4 ";
	}


};


class BasicProg :public Programming {

private:
	virtual void Pro1() {
		cout << "learn basics ";
	}
	virtual void Pro2() {
		cout << "was good ";
	}
	void Pro3() {
		cout << "but ";
	}
	virtual void Con1() {
		cout << "bas prog 4 ";
	}


};

class PF :public BasicProg
{

public:
	virtual void Pro1() {
		cout << "pf ";
	}

	void Pro3() {
		cout << "pf3. ";
	}
	virtual void Con1() {
		cout << "pf4 ";
	}


};


class OOP :public BasicProg {

public:
	virtual void Pro1() {
		cout << "oop ";
	}
	virtual void Pro2() {
		cout << "reuse ";
	}
	void Pro3() {
		cout << "polymorphism ";
	}
	virtual void Con1() {
		cout << "too many ";
	}


};



class Humanities :public Course {

public:
	virtual void Pro1() {
		cout << "Important ";
	}
	virtual void Pro2() {
		cout << "to ";
	}
	virtual void Pro3() {
		cout << "learn ";
	}
	virtual void Con1() {
		cout << "None ";
	}


};

class Isl : public Humanities {

};

class CommSkills : public Humanities {

};

int main() {

	Course* cp; AdvProgramming* app; Course co;
	PF p; OOP o; Algo a; DS d; CommSkills c;
	Isl i;
	Course& cr = p; Course& cr1(co);
	Humanities h;
	cp = &p;
	cp->Pro1();


	cr = o;
	cr.Pro2();
	cr.Pro3();
	cp = &o;
	cp->Pro1();
	app = &d;
	app->Pro1();
	app->Pro2();
	cr1 = h;
	cr1.Pro1();
	cr1.Pro2();
	cr1.Pro3();

	return 0;
}