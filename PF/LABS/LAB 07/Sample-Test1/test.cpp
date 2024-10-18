#include "pch.h"
#include "Header.h"


TEST(Task1, TestCase1) {
	Time obj1(900, 900, 900), obj2(9000, 9000, 9000);
	obj1.calculateTime(obj2);
	obj1.calculateDays();
	EXPECT_EQ(0, obj1.getSeconds());
	EXPECT_EQ(45, obj1.getMinutes());
	EXPECT_EQ(11, obj1.getHours());
}

TEST(Task2, TestCase1) {
	Matrix obj1(3), obj2(2);
	Matrix obj = obj1.dot(obj2);
	EXPECT_EQ(6, obj.retrieveValue(0, 0));
}

TEST(Task2, TestCase2) {
	Matrix obj1(5), obj2(2);
	Matrix obj = obj1.dot(obj2);
	EXPECT_EQ(10, obj.retrieveValue(2, 2));
}

TEST(Task3, TestCase1) {
	Product phone("Iphone", 1000, 20), Glasses("Gucci", 500, 12), Laptop, Shirt("D&G", 250, 40), Table;
	EXPECT_EQ(5, Product::countProduct());
}

TEST(Task3, TestCase2) {
	Product productArray[12];
	EXPECT_EQ(17, Product::countProduct());
}