#include "pch.h"
#include <cstring>
#include "Car.h"
#include "Sequence.h"
#include "Sandwich.h"
#include "CustomerAccount.h"
#include "CSR.h"
#include "Matrix.h"
#include "String.h"




//----------Question #01----------

TEST(Q1, first) {
	Car car;
	car.setPetrolLevel(29);
	car.setPetrolLevel(46);
	car.setPetrolLevel(-7);
	ASSERT_EQ(29, car.getPetrolLevel());
}

TEST(Q1, second) {
	Car car;
	ASSERT_TRUE(car.isEmpty());

	Car car1(20);
	ASSERT_FALSE(car1.isEmpty());
}

TEST(Q1, third) {
	Car car;
	car.Refill();
	ASSERT_EQ(45, car.petrolLevel);
}

TEST(Q1, fourth) {
	Car car;
	car.Refill();
	ASSERT_FALSE(car.MoveCar(54));
	ASSERT_TRUE(car.MoveCar(29));
	ASSERT_EQ(16, car.petrolLevel);
}



//----------Question #02----------

TEST(Q2, first) {
	Sequence sequence;
	ASSERT_EQ(10, sequence.getLength());

	int* pseq = sequence.getSeq();
	for (int i = 0; i < 10; i++)
		ASSERT_EQ(0, *(pseq + i));

	Sequence sequence1(5, 200, 300, 400, 500, 600);
	int* pseq1 = sequence1.getSeq();
	ASSERT_EQ(5, sequence1.getLength());
	ASSERT_EQ(200, *pseq1);
	ASSERT_EQ(400, *(pseq1 + 2));
	ASSERT_EQ(600, *(pseq1 + 4));
}

TEST(Q2, second) {
	Sequence sequence1(6, 205, 305, 405, 505, 605, 705);
	int* pseq1 = sequence1.getSeq();

	Sequence sequence2(sequence1);
	int* pseq2 = sequence2.getSeq();
	ASSERT_NE(pseq2, pseq1);
	ASSERT_EQ(6, sequence2.getLength());
	ASSERT_EQ(305, *(pseq2 + 1));
	ASSERT_EQ(505, *(pseq2 + 3));
	ASSERT_EQ(705, *(pseq2 + 5));
}

TEST(Q2, third) {
	Sequence sequence(20, 800, 30, 25, 550, 69, 98, 31, 12, 102, 84);

	sequence.Sort(7);
	int* pseq = sequence.getSeq();
	ASSERT_EQ(25, *pseq);
	ASSERT_EQ(30, *(pseq + 1));
	ASSERT_EQ(69, *(pseq + 3));
	ASSERT_EQ(550, *(pseq + 5));
	ASSERT_EQ(800, *(pseq + 6));

	ASSERT_EQ(12, *(pseq + 7));
	ASSERT_EQ(102, *(pseq + 8));
}

TEST(Q2, fourth) {
	Sequence sequence(8, 5, 20, 69, 88, 3, 20, 3, 88);

	ASSERT_EQ(5, sequence.RemoveDuplicates());
	int* pseq = sequence.getSeq();
	ASSERT_EQ(8, sequence.getLength());
	ASSERT_EQ(3, *pseq);
	ASSERT_EQ(5, *(pseq + 1));
	ASSERT_EQ(20, *(pseq + 2));
	ASSERT_EQ(69, *(pseq + 3));
	ASSERT_EQ(88, *(pseq + 4));
}

