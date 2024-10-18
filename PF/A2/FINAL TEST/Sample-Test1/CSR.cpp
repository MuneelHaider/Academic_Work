#include <iostream>
#include "pch.h"
#include "CSR.h"

CSR::CSR(){



}

int CSR::totalComplaintsResolved = 0;

CSR::CSR(int x){


}

int CSR::getCSRID() { 

	return csrID;
}

char* CSR::getName() {

	return csrName;
}

int CSR::getHours() {

	return hours;
}

int CSR::getComplaintsResolved() {

	return complaintsResolved;
}

float CSR::getPayrate() {

	return payrate;
}

float CSR::getWage() {

	return wage;
}

void CSR::setCSRID(int ID) {

	csrID = ID;
}

void CSR::setName(char* n) {

	csrName = n;
}

void CSR::setHours(int hoursVal) {

	hours = hoursVal;
}

void CSR::setComplaintsResolved(int cpsResolved) {

	complaintsResolved = cpsResolved;
}

void CSR::setTotalCpsResolved(int totalCpsResolved) {

	totalComplaintsResolved = totalCpsResolved;
}

void CSR::calcPayrate() {

	payrate = 25 + (25 * (complaintsResolved / totalComplaintsResolved));
}

void CSR::calcWage() {

	wage = payrate + wage;
}

int CSR::getTotalCpsResolved() {

	return totalComplaintsResolved;
}




CSR getCSR_at(CSR employees[7], int index) {

	CSR c;

	return c;
}

void calcTotalComplaints(CSR[7]){


}

void calcAllEmployeeWages(CSR[7]) {

}
void SortByHours(CSR[7]) {

}
void SortByComplaintsRes(CSR[7]) {

}
void SortByWages(CSR[7]) {

}