#include "pch.h"
#include <gtest/gtest.h>
#include<iostream>
#include "Q1.h"
#include "Q2A.h"
#include "Q2B.h"
#include "Q3.h"
#include "Q4.h"
#include "Q5.h"
#include "Q6.h"
using namespace std;

//--------------------------------------------------Question 1 --------------------------------------------------
TEST(bookSeats, T1) {

	int numOfRows = 9;
	char** bus = bookSeats(numOfRows);

	// Select seats 1C, 5D, 6A, 8A, and 9D

	char** testBus = new char* [numOfRows];

	for (int i = 0; i < numOfRows; i++)
		*(testBus + i) = new char[5];

	strcpy(*(testBus + 0), "1ABXD");
	strcpy(*(testBus + 1), "2ABCD");
	strcpy(*(testBus + 2), "3ABCD");
	strcpy(*(testBus + 3), "4ABCD");
	strcpy(*(testBus + 4), "5ABCX");
	strcpy(*(testBus + 5), "6XBCD");
	strcpy(*(testBus + 6), "7ABCD");
	strcpy(*(testBus + 7), "8XBCD");
	strcpy(*(testBus + 8), "9ABCX");

	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < 5; j++) {
			EXPECT_EQ(testBus[i][j], bus[i][j]);
		}
	}
}

TEST(bookSeats, T2) {

	int numOfRows = 5;
	char** bus = bookSeats(numOfRows);

	// Select seats 1B, 2B, 3D, 5A, and 5B

	char** testBus = new char* [numOfRows];

	for (int i = 0; i < numOfRows; i++)
		*(testBus + i) = new char[5];

	strcpy(*(testBus + 0), "1AXCD");
	strcpy(*(testBus + 1), "2AXCD");
	strcpy(*(testBus + 2), "3ABCX");
	strcpy(*(testBus + 3), "4ABCD");
	strcpy(*(testBus + 4), "5XXCD");

	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < 5; j++) {
			EXPECT_EQ(testBus[i][j], bus[i][j]);
		}
	}
}



//-------------------------------------------------- Question 2A --------------------------------------------------

TEST(maxScore, T1) {

	int rows = 5, cols = 5;

	int** matrix = new int* [rows];

	for (int i = 0; i < rows; i++)
		matrix[i] = new int[cols];

	matrix[0][0] = 1;
	matrix[0][1] = 1;
	matrix[0][2] = -1;
	matrix[0][3] = 1;
	matrix[0][4] = 1;

	matrix[1][0] = 1;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = -1;
	matrix[1][4] = 1;

	matrix[2][0] = 1;
	matrix[2][1] = 1;
	matrix[2][2] = 1;
	matrix[2][3] = 1;
	matrix[2][4] = -1;

	matrix[3][0] = -1;
	matrix[3][1] = 1;
	matrix[3][2] = 1;
	matrix[3][3] = 1;
	matrix[3][4] = 1;

	matrix[4][0] = 1;
	matrix[4][1] = 1;
	matrix[4][2] = -1;
	matrix[4][3] = -1;
	matrix[4][4] = 1;

	/*
		{ 1,  1, -1,  1,  1}
		{ 1,  1,  0, -1,  1}
		{ 1,  1,  1,  1, -1}
		{-1,  1,  1,  1,  1}
		{ 1,  1, -1, -1,  1}
	*/

	// Do not uncomment the above matrix!

	int score = maxScore(matrix, rows, cols);
	EXPECT_EQ(12, score);

}


//-------------------------------------------------- Question 2B ---------------------------------------------------

TEST(minCost, T1) {

	int rows = 5, cols = 5;

	int** matrix = new int* [rows];

	for (int i = 0; i < rows; i++)
		matrix[i] = new int[cols];

	matrix[0][0] = 3;
	matrix[0][1] = 7;
	matrix[0][2] = 8;
	matrix[0][3] = 6;
	matrix[0][4] = 4;

	matrix[1][0] = 6;
	matrix[1][1] = 5;
	matrix[1][2] = 3;
	matrix[1][3] = 9;
	matrix[1][4] = 2;

	matrix[2][0] = 13;
	matrix[2][1] = 8;
	matrix[2][2] = 1;
	matrix[2][3] = 2;
	matrix[2][4] = 4;

	matrix[3][0] = 7;
	matrix[3][1] = 1;
	matrix[3][2] = 7;
	matrix[3][3] = 3;
	matrix[3][4] = 6;

	matrix[4][0] = 2;
	matrix[4][1] = 9;
	matrix[4][2] = 8;
	matrix[4][3] = 9;
	matrix[4][4] = 2;

	/*
		{3, 7, 8, 6, 4}
		{6, 5, 3, 9, 2}
		{9, 8, 1, 2, 4}
		{7, 1, 7, 3, 6}
		{2, 9, 8, 9, 2}
	*/

	// Do not uncomment the above matrix!

	int cost = minCost(matrix, rows, cols);
	EXPECT_EQ(31, cost);
}

