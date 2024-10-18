/*      Muneel Haider       
        21I-0640        
        LAB 4 Data Structuers   */    

#include <iostream>
#include "Merge_Sort.h"
#include "Bubble_Sort.h"
using namespace std;

int main() {

    // Run this Function for Merge Sort
    Merge_MAIN();

    cout << endl << endl << endl;

    // Run this Function for Bubble Sort
    Bubble_MAIN();

    cout << endl << endl << endl << 
        
        "Both Merge sort and Bubble sort have their pros and cons," << endl <<
        "but bubble sort quickly becomes less efficient when it" << endl <<
        "comes to sorting larger data sets.Where as merge sort" << endl << 
        "becomes more efficient as the data set size grows." << endl << 
        "At best, bubble sort has O(n) with smaller data sets," << endl <<
        "and worst case scenario is O(n^2) which is pretty bad" << endl <<
        "On the other hand, merge sort performs with a complexity of O(n log(n))" << endl
    << endl;

    return 0;
}