TEST(Q2, fifth) {
	Sequence sequence(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	sequence.Rotate(5);
	int* pseq = sequence.getSeq();
	ASSERT_EQ(6, *pseq);
	ASSERT_EQ(7, *(pseq + 1));
	ASSERT_EQ(8, *(pseq + 2));
	ASSERT_EQ(4, *(pseq + 8));
	ASSERT_EQ(5, *(pseq + 9));

	sequence.Rotate(15);

	ASSERT_EQ(6, *(pseq + 5));
	ASSERT_EQ(9, *(pseq + 8));
	ASSERT_EQ(10, *(pseq + 9));
}



//----------Question #03----------

TEST(Q3, first) {
	Sandwich S;

	ASSERT_EQ(NULL, S.getName());
	ASSERT_EQ(NULL, S.getFilling());
	ASSERT_EQ(NULL, S.getSize());
	ASSERT_EQ(0.0, S.getPrice());
	ASSERT_FALSE(S.check_status());

	char filling[] = "Sauce";
	char name[] = "Chicken";
	char size[] = "small";

	Sandwich S2(filling, 400);
	S2.setName(name);
	S2.setSize(size);

	ASSERT_EQ(0, strcmp("Chicken", S2.getName()));
	ASSERT_EQ(0, strcmp("Sauce", S2.getFilling()));
	ASSERT_EQ(0, strcmp("small", S2.getSize()));
	ASSERT_EQ(400.0, S2.getPrice());
}

TEST(Q3, second) {
	char filling[] = "Sauce";
	char name[] = "Vegetable";
	char size[] = "large";
	Sandwich S(filling, 1000, name,
		size, true);

	ASSERT_EQ(0, strcmp("Vegetable", S.getName()));
	ASSERT_EQ(0, strcmp("Sauce", S.getFilling()));
	ASSERT_EQ(0, strcmp("large", S.getSize()));
	ASSERT_EQ(1000.0, S.getPrice());
	ASSERT_TRUE(S.check_status());

	Sandwich S2(S);

	char nfilling[] = "Spicy Sauce";
	S2.setFilling(nfilling);

	ASSERT_EQ(0, strcmp("Vegetable", S2.getName()));
	ASSERT_EQ(0, strcmp("Spicy Sauce", S2.getFilling()));
	ASSERT_EQ(0, strcmp("large", S2.getSize()));
	ASSERT_EQ(1000.0, S2.getPrice());
	ASSERT_TRUE(S2.check_status());

	ASSERT_EQ(0, strcmp("Sauce", S.getFilling()));
}

TEST(Q3, third) {
	Sandwich S;

	char filling[] = "sauce";
	char name[] = "chicken zinger";
	char size[] = "big";

	S.setName(name);
	S.setFilling(filling);
	S.setSize(size);
	S.setPrice(1200);

	//because size can only be small, medium or large
	ASSERT_EQ(NULL, S.getSize());

	char nsize[] = "large";
	S.setSize(nsize);

	ASSERT_FALSE(S.check_status());

	S.makeSandwich();

	ASSERT_EQ(0, strcmp("chicken zinger", S.getName()));
	ASSERT_EQ(0, strcmp("sauce", S.getFilling()));
	ASSERT_EQ(0, strcmp("large", S.getSize()));
	ASSERT_EQ(1200.0, S.getPrice());
	ASSERT_TRUE(S.check_status());
}


//----------Question #04----------

TEST(Q4, first) {
	CustomerAccount* customers[100];
	int accountsOpen = 0;

	char name[] = "NUCES";
	char address[] = "H-11/4";
	char city[] = "Isd";
	char state[] = "Pk";

	OpenCustomerAccount(customers, accountsOpen, name, address, city, state, 44000,
		33333333333333, 850000);

	ASSERT_EQ(0, strcmp("NUCES", customers[0]->name));
	ASSERT_EQ(0, strcmp("H-11/4", customers[0]->address.address));
	ASSERT_EQ(0, strcmp("Isd", customers[0]->address.city));
	ASSERT_EQ(0, strcmp("Pk", customers[0]->address.state));
	ASSERT_EQ(44000, customers[0]->address.zip_code);
	ASSERT_EQ(33333333333333, customers[0]->phoneNum);
	ASSERT_EQ(850000, customers[0]->balance);
}

TEST(Q4, second) {
	CustomerAccount* customers[100];
	int accountsOpen = 0;

	char name[] = "NUCES";
	char address[] = "H-11/4";
	char city[] = "Isd";
	char state[] = "Pk";

	OpenCustomerAccount(customers, accountsOpen, name, address, city,
		state, 44000, 33333333333333, 850000);

	ASSERT_EQ(850000, customers[0]->balance);

	char account[] = "PK001";
	ASSERT_EQ(0, SearchCustomer(customers, accountsOpen, account));

	char nname[] = "NUCES-1";
	OpenCustomerAccount(customers, accountsOpen, nname,
		address, city, state, 44100, 33333333333344, 950000);

	char accountID[] = "PK002";
	int index = SearchCustomer(customers, accountsOpen, accountID);

	ASSERT_EQ(0, strcmp("NUCES-1", customers[index]->name));
	ASSERT_EQ(950000, customers[index]->balance);
	ASSERT_EQ(44100, customers[index]->address.zip_code);

	char fakeaccount[] = "PK101";
	ASSERT_EQ(-1, SearchCustomer(customers, accountsOpen, fakeaccount));
}

TEST(Q4, third) {
	CustomerAccount* customers[100];
	int accountsOpen = 0;

	char name[] = "NUCES";
	char address[] = "H-11/4";
	char city[] = "Isd";
	char state[] = "Pk";

	for (int i = 0; i < 500; i++)
		OpenCustomerAccount(customers, accountsOpen, name, address, city, state, 44000,
			33333333333333, 850000);

	char fakeAccount[] = "PK449";
	char validAccount[] = "PK001";
	ASSERT_EQ(-1, SearchCustomer(customers, accountsOpen, fakeAccount));
	ASSERT_LT(-1, SearchCustomer(customers, accountsOpen, validAccount));
}

TEST(Q4, fourth) {
	CustomerAccount* customers[100];
	int accountsOpen = 0;

	char name[] = "NUCES";
	char address[] = "H-11/4";
	char city[] = "Isd";
	char state[] = "Pk";

	OpenCustomerAccount(customers, accountsOpen, name, address, city, state, 44000,
		33333333333333, 850000);

	char nname[] = "NUCES-1";
	OpenCustomerAccount(customers, accountsOpen, nname,
		address, city, state, 44100, 33333333333344, 8500000);

	char account[] = "PK001";
	char fakeaccount[] = "PK500";

	int index = SearchCustomer(customers, accountsOpen, account);

	ASSERT_EQ(true, UpdateCustomerAccount(customers, accountsOpen, account, static_cast<long long>(555555555555555)));
	ASSERT_EQ(false, UpdateCustomerAccount(customers, accountsOpen, fakeaccount, static_cast<long long>(555555555555555)));

	ASSERT_EQ(555555555555555, customers[index]->phoneNum);

	ASSERT_EQ(true, UpdateCustomerAccount(customers, accountsOpen, account, static_cast<float>(5500000)));
	ASSERT_EQ(false, UpdateCustomerAccount(customers, accountsOpen, fakeaccount, static_cast<float>(5500000)));

	ASSERT_EQ(static_cast<float>(5500000), customers[index]->balance);

	Address add;

	char tempAddress[] = "FAST-NUCES";
	add.address = tempAddress;

	char tempCity[] = "Kch";
	add.city = tempCity;

	char tempState[] = "Pk";
	add.state = tempState;

	add.zip_code = 75600;

	char accountID[] = "PK002";

	ASSERT_EQ(true, UpdateCustomerAccount(customers, accountsOpen, accountID, add));
	ASSERT_EQ(false, UpdateCustomerAccount(customers, accountsOpen, fakeaccount, add));

	int newIndex = SearchCustomer(customers, accountsOpen, accountID);

	ASSERT_EQ(0, strcmp("FAST-NUCES", customers[newIndex]->address.address));
	ASSERT_EQ(0, strcmp("Kch", customers[newIndex]->address.city));
	ASSERT_EQ(0, strcmp("Pk", customers[newIndex]->address.state));
	ASSERT_EQ(add.zip_code, customers[newIndex]->address.zip_code);
}


//----------Question #05----------

TEST(Q5, first) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		char name[] = { 'E', 'M', 'P', 'L', 'O', 'Y', 'E', 'E', char(i + 49), '\0' };
		employees[i].setCSRID(i + 1);
		employees[i].setName(name);
		employees[i].setHours((i + 1) * 25);
		employees[i].setComplaintsResolved((i + 1) * 20);
	}

	employees[0].setCSRID(-5);
	employees[2].setHours(-8);
	employees[4].setComplaintsResolved(-100);

	for (int i = 0; i < 7; i++)
	{
		ASSERT_EQ(i + 1, employees[i].getCSRID());
		char name[] = { 'E', 'M', 'P', 'L', 'O', 'Y', 'E', 'E', char(i + 49), '\0' };
		ASSERT_EQ(0, strcmp(name, employees[i].getName()));
		ASSERT_EQ((i + 1) * 25, employees[i].getHours());
		ASSERT_EQ((i + 1) * 20, employees[i].getComplaintsResolved());
	}
}

