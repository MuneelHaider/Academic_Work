#pragma once
#include <iostream>
using namespace std;

template <typename M>
void Swapper(M& num1, M& num2) {

	M temp;
	temp = num2;
	num2 = num1;
	num1 = temp;
}