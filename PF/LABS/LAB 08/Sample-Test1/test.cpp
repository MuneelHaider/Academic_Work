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

TEST(Task2, testCase1) {
	Date obj1(10, 12, 1995), obj2(11, 11, 2000);
	EXPECT_EQ(true, obj2 > obj1);
	EXPECT_TRUE(true);
}

TEST(Task2, testCase2) {
	Date obj1(10, 12, 1995), obj2(11, 11, 2000);
	EXPECT_EQ(true, obj1 < obj2);
	EXPECT_TRUE(true);
}

TEST(Task2, testCase3) {
	Date obj1(10, 12, 1995), obj2(10, 12, 1995);
	EXPECT_EQ(true, obj1 == obj2);
	EXPECT_TRUE(true);
}

TEST(Task3, testCase1) {
	Money moneyObj1, moneyObj2(12, 113);
	EXPECT_EQ(false, moneyObj1 == moneyObj2);
	EXPECT_TRUE(true);
}

TEST(Task3, testCase2) {
	Money moneyObj1, moneyObj2(12, 113);
	moneyObj1 = moneyObj2 + moneyObj2;
	EXPECT_EQ(26, moneyObj1.getDollars());
	EXPECT_TRUE(true);
}

TEST(Task3, testCase3) {
	Money moneyObj1, moneyObj2(12, 113);
	moneyObj1 = moneyObj2 - moneyObj2;
	EXPECT_EQ(0, moneyObj1.getDollars());
	EXPECT_TRUE(true);
}

TEST(Task3, testCase4) {
	Money moneyObj1(12, 113);
	moneyObj1 = moneyObj1 * 2;
	EXPECT_EQ(26, moneyObj1.getDollars());
	EXPECT_TRUE(true);
}

TEST(Task3, testCase5) {
	Money moneyObj1(12, 113);
	moneyObj1 = moneyObj1 / 2;
	EXPECT_EQ(6, moneyObj1.getDollars());
	EXPECT_TRUE(true);
}