TEST(Q5, second) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		char name[] = { 'E', 'M', 'P', 'L', 'O', 'Y', 'E', 'E', char(i + 49), '\0' };
		employees[i].setCSRID(i + 1);
		employees[i].setName(name);
		employees[i].setHours((i + 1) * 25);
		employees[i].setComplaintsResolved((i + 1) * 20);
	}

	ASSERT_EQ(employees[3].getCSRID(), getCSR_at(employees, 3).getCSRID());
	ASSERT_EQ(0, strcmp(employees[2].getName(), getCSR_at(employees, 2).getName()));

	calcTotalComplaints(employees);
	calcAllEmployeeWages(employees);

	ASSERT_EQ(560, CSR::getTotalCpsResolved());

	ASSERT_EQ(28, static_cast<int>(employees[3].getPayrate()));
	ASSERT_EQ(30, static_cast<int>(employees[5].getPayrate()));
	ASSERT_EQ(26, static_cast<int>(employees[1].getPayrate()));

	ASSERT_EQ(2075, static_cast<int>(employees[2].getWage()));
	ASSERT_EQ(3683, static_cast<int>(employees[4].getWage()));
	ASSERT_EQ(5468, static_cast<int>(employees[6].getWage()));
}

TEST(Q5, third) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		char name[] = { 'E', 'M', 'P', 'L', 'O', 'Y', 'E', 'E', char(i + 49), '\0' };
		employees[i].setCSRID(i + 1);
		employees[i].setName(name);
		employees[i].setHours((i + 1) * 25);
		employees[i].setComplaintsResolved((i + 1) * 20);
	}

	employees[3].setHours(45);
	employees[5].setHours(90);

	calcTotalComplaints(employees);
	calcAllEmployeeWages(employees);

	SortByHours(employees);

	ASSERT_EQ(7, employees[0].getCSRID());
	ASSERT_EQ(5, employees[1].getCSRID());
	ASSERT_EQ(6, employees[2].getCSRID());
	ASSERT_EQ(2, employees[4].getCSRID());
	ASSERT_EQ(1, employees[6].getCSRID());

	ASSERT_EQ(175, employees[0].getHours());
	ASSERT_EQ(125, employees[1].getHours());
	ASSERT_EQ(90, employees[2].getHours());
	ASSERT_EQ(50, employees[4].getHours());
	ASSERT_EQ(25, employees[6].getHours());
}

