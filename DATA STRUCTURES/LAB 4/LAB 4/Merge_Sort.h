#pragma once

/*      Muneel Haider
        21I-0640
        LAB 4 Data Structuers   */

#include <iostream>
using namespace std;

// Merge sort 
void Merge_Sort(int* Array, int least, int highest, int middle)
{
    int Index_i = least;
    int Index_j = middle + 1;
    int Index_k = least;
    int Temp[50];

    while (Index_i <= middle && Index_j <= highest) {

        if (Array[Index_i] < Array[Index_j]) {

            Temp[Index_k] = Array[Index_i];
            Index_k++;
            Index_i++;
        }
        else {

            Temp[Index_k] = Array[Index_j];
            Index_k++;
            Index_j++;
        }
    }

    while (Index_i <= middle) {

        Temp[Index_k] = Array[Index_i];
        Index_k++;
        Index_i++;
    }

    while (Index_j <= highest) {

        Temp[Index_k] = Array[Index_j];
        Index_k++;
        Index_j++;
    }

    for (int i = least; i < Index_k; i++) {

        Array[i] = Temp[i];
    }
}

void Merge_Sort_Algo(int* Array, int least, int highest) {

    int middle = 0;

    if (least < highest) {

        middle = (least + highest) / 2;

        Merge_Sort_Algo(Array, least, middle);

        Merge_Sort_Algo(Array, middle + 1, highest);

        //merge or conquer sorted arrays
        Merge_Sort(Array, least, highest, middle);
    }
}

void Merge_MAIN() {

    int myarray[] = { 10, 3, 1, 2, 4, 9 };

    int num = 6;

    Merge_Sort_Algo(myarray, 0, num - 1);

    cout << "Sorted array of Merge Sort\n";

    for (int i = 0; i < num; i++)
    {
        cout << myarray[i] << "\t";
    }
}