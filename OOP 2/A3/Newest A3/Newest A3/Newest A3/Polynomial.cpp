#include "pch.h"
#include "Polynomial.h"
#include <iostream>
using namespace std;


ostream& operator<<(ostream& output, const Polynomial&) {

	return output;
}
istream& operator>>(istream& input, Polynomial& obj) {

	input.ignore();
	getline(input, obj.poly);

	return input;
} // inputs the Polynomial

Polynomial::Polynomial() {

	degree = 0;
	poly = "";
}

Polynomial::Polynomial(int n) {

	degree = n;
	poly = "";
}

Polynomial::Polynomial(const Polynomial& obj) {

	degree = obj.degree;
	poly = obj.poly;
}

Polynomial Polynomial::operator=(const Polynomial& rhs) {

	degree = rhs.degree;
	poly = rhs.poly;

	return *this;
}

Polynomial Polynomial::operator-(const Polynomial& obj) {

	int size1 = poly.length();
	int size2 = obj.poly.length();
	int r3 = 0;
	int r2 = 0;
	int r1 = 0;
	int r = 0;
	int adder = 0;
	int added = 0;
	bool deg = true;

	Polynomial result;

	// For x^3
	for (int i = 0; i < size1 - 1; i++) {

		if (poly[i] == '^' && poly[i + 1] == '3') {

			adder = poly[i - 2] - 48;
		}
	}
	for (int i = 0; i < size2 - 1; i++) {

		if (obj.poly[i] == '^' && obj.poly[i + 1] == '3') {

			added = obj.poly[i - 2] - 48;
		}
	}
	r3 = adder - added;

	// For x^2
	for (int i = 0; i < size1 - 1; i++) {

		if (poly[i] == '^' && poly[i + 1] == '2') {

			adder = poly[i - 2] - 48;
		}
	}
	for (int i = 0; i < size2 - 1; i++) {

		if (obj.poly[i] == '^' && obj.poly[i + 1] == '2') {

			added = obj.poly[i - 2] - 48;
		}
	}
	r2 = adder - added;

	adder = 0;
	added = 0;

	// For x^1
	for (int i = 0; i < size1 - 1; i++) {

		if (poly[i] == 'x' && poly[i + 1] == ' ') {

			adder = poly[i - 1] - 48;
		}
	}

	bool f = false;

	for (int i = 0; i < size2 - 1; i++) {

		if (obj.poly[i + 1] == 'x' && obj.poly[i + 2] == ' ') {

			added = obj.poly[i] - 48;
		}
		if (obj.poly[i] == 'x') {

			f = true;
		}
	}

	if (f == true) {

		added = 1;
	}
	r1 = adder - added;

	adder = 0;
	added = 0;

	// For CONSTANTS
	for (int i = 1; i < size1; i++) {

		if (poly[i - 1] == ' ' && poly[i] <= '9' && poly[i] >= '1' && poly[i + 1] != 'x') {

			adder = poly[i] - 48;
		}
	}
	for (int i = 1; i < size2; i++) {

		if (obj.poly[i - 1] == ' ' && obj.poly[i] <= '9' && obj.poly[i] >= '1' && obj.poly[i + 1] != 'x') {

			added = obj.poly[i] - 48;
		}
	}
	r = adder - added;

	adder = 0;
	added = 0;

	if (r3 != 0) {

		if (r3 < 0) {

			result.poly += "-";
		}

		result.poly += char(r3 + 48);
		result.poly += "x^3";
		result.degree = 3;
		if (deg) {
			result.degree = 3;
			deg = false;
		}
	}
	if (r2 != 0) {

		if (deg) {
			result.degree = 2;
			deg = false;
		}
		else {

			if (r2 < 0) {

				abs(r2);
				result.poly += " - ";
			}
			else {
				result.poly += " + ";
			}
		}

		result.poly += char(r2 + 48);
		result.poly += "x^2";
	}
	if (r1 != 0) {

		if (deg) {
			result.degree = 1;
			deg = false;
		}
		else {

			if (r1 < 0) {

				abs(r1);
				result.poly += " - ";
			}
			else {
				result.poly += " + ";
			}
		}

		result.poly += char(r1 + 48);
		result.poly += "x";
	}
	if (r != 0) {

		if (deg) {
			result.degree = 0;
			deg = false;
		}
		else {

			if (r < 0) {

				abs(r);
				result.poly += " - ";
			}
			else {
				result.poly += " + ";
			}
		}

		result.poly += char(r + 48);
	}

	return result;
}

