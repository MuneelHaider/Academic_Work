#pragma once

/*      Muneel Haider
        21I-0640
        LAB 4 Data Structuers   */

#include <iostream>
using namespace std;

void bubbleSort(int* arr, int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {
         
            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Bubble_MAIN() {

    int myarray[] = { 10, 3, 1, 2, 4, 9 };

    int num = 6;

    bubbleSort(myarray, num);

    cout << "Sorted Array of Bubble Sort" << endl;
    for (int i = 0; i < num; i++) {

        cout << myarray[i] << "\t";
    }
}