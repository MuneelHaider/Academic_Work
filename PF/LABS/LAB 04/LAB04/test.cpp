#include "LAB 04.h"
#include "pch.h"

const char* str1 = "wavelength";
const char* str2 = "characteristics";
const char* str3 = "instagramer";
const char* str4 = "program";
const char* str5 = "integer";

//task 4 test cases
test(task4, testcase1) {
	expect_eq(2, getcharcount(str1, 'e'));
	expect_eq(3, getcharcount(str2, 'c'));
	expect_eq(2, getcharcount(str3, 'r'));
}
test(task4, testcase2) {
	expect_eq(1, getcharcount(str4, 'g'));
	expect_eq(2, getcharcount(str5, 'e'));
}


//task 5 test cases
test(task5, testcase1) {
	expect_eq(9, getunicharcount(str1, str1));
	expect_eq(8, getunicharcount(str2, str2));
	expect_eq(9, getunicharcount(str3, str3));
}
test(task5, testcase2) {
	expect_eq(6, getunicharcount(str4, str4));
	expect_eq(6, getunicharcount(str5, str5));
}