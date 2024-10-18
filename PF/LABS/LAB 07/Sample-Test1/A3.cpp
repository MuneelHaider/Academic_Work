#include <iostream>
using namespace std;

class Product {

	string name;
	int price;
	int quantity;
	static int totalProduct;

public:

	Product() {
		counter();
	}

	Product(string nameVal, int priceVal, int quantityVal) {

		name = nameVal;
		price = priceVal;
		quantity = quantityVal;
		counter();
	}

	void getData() {

		cout << name << endl;
		cout << price << endl;
		cout << quantity << endl;
	}

	static void counter() {

		totalProduct += 1;
	}

	static int countProduct() {

		return totalProduct;
	}
};

int Product::totalProduct = 0;

//int main() {
//
//	Product phone("Iphone", 1000, 20), Glasses("Gucci", 500, 12), Laptop, Shirt("D&G", 250, 40), Table;
//	cout << Product::countProduct();
//
//	return 0;
//}