#pragma once

/*      Muneel Haider
		21i-0640
		Task 2
		Data Structures     */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void WritingIntoFileTask2(float A2, float AI2, float SS2, int* clusterArray, int* OldCluster, int limit, int* Age, int* Annual, int* Spending, string* CustomerID, string* gender) {

	ofstream t1("Segmented_Customer_2.csv", ios::app);
	int counter = 0;

	if (!t1.is_open()) {

		cout << "ERROR Opening File." << endl << endl;
	}

	t1 << "CustomerID" << "," << "Gender" << "," << "Age" << "," << "Annual Icnome (k$)" << "," << "Spending Score (1 - 100)" << "," << "Cluster Value" << endl;

	for (int i = 1; i < limit; i++) {

		t1 << CustomerID[i] << "," << gender[i] << "," << to_string(Age[counter]) << "," << to_string(Annual[counter]) << "," << to_string(Spending[counter]) << "," << clusterArray[i] << endl;

		counter++;
	}

	t1.close();

	exit(0);

}

float MeanDistanceCalcfor3(float x1, float y1, float z1, float x2, float y2, float z2) {

	float answer = 0;

	answer = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1)*(z2 - z1));

	return answer;
}

void kMeansAlgoTask2(int* Age, int* AnnualIncome, int* SpendingScore, int limit, string* ageVar, string* AnnualVar, string* Spending, string* CustomerID, string* gender) {

	int counter = 0;

	float A1 = Age[25];
	float AI1 = AnnualIncome[25];
	float SS1 = SpendingScore[25];

	float A2 = Age[50];
	float AI2 = AnnualIncome[50];
	float SS2 = SpendingScore[50];

	float A3 = Age[75];
	float AI3 = AnnualIncome[75];
	float SS3 = SpendingScore[75];

	float k1 = 1;
	float k2 = 2;
	float k3 = 0;

	float c11 = 0;
	float c12 = 0;
	float c13 = 0;

	float c21 = 0;
	float c22 = 0;
	float c23 = 0;

	float c31 = 0;
	float c32 = 0;
	float c33 = 0;

	float count1 = 0;
	float count2 = 0;
	float count3 = 0;

	int clusterArray[205];
	int OldCluster[205];
	bool flag = false;
	bool hogya = false;
	int confirm = 0;

	while (flag == false) {

		while (counter != limit) {

			k1 = MeanDistanceCalcfor3(Age[counter], AnnualIncome[counter], SpendingScore[counter], A1, AI1, SS1);
			k2 = MeanDistanceCalcfor3(Age[counter], AnnualIncome[counter], SpendingScore[counter], A2, AI2, SS2);
			k3 = MeanDistanceCalcfor3(Age[counter], AnnualIncome[counter], SpendingScore[counter], A3, AI3, SS3);
		
			if (k1 < k2 && k1 < k3) {

				clusterArray[counter] = 1;
				count1++;
			}
			else if (k2 < k1 && k2 < k3) {

				clusterArray[counter] = 2;
				count2++;
			}
			else {

				clusterArray[counter] = 3;
				count3++;
			}

			counter++;
		}

		counter = 0;

		if (confirm == limit - 1) {

			// This flag will break the outer while loop
			flag = true;
		}

		for (int i = 0; i < limit; i++) {

			// Saving the clusterArray so that it may be used to confirm our cluster formation
			OldCluster[i] = clusterArray[i];
		}

		for (int i = 0; i < limit; i++) {

			// Now new centroids will form according to clusters
			if (clusterArray[i] == 1) {

				c11 += Age[i];
				c12 += AnnualIncome[i];
				c13 += SpendingScore[i];
			}

			else if (clusterArray[i] == 2) {

				c21 += Age[i];
				c22 += AnnualIncome[i];
				c23 += SpendingScore[i];
			}

			else if (clusterArray[i] == 3) {

				c31 += Age[i];
				c32 += AnnualIncome[i];
				c33 += SpendingScore[i];
			}
		}

		confirm++;

		A1 = c11 / count1;
		AI1 = c12 / count1;
		SS1 = c13 / count1;

		A2 = c21 / count2;
		AI2 = c22 / count2;
		SS2 = c23 / count2;

		A3 = c31 / count3;
		AI3 = c32 / count3;
		SS3 = c33 / count3;
	}

	WritingIntoFileTask2(A2, AI2, SS2, clusterArray, OldCluster, limit, Age, AnnualIncome, SpendingScore, CustomerID, gender);
}

void MyFunctionTask2(string* ageVar, string* annualincomeVar, string* spendingscoreVar, int limit, string* ID, string* gender) {

	int counter = 0;

	int Age[205];
	int AnnualIncome[205];
	int SpendingScore[205];
	
	for (int i = 1; i < limit; i++) {

		Age[counter] = stoi(ageVar[i]);
		AnnualIncome[counter] = stoi(annualincomeVar[i]);
		SpendingScore[counter] = stoi(spendingscoreVar[i]);

		counter++;
	}

	kMeansAlgoTask2(Age, AnnualIncome, SpendingScore, counter, ageVar, annualincomeVar, spendingscoreVar, ID, gender);
}