TEST(minCost, T2) {

	int rows = 5, cols = 5;

	int** matrix = new int* [rows];

	for (int i = 0; i < rows; i++)
		matrix[i] = new int[cols];

	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[0][2] = 3;
	matrix[0][3] = 4;
	matrix[0][4] = 1;

	matrix[1][0] = 6;
	matrix[1][1] = 7;
	matrix[1][2] = 8;
	matrix[1][3] = 9;
	matrix[1][4] = 0;

	matrix[2][0] = 9;
	matrix[2][1] = 2;
	matrix[2][2] = 7;
	matrix[2][3] = 6;
	matrix[2][4] = 3;

	matrix[3][0] = 4;
	matrix[3][1] = 3;
	matrix[3][2] = 2;
	matrix[3][3] = 5;
	matrix[3][4] = 0;

	matrix[4][0] = 1;
	matrix[4][1] = 2;
	matrix[4][2] = 3;
	matrix[4][3] = 4;
	matrix[4][4] = 5;

	/*
		{1, 2, 3, 4, 1}
		{6, 7, 8, 9, 0}
		{9, 2, 7, 6, 3}
		{4, 3, 2, 5, 0}
		{1, 2, 3, 4, 5}
	*/

	// Do not uncomment the above matrix!


	int cost = minCost(matrix, rows, cols);
	EXPECT_EQ(19, cost);
}



//--------------------------------------------------Question 3 --------------------------------------------------


TEST(Question1, First) {
	int candidates = 3;
	char** names = allocateNames(candidates);

	setNames(candidates, names, "aizaz");
	setNames(candidates, names, "rose");
	setNames(candidates, names, "jack");


	EXPECT_EQ(strcmp(names[0], "aizaz"), 0);
	EXPECT_EQ(strcmp(names[1], "rose"), 0);
	EXPECT_EQ(strcmp(names[2], "jack"), 0);

}

TEST(Question1, Second) {
	int candidates = 3;
	int* votes = allocateVotes(candidates);
	char** names = allocateNames(candidates);
	setNames(candidates, names, "a");
	setNames(candidates, names, "b");
	setNames(candidates, names, "c");

	setVotes(candidates, names, "a", votes, 1020);
	setVotes(candidates, names, "b", votes, 2001);
	setVotes(candidates, names, "c", votes, 3002);


	EXPECT_EQ(votes[0], 1020);
	EXPECT_EQ(votes[1], 2001);
	EXPECT_EQ(votes[2], 3002);
}

TEST(Question1, Third) {
	int candidates = 3;
	int* votes = allocateVotes(candidates);
	char** names = allocateNames(candidates);
	setNames(candidates, names, "a");
	setNames(candidates, names, "b");
	setNames(candidates, names, "c");

	setVotes(candidates, names, "a", votes, 200);
	setVotes(candidates, names, "b", votes, 200);
	setVotes(candidates, names, "c", votes, 300);

	float percA = (200 / float(700)) * 100;
	float percB = (200 / float(700)) * 100;
	float percC = (300 / float(700)) * 100;

	float* percentages = allocatePercentages(candidates, votes);

	EXPECT_EQ(percentages[0], percA);
	EXPECT_EQ(percentages[1], percB);
	EXPECT_EQ(percentages[2], percC);

	int totalVotes = returnTotalVotes(candidates, votes);
	EXPECT_EQ(totalVotes, 700);

}



//--------------------------------------------------Question 4 --------------------------------------------------

