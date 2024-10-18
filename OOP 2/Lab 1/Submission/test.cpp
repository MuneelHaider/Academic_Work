#include "pch.h"
#include "Header.h"

TEST(TestCaseName1, TestName1) {

  EXPECT_EQ(addition(1,1), 2);
}

TEST(TestCaseName2, TestName2) {

	EXPECT_EQ(subtraction(10, 5), 5);
}

TEST(TestCaseName3, TestName3) {

	EXPECT_EQ(multiplication(3, 3), 9);
}

TEST(TestCaseName4, TestName4) {

	EXPECT_EQ(division(8, 2), 4);
}