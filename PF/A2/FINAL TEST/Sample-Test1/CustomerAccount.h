#pragma once

struct Address {

	char* address;
	char* city;
	char* state;
	int zip_code;
};

struct CustomerAccount {

	char* name;
	Address address;
	long long phoneNum;
	float balance;
	char* accountNum;
};

void OpenCustomerAccount(CustomerAccount *[], int&, char*, char*, char*, char*, int, long long, float);
int SearchCustomer(CustomerAccount* [], int,char*);
bool UpdateCustomerAccount(CustomerAccount* [], int, char*, Address);
bool UpdateCustomerAccount(CustomerAccount* [], int, char*, long long);
bool UpdateCustomerAccount(CustomerAccount* [], int, char*, float);
void DisplayAllCustomers(CustomerAccount* [], int);