Polynomial Polynomial::operator+(const Polynomial& obj) {

	int size1 = poly.length();
	int size2 = obj.poly.length();
	int r3 = 0;
	int r2 = 0;
	int r1 = 0;
	int r = 0;
	int adder = 0;
	int added = 0;
	bool deg = true;

	Polynomial result;

	// For x^3
	for (int i = 0; i < size1 - 1; i++) {

		if (poly[i] == '^' && poly[i + 1] == '3') {

			adder = poly[i - 2] - 48;
		}
	}
	for (int i = 0; i < size2 - 1; i++) {

		if (obj.poly[i] == '^' && obj.poly[i + 1] == '3') {

			added = obj.poly[i - 2] - 48;
		}
	}
	r3 = adder + added;

	// For x^2
	for (int i = 0; i < size1 - 1; i++) {

		if (poly[i] == '^' && poly[i + 1] == '2') {

			adder = poly[i - 2] - 48;
		}
	}
	for (int i = 0; i < size2 - 1; i++) {

		if (obj.poly[i] == '^' && obj.poly[i + 1] == '2') {

			added = obj.poly[i - 2] - 48;
		}
	}
	r2 = adder + added;

	adder = 0;
	added = 0;

	// For x^1
	for (int i = 0; i < size1 - 1; i++) {

		if (poly[i] == 'x' && poly[i + 1] == ' ') {

			adder = poly[i - 1] - 48;
		}
	}

	bool f = false;

	for (int i = 0; i < size2 - 1; i++) {

		if (obj.poly[i + 1] == 'x' && obj.poly[i + 2] == ' ') {

			added = obj.poly[i] - 48;
		}
		if (obj.poly[i] == 'x') {

			f = true;
		}
	}

	if (f == true) {

		added = 1;
	}
	r1 = adder + added;

	adder = 0;
	added = 0;

	// For CONSTANTS
	for (int i = 1; i < size1; i++) {

		if (poly[i - 1] == ' ' && poly[i] <= '9' && poly[i] >= '1' && poly[i + 1] != 'x') {

			adder = poly[i] - 48;
		}
	}
	for (int i = 1; i < size2; i++) {

		if (obj.poly[i - 1] == ' ' && obj.poly[i] <= '9' && obj.poly[i] >= '1' && obj.poly[i + 1] != 'x') {

			added = obj.poly[i] - 48;
		}
	}
	r = adder + added;

	adder = 0;
	added = 0;

	if (r3 != 0) {

		result.poly += char(r3 + 48);
		result.poly += "x^3";
		result.degree = 3;
		if (deg) {
			result.degree = 3;
			deg = false;
		}
	}
	if (r2 != 0) {

		if (deg) {
			result.degree = 2;
			deg = false;
		}
		else {
			result.poly += " + ";
		}
		result.poly += char(r2 + 48);
		result.poly += "x^2";
	}
	if (r1 != 0) {

		if (deg) {
			result.degree = 1;
			deg = false;
		}
		else {
			result.poly += " + ";
		}

		result.poly += char(r1 + 48);
		result.poly += "x";
	}
	if (r != 0) {

		if (deg) {
			result.degree = 0;
			deg = false;
		}
		else {
			result.poly += " + ";
		}

		result.poly += char(r + 48);
	}

	return result;
}

Polynomial::operator string() const {

	return poly;
}

void Polynomial::operator+=(const Polynomial& obj) {

	int size1 = poly.length();
	int size2 = obj.poly.length();
	int r3 = 0;
	int r2 = 0;
	int r1 = 0;
	int r = 0;
	int adder = 0;
	int added = 0;
	bool deg = true;

	// For x^3
	for (int i = 0; i < size1 - 1; i++) {

		if (poly[i] == '^' && poly[i + 1] == '3') {

			adder = poly[i - 2] - 48;
		}
	}
	for (int i = 0; i < size2 - 1; i++) {

		if (obj.poly[i] == '^' && obj.poly[i + 1] == '3') {

			added = obj.poly[i - 2] - 48;
		}
	}
	r3 = adder + added;

	// For x^2
	for (int i = 0; i < size1 - 1; i++) {

		if (poly[i] == '^' && poly[i + 1] == '2') {

			adder = poly[i - 2] - 48;
		}
	}
	for (int i = 0; i < size2 - 1; i++) {

		if (obj.poly[i] == '^' && obj.poly[i + 1] == '2') {

			added = obj.poly[i - 2] - 48;
		}
	}
	r2 = adder + added;

	adder = 0;
	added = 0;

	// For x^1
	for (int i = 0; i < size1 - 1; i++) {

		if (poly[i] == 'x' && poly[i + 1] == ' ') {

			adder = poly[i - 1] - 48;
		}
	}

	bool f = false;

	for (int i = 0; i < size2 - 1; i++) {

		if (obj.poly[i + 1] == 'x' && obj.poly[i + 2] == ' ') {

			added = obj.poly[i] - 48;
		}
		if (obj.poly[i] == 'x') {

			f = true;
		}
	}

	if (f == true) {

		added = 1;
	}
	r1 = adder + added;

	adder = 0;
	added = 0;

	// For CONSTANTS
	for (int i = 1; i < size1; i++) {

		if (poly[i - 1] == ' ' && poly[i] <= '9' && poly[i] >= '1' && poly[i + 1] != 'x') {

			adder = poly[i] - 48;
		}
	}
	for (int i = 1; i < size2; i++) {

		if (obj.poly[i - 1] == ' ' && obj.poly[i] <= '9' && obj.poly[i] >= '1' && obj.poly[i + 1] != 'x') {

			added = obj.poly[i] - 48;
		}
	}
	r = adder + added;

	adder = 0;
	added = 0;
	poly = "";

	if (r3 != 0) {

		poly += char(r3 + 48);
		poly += "x^3";
		degree = 3;
		if (deg) {
			degree = 3;
			deg = false;
		}
	}
	if (r2 != 0) {

		if (deg) {
			degree = 2;
			deg = false;
		}
		else {
			poly += " + ";
		}
		poly += char(r2 + 48);
		poly += "x^2";
	}
	if (r1 != 0) {

		if (deg) {
			degree = 1;
			deg = false;
		}
		else {
			poly += " + ";
		}

		poly += char(r1 + 48);
		poly += "x";
	}
	if (r != 0) {

		if (deg) {
			degree = 0;
			deg = false;
		}
		else {
			poly += " + ";
		}

		poly += char(r + 48);
	}
}

