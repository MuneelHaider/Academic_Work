//#include <iostream>
//using namespace std;
//
//class Matrix {
//
//	int** array;
//
//public:
//
//	Matrix(int n = 0) {
//
//		array = new int* [3];
//		for (int i = 0; i < 3; i++) {
//
//			*(array + i) = new int[3];
//		}
//
//		for (int i = 0; i < 3; i++) {
//
//			for (int j = 0; j < 3; j++) {
//
//				array[i][j] = n;
//			}
//		}
//	}
//
//	Matrix dot(Matrix obj) {
//
//		for (int i = 0; i < 3; i++) {
//			
//			for (int j = 0; j < 3; j++) {
//
//				obj.array[i][j] *= array[i][j];
//			}
//		}
//
//		return obj;
//	}
//
//	int retrieveValue(int r, int c) {
//
//		return array[r][c];
//	}
//};
//
////int main() {
////
////	Matrix obj1(5), obj2(2);
////	Matrix obj = obj1.dot(obj2);
////	cout << obj.retrieveValue(2, 2);
////
////	return 0;
////}