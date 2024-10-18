#include "pch.h"
#include <iostream>
#include <string>
#include "Money.h"
#include "Date.h"
#include "BigInt.h"
#include "Polynomial.h"
#include "Bouquet.h"

// Q1: Money

TEST(Money, Constructors) {

	Money m1;

	ASSERT_EQ(0, m1.getDollars());
	ASSERT_EQ(0, m1.getQuarters());
	ASSERT_EQ(0, m1.getNickels());
	ASSERT_EQ(0, m1.getCents());

	Money m2(25.68);

	ASSERT_EQ(25, m2.getDollars());
	ASSERT_EQ(2, m2.getQuarters());
	ASSERT_EQ(3, m2.getNickels());
	ASSERT_EQ(3, m2.getCents());

}

TEST(Money, AdditionSubtractionMoney) {

	Money m1(15.66);
	Money m2(16.93);

	m1 = m1 + m2;
	//32.59

	ASSERT_EQ(32, m1.getDollars());
	ASSERT_EQ(2, m1.getQuarters());
	ASSERT_EQ(1, m1.getNickels());
	ASSERT_EQ(4, m1.getCents());

	Money m3(12.44);

	m1 = m1 - m3;
	//20.15

	ASSERT_EQ(20, m1.getDollars());
	ASSERT_EQ(0, m1.getQuarters());
	ASSERT_EQ(3, m1.getNickels());
	ASSERT_EQ(0, m1.getCents());


}

TEST(Money, AdditionSubtractionDollar) {

	Money m1(50);
	Dollar d1(5);
	Dollar d2(6);

	m1 = m1 + d1;

	ASSERT_EQ(55, m1.getDollars());

	m1 = m1 - d2;

	ASSERT_EQ(49, m1.getDollars());

}

TEST(Money, AdditionSubtractionNickel) {

	Money m1(3.74);
	Nickel n1(10);
	Nickel n2(4);

	m1 = m1 + n1;
	//4.24

	ASSERT_EQ(4, m1.getDollars());
	ASSERT_EQ(0, m1.getQuarters());
	ASSERT_EQ(4, m1.getNickels());
	ASSERT_EQ(4, m1.getCents());

	m1 = m1 - n2;
	//4.04

	ASSERT_EQ(4, m1.getDollars());
	ASSERT_EQ(0, m1.getQuarters());
	ASSERT_EQ(0, m1.getNickels());
	ASSERT_EQ(4, m1.getCents());

}

TEST(Money, AdditionSubtractionQuarter) {

	Money m1(6.83);
	Quarter q1(3);
	Quarter q2(5);

	m1 = m1 + q1;
	//7.58

	ASSERT_EQ(7, m1.getDollars());
	ASSERT_EQ(2, m1.getQuarters());
	ASSERT_EQ(1, m1.getNickels());
	ASSERT_EQ(3, m1.getCents());

	m1 = m1 - q2;
	//6.33

	ASSERT_EQ(6, m1.getDollars());
	ASSERT_EQ(1, m1.getQuarters());
	ASSERT_EQ(1, m1.getNickels());
	ASSERT_EQ(3, m1.getCents());

}

TEST(Money, AdditionSubtractionCent) {

	Money m1(3);
	Cent c1(56);
	Cent c2(24);

	m1 = m1 + c1;
	//3.56

	ASSERT_EQ(3, m1.getDollars());
	ASSERT_EQ(2, m1.getQuarters());
	ASSERT_EQ(1, m1.getNickels());
	ASSERT_EQ(1, m1.getCents());

	m1 = m1 - c2;
	//3.32

	ASSERT_EQ(3, m1.getDollars());
	ASSERT_EQ(1, m1.getQuarters());
	ASSERT_EQ(1, m1.getNickels());
	ASSERT_EQ(2, m1.getCents());

}

TEST(Money, Rounding) {

	Money m1(6.78);
	Money m2(15.55);

	m1++;
	m2--;

	ASSERT_EQ(7, m1.getDollars());
	ASSERT_EQ(0, m1.getQuarters());
	ASSERT_EQ(0, m1.getNickels());
	ASSERT_EQ(0, m1.getCents());

	ASSERT_EQ(15, m2.getDollars());
	ASSERT_EQ(2, m2.getQuarters());
	ASSERT_EQ(0, m2.getNickels());
	ASSERT_EQ(0, m2.getCents());

}

