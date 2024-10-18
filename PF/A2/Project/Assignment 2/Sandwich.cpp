#include <iostream>
#include "pch.h"
#include "Sandwich.h"
using namespace std;



void Sandwich::setFilling(char* fillingVal) {

	filling = fillingVal;
}

void Sandwich::setPrice(double priceVal) {

	price = priceVal;
}

void Sandwich::setName(char* nameVal) {

	name = nameVal;
}

void Sandwich::setSize(char* sizeVal) {

	if (strcmp(sizeVal, "small") == 0 || strcmp(sizeVal, "medium") == 0 || strcmp(sizeVal, "large") == 0) {

		size = sizeVal;
	}
}

char* Sandwich::getFilling() {

	return filling;
}

double Sandwich::getPrice() {

	return price;
}

char* Sandwich::getName() {
		
	return name;
}

char* Sandwich::getSize() {

	return size;
}

void Sandwich::makeSandwich() {

	if (*filling != NULL) {

		is_ready = true;
	}
	else {

		is_ready = false;
	}
}

bool Sandwich::check_status() {

	if (is_ready == true) {

		return true;
	}
	else {

		return false;
	}
}