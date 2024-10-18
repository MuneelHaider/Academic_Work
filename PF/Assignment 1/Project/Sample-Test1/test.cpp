#include "pch.h"
#include"Source.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(Question1, First) {
	char t1[] = "bottle";
	char ans[] = ". ..  ... ....  .... ....  .... ....  ... .  . .....";
	ASSERT_EQ(0, strcmp(ans, convertToTapCode(t1)));
}

TEST(Question1, Second) {
	char t1[] = "coding";
	char ans[] = ". ...  ... ....  . ....  .. ....  ... ...  .. ..";
	ASSERT_EQ(0, strcmp(ans, convertToTapCode(t1)));
}