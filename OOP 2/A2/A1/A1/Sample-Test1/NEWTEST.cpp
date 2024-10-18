#include "pch.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"
#include "Q5.h"
#include "Q6.h"
#include "Q7.h"


//------------------------------------- Question #01 ------------------------------
TEST(Q1, first) {
	Invoice i1(NULL, NULL, -50, 2.0);
	ASSERT_EQ(0, i1.getQuantity());
	ASSERT_EQ(2.0, i1.getPricePerItem());
	ASSERT_EQ(0, i1.getInvoiceAmount());
}

TEST(Q1, second) {
	Invoice i1("car0", "autmobile", 100, 12.0);

	ASSERT_EQ(0, strcmp("car0", i1.getPartNum()));
	ASSERT_EQ(0, strcmp("autmobile", i1.getPartDesc()));
	ASSERT_EQ(100, i1.getQuantity());
	ASSERT_EQ(12.0, i1.getPricePerItem());
	ASSERT_EQ(1200, i1.getInvoiceAmount());
}

TEST(Q1, third) {
	char partNum[] = "car1";
	char partDesc[] = "automobile";
	Invoice i1(partNum, partDesc, 50, 2.0);

	ASSERT_EQ(0, strcmp(partNum, i1.getPartNum()));
	ASSERT_EQ(0, strcmp(partDesc, i1.getPartDesc()));
	ASSERT_EQ(50, i1.getQuantity());
	ASSERT_EQ(2.0, i1.getPricePerItem());
	ASSERT_EQ(100, i1.getInvoiceAmount());
}

TEST(Q1, fourth) {
	char partNum[] = "car2";
	char partDesc[] = "automobile";
	Invoice i1(partNum, partDesc, 6, 7.0);

	Invoice i2 = i1;

	ASSERT_EQ(0, strcmp(partNum, i2.getPartNum()));
	ASSERT_EQ(0, strcmp(partDesc, i2.getPartDesc()));
	ASSERT_EQ(6, i2.getQuantity());
	ASSERT_EQ(7.0, i2.getPricePerItem());
	ASSERT_EQ(42, i2.getInvoiceAmount());
}


//------------------------------------- Question #02 ------------------------------
TEST(Q2, first) {
	Date d1(20, 1, 2022);
	ASSERT_EQ(1, d1.getMonth());
	d1.setMonth(15);
	ASSERT_EQ(1, d1.getMonth());
}


TEST(Q2, second) {
	Date d1(25, 5, 2022); // 25 / May / 2022
	d1.nextDay();
	ASSERT_EQ(26, d1.getDay());
	ASSERT_EQ(5, d1.getMonth());
	ASSERT_EQ(2022, d1.getYear());
}

TEST(Q2, third) {
	Date d1(31, 12, 2022); // 31 / dec / 2022
	d1.nextDay();
	ASSERT_EQ(1, d1.getDay());
	ASSERT_EQ(1, d1.getMonth());
	ASSERT_EQ(2023, d1.getYear());
}

TEST(Q2, fourth) {
	Date d1(28, 2, 2024);

	d1.nextDay();
	Date d2 = d1;
	ASSERT_EQ(29, d1.getDay());
	ASSERT_EQ(2, d1.getMonth());
	ASSERT_EQ(2024, d1.getYear());

	d2.nextDay();
	ASSERT_EQ(1, d2.getDay());
	ASSERT_EQ(3, d2.getMonth());
	ASSERT_EQ(2024, d2.getYear());
}

//------------------------------------- Question #03 -----------------------------

TEST(Q3, first) {
	DateAndTime d1(25, 5, 2022, 59, 59, 11, 'a');
	d1.tick();
	ASSERT_EQ(0, d1.getSec());
	ASSERT_EQ(0, d1.getMin());
	ASSERT_EQ(12, d1.getHour());
	ASSERT_EQ('p', d1.getMeridiem());

	ASSERT_EQ(25, d1.getDay());
	ASSERT_EQ(5, d1.getMonth());
	ASSERT_EQ(2022, d1.getYear());
}

