#include <iostream>
#include "pch.h"
#include "Car.h"
using namespace std;

Car::Car() {

}
Car::Car(int petrolLevelVal) {

	petrolLevel = petrolLevelVal;
}

int Car::getPetrolLevel() {

	return petrolLevel;
}

void Car::setPetrolLevel(int petrolLevelVal) {

	if (petrolLevelVal > 45) {

	}
	else if (petrolLevelVal < 0) {

	}
	else {

		petrolLevel = petrolLevelVal;
	}
}

bool Car::MoveCar(int distanceKM) {

	if (distanceKM > 45) {

		return false;
	}
	if (distanceKM > petrolLevel) {

		return false;
	}
	if (distanceKM <= petrolLevel) {

		petrolLevel -= distanceKM;
		return true;
	}
}

void Car::Refill() {

	petrolLevel = 45;
}

bool Car::isEmpty() {

	if (petrolLevel <= 0) {

		return true;
	}
	else {

		return false;
	}
}