TEST(Money, Comparison) {

	Money m1(9.49);
	Money m2(18.50);
	Money m3(9.49);

	ASSERT_EQ(1, m2 >= m1);
	ASSERT_EQ(1, m1 <= m3);
	ASSERT_EQ(0, m1 >= m2);

}

TEST(Money, QuartersAndNickels) {

	Money m1(3.66);
	Money m2(4.27);

	Quarter q;
	Nickel n;

	q = !m1;

	ASSERT_EQ(14, q.getQuarters());

	n = ~m2;

	ASSERT_EQ(85, n.getNickels());

}

TEST(Money, DivideAndMultiply) {

	Money m1(53.44);
	Money m2(10.22);
	Money m3;

	m3 = m1 / 6;
	//7.63

	ASSERT_EQ(7, m3.getDollars());
	ASSERT_EQ(2, m3.getQuarters());
	ASSERT_EQ(2, m3.getNickels());
	ASSERT_EQ(3, m3.getCents());

	m3 = m2 * 2;
	//20.44

	ASSERT_EQ(20, m3.getDollars());
	ASSERT_EQ(1, m3.getQuarters());
	ASSERT_EQ(3, m3.getNickels());
	ASSERT_EQ(4, m3.getCents());

}

// Q2: Date

TEST(Date, Constructors) {

	Date d(1947, 8, 14);

	ASSERT_EQ(1974, d.getYear());
	ASSERT_EQ(8, d.getMonth());
	ASSERT_EQ(14, d.getDay());

}

TEST(Date, AssignmentOperator) {

	Date d1(1947, 8, 14);
	Date d2(1000, 1, 1);

	d2 = d1;

	ASSERT_EQ(1974, d2.getYear());
	ASSERT_EQ(8, d2.getMonth());
	ASSERT_EQ(14, d2.getDay());

}

TEST(Date, IntArithmetic) {

	Date d1(1947, 8, 14);

	d1 = d1 + 222;

	ASSERT_EQ(1948, d1.getYear());
	ASSERT_EQ(3, d1.getMonth());
	ASSERT_EQ(23, d1.getDay());

	d1 = d1 - 450;

	ASSERT_EQ(1946, d1.getYear());
	ASSERT_EQ(12, d1.getMonth());
	ASSERT_EQ(29, d1.getDay());

}

TEST(Date, DateArithmetic) {

	Date d1(2024, 6, 19);
	Date d2(1930, 1, 1);
	int difference;
	Date d3(1000, 1, 1);
	d3 = d2 + d1;

	ASSERT_EQ(3954, d3.getYear());
	ASSERT_EQ(7, d3.getMonth());
	ASSERT_EQ(20, d3.getDay());

	difference = d2 - d1;

	ASSERT_EQ(34503, difference);

}

TEST(Date, Comparison) {

	Date d1(1947, 5, 10);
	Date d2(1974, 8, 20);
	Date d3(1974, 8, 20);

	ASSERT_EQ(1, d2 > d1);
	ASSERT_EQ(1, d3 <= d2);
	ASSERT_EQ(1, d1 < d2);
	ASSERT_EQ(1, d2 >= d3);

}

TEST(Date, Equalility) {

	Date d1(1947, 5, 10);
	Date d2(1974, 8, 20);
	Date d3(1974, 8, 20);

	ASSERT_EQ(1, d1 != d2);
	ASSERT_EQ(1, d2 == d3);

}

TEST(Date, LeapYear) {

	Date d1(1996, 5, 29);
	Date d2(1995, 8, 16);

	ASSERT_EQ(1, d1.isLeapYear());
	ASSERT_EQ(0, d2.isLeapYear());

}

TEST(Date, toString) {

	Date d1(1996, 5, 29);

	ASSERT_EQ(0, strcmp("1996/05/29", d1.ToString()));

}


// Q3: BigInt  