TEST(Q5, fourth) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		char name[] = { 'E', 'M', 'P', 'L', 'O', 'Y', 'E', 'E', char(i + 49), '\0' };
		employees[i].setCSRID(i + 1);
		employees[i].setName(name);
		employees[i].setHours((i + 1) * 25);
		employees[i].setComplaintsResolved((i + 1) * 20);
	}

	employees[3].setComplaintsResolved(145);
	employees[5].setComplaintsResolved(90);

	calcTotalComplaints(employees);
	calcAllEmployeeWages(employees);

	SortByComplaintsRes(employees);

	ASSERT_EQ(4, employees[0].getCSRID());
	ASSERT_EQ(7, employees[1].getCSRID());
	ASSERT_EQ(5, employees[2].getCSRID());
	ASSERT_EQ(3, employees[4].getCSRID());
	ASSERT_EQ(1, employees[6].getCSRID());

	ASSERT_EQ(145, employees[0].getComplaintsResolved());
	ASSERT_EQ(140, employees[1].getComplaintsResolved());
	ASSERT_EQ(100, employees[2].getComplaintsResolved());
	ASSERT_EQ(60, employees[4].getComplaintsResolved());
	ASSERT_EQ(20, employees[6].getComplaintsResolved());
}

TEST(Q5, fifth) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		char name[] = { 'E', 'M', 'P', 'L', 'O', 'Y', 'E', 'E', char(i + 49), '\0' };
		employees[i].setCSRID(i + 1);
		employees[i].setName(name);
		employees[i].setHours((i + 1) * 25);
		employees[i].setComplaintsResolved((i + 1) * 20);
	}

	employees[2].setHours(45);
	employees[4].setHours(90);
	employees[3].setHours(70);
	employees[3].setComplaintsResolved(145);
	employees[5].setComplaintsResolved(90);
	employees[1].setComplaintsResolved(115);

	calcTotalComplaints(employees);
	calcAllEmployeeWages(employees);

	SortByWages(employees);

	ASSERT_EQ(7, employees[0].getCSRID());
	ASSERT_EQ(6, employees[1].getCSRID());
	ASSERT_EQ(5, employees[2].getCSRID());
	ASSERT_EQ(4, employees[3].getCSRID());
	ASSERT_EQ(1, employees[6].getCSRID());

	ASSERT_EQ(5289, static_cast<int>(employees[0].getWage()));
	ASSERT_EQ(4253, static_cast<int>(employees[1].getWage()));
	ASSERT_EQ(2585, static_cast<int>(employees[2].getWage()));
	ASSERT_EQ(1464, static_cast<int>(employees[4].getWage()));
	ASSERT_EQ(643, static_cast<int>(employees[6].getWage()));
}


