#include "pch.h"
#include <iostream>
#include "Bouquet.h"
#include <string>
using namespace std;

string StringC(int value) {

	char result[20] = {};
	char lmao[20] = {};
	int temp = 0;
	int number = 0;
	int index = 0;
	int counter = 0;
	bool flag = false;

	while (value != 0 || index == 20) {

		temp = value % 10;
		value /= 10;
		result[index] = char(temp + 48);
		index++;
	}
	result[index] = '\0';

	counter = index - 1;

	for (int i = 0; i < index; i++) {

		lmao[i] = result[counter];
		counter--;
		temp = i;
	}
	lmao[temp + 1] = '\0';

	return lmao;
}

string StringB(bool value) {

	if (value == true) {

		return "1";
	}
	else {

		return "0";
	}
}

string StringF(float number) {

	string answer;

	int value = number;
	int decimal = (number - value) * 100;
	char result[20] = {};
	char lmao[20] = {};
	int temp = 0;
	int index = 0;
	int counter = 0;
	bool flag = false;

	while (value != 0 || index == 20) {

		temp = value % 10;
		value /= 10;
		result[index] = char(temp + 48);
		index++;
	}
	result[index] = '\0';

	counter = index - 1;

	for (int i = 0; i < index; i++) {

		lmao[i] = result[counter];
		counter--;
		temp = i;
	}
	lmao[temp + 1] = '\0';

	answer += lmao;
	answer += ".";

	char result1[20] = {};
	char lmao2[20] = {};
	int temp1 = 0;
	int number1 = 0;
	int index1 = 0;
	int counter1 = 0;
	bool flag1 = false;

	if (decimal == 0) {

		answer += '0';
		return answer;
	}
	else {

		while (decimal != 0 || index1 == 20) {

			temp1 = decimal % 10;
			decimal /= 10;
			result1[index1] = char(temp1 + 48);
			index1++;
		}
	}
	result1[index1] = '\0';

	counter1 = index1 - 1;

	for (int i = 0; i < index1; i++) {

		lmao2[i] = result1[counter1];
		counter1--;
		temp1 = i;
	}
	lmao2[temp1 + 1] = '\0';

	answer += lmao2;

	return answer;
}

Flower::Flower() {

	name = "";
	color = "";
	UnitPrice = 0;
	perfumed = false;
	sale = false;
}
Flower::Flower(string n, string c, float p = 0, bool perf = false, bool s = false) {

	name = n;
	color = c;
	UnitPrice = p;
	perfumed = perf;
	sale = s;
}

string Flower::getName() {

	return name;
}
void Flower::setName(string n) {

	name = n;
}

string Flower::getColor() {

	return color;
}
void Flower::setColor(string c) {

	color = c;
}

float Flower::getPrice() {

	return UnitPrice;
}
void Flower::setPrice(float p) {

	UnitPrice = p;
}

bool Flower::getPerf() {

	return perfumed;
}
void Flower::setPerf(bool flag) {

	perfumed = flag;
}

bool Flower::getSale() {

	return sale;
}
void Flower::setSale(bool f) {

	sale = f;
}

float Flower::price() {

	if (sale == true) {

		return UnitPrice / 2;
	}
	else {

		return UnitPrice;
	}
}

bool Flower::perfume() {

	return perfumed;
}

Flower::operator string() const {

	string result;
	bool flag = false;

	result = name;
	result += " ";
	result += color;
	result += " ";
	result += StringB(perfumed);
	result += ", Price: ";

	int lol = UnitPrice;

	if (lol == UnitPrice) {

		flag = false;
	}
	else {

		flag = true;
	}

	result += StringF(UnitPrice);

	if (flag == true) {

		result.pop_back();
	}

	result += " Rs.";

	return result;
}

bool Flower::operator==(Flower& obj) {

	if (this->name == obj.name) {
		if (this->color == obj.color) {
			if (this->perfumed == obj.perfumed) {

				return true;
			}
		}
	}

	return false;
}

/***********************************************************/

Bouquet::Bouquet() {

	amount = 0;
}
Bouquet::Bouquet(int a) {

	amount = a;
	group = new Flower[amount];
	group->setPerf(true);
}

int Bouquet::getAmount() {

	return amount;
}
void Bouquet::setAmount(int a) {

	amount = a;
}
void Bouquet::increase1Amount() {

	amount += 1;
}

float Bouquet::price() {

	float result = 0;
	for (int i = 0; i < amount; i++) {

		result += group[i].getPrice();
	}

	return result;
}

Bouquet::operator string() const {

	string sentence = "";
	float sum = 0;

	for (int i = 0; i < amount; i++) {

		sentence += group[i].getName();
		sentence += " ";
		sentence += group[i].getColor();
		sentence += " ";
		sentence += to_string(group[i].getPerf());
		sentence += ", Price: ";
		sentence += to_string(group[i].getPrice());
		sentence.pop_back();
		sentence.pop_back();
		sentence.pop_back();
		sentence.pop_back();
		sentence.pop_back();
		sentence += " Rs.\nTotal Price: ";
		sum += group[i].getPrice();
		sentence += to_string(sum);
		sentence.pop_back();
		sentence.pop_back();
		sentence.pop_back();
		sentence.pop_back();
		sentence.pop_back();
		sentence += " Rs.";
	}

	if (amount == 0) {

		string out = "Still no flower in the bouquet";
		return out;
	}

	return sentence;
}

Bouquet Bouquet::operator+=(Flower& obj) {

	group[amount].setName(obj.getName());
	group[amount].setColor(obj.getColor());
	group[amount].setPerf(obj.getPerf());
	group[amount].setPrice(obj.getPrice());
	group[amount].setSale(obj.getSale());
	amount++;

	return *this;
}

Bouquet Bouquet::operator-=(Flower& obj) {

	for (int i = 0; i < amount; i++) {

		if (group[i].getName() == obj.getName()) {

			if (group[i].getColor() == obj.getColor()) {

				if (group[i].getPerf() == obj.getPerf()) {

					group[i].setPerf(0);
					group[i].setColor("");
					group[i].setName("");
					group[i].setPrice(0);
					group[i].setSale(0);
				}
			}
		}
	}

	amount--;

	return *this;
}

Bouquet Bouquet::operator+(Flower& obj) {

	Bouquet temp(amount);

	temp = *this;

	temp.group[amount].setName(obj.getName());
	temp.group[amount].setColor(obj.getColor());
	temp.group[amount].setPerf(obj.getPerf());
	temp.group[amount].setPrice(obj.getPrice());
	temp.group[amount].setSale(obj.getSale());
	amount++;

	return temp;
}

Bouquet Bouquet::operator-(Flower& obj) {

	Bouquet temp = *this;

	for (int i = 0; i < amount; i++) {

		if (temp.group[i].getName() == obj.getName()) {

			if (temp.group[i].getColor() == obj.getColor()) {

				if (temp.group[i].getPerf() == obj.getPerf()) {

					temp.group[i].setPerf(0);
					temp.group[i].setColor("");
					temp.group[i].setName("");
					temp.group[i].setPrice(0);
					temp.group[i].setSale(0);
				}
			}
		}
	}

	temp.amount--;

	return temp;
}