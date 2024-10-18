#include "pch.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"

TEST(Task1, TestCase1) {
	Distance distanceObj1(12, 13), distanceObj2(12, 15), distanceObj3;
	distanceObj3 = distanceObj1 + distanceObj2;
	EXPECT_EQ(26, distanceObj3.getFeets());
	EXPECT_EQ(4, distanceObj3.getInches());
	EXPECT_TRUE(true);
}

TEST(Task1, TestCase2) {
	Distance distanceObj1(12, 13), distanceObj2(12, 15), distanceObj3;
	distanceObj3 = distanceObj1 - distanceObj2;
	EXPECT_EQ(0, distanceObj3.getFeets());
	EXPECT_EQ(-2, distanceObj3.getInches());
	EXPECT_TRUE(true);
}

TEST(Task1, TestCase3) {
	Distance distanceObj1(12, 13), distanceObj2(12, 15);
	EXPECT_EQ(false, distanceObj1.operator==(distanceObj2));
	EXPECT_TRUE(true);
}

TEST(Task1, TestCase4) {
	Distance distanceObj1(12, 13), distanceObj2(12, 13);
	EXPECT_EQ(true, distanceObj1.operator==(distanceObj2));
	EXPECT_TRUE(true);
}

TEST(Task2, testCase1) {
	Product obj1(5, 1), obj2(6, 2);
	obj2 = obj1;
	EXPECT_EQ(11, obj2.getQuantity());
	EXPECT_TRUE(true);
}

TEST(Task2, testCase2) {
	Product obj1(5, 1);
	obj1 -= 5;
	EXPECT_EQ(0, obj1.getQuantity());
	EXPECT_TRUE(true);
}

int main() {

	Vector V1, V2;

	int temp[3] = { 1, 2, 3 };
	int temp1[3] = { 4,5,6 };
	int* ptr = temp;
	int* ptr1 = temp1;

	cout << "1st Array:" << endl;
	V1.equateArray(ptr);
	V1.printArray();

	cout << "Second Array:" << endl;
	V2.equateArray(ptr1);
	V2.printArray();

	cout << "Sum of Arrays:" << endl;
	V1 + V2;
	V1.printArray();

	cout << "Difference of Arrays:" << endl;
	V1 - V2;
	V1.printArray();
	cout << endl;

	return 0;
}