//----------Question #06----------

TEST(Q6, first) {
	char st[] = "Object Oriented Programming";
	String str(st);
	char* data = str.getdata();
	ASSERT_EQ(0, strcmp("Object Oriented Programming", data));

	String str1(50);
	ASSERT_EQ(50, str1.strLength());
	ASSERT_EQ(0, strcmp("", str1.getdata()));

	String str2(str);
	ASSERT_EQ(0, strcmp(str2.getdata(), str.getdata()));
	ASSERT_NE(str2.getdata(), data);
}

TEST(Q6, second) {
	char st[] = "Object Oriented Programming";
	String str(st);
	ASSERT_EQ(27, str.strLength());
	ASSERT_FALSE(str.empty());
	str.clear();
	ASSERT_EQ(0, str.strLength());
	ASSERT_TRUE(str.empty());

	//checking for validation in clear function
	str.clear();
	ASSERT_EQ(NULL, str.getdata());
}

TEST(Q6, third) {
	char st[] = "Object ORieNted ProgrammIng";
	String str(st);
	ASSERT_EQ(0, str.charAt('O'));
	ASSERT_EQ(16, str.charAt('P'));
	ASSERT_EQ(24, str.charAt('I'));
	ASSERT_EQ(11, str.charAt('N'));

	char st1[] = "Semester: Spring 2022";
	String str1(st1);
	ASSERT_EQ(2, str1.charAt('m'));
	ASSERT_EQ(1, str1.charAt('e'));
	ASSERT_EQ(7, str1.charAt('r'));
	ASSERT_EQ(9, str1.charAt(' '));
	ASSERT_EQ(8, str1.charAt(':'));
	ASSERT_EQ(11, str1.charAt('p'));
	ASSERT_EQ(17, str1.charAt('2'));
	ASSERT_EQ(18, str1.charAt('0'));
}

TEST(Q6, fourth) {
	char st[] = "Object Oriented Programming";
	String str(st);

	char t1[] = "Object 0riented Programming", t2[] = "Object Oriented ProgramminG", t3[] = "object Oriented Programming", t4[] = "Object Oriented Programming";
	ASSERT_FALSE(str.equals(t1));
	ASSERT_FALSE(str.equals(t2));
	ASSERT_FALSE(str.equals(t3));
	ASSERT_TRUE(str.equals(t4));

	char st1[] = "Semester: Spring 2022";
	String str1(st1);

	char t11[] = "Semester: Sring 2022", t12[] = "Semester: Srping 2022", t13[] = "Semester: Spring 2O22", t14[] = "Semester: Spring 2022";
	ASSERT_FALSE(str1.equals(t11));
	ASSERT_FALSE(str1.equals(t12));
	ASSERT_FALSE(str1.equals(t13));
	ASSERT_TRUE(str1.equals(t14));
}

TEST(Q6, fifth) {
	char st[] = "ObjectOrientedProgramming";
	String str(st);
	char t1[] = "ObJEctOrIEntedPrograMMing", t2[] = "objeCtorienTEdprogrammiNg", t3[] = "Object0rientedProgramming", t4[] = "OBJECTORIENTEDProgRAMMing";
	ASSERT_TRUE(str.equalsIgnoreCase(t1));
	ASSERT_TRUE(str.equalsIgnoreCase(t2));
	ASSERT_FALSE(str.equalsIgnoreCase(t3));
	ASSERT_TRUE(str.equalsIgnoreCase(t4));
}

TEST(Q6, sixth) {
	char st[] = "Object-Oriented-Programming, Assignment:02";
	String str1(st);
	char t1[] = "ObjEct-OriEntEd-PrOgrAmming, AssigNment:02", t2[] = "Object-0rieNted-ProgrammIng, Assignment 02",
		t3[] = "Object-Oriented-Programming, Assignment:O2", t4[] = "ObJECT-OrienTED-ProgRAMming, ASSignment:02";
	ASSERT_TRUE(str1.equalsIgnoreCase(t1));
	ASSERT_FALSE(str1.equalsIgnoreCase(t2));
	ASSERT_FALSE(str1.equalsIgnoreCase(t3));
	ASSERT_TRUE(str1.equalsIgnoreCase(t4));
}

