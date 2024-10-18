#pragma once

struct Car {

	int petrolLevel = 0;
	int km = 0;

public:

	Car() {

	}
	Car(int petrolLevelVal) {

		petrolLevel = petrolLevelVal;
	}

	int getPetrolLevel();
	void setPetrolLevel(int petrolLevelVal);
	bool MoveCar(int distanceKM);
	void Refill();
	bool isEmpty();
};