TEST(Question2, T1) {

	int* result;
	int marks[] = { 10,80,65,50,65,70,50,30,65,65,70,65,65 };
	int* expectedResult = new int[81];
	for (int i = 0; i < 81; i++) {
		expectedResult[i] = 0;
	}
	expectedResult[10] = 1;
	expectedResult[80] = 1;
	expectedResult[70] = 2;
	expectedResult[65] = 6;
	expectedResult[50] = 2;
	expectedResult[30] = 1;
	calculateHistogram(marks, result, 13);
	for (int i = 0; i < 81; i++) {
		EXPECT_EQ(expectedResult[i], result[i]);
	}
}

TEST(Question2, T2) {

	int* result;
	int marks[] = { 10,10,13,13,13,40,70,70,80,90,91,91,92 };
	int* expectedResult = new int[93];
	for (int i = 0; i < 93; i++) {
		expectedResult[i] = 0;
	}
	expectedResult[10] = 2;
	expectedResult[13] = 3;
	expectedResult[40] = 1;
	expectedResult[70] = 2;
	expectedResult[80] = 1;
	expectedResult[90] = 1;
	expectedResult[91] = 2;
	expectedResult[92] = 1;
	calculateHistogram(marks, result, 13);
	for (int i = 0; i < 93; i++) {
		EXPECT_EQ(expectedResult[i], result[i]);
	}
}

//--------------------------------------------------Question 5 --------------------------------------------------
TEST(maximum, First) {
	int* Arr = new int[5];
	Arr[0] = 20;
	Arr[1] = 6;
	Arr[2] = 1;
	Arr[3] = 4;
	Arr[4] = 2;

	ASSERT_EQ(maximum(Arr, 5), 20);
}

TEST(maximum, Second) {
	int* Arr = new int[7];
	Arr[0] = 8;
	Arr[1] = 9;
	Arr[2] = 1;
	Arr[3] = 40;
	Arr[4] = 2;
	Arr[5] = 3;
	Arr[6] = 4;

	ASSERT_EQ(maximum(Arr, 7), 40);
}


TEST(Swap, First) {
	int a = 11;
	int b = 222;

	swap(&a, &b);
	ASSERT_EQ(a, 222);
	ASSERT_EQ(b, 11);

}


TEST(Swap, Second) {
	int a = -121;
	int b = 212;

	swap(&a, &b);
	ASSERT_EQ(a, 212);
	ASSERT_EQ(b, -121);

}


TEST(merge, First) {
	int* Arr = new int[5];
	Arr[0] = 8;
	Arr[1] = 9;
	Arr[2] = 1;
	Arr[3] = 0;
	Arr[4] = 2;

	int* Arr2 = new int[7];
	Arr2[0] = 8;
	Arr2[1] = 9;
	Arr2[2] = 1;
	Arr2[3] = 0;
	Arr2[4] = 2;
	Arr2[5] = 3;
	Arr2[6] = 4;

	int* a = merge(Arr, Arr2, 5, 7);

	ASSERT_EQ(a[0], 8);
	ASSERT_EQ(a[1], 9);
	ASSERT_EQ(a[2], 1);
	ASSERT_EQ(a[3], 0);
	ASSERT_EQ(a[4], 2);
	ASSERT_EQ(a[5], 8);
	ASSERT_EQ(a[6], 9);
	ASSERT_EQ(a[7], 1);
	ASSERT_EQ(a[8], 0);
	ASSERT_EQ(a[9], 2);
	ASSERT_EQ(a[10], 3);
	ASSERT_EQ(a[11], 4);
}


TEST(merge, Second) {
	int* Arr = new int[3];
	Arr[0] = 1;
	Arr[1] = 2;
	Arr[2] = 3;


	int* Arr2 = new int[5];
	Arr2[0] = 6;
	Arr2[1] = 7;
	Arr2[2] = 8;
	Arr2[3] = 9;
	Arr2[4] = 10;

	int* a = merge(Arr, Arr2, 3, 5);

	ASSERT_EQ(a[0], 1);
	ASSERT_EQ(a[1], 2);
	ASSERT_EQ(a[2], 3);
	ASSERT_EQ(a[3], 6);
	ASSERT_EQ(a[4], 7);
	ASSERT_EQ(a[5], 8);
	ASSERT_EQ(a[6], 9);
	ASSERT_EQ(a[7], 10);

}


TEST(Reverse, First) {
	char* Arr = new char[11];
	Arr[0] = 'a';
	Arr[1] = 'i';
	Arr[2] = 'z';
	Arr[3] = 'a';
	Arr[4] = 'z';
	Arr[5] = 'a';
	Arr[6] = 'h';
	Arr[7] = 'm';
	Arr[8] = 'e';
	Arr[9] = 'd';
	Arr[10] = '\0';

	char* New = reverse(Arr);


	ASSERT_EQ(New[0], 'd');
	ASSERT_EQ(New[1], 'e');
	ASSERT_EQ(New[2], 'm');
	ASSERT_EQ(New[3], 'h');
	ASSERT_EQ(New[4], 'a');
	ASSERT_EQ(New[5], 'z');
	ASSERT_EQ(New[6], 'a');
	ASSERT_EQ(New[7], 'z');
	ASSERT_EQ(New[8], 'i');
	ASSERT_EQ(New[9], 'a');

}

TEST(Reverse, Second) {
	char* Arr = new char[9];
	Arr[0] = 'F';
	Arr[1] = 'o';
	Arr[2] = 'o';
	Arr[3] = 't';
	Arr[4] = 'b';
	Arr[5] = 'a';
	Arr[6] = 'l';
	Arr[7] = 'l';
	Arr[8] = '\0';

	char* New = reverse(Arr);

	ASSERT_EQ(New[0], 'l');
	ASSERT_EQ(New[7], 'F');

}


TEST(Even, First) {
	int* Arr = new int[8];
	Arr[0] = 1;
	Arr[1] = 2;
	Arr[2] = 3;
	Arr[3] = 4;
	Arr[4] = 5;
	Arr[5] = 5;
	Arr[6] = 5;
	Arr[7] = 5;


	ASSERT_EQ(countEven(Arr, 8), 2);

}

TEST(Even, Second) {
	int* Arr = new int[4];
	Arr[0] = 2;
	Arr[1] = 2;
	Arr[2] = 2;
	Arr[3] = 4;



	ASSERT_EQ(countEven(Arr, 4), 4);

}

TEST(compare, First) {
	char* Arr = new char[5];
	Arr[0] = 'a';
	Arr[1] = 'i';
	Arr[2] = '0';
	Arr[3] = 'a';
	Arr[4] = 'z';


	ASSERT_EQ(compare(Arr, '7'), 0);

}


TEST(Compare, Second) {
	char* Arr = new char[6];
	Arr[0] = 'a';
	Arr[1] = 'i';
	Arr[2] = 'z';
	Arr[3] = 'a';
	Arr[4] = 'z';
	Arr[5] = '1';


	ASSERT_EQ(compare(Arr, '1'), 1);

}



//--------------------------------------------------Question 6 --------------------------------------------------


TEST(find, found) {

	int arr[] = { 3, 79, 42, 20, 37, 58, 61, 87 };
	int length = 8;
	int target = 61;

	EXPECT_EQ(length - 1, find(arr, length, target));


}

TEST(find, notFound) {

	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 99, 69, 21, 420, 512 };
	int length = 13;
	int target = 1024;

	EXPECT_EQ(-1, find(arr, length, target));

}


TEST(isPalindrome, yes) {

	char str[] = "123f4f321\0";
	int size = 9;

	EXPECT_TRUE(isPalindrome(str, size));

}

TEST(isPalindrome, no) {

	char str[] = "123456\0";
	int size = 6;

	EXPECT_FALSE(isPalindrome(str, size));

}


TEST(replace, four) {

	char* s1 = new char[20] {'t', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', ' ', 'c', 'a', 's', 'e', '\0'};
		char* s2 = new char[20] { 't', 'h', 'i', 's', '_', 'i', 's', '_', 'a', '_', 't', 'e', 's', 't', '_', 'c', 'a', 's', 'e', '\0'};
		replace(s1, ' ', '_');
	bool cmp = !strcmp(s1, s2);
	EXPECT_TRUE(cmp);

	}

		TEST(replace, three) {

		char* s1 = new char[16] {'T', 'o', 'm', ' ', 'a', 't', 'e', ' ', 'a', ' ', 'p', 'e', 'a', 'c', 'h', '\0'};
		char* s2 = new char[16] {'T', 'o', 'm', ' ', 'i', 't', 'e', ' ', 'i', ' ', 'p', 'e', 'i', 'c', 'h', '\0' };
		replace(s1, 'a', 'i');
		bool cmp = !strcmp(s1, s2);
		EXPECT_TRUE(cmp);

	}

	int main(int argc, char** argv) {
		
		PrintPattern(5, '*');

		PrintPattern1(1, 5, '*', '-');
	}