#pragma once
#include <iostream>
using namespace std;

template <typename M>
M GreaterThan(M num1, M num2) {

	return (num1 > num2) ? num1 : num2;
}