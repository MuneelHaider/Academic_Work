#pragma once

struct Car {

	int petrolLevel = 0;
	int km = 0;

public:

	Car();
	Car(int petrolLevelVal);
	void setPetrolLevel(int);
	int getPetrolLevel();
	bool MoveCar(int);
	void Refill();
	bool isEmpty();
};