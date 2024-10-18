#include "pch.h"
#include "../ConsoleApplication1/Q1.h"
#include "../ConsoleApplication1/Q2.h"


Employee empObj1("Sami", "Islamabad", 26, 25, 456123);
Employee empObj2("Ghani", "Peshawar", 26, 25, 412456);

TEST(Task1TestSuites, Test1) {
	int scores[5] = { 2, 4, 12, 45, 32 };
	TestScores testScoreObj(scores);
	EXPECT_EQ(19, testScoreObj.getScoreAverage());
	EXPECT_TRUE(true);
}

TEST(Task2TestSuites, Test2) {
	int scores[5] = { 2, 4, 12, 45, -1 };
	TestScores testScoreObj(scores);
	EXPECT_EQ(0, testScoreObj.getScoreAverage());
	EXPECT_TRUE(true);
}

TEST(Task2TestSuites, Test3) {
	int scores[5] = { 2, 4, 12, 45, 101 };
	TestScores testScoreObj(scores);
	EXPECT_EQ(0, testScoreObj.getScoreAverage());
	EXPECT_TRUE(true);
}

TEST(Task5TestSuites, Test1) {

	EXPECT_EQ("Sami", empObj1.getName());
	EXPECT_TRUE(true);
}

TEST(Task5TestSuites, Test2) {
	EXPECT_EQ(2, Employee::getTotalEmployee());
	EXPECT_TRUE(true);
}