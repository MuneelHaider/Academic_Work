#pragma once

/*      Muneel Haider
		21i-0640
		Task 1
		Data Structures     */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Main Writing function
void WritingIntoFile(float& IDC1, float& MDC1, float MPC1, float IDC2, float MDC2, float MPC2, float IDC3, float MDC3, float MPC3, int* TheCluster, int* clusterArray, float* IDArray, float* MD, float* MP, int limit) {

	ofstream MyFile("driver-data1.csv", ios::app);

	if (!MyFile.is_open()) {

		cout << "ERROR Opening File." << endl << endl;
	}

	// Forming headers
	MyFile << "id" << "," << "mean_dist_day" << "," << "mean_over_speed_perc" << "," << "Cluster" << endl;

	// Will write the previous data along with their respective cluster value
	for (int i = 0; i < limit; i++) {

		MyFile << to_string(round(IDArray[i])) << "," << to_string(round(MD[i])) << "," << to_string(round(MP[i])) << "," << TheCluster[i] << endl;
	}

	// New Data is written along with cluster value
	MyFile << to_string(round(IDC1)) << "," << to_string(round(MDC2)) << "," << to_string(round(MPC2)) << "," << to_string(TheCluster[2000]) << endl;

	MyFile.close();

	// To close the program since my implementation is complete
	exit(0);
}


float MeanDistanceCalc(float x1, float y1, float z1, float x2, float y2, float z2) {

	float answer = 0;

	answer = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));

	return answer;
}

// The main function where clustering is done
void kMeansAlgo(float* IDArray, float* MeanDArray, float* MeanPArray, int limit) {

	int counter = 0;

	// Making centroids around which the algorithm will start

	// First centroid
	float IDC1 = IDArray[1000];
	float MDC1 = MeanDArray[1000];
	float MPC1 = MeanPArray[1000];

	// Second centroid
	float IDC2 = IDArray[2000];
	float MDC2 = MeanDArray[2000];
	float MPC2 = MeanPArray[2000];

	// Third centroid
	float IDC3 = IDArray[3000];
	float MDC3 = MeanDArray[3000];
	float MPC3 = MeanPArray[3000];

	// For kAlgoritm, i needed some extra values
	// The following are extra values which will be used
	float k1 = 1;
	float k2 = 2;
	float k3 = 3;

	float c11 = 0;
	float c12 = 0;
	float c13 = 0;

	float c21 = 0;
	float c22 = 0;
	float c23 = 0;

	float c31 = 0;
	float c32 = 0;
	float c33 = 0;

	int count1 = 0;
	int count2 = 0;
	int count3 = 0;

	int clusterArray[4001];
	int OldCluster[4001];
	int TheCluster[4001];
	bool flag = false;
	bool hogya = false;
	int confirm = 0;

	while (flag == false) {

		// Calculating K's which further decide which cluster it belongs to
		while (counter != limit) {

			// Calculates the mean distance according to parameters
			k1 = MeanDistanceCalc(IDArray[counter], MeanDArray[counter], MeanPArray[counter], IDC1, MDC1, MPC1);
			k2 = MeanDistanceCalc(IDArray[counter], MeanDArray[counter], MeanPArray[counter], IDC2, MDC2, MPC2);
			k3 = MeanDistanceCalc(IDArray[counter], MeanDArray[counter], MeanPArray[counter], IDC3, MDC3, MPC3);

			// Applies and saves the clustering value into respective index
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

		// Saving Final Formed Cluster
		if (hogya == false) {
			for (int i = 0; i < limit; i++) {

				TheCluster[i] = clusterArray[i];
			}
		}
		hogya = true;

		// Confirming if old cluster = new cluster
		for (int i = 0; i < limit; i++) {

			if (OldCluster[i] == clusterArray[i]) {

				confirm++;
			}

			if (confirm == 3999) {

				// This flag will break the inner while loop
				flag = true;
			}

			// Saving the clusterArray so that it may be used to confirm our cluster formation
			OldCluster[i] = clusterArray[i];
		}

		// Adding the values after clustering
		for (int i = 0; i < limit; i++) {

			// Now new centroids will form according to clusters
			if (clusterArray[i] == 1) {

				c11 += IDArray[i];
				c12 += MeanDArray[i];
				c13 += MeanPArray[i];
			}

			else if (clusterArray[i] == 2) {

				c21 += IDArray[i];
				c22 += MeanDArray[i];
				c23 += MeanPArray[i];
			}

			else if (clusterArray[i] == 3) {

				c31 += IDArray[i];
				c32 += MeanDArray[i];
				c33 += MeanPArray[i];
			}
		}

		// Forming new centroids
		IDC1 = c11 / count1;
		MDC1 = c12 / count1;
		MPC1 = c13 / count1;

		IDC2 = c21 / count2;
		MDC2 = c22 / count2;
		MPC2 = c23 / count3;

		IDC3 = c31 / count3;
		MDC3 = c32 / count3;
		MPC3 = c33 / count3;
	}

	// Final and last function where all data will be written into a new file by the name "driver-data1.csv"
	WritingIntoFile(IDC1, MDC1, MPC1, IDC2, MDC2, MPC2, IDC3, MDC3, MPC3, TheCluster, clusterArray, IDArray, MeanDArray, MeanPArray, limit);
}

// I made a second function similar to main to reduce and divide my code
void MyFunction(string* ID, string* MeanD, string* MeanP, int limit) {

	float IDArray[4004];
	float MeanDArray[4004];
	float MeanPArray[4004];
	int counter = 0;

	// Converting read strings into floats for calculations
	for (int i = 1; i < limit; i++) {

		IDArray[counter] = stof(ID[i]);
		MeanDArray[counter] = stof(MeanD[i]);
		MeanPArray[counter] = stof(MeanP[i]);

		counter++;
	}

	// Main Function where SuperClustering will be done
	kMeansAlgo(IDArray, MeanDArray, MeanPArray, counter);
}