TEST(BigInt, Constructors) {
	string expected1 = "3274194613278946789126347892136497812364981326";
	string expected2 = "82347047890123470289374";
	BigInt a(expected1);
	BigInt b("82347047890123470289374");
	BigInt c(a);
	string s1 = (string)a;
	string s2 = (string)b;
	string s3 = (string)c;
	ASSERT_EQ(0, s1.compare(expected1));
	ASSERT_EQ(0, s2.compare(expected2));
	ASSERT_EQ(0, s3.compare(expected1));

}
//TEST(BigInt, Addition) {
//	string str = "1212121212121212";
//	BigInt a(str);
//	BigInt b = a + 2;
//	BigInt c;
//	c = a + b;
//	BigInt d(2);
//	d += a;
//
//	string s1 = (string)b; string expected1 = "1212121212121214";
//	string s2 = (string)c; string expected2 = "2424242424242426";
//	string s3 = (string)d; string expected3 = "1212121212121214";
//
//	ASSERT_EQ(0, s1.compare(expected1));
//	ASSERT_EQ(0, s2.compare(expected2));
//	ASSERT_EQ(0, s3.compare(expected3));
//
//
//}
//
//TEST(BigInt, Subtraction) {
//	string str = "1212121212121214";
//	BigInt a(str);
//	BigInt b = a - 2;
//	BigInt c;
//	c = a - b;
//	BigInt d(3);
//	a -= d;
//
//	string s1 = (string)b; string expected1 = "1212121212121212";
//	string s2 = (string)c; string expected2 = "2";
//	string s3 = (string)a; string expected3 = "1212121212121211";
//
//	ASSERT_EQ(0, s1.compare(expected1));
//	ASSERT_EQ(0, s2.compare(expected2));
//	ASSERT_EQ(0, s3.compare(expected3));
//
//}
//TEST(BigInt, Mul) {
//	string str = "1428707024381847923809472381907402137489012374012074";
//	BigInt a(str);
//	BigInt b;
//	BigInt c = a * b;
//
//	BigInt d(1234);
//	a *= d;
//
//	string s1 = (string)c; string expected1 = "0";
//	string s2 = (string)a; string expected2 = "1763024468087200337980888919273734237661441269530899316";
//
//	ASSERT_EQ(0, s1.compare(expected1));
//	ASSERT_EQ(0, s2.compare(expected2));
//
//
//}

TEST(BigInt, LogicalOperators) {
	string str1 = "1428707024381847923809472381907402137489012374012074";
	string str2 = "1763024468087200337980888919273734237661441269530899316";
	BigInt a(str1);
	BigInt c(str1);
	BigInt b(str2);

	ASSERT_EQ(true, a == c);
	ASSERT_EQ(false, a == b);
	ASSERT_EQ(true, a != b);
	ASSERT_EQ(true, a <= b);
	ASSERT_EQ(false, a >= b);
	ASSERT_EQ(false, a > b);
	ASSERT_EQ(true, a < b);


}

//TEST(BigInt, UnaryOperators) {
//	string str1 = "1212121212121212";
//	string str2 = "1212121212121214";
//	BigInt a(str1);
//	BigInt c(str1);
//	BigInt b(str2);
//	a++;
//	string s1 = (string)a; string expected1 = "1212121212121213";
//	ASSERT_EQ(0, s1.compare(expected1));
//
//	--a;
//	string s2 = (string)a; string expected2 = "1212121212121212";
//	ASSERT_EQ(0, s2.compare(expected2));
//
//	++b;
//	string s3 = (string)b; string expected3 = "1212121212121215";
//	ASSERT_EQ(0, s3.compare(expected3));
//
//	b--;
//	string s4 = (string)b; string expected4 = "1212121212121214";
//	ASSERT_EQ(0, s4.compare(expected4));
//
//
//
//}

TEST(BigInt, InputOutput) {
	BigInt s1;
	cin >> s1;// input "8989867" on terminal
	BigInt s2("8989867");
	cout << s1;
	ASSERT_EQ(true, s2 == s1);

}