TEST(Q3, second) {
	DateAndTime d1(31, 12, 2022, 59, 59, 11, 'p');
	d1.tick();
	ASSERT_EQ(0, d1.getSec());
	ASSERT_EQ(0, d1.getMin());
	ASSERT_EQ(12, d1.getHour());
	ASSERT_EQ('a', d1.getMeridiem());

	ASSERT_EQ(1, d1.getDay());
	ASSERT_EQ(1, d1.getMonth());
	ASSERT_EQ(2023, d1.getYear());
}


TEST(Q3, third) {
	DateAndTime d1(28, 2, 2024, 59, 59, 11, 'p');
	d1.tick();
	ASSERT_EQ(0, d1.getSec());
	ASSERT_EQ(0, d1.getMin());
	ASSERT_EQ(12, d1.getHour());
	ASSERT_EQ('a', d1.getMeridiem());

	ASSERT_EQ(29, d1.getDay());
	ASSERT_EQ(2, d1.getMonth());
	ASSERT_EQ(2024, d1.getYear());
}

TEST(Q3, fourth) {
	DateAndTime d1(31, 12, 2022, 58, 59, 11, 'p'); // 31 / dec / 2022 59:59:11 a
	d1.tick();
	d1.tick();
	ASSERT_EQ(0, d1.getSec());
	ASSERT_EQ(0, d1.getMin());
	ASSERT_EQ(12, d1.getHour());
	ASSERT_EQ('a', d1.getMeridiem());

	DateAndTime d2 = d1;

	ASSERT_EQ(1, d2.getDay());
	ASSERT_EQ(1, d2.getMonth());
	ASSERT_EQ(2023, d2.getYear());
}

//------------------------------------- Question #04 ------------------------------

//Integer Class

TEST(Integer, Set)
{
	Integer i1;

	int integer = 5;
	i1.set(integer);
	EXPECT_EQ(i1.get(), integer);
	EXPECT_TRUE(true);
}

TEST(Integer, bitCount)
{
	Integer i2(10);
	Integer i3(20);
	Integer i4("900");
	EXPECT_EQ(i2.bitCount(), 2);
	EXPECT_TRUE(true);
}
/////////////////////////////////////////   OR    ///////////////////////////////////////
TEST(Integer, bitCountModdMethod)
{
	Integer i2(50);
	Integer i3(20);
	Integer i4("900");
	EXPECT_EQ(i2.bitCount(), 3);
	EXPECT_TRUE(true);
}
TEST(Integer, Comparison)
{
	Integer i2(30);
	Integer i3(40);
	ASSERT_EQ(i2.compareTo(i3), 0);
	EXPECT_FALSE(false);

	i2.set(40);
	ASSERT_EQ(i2.compareTo(i3), 1);
	EXPECT_TRUE(true);
}

TEST(Integer, DoubleV)
{
	Integer i2(20);
	EXPECT_EQ(i2.doubleValue(), 20.00);
	EXPECT_TRUE(true);
}

TEST(Integer, FloatV)
{
	Integer i2(20);
	EXPECT_EQ(i2.floatValue(), 20.0);
	EXPECT_TRUE(true);
}

TEST(Integer, Plus)
{
	Integer result(0);
	Integer i2(20);
	Integer i3(20);
	result = i2.plus(i3);
	EXPECT_EQ(result.get(), 40);
	EXPECT_TRUE(true);
}

TEST(Integer, Subtract)
{
	Integer result(0);
	Integer i2(-10);
	Integer i3(20);
	result = i2.minus(i3);
	EXPECT_EQ(result.get(), -30);
	EXPECT_TRUE(true);
}

TEST(Integer, Mult)
{
	Integer result(0);
	Integer i2(20);
	Integer i3(20);
	result = i2.multiple(i3);
	EXPECT_EQ(result.get(), 400);
	EXPECT_TRUE(true);
}

TEST(Integer, Div)
{
	Integer result(0);
	Integer i2(100);
	Integer i3(20);
	result = i2.divide(i3);
	EXPECT_EQ(result.get(), 5);
	EXPECT_TRUE(true);
}

TEST(Integer, LeadZeros)
{
	int integer = 99;
	Integer result(0);
	EXPECT_EQ(result.numberOfLeadingZeros(integer), 25);
	EXPECT_TRUE(true);
}

