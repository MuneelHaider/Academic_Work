#pragma once

struct Address {

	char* address;
	char* city;
	char* state;
	int zip_code;
}ac;

struct CustomerAccount {

	char* name;
	Address address;
	long long phoneNum;
	float balance;
	char* accountNum;
}acc;