// Q4: Polynominal
TEST(Polynominal, Constructors) {
	Polynomial x(2);
	cin >> x;// input 2x^2 + 2x + 2
	string s1 = (string)x;
	string s2 = "2x^2 + 2x + 2";
	ASSERT_EQ(0, s1.compare(s2));
	cout << x;
	Polynomial z(x);
	string s3 = (string)z;

	ASSERT_EQ(0, s3.compare(s2));
	cout << z;

}

TEST(Polynominal, ArithmeticOperatorsplus) {
	Polynomial x(2);
	cin >> x;// input 2x^2 + 2x + 2
	string s1 = (string)x;
	string s2 = "2x^2 + 2x + 2";
	ASSERT_EQ(0, s1.compare(s2));
	cout << x;
	Polynomial z(1);
	cin >> z;// input x + 3

	Polynomial y = x + z;
	//cout<<y;
	string s3 = (string)y;
	string s4 = "2x^2 + 3x + 5";
	ASSERT_EQ(0, s3.compare(s2));
	y += z;

	string s5 = (string)y;
	string s6 = "2x^2 + 4x + 8";
	ASSERT_EQ(0, s5.compare(s6));


}

TEST(Polynominal, ArithmeticOperatorssub) {
	Polynomial x(2);
	cin >> x;// input 2x^2 + 2x + 2
	string s1 = (string)x;
	string s2 = "2x^2 + 2x + 2";
	ASSERT_EQ(0, s1.compare(s2));
	cout << x;
	Polynomial z(1);
	cin >> z;// input 2x + 2

	Polynomial y = x - z;
	//cout<<y;
	string s3 = (string)y;
	string s4 = "2x^2";
	ASSERT_EQ(0, s3.compare(s2));

	y -= z;

	string s5 = (string)y;
	string s6 = "2x^2 - 2x - 2";
	ASSERT_EQ(0, s5.compare(s6));

}

TEST(Polynominal, Equalility) {
	Polynomial x(2);
	cin >> x;// input 2x^2 + 2x + 2
	string s1 = (string)x;
	string s2 = "2x^2 + 2x + 2";
	ASSERT_EQ(0, s1.compare(s2));
	cout << x;
	Polynomial z(2);
	cin >> z;// input 2x^2 + 2x + 2
	ASSERT_EQ(true, z == x);

}

// Q5: Bouquet


TEST(Bouquet, Constructors) {
	Flower r1("Rose", "Yellow", 1.5);
	Flower r2("Rose", "Yellow", 3.0, true);
	Flower r3("Rose", "Red", 2.0, true, true);

	string s1 = (string)r1;
	string s2 = "Rose Yellow 0, Price: 1.5 Rs.";
	string s3 = (string)r2;
	string s4 = "Rose Yellow 1, Price: 3.0 Rs.";

	ASSERT_EQ(0, s1.compare(s2));
	ASSERT_EQ(0, s3.compare(s4));

	cout << r3 << endl;
	Bouquet b1;
	string s5 = (string)b1;
	string s6 = "Still no flower in the bouquet";
	ASSERT_EQ(0, s6.compare(s5));


}

TEST(Bouquet, AddRemoveFlower) {
	Flower r1("Rose", "Yellow", 1.5);
	Flower r2("Rose", "Yellow", 3.0, true);
	Flower r3("Rose", "Red", 2.0, true, true);


	Bouquet b1;
	b1 += r1; // add one Flower of r1 type
	string s1 = (string)b1;
	string s2 = "Rose Yellow 0, Price: 1.5 Rs.\nTotal Price: 1.5 Rs.";
	ASSERT_EQ(0, s1.compare(s2));
	b1 = b1 - r1; // Delete all the Flowers of type r1
	string s3 = (string)b1;
	string s4 = "Still no flower in the bouquet";
	ASSERT_EQ(0, s3.compare(s4));
	b1 += r1; // add another Flower of r1
	b1 += r2;
	b1 += r3;
	cout << b1 << endl;

	Bouquet b2;
	b2 = b1 + r1; // Add one Flower of type r1
	cout << b2 << endl;

	// Delete all the perfumed flowers from the bouquet.
	b2 -= r2;
	cout << b2 << endl;
	b2 -= r3;
	cout << b2 << endl;

}
int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
