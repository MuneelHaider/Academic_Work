#pragma once
#include <iostream>
using namespace std;

class Distance {

	int feet;
	int inches;

public:

	Distance(int f = 0, int i = 0) {

		feet = f;
		inches = i;
	}
	
	int getFeets() {

		return feet;
	}
	void setFeets(int f) {

		feet = f;
	}

	int getInches() {

		return inches;
	}
	void setInches(int i) {

		if (i >= 12) {

			while (i < 12) {

				i -= 12;
				feet++;
			}
		}

		inches = i;
	}

	Distance operator+(const Distance& obj) {

		this->inches += obj.inches;

		if (this->inches >= 12) {

			while (this->inches >= 12) {

				this->inches -= 12;
				this->feet += 1;
			}
		}

		this->feet += obj.feet;

		return *this;
	}

	Distance operator-(const Distance& obj) {

		this->inches -= obj.inches;

		if (this->inches >= 12) {

			while (this->inches >= 12) {

				inches -= 12;
				feet++;
			}
		}

		this->feet -= obj.feet;

		return *this;
	}

	bool operator==(const Distance& obj) {

		if (this->feet == obj.feet) {

			if (this->inches == obj.inches) {

				return true;
			}
			else {

				return false;
			}
		}
		else {

			return false;
		}
	}
};