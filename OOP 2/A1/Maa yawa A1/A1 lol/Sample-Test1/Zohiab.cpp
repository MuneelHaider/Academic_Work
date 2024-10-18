#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int i = 0, a = 0, b = 0, u = 3, p = 4;
	double result = 0;

	double r1 = sqrt((u) * (i ^ (a / b)) * ((i ^ 2) - 1));
	double r2 = (sqrt((p) * (i)-2) + sqrt((p) * (i)-1));

	result = r1 / r2;

	cout << result;
}