//TEST(Q6, seventh) {
//	char st[] = "Object-Oriented-Programming, Assignment:02";
//	String str(st);
//	char t1[] = "Ass", t2[] = "Orie", t3[] = "ec", t4[] = ",";
//	ASSERT_EQ(0, strcmp(str.substring(t1, 5), "Assignment:02"));
//	ASSERT_EQ(NULL, str.substring(t2, 15));
//	ASSERT_EQ(0, strcmp(str.substring(t3, 2), "ect-Oriented-Programming, Assignment:02"));
//	ASSERT_EQ(0, strcmp(str.substring(t4, 16), ", Assignment:02"));
//}

TEST(Q6, eighth) {
	char st[] = "Object-Oriented-Programming, Assignment:02";
	String str(st);
	char* originalString = str.getdata();
	char t1[] = "ent";
	char* subString = str.substring(t1, 5);

	ASSERT_EQ(0, strcmp(subString, "ented-Programming, Assignment:02"));
	ASSERT_NE(originalString + 10, subString);
}

TEST(Q6, ninth) {
	char st[] = "Object-Oriented-Programming, Assignment:02";
	String str(st);

	char t1[] = "ject", t2[] = " ", t3[] = "ign";
	ASSERT_EQ(0, strcmp(str.substring(t1, 1, 10), "ject-Orie"));
	ASSERT_EQ(NULL, str.substring(t1, 5, 10));
	ASSERT_EQ(0, strcmp(str.substring(t2, 7, 38), " Assignment"));
	ASSERT_EQ(0, strcmp(str.substring(t3, 2, 40), "ignment:0"));
}

TEST(Q6, tenth) {
	char st[] = "Object-Oriented-Programming, Assignment:02";
	String str(st);
	char* originalString = str.getdata();

	char t1[] = "O";
	char* subString = str.substring(t1, 2, 14);

	ASSERT_EQ(0, strcmp(subString, "Oriented"));
	ASSERT_NE(originalString + 7, subString);
}


//----------Question #07----------

TEST(Q7, first) {
	Matrix M(4, 5, 6, 7);

	ASSERT_EQ(2, M.getRow());
	ASSERT_EQ(2, M.getCol());

	ASSERT_EQ(4, M.getValue(0, 0));
	ASSERT_EQ(5, M.getValue(0, 1));
	ASSERT_EQ(6, M.getValue(1, 0));
	ASSERT_EQ(7, M.getValue(1, 1));

	Matrix M1(100, 200, 300, 400, 500, 600, 700, 800, 900);

	ASSERT_EQ(3, M1.getRow());
	ASSERT_EQ(3, M1.getCol());

	ASSERT_EQ(100, M1.getValue(0, 0));
	ASSERT_EQ(300, M1.getValue(0, 2));
	ASSERT_EQ(500, M1.getValue(1, 1));
	ASSERT_EQ(800, M1.getValue(2, 1));
}

TEST(Q7, second) {
	Matrix M(100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600);

	ASSERT_EQ(4, M.getRow());
	ASSERT_EQ(4, M.getCol());

	ASSERT_EQ(400, M.getValue(0, 3));
	ASSERT_EQ(600, M.getValue(1, 1));
	ASSERT_EQ(1100, M.getValue(2, 2));
	ASSERT_EQ(1300, M.getValue(3, 0));
}


TEST(Q7, third) {
	Matrix M1(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160);
	Matrix M2(M1);
	M2.setValue(1, 1, 609);

	ASSERT_EQ(60, M1.getValue(1, 1));
	ASSERT_EQ(609, M2.getValue(1, 1));
}

TEST(Q7, fourth) {
	Matrix M1(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160);

	ASSERT_EQ(1360, M1.Total());
	ASSERT_EQ(85, M1.Average());
}

TEST(Q7, fifth) {
	Matrix M1(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160);

	ASSERT_EQ(420, M1.RowTotal(2));

	M1.setValue(2, 1, 60);

	ASSERT_EQ(380, M1.RowTotal(2));
}

TEST(Q7, sixth) {
	Matrix M1(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160);
	M1.setValue(1, 2, 60);

	ASSERT_EQ(320, M1.ColumnTotal(1));
	ASSERT_EQ(350, M1.ColumnTotal(2));
}

