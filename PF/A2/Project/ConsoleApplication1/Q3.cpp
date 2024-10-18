#include <iostream>
using namespace std;

class Distance {

	int Feet = 0;
	int Inches = 0;

public:

	Distance(int f = 0, int i = 0) {

		Feet = f;
		Inches = i;

		set_distance(Feet, Inches);
		Display_distance();
	}

	void set_distance(int f, int i);

	void Display_distance();
	
};

void Distance::set_distance(int f, int i) {

	Feet = f;

	if (i > 11) {

		while (i > 11) {

			Feet++;
			i = i - 12;
		}
	}
	Inches = i;
}

void Distance::Display_distance() {

	cout << "Feet:   " << Feet << endl;
	cout << "Inches: " << Inches << endl;
}

int main() {

	int feet = 6;
	int inches = 13;

	cin >> feet >> inches;

	Distance obj1(feet, inches);

	return 0;
}