/////////////////////////////////////////   OR    ///////////////////////////////////////
TEST(Integer, LeadZerosModMethod)
{
	int integer = 5;
	Integer result(0);
	EXPECT_EQ(result.numberOfLeadingZeros(integer), 30);
	EXPECT_TRUE(true);
}

TEST(Integer, TrailZeros)
{
	int integer = 99;
	Integer result(0);
	EXPECT_EQ(result.numberOfTrailingZeros(integer), 0);
	EXPECT_TRUE(true);
}
TEST(Integer, Binary)
{
	int integer = 99;
	Integer result(0);
	EXPECT_EQ(result.toBinaryString(integer), "01100011");
	EXPECT_TRUE(true);
}
/////////////////////////////////////////   OR    ///////////////////////////////////////
TEST(Integer, BinaryModMethod)
{
	int integer = 99;
	Integer result(0);
	EXPECT_EQ(result.toBinaryString(integer), "1100011");
	EXPECT_TRUE(true);
}
TEST(Integer, Hex)
{
	int integer = 99;
	Integer result(0);
	EXPECT_EQ(result.toHexString(integer), "63");
	EXPECT_TRUE(true);
}

TEST(Integer, Oct)
{
	int integer = 875;
	Integer result(0);
	EXPECT_EQ(result.toOctString(integer), "1553");
	EXPECT_TRUE(true);
}

//------------------------------------- Question #05 ------------------------------
// Family Class




TEST(Family, Youngest)
{
	Person ancestor("John", 'M', 1, 1, 1806);

	Person p1("Mark", 'M', 4, 6, 1880);
	Person p2("Elizabeth", 'F', 1, 6, 1840);
	Person p3("Doe", 'M', 9, 7, 1822);
	Person p4("Diana", 'F', 10, 2, 1860);
	Person p5("George", 'M', 2, 7, 1870);
	Person p6("William", 'M', 10, 9, 1870);
	Person p7("Robert", 'M', 10, 12, 1872);
	Person p8("Bob", 'M', 2, 7, 1860);
	Person p9("Adam", 'M', 6, 6, 1892);
	Person p10("Elexender", 'M', 5, 5, 1890);
	Person p11("Adam", 'M', 2, 7, 1899);
	Person p12("Elsa", 'F', 8, 12, 1900);
	Person p13("Katherine", 'F', 8, 10, 1890);
	Person p14("Emma", 'F', 6, 11, 1920);
	Person p15("Harper", 'F', 22, 5, 1922);
	Person p16("Alice", 'M', 11, 12, 1902);
	Person p17("Daniel", 'M', 11, 12, 1902);
	Person p18("Jack", 'M', 11, 12, 1902);
	Person p19("Oliver", 'M', 11, 12, 1902);
	FamilyTree fTree(&ancestor);
	fTree.registerChild(ancestor, p1);
	fTree.registerChild(ancestor, p2);
	fTree.registerChild(ancestor, p3);


	fTree.registerChild(p1, p4);
	fTree.registerChild(p1, p5);

	fTree.registerChild(p4, p9);
	fTree.registerChild(p4, p10);

	fTree.registerChild(p10, p14);
	fTree.registerChild(p10, p15);

	fTree.registerChild(p14, p17);

	fTree.registerChild(p2, p6);
	fTree.registerChild(p2, p7);

	fTree.registerChild(p7, p11);
	fTree.registerChild(p7, p12);
	fTree.registerChild(p7, p16);

	fTree.registerChild(p16, p18);

	fTree.registerChild(p3, p8);

	fTree.registerChild(p8, p13);

	fTree.registerChild(p13, p19);



	string young = fTree.findYoungestChildOf(p1).getName();
	EXPECT_EQ("George", young);
	EXPECT_TRUE(true);
}