TEST(Q7, seventh) {
	Matrix M1(100, 25, 3000, 24, 56, 61, 73, 81, 79, 810, 9011, 8012, 103, 104, 1500, 1060);

	ASSERT_EQ(81, M1.HighestInRow(1));
	ASSERT_EQ(9011, M1.HighestInRow(2));
	ASSERT_EQ(1500, M1.HighestInRow(3));
}

TEST(Q7, eighth) {
	Matrix M1(100, 25, 3000, 24, 56, 61, 73, 81, 79, 810, 9011, 8012, 103, 104, 1500, 1060);

	ASSERT_EQ(24, M1.LowestInRow(0));
	ASSERT_EQ(103, M1.LowestInRow(3));
	ASSERT_EQ(56, M1.LowestInRow(1));
}

TEST(Q7, ninth) {
	Matrix M1(100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600);
	Matrix M2 = M1.Transpose();

	ASSERT_EQ(200, M1.getValue(0, 1));
	ASSERT_EQ(200, M2.getValue(1, 0));

	ASSERT_EQ(1500, M1.getValue(3, 2));
	ASSERT_EQ(1500, M2.getValue(2, 3));

	ASSERT_EQ(700, M1.getValue(1, 2));
	ASSERT_EQ(700, M2.getValue(2, 1));

	ASSERT_EQ(800, M1.getValue(1, 3));
	ASSERT_EQ(800, M2.getValue(3, 1));

	ASSERT_EQ(1000, M1.getValue(2, 1));
	ASSERT_EQ(1000, M2.getValue(1, 2));

	ASSERT_EQ(900, M1.getValue(2, 0));
	ASSERT_EQ(900, M2.getValue(0, 2));

	ASSERT_EQ(1300, M1.getValue(3, 0));
	ASSERT_EQ(1300, M2.getValue(0, 3));
}

TEST(Q7, tenth) {
	Matrix M1(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160);

	ASSERT_EQ(340, M1.LeftDiagonalTotal());

	M1.setValue(2, 2, 34);

	ASSERT_EQ(264, M1.LeftDiagonalTotal());
}

TEST(Q7, eleventh) {
	Matrix M1(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160);

	ASSERT_EQ(340, M1.RightDiagonalTotal());

	M1.setValue(1, 2, 34);

	ASSERT_EQ(304, M1.RightDiagonalTotal());
}

TEST(Q7, twelfth) {
	Matrix M1(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160);

	Matrix M(1, 2, 3, 4);

	Matrix faulty = M1.Add(M);

	ASSERT_EQ(0, faulty.getRow());
	ASSERT_EQ(0, faulty.getCol());

	Matrix M2(M1);
	for (int i = 0; i < 4; i++)
		M2.setValue(i, i, 0);

	Matrix M3 = M1.Add(M2);

	// M1			M3
	// 1  2  3  4   2  4  6  8
	// 5  6  7  8	10 12 14 16
	// 9  10 11 12  18 20 22 24
	// 13 14 15 16  26 28 30 32

	ASSERT_EQ(60, M3.getValue(1, 1));
	ASSERT_EQ(80, M3.getValue(0, 3));
	ASSERT_EQ(280, M3.getValue(3, 1));
	ASSERT_EQ(180, M3.getValue(2, 0));
	ASSERT_EQ(110, M3.getValue(2, 2));
	ASSERT_EQ(240, M3.getValue(2, 3));
}

TEST(Q7, thirteenth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	Matrix M(1, 2, 3, 4);

	Matrix faulty = M1.Subtract(M);

	ASSERT_EQ(0, faulty.getRow());
	ASSERT_EQ(0, faulty.getCol());

	Matrix M2(M1);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			M1.setValue(i, j, M1.getValue(i, j) * 10);

	Matrix M3 = M1.Subtract(M2);

	int exp = 9;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ASSERT_EQ(exp, M3.getValue(i, j));
			exp += 9;
		}
	}
}

