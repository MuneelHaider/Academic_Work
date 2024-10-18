#pragma once
#include "gtest/gtest.h"
#include<iostream>
char* convertToString(char* ptr);
char* convertToTapCode(char* ptr);
void countLetters(char* ptr, int*& array, int& size);
void removePunctuation(char* ptr);
bool isprimeNumber(int number, int i);
char findUppercase(char* ptr);
int sum(int** array, int row, int column, int& evenSum, int& oddSum);
void PrintPattern(int start, int end);