void Polynomial::operator-=(const Polynomial& obj) {

	int size1 = poly.length();
	int size2 = obj.poly.length();
	int r3 = 0;
	int r2 = 0;
	int r1 = 0;
	int r = 0;
	int adder = 0;
	int added = 0;
	bool deg = true;

	// For x^3
	for (int i = 0; i < size1 - 1; i++) {

		if (poly[i] == '^' && poly[i + 1] == '3') {

			adder = poly[i - 2] - 48;
		}
	}
	for (int i = 0; i < size2 - 1; i++) {

		if (obj.poly[i] == '^' && obj.poly[i + 1] == '3') {

			added = obj.poly[i - 2] - 48;
		}
	}
	r3 = adder - added;

	// For x^2
	for (int i = 0; i < size1 - 1; i++) {

		if (poly[i] == '^' && poly[i + 1] == '2') {

			adder = poly[i - 2] - 48;
		}
	}
	for (int i = 0; i < size2 - 1; i++) {

		if (obj.poly[i] == '^' && obj.poly[i + 1] == '2') {

			added = obj.poly[i - 2] - 48;
		}
	}
	r2 = adder - added;

	adder = 0;
	added = 0;

	// For x^1
	for (int i = 0; i < size1; i++) {

		if (poly[i] == 'x' && poly[i + 1] == ' ') {

			adder = poly[i - 1] - 48;
		}
		else if (poly[i] == 'x' && poly[i + 1] == '\0') {

			adder = poly[i - 1] - 48;
		}
	}

	bool f = false;

	for (int i = 0; i < size2; i++) {

		if (obj.poly[i + 1] == 'x' && obj.poly[i + 2] == ' ') {

			added = obj.poly[i] - 48;
		}
		if (obj.poly[i] == 'x') {

			f = true;
		}
	}

	if (f == true) {

		added = 1;
	}
	r1 = adder - added;

	adder = 0;
	added = 0;

	// For CONSTANTS
	for (int i = 1; i < size1; i++) {

		if (poly[i - 1] == ' ' && poly[i] <= '9' && poly[i] >= '1' && poly[i + 1] != 'x') {

			adder = poly[i] - 48;
		}
	}
	for (int i = 1; i < size2; i++) {

		if (obj.poly[i - 1] == ' ' && obj.poly[i] <= '9' && obj.poly[i] >= '1' && obj.poly[i + 1] != 'x') {

			added = obj.poly[i] - 48;
		}
	}
	r = adder - added;

	adder = 0;
	added = 0;
	poly = "";

	if (r3 != 0) {

		if (r3 < 0) {

			r3 *= -1;
			poly += "-";
		}
		if (r3 != 1) {
			poly += char(r3 + 48);
		}
		poly += "x^3";
		degree = 3;
		if (deg) {
			degree = 3;
			deg = false;
		}
	}
	if (r2 != 0) {

		if (deg) {
			degree = 2;
			deg = false;
		}
		else {

			if (r2 < 0) {

				r2 *= -1;
				poly += " - ";
			}
			else {
				poly += " + ";
			}
		}
		if (r2 != 1) {
			poly += char(r2 + 48);
		}

		poly += "x^2";
	}
	if (r1 != 0) {

		if (deg) {
			degree = 1;
			deg = false;
		}
		else {

			if (r1 < 0) {

				r1 *= -1;
				poly += " - ";
			}
			else {
				poly += " + ";
			}
		}
		if (r1 != 1) {
			poly += char(r1 + 48);
		}

		poly += "x";
	}
	if (r != 0) {

		if (deg) {
			degree = 0;
			deg = false;
		}
		else {

			if (r < 0) {

				r *= -1;
				poly += " - ";
			}
			else {
				poly += " + ";
			}
		}

		poly += char(r + 48);
	}
}

bool Polynomial::operator==(const Polynomial& obj) {

	bool flag = true;
	int size = poly.length();

	for (int i = 0; i < size; i++) {

		if (poly[i] != obj.poly[i]) {

			flag = false;
			break;
		}
	}

	return flag;
}