#pragma once

struct partsType {

	int partNum;
	double price;
	int quantitiesInStock;
};

void parttype_insert(partsType data[3]) {

	data[1].price = 3500;
	data[1].partNum = 124;
	data[1].quantitiesInStock = 20;

	data[0].price = 2500;
	data[0].partNum = 123;
	data[0].quantitiesInStock = 10;
}