TEST(Family, Eldest)
{
	Person ancestor("John", 'M', 1, 1, 1806);

	Person p1("Mark", 'M', 4, 6, 1880);
	Person p2("Elizabeth", 'F', 1, 6, 1840);
	Person p3("Doe", 'M', 9, 7, 1822);
	Person p4("Diana", 'F', 10, 2, 1860);
	Person p5("George", 'M', 2, 7, 1870);
	Person p6("William", 'M', 10, 9, 1870);
	Person p7("Robert", 'M', 10, 12, 1872);
	Person p8("Bob", 'M', 2, 7, 1860);
	Person p9("Adam", 'M', 6, 6, 1892);
	Person p10("Elexender", 'M', 5, 5, 1890);
	Person p11("Adam", 'M', 2, 7, 1899);
	Person p12("Elsa", 'F', 8, 12, 1900);
	Person p13("Katherine", 'F', 8, 10, 1890);
	Person p14("Emma", 'F', 6, 11, 1920);
	Person p15("Harper", 'F', 22, 5, 1922);
	Person p16("Alice", 'M', 11, 12, 1902);
	Person p17("Daniel", 'M', 11, 12, 1902);
	Person p18("Jack", 'M', 11, 12, 1902);
	Person p19("Oliver", 'M', 11, 12, 1902);
	FamilyTree fTree(&ancestor);
	fTree.registerChild(ancestor, p1);
	fTree.registerChild(ancestor, p2);
	fTree.registerChild(ancestor, p3);


	fTree.registerChild(p1, p4);
	fTree.registerChild(p1, p5);

	fTree.registerChild(p4, p9);
	fTree.registerChild(p4, p10);

	fTree.registerChild(p10, p14);
	fTree.registerChild(p10, p15);

	fTree.registerChild(p14, p17);

	fTree.registerChild(p2, p6);
	fTree.registerChild(p2, p7);

	fTree.registerChild(p7, p11);
	fTree.registerChild(p7, p12);
	fTree.registerChild(p7, p16);

	fTree.registerChild(p16, p18);

	fTree.registerChild(p3, p8);

	fTree.registerChild(p8, p13);

	fTree.registerChild(p13, p19);
	string eldest = fTree.FindEldestGrandsonOf(&ancestor)->getName();
	EXPECT_EQ("Bob", eldest);
	EXPECT_TRUE(true);
}
//------------------------------------- Question #06 ------------------------------

// Matrix

TEST(Matrix, Set)
{
	Matrix b(2, 2);

	b.set(0, 0, -5);
	b.set(0, 1, 6);
	b.set(1, 0, 8);
	b.set(1, 1, 2);
	EXPECT_EQ(-5, b.get(0, 0));
	EXPECT_EQ(6, b.get(0, 1));
	EXPECT_EQ(8, b.get(1, 0));
	EXPECT_EQ(2, b.get(1, 1));
	EXPECT_TRUE(true);
}

TEST(Matrix, Copy)
{
	Matrix a(2, 2);
	Matrix b(2, 2);
	b.set(0, 0, -5);
	b.set(0, 1, 6);
	b.set(1, 0, 8);
	b.set(1, 1, 2);
	a.assign(b);

	EXPECT_EQ(a.get(0, 0), b.get(0, 0));
	EXPECT_EQ(a.get(0, 1), b.get(0, 1));
	EXPECT_EQ(a.get(1, 0), b.get(1, 0));
	EXPECT_EQ(a.get(1, 1), b.get(1, 1));
	EXPECT_TRUE(true);
}

TEST(Matrix, Add)
{
	Matrix a(2, 2);
	Matrix b(2, 2);
	a.set(0, 0, 1);
	a.set(0, 1, -1);
	a.set(1, 0, 3);
	a.set(1, 1, -3);
	b.set(0, 0, -2);
	b.set(0, 1, 2);
	b.set(1, 0, -4);
	b.set(1, 1, 4);
	Matrix result(b.add(a));
	EXPECT_EQ(result.get(0, 0), -1);
	EXPECT_EQ(result.get(0, 1), 1);
	EXPECT_EQ(result.get(1, 0), -1);
	EXPECT_EQ(result.get(1, 1), 1);
	EXPECT_TRUE(true);
}
TEST(Matrix, AddFloat)
{
	float n = 3.0;
	Matrix a(2, 3);
	a.set(0, 0, 8);
	a.set(0, 1, 1);
	a.set(0, 2, 2);
	a.set(1, 0, -5);
	a.set(1, 1, 6);
	a.set(1, 2, 7);
	Matrix result(a.add(n));
	EXPECT_EQ(result.get(0, 0), 11.0);
	EXPECT_EQ(result.get(0, 1), 4.0);
	EXPECT_EQ(result.get(0, 2), 5.0);
	EXPECT_EQ(result.get(1, 0), -2.0);
	EXPECT_EQ(result.get(1, 1), 9.0);
	EXPECT_EQ(result.get(1, 2), 10.0);
	EXPECT_TRUE(true);
}

