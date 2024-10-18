#include "pch.cpp"
#include "pch.h"
#include <gtest/gtest.h>
#include <cstring>
TEST(Question1, First) {
	ASSERT_EQ(0, 0);
}

// //-------------------Question No 1-----------------
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

TEST(Question1, Third) {
	char ans[] = "decode";
	char t1[] = ". ....  . .....  . ...  ... ....  . ....  . .....";
	ASSERT_EQ(0, strcmp(ans, convertToString(t1)));
}

TEST(Question1, Fourth) {
	char ans[] = "cipher";
	char t1[] = ". ...  .. ....  ... .....  .. ...  . .....  .... ..";
	ASSERT_EQ(0, strcmp(ans, convertToString(t1)));
}



//-------------------Question No 3-----------------
TEST(Question3a, First) {
	char t1[] = "punctuation? needs&  :to be (removed).";
	removePunctuation(t1);
	ASSERT_EQ(0, strcmp(t1, "punctuation needs to be removed"));
}

TEST(Question3a, Second) {
	char t1[] = "There: (are) multiple#  punctuation(s) marks?";
	removePunctuation(t1);
	ASSERT_EQ(0, strcmp(t1, "There are multiple punctuations marks"));
}

TEST(Question3b, First) {
	char t1[] = "Find Frequency";
	int* arr;
	int size = 0;
	countLetters(t1, arr, size);
	ASSERT_EQ(1, arr[4]);
	ASSERT_EQ(2, arr[2]);
	ASSERT_EQ(2, arr[0]);
	ASSERT_EQ(1, arr[5]);
	ASSERT_EQ(11, size);
}

TEST(Question3b, Second) {
	char t1[] = "Testing function";
	int* arr;
	int size = 0;
	countLetters(t1, arr, size);
	ASSERT_EQ(1, arr[0]);
	ASSERT_EQ(1, arr[2]);
	ASSERT_EQ(2, arr[4]);
	ASSERT_EQ(2, arr[3]);
	ASSERT_EQ(12, size);
}
//-------------------Question No 4-----------------
TEST(Question4a, First) {
	ASSERT_EQ(true, isprimeNumber(31));
}

TEST(Question4a, Second) {
	ASSERT_EQ(false, isprimeNumber(27));
}

TEST(Question4b, First) {
	char t1[] = "finding big leTter";
	ASSERT_EQ('T', findUppercase(t1));
}

TEST(Question4b, Second) {
	char t1[] = "the upper case letter iS not O";
	ASSERT_EQ('S', findUppercase(t1));
}

TEST(Question4c, First) {
	int** arr = new int* [4];
	for (int i = 0; i < 4; i++) {
		arr[i] = new int[4];
	}
	arr[0][0] = 3;
	arr[0][1] = 16;
	arr[0][2] = 9;
	arr[0][3] = 7;

	arr[1][0] = 1;
	arr[1][1] = 6;
	arr[1][2] = 21;
	arr[1][3] = 13;

	arr[2][0] = 23;
	arr[2][1] = 21;
	arr[2][2] = 10;
	arr[2][3] = 12;

	arr[3][0] = 5;
	arr[3][1] = 0;
	arr[3][2] = 8;
	arr[3][3] = 11;

	int evenSum = 0;
	int oddSum = 0;

	sum(arr, 4, 4, evenSum, oddSum);

	ASSERT_EQ(52, evenSum);
	ASSERT_EQ(114, oddSum);
}

TEST(Question4c, Second) {
	int** arr = new int* [3];
	for (int i = 0; i < 3; i++) {
		arr[i] = new int[2];
	}
	arr[0][0] = 20;
	arr[0][1] = 5;

	arr[1][0] = 10;
	arr[1][1] = 2;

	arr[2][0] = 7;
	arr[2][1] = 9;

	int evenSum = 0;
	int oddSum = 0;

	sum(arr, 3, 2, evenSum, oddSum);

	ASSERT_EQ(32, evenSum);
	ASSERT_EQ(21, oddSum);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