TEST(Q7, fourteenth) {
	Matrix M(81, 21, 12, 13, 62, 12, 14, 16, 124, 32, 42, 33, 31, 5, 7, 45);

	Matrix M1(6, 7, 8, 9, 10, 11, 12, 13, 14);

	Matrix FM = M.Multiply(M1);

	ASSERT_EQ(0, FM.getCol());
	ASSERT_EQ(0, FM.getRow());

	Matrix N(67, 98, 9, 54, 32, 76, 96, 4, 6, 878, 96, 5, 86, 44, 32, 46);

	Matrix X = M.Multiply(N);

	ASSERT_EQ(7289, X.getValue(0, 0));
	ASSERT_EQ(20642, X.getValue(0, 1));
	ASSERT_EQ(4313, X.getValue(0, 2));
	ASSERT_EQ(5116, X.getValue(0, 3));
	ASSERT_EQ(5998, X.getValue(1, 0));
	ASSERT_EQ(19984, X.getValue(1, 1));
	ASSERT_EQ(3566, X.getValue(1, 2));
	ASSERT_EQ(4202, X.getValue(1, 3));
	ASSERT_EQ(12422, X.getValue(2, 0));
	ASSERT_EQ(52912, X.getValue(2, 1));
	ASSERT_EQ(9276, X.getValue(2, 2));
	ASSERT_EQ(8552, X.getValue(2, 3));
	ASSERT_EQ(6149, X.getValue(3, 0));
	ASSERT_EQ(11544, X.getValue(3, 1));
	ASSERT_EQ(2871, X.getValue(3, 2));
	ASSERT_EQ(3799, X.getValue(3, 3));
}


TEST(Q7, fifteenth) {
	Matrix X(9, 2, 3, 0, -5, 2, 3, 4, 100, 12, -50, 12, -50, 100, 2, 8);

	// -50 -5 0 2 3 4 8 9 12 100

	ASSERT_EQ(-50, X.FindkSmallest(1));
	ASSERT_EQ(0, X.FindkSmallest(3));
	ASSERT_EQ(2, X.FindkSmallest(4));
	ASSERT_EQ(8, X.FindkSmallest(7));
	ASSERT_EQ(100, X.FindkSmallest(10));

	// return largest value if k is greater than the indexes of the matrix 
	// or due to duplicates in matrix, k becomes greater than all the unique values

	// return 0 if k is less than 1

	ASSERT_EQ(100, X.FindkSmallest(12));
	ASSERT_EQ(100, X.FindkSmallest(18));
	ASSERT_EQ(0, X.FindkSmallest(0));
}

TEST(Q7, sixteenth) {
	Matrix X(9, 2, 3, 0, -5, 2, 3, 4, 100, 12, -50, 12, -50, 100, 2, 8);

	// 100 12 9 8 4 3 2 0 -5 -50

	ASSERT_EQ(100, X.FindkLargest(1));
	ASSERT_EQ(2, X.FindkLargest(7));
	ASSERT_EQ(8, X.FindkLargest(4));
	ASSERT_EQ(9, X.FindkLargest(3));
	ASSERT_EQ(-5, X.FindkLargest(9));
	ASSERT_EQ(-50, X.FindkLargest(10));

	// return smallest value if k is greater than the indexes of the matrix 
	// or due to duplicates in matrix, k becomes greater than all the unique values

	// return 0 if k is less than 1

	ASSERT_EQ(-50, X.FindkLargest(11));
	ASSERT_EQ(-50, X.FindkLargest(20));
	ASSERT_EQ(0, X.FindkLargest(0));
}

TEST(Q7, seventeenth) {
	Matrix M(200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700);

	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9);

	Matrix FM = M.merge(M1);

	ASSERT_EQ(0, FM.getCol());
	ASSERT_EQ(0, FM.getRow());

	Matrix N(1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 3000, 3100, 3200, 3300);

	Matrix X = M.merge(N);


	// 200   300   400   500    1800   1900   2000   2100
	// 600   700   800   900    2200   2300   2400   2500
	// 1000  1100  1200  1300   2600   2700   2800   2900
	// 1400  1500  1600  1700   3000   3100   3200   3300

	ASSERT_EQ(700, X.getValue(1, 1));
	ASSERT_EQ(1200, X.getValue(2, 2));
	ASSERT_EQ(900, X.getValue(1, 3));
	ASSERT_EQ(1300, X.getValue(2, 3));
	ASSERT_EQ(1800, X.getValue(0, 4));
	ASSERT_EQ(3300, X.getValue(3, 7));
	ASSERT_EQ(3100, X.getValue(3, 5));
	ASSERT_EQ(2400, X.getValue(1, 6));
	ASSERT_EQ(2600, X.getValue(2, 4));
}