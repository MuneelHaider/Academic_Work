#include <iostream>
using namespace std;

char* addition(char* array1, char* array2) {

	char array3[10];
	char* ptr = &array3[0];

	for (int i = 0; i < 10; i++) {

		ptr[i] = int(array1[i] + array2[i]);

		cout << int(ptr[i] - 96) << " ";
	}

	return ptr;
}

char* subtraction(char* array1, char* array2) {

		char array3[10];
		char* ptr = &array3[0];

		for (int i = 0; i < 10; i++) {

			ptr[i] = int(array1[i] - array2[i]);

			cout << int(ptr[i]) << " ";
		}

		return ptr;
}

//char* multiplication(char* array1, char* array2) {
//
//	char array3[10];
//	char* ptr = &array3[0];
//
//	for (int i = 0; i < 10; i++) {
//
//		cout << array1[i] << array2[i];
//		ptr[i] = int( array1[i] * array2[i] );
//
//		cout << int(ptr[i]) << " ";
//	}
//
//	return ptr;
//}

int main() {

	char array1[10] = { '1','3','2','1','4','2','1','3','1','2' };
	char* ptr1 = &array1[0];
	
	char array2[10] = { '3','2','1','1','2','3','3','2','1','2' };
	char* ptr2 = &array2[0];
	
	char array3[10];
	char* ptr3 = &array3[0];

	cout << "Addition:" << endl;
	ptr3 = addition(ptr1, ptr2);
	cout << endl;

	cout << endl << "Subtraction" << endl;
	ptr3 = subtraction(ptr1, ptr2);
	cout << endl;

	/*cout << endl << "Multiplication" << endl;
	ptr3 = multiplication(ptr1, ptr2);
	cout << endl;*/

	return 0;
}