TEST(Matrix, SubAfromB)
{
	Matrix a(2, 2);
	Matrix b(2, 2);
	b.set(0, 0, 2);
	b.set(0, 1, 9);
	b.set(1, 0, 3);
	b.set(1, 1, 4);
	Matrix result(b.subtract(a));
	EXPECT_EQ(result.get(0, 0), 2);
	EXPECT_EQ(result.get(0, 1), 9);
	EXPECT_EQ(result.get(1, 0), 3);
	EXPECT_EQ(result.get(1, 1), 4);
	EXPECT_TRUE(true);
}
/////////////////////////////////////////   OR    ///////////////////////////////////////
TEST(Matrix, SubBfromA)
{
	Matrix a(2, 2);
	Matrix b(2, 2);
	b.set(0, 0, 2);
	b.set(0, 1, 9);
	b.set(1, 0, 3);
	b.set(1, 1, 4);
	Matrix result(b.subtract(a));
	EXPECT_EQ(result.get(0, 0), -2);
	EXPECT_EQ(result.get(0, 1), -9);
	EXPECT_EQ(result.get(1, 0), -3);
	EXPECT_EQ(result.get(1, 1), -4);
	EXPECT_TRUE(true);
}

TEST(Matrix, MultiplySquareMatrices)
{
	Matrix a(2, 2);
	Matrix b(2, 2);
	b.set(0, 0, 2);
	b.set(0, 1, 9);
	b.set(1, 0, 3);
	b.set(1, 1, 4);
	Matrix result(b.multiply(a));
	EXPECT_EQ(result.get(0, 0), 0);
	EXPECT_EQ(result.get(0, 1), 0);
	EXPECT_EQ(result.get(1, 0), 0);
	EXPECT_EQ(result.get(1, 1), 0);
	EXPECT_TRUE(true);
}

TEST(Matrix, MultiplyNonSquareMatrices)
{
	Matrix a(2, 3);
	Matrix b(3, 2);
	a.set(0, 0, 8);
	a.set(0, 1, 1);
	a.set(0, 2, 2);
	a.set(1, 0, -5);
	a.set(1, 1, 6);
	a.set(1, 2, 7);
	b.set(0, 0, -5);
	b.set(0, 1, 1);
	b.set(1, 0, 0);
	b.set(1, 1, 2);
	b.set(2, 0, -11);
	b.set(2, 1, 7);
	Matrix result(a.multiply(b));
	EXPECT_EQ(result.get(0, 0), -62);
	EXPECT_EQ(result.get(0, 1), 24);
	EXPECT_EQ(result.get(1, 0), -52);
	EXPECT_EQ(result.get(1, 1), 56);
	EXPECT_TRUE(true);
}
TEST(Matrix, MultiplyElement)
{
	Matrix a(2, 2);
	Matrix b(2, 2);
	a.set(0, 0, 1);
	a.set(0, 1, 2);
	a.set(1, 0, 3);
	a.set(1, 1, 4);
	b.set(0, 0, 2);
	b.set(0, 1, 9);
	b.set(1, 0, 3);
	b.set(1, 1, 4);
	Matrix result(a.multiplyElement(b));
	EXPECT_EQ(result.get(0, 0), 2);
	EXPECT_EQ(result.get(0, 1), 18);
	EXPECT_EQ(result.get(1, 0), 9);
	EXPECT_EQ(result.get(1, 1), 16);
	EXPECT_TRUE(true);
}
TEST(Matrix, MultiplyFloat)
{
	float n = 3.0;
	Matrix a(2, 2);

	a.set(0, 0, 1);
	a.set(0, 1, 2);
	a.set(1, 0, 3);
	a.set(1, 1, 4);

	Matrix result(a.multiply(n));
	EXPECT_EQ(result.get(0, 0), 3.0);
	EXPECT_EQ(result.get(0, 1), 6.0);
	EXPECT_EQ(result.get(1, 0), 9.0);
	EXPECT_EQ(result.get(1, 1), 12.0);
	EXPECT_TRUE(true);
}
//------------------------------------- Question #07 -----------------------------
TEST(Q7, first) {

	SavingAccount** saver = new SavingAccount * [100];
	int accountsOpen = 0;

	for (int i = 1; i <= 50; i++)
	{
		OpenCustomerAccount(saver, accountsOpen, "George", i);
	}


	ASSERT_EQ(0, strcmp("George", saver[accountsOpen]->name));
	ASSERT_EQ(50, saver[accountsOpen]->savingBalance);
}

