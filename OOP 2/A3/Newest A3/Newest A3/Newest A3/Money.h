#include "pch.h"
#include <iostream>
using namespace std;

/*		Muneel Haider
		21i-0640
		Assignment 3		*/

class Dollar {

	int d;

public:

	Dollar();
	Dollar(int num);

	void setDollar(int s);
	float getD();
	void increase1Dollar();
	void decrease1Dollar();

	Dollar operator+=(Dollar& obj);
	Dollar operator-=(Dollar& obj);
};
class Quarter {

	int q;

public:

	Quarter();
	Quarter(int num);

	void setQuarter(int s);
	int getQ();
	int getQuarters();

	void increase1Quarter();
	void decrease4Quarter();
	void decrease1Quarter();
	void increase4Quarter();
	void increase5Quarter();

	Quarter operator+=(Quarter& obj);
	Quarter operator-=(Quarter& obj);
};
class Nickel {

	int n;

public:

	Nickel();
	Nickel(int num);

	void setNickel(int s);
	int getN();
	int getNickels();
	void increase1Nickel();
	void decrease5Nickel();
	void decrease1Nickel();
	void increase5Nickel();

	Nickel operator+=(Nickel& obj);
	Nickel operator-=(Nickel& obj);
};
class Cent {

	int c;

public:

	Cent();
	Cent(int num);

	void setCent(int v);
	float getC();
	void increase1Cent();	
	void decrease5Cent();
	void increase5Cent();

	Cent operator+=(Cent& obj);
	Cent operator-=(Cent& obj);
};

class Money {
	
	Dollar dollars;
	Quarter quarters;
	Nickel nickels;
	Cent cents;
	double original;

public:

	Money();
	Money(double num);

	int getDollars();
	int getQuarters();
	int getNickels();
	int getCents();

    Money operator+(Money m);
	Money operator-(Money m);
	Money operator+(Dollar d);
	Money operator-(Dollar d);
 	Money operator+(Nickel d);
	Money operator-(Nickel d);
	Money operator+(Quarter d);
	Money operator-(Quarter d);
	Money operator+(Cent d);    
	Money operator-(Cent d);

	Money operator++(int n); 
	Money operator--(int n); 

	bool operator>=(Money& obj);
	bool operator<=(Money& obj);
	
	Quarter operator!();
	Nickel operator~();

	Money operator/(int n);
	Money operator*(int n);
	
	void MoneyChecker();
};