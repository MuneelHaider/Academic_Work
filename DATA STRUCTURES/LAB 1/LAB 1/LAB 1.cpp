#include <iostream>
#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"
#include "Task_4.h"
using namespace std;

int main() {

    /*int size = 0;

    cout << "The size of both array should be same!" << endl;
    cout << "Please enter size of array:" << endl;
    cin >> size;

    int* a1 = new int[size];
    int* a2 = new int[size];
    
    cout << "Please enter elements of first array:" << endl;
    for (int i = 0; i < size; i++) {

        cout << i << "  ";
        cin >> a1[i];
    }

    cout << "Please enter elemetns of second array:" << endl;
    for (int i = 0; i < size; i++) {

        cout << i << "  ";
        cin >> a2[i];
    }


    ArrayFinder(a1, a2, size);

    cout << endl << endl;
    cout << "Array 1 after clearing" << endl;

    for (int i = 0; i < 10; i++) {

        cout << a1[i] << endl;
    }

    cout << endl << endl;
    cout << "Array 2 after clearing" << endl;

    for (int i = 0; i < 10; i++) {

        cout << a2[i] << endl;
    }*/

    Container<int> A(10);
    A.insert(5);
    A.insert(11);
    A.print();
    A.remove();
    A.print();

    return 0;
}