TEST(Q7, second) {

	SavingAccount** saver = new SavingAccount * [100];
	int accountsOpen = 0;

	OpenCustomerAccount(saver, accountsOpen, "Jhon", 10);
	OpenCustomerAccount(saver, accountsOpen, "Ali", 50);


	ASSERT_EQ(0, strcmp("Jhon", saver[accountsOpen]->name));
	ASSERT_EQ(10, saver[accountsOpen]->savingBalance);

	ASSERT_EQ(0, strcmp("Ali", saver[accountsOpen]->name));
	ASSERT_EQ(50, saver[accountsOpen]->savingBalance);
}

TEST(Q7, third) {
	SavingAccount saver;
	saver.name = "Zain";
	saver.annualInterestRate = 10;
	saver.savingBalance = 25;
	saver.accountNum = "SA01";
	modifyInterestRate(&saver, 3);

	ASSERT_EQ(6.25, calculateMonthlyInterest(&saver));
}

TEST(Q7, fourth) {
	SavingAccount** saver = new SavingAccount * [100];
	int accountsOpen = 0;
	for (int i = 0; i < 100; i++)
	{
		OpenCustomerAccount(saver, accountsOpen, "Jhon", i);
	}

	ASSERT_EQ(-1, SearchCustomer(saver, accountsOpen, "110"));
	ASSERT_EQ(98, SearchCustomer(saver, accountsOpen, "98"));
}

TEST(Q7, fifth) {

	SavingAccount** saver = new SavingAccount * [100];
	int accountsOpen = 0;


	for (int i = 0; i < 95; i++)
	{
		OpenCustomerAccount(saver, accountsOpen, "Jhon", i);
	}

	ASSERT_EQ(-1, SearchCustomer(saver, accountsOpen - 1, "101"));
	ASSERT_EQ(90, SearchCustomer(saver, accountsOpen - 1, "90"));
	ASSERT_EQ(95, accountsOpen);

}

TEST(Q7, sixth) {

	SavingAccount s1, s2, s3, s4, s5;
	s1.name = "Moeez";
	s1.annualInterestRate = 10;
	s1.savingBalance = 24;
	s1.accountNum = "SA00";

	s2.name = "Nouman";
	s2.annualInterestRate = 15;
	s2.savingBalance = 30;
	s2.accountNum = "SA01";

	s3.name = "Fariz";
	s3.annualInterestRate = 20;
	s3.savingBalance = 50;
	s3.accountNum = "SA02";

	s4.name = "Luqman";
	s4.annualInterestRate = 10;
	s4.savingBalance = 70;
	s4.accountNum = "SA03";

	s5.name = "Hayat";
	s5.annualInterestRate = 10;
	s5.savingBalance = 80;
	s5.accountNum = "SA04";

	SavingAccount** saver = new SavingAccount * [100];
	int accountsOpen = 5;

	saver[0] = &s1;
	saver[1] = &s2;
	saver[2] = &s3;
	saver[3] = &s4;
	saver[4] = &s5;

	int index = SearchCustomer(saver, accountsOpen - 1, "02");


	ASSERT_EQ(50, saver[index]->savingBalance);
	UpdateAccountBalance(saver, index, "02", 80);
	ASSERT_EQ(80, saver[index]->savingBalance);
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
