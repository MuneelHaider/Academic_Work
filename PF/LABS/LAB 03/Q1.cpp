#include <iostream>
using namespace std;

int* splitarray(int* array, int size) {

    int max1 = 0, max2 = 0, diff = 0, counter = 0;
    int* ptr = new int[size+1];

    for (int i = 0; i < size; i++) {

        if (*(array + i) > max1) {

            max1 = *(array + i);
        }
        else if(*(array+i) > max2) {

            max2 = *(array + i);
        }
    }
    diff = max1 - max2;

    for (int i = 0; i < size+1; i++) {

        if (*(array + i) != max1) {

            *(ptr + counter) = *(array + i);
        }
        else {

            *(ptr + counter++) = max2;
            *(ptr + counter) = diff;
        }

        counter++;
    }

    return ptr;
}

int main()
{
    int array[5] = { 4,8,6,3,2 };
    int result[6];
    int* ptr = &array[0];
    int* answer = &result[6];

    answer = splitarray(ptr, 5);

    cout << "Original Array" << endl;
    for (int i = 0; i < 5; i++) {

        cout << *(array + i) << " ";
    }

    cout << endl << endl << "Final Array" << endl;
    for (int i = 0; i < 6; i++) {

        cout << *(answer + i) << " ";
    }
    cout << endl << endl;

    return 0;
}