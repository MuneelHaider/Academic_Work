#include "pch.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"

TEST(Lab04, Problem1) {

	//suppose on index arr[0][1][1], 7 is stored.
	int rows = 2;
	int columns = 2;
	int*** array = createFillAndReturn3DArray(rows, columns);
	EXPECT_EQ((*(*(*array + 0) + 1) + 1), 2);
}

TEST(Lab04, Problem2) {

	int rows = 2;
	int columns = 2;
	//suppose the sum is 28
	EXPECT_EQ(sumOf3DArray(rows, columns), 28);
}

TEST(Lab04, Problem3) {
 
	int rows = 2;
	int columns = 2;
	int*** array = define3DArray(rows, columns);
	//store values in the 3D array

	EXPECT_EQ(findAverageOf3DArray(array, rows, columns), 3.5);
}

//TEST(Lab04, Problem4) {
//	string myName = "Irfan Irfi";
//
//	char*** charName = storeMyNameIn3D(myName, 10);
//
//	EXPECT_EQ('I', charName[0][0][0]);
//	EXPECT_EQ('r', charName[0][0][1]);
//}