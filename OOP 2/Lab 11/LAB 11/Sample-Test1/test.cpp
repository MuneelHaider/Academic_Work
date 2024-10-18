#include "pch.h"
#include "Q1.h"
#include "Q3.h"

TEST(Task1, AccountBalanceTestCase1) {
	Account account(10000, 1000);
	EXPECT_EQ(9000, --account);
	EXPECT_EQ(9000, ~account);
	EXPECT_EQ(11000, account += 2000);
}
TEST(Task1, AccountBalanceTestCase2) {
	Account account(10000, 1000);
	EXPECT_EQ(8000, account -= 2000);
	EXPECT_EQ(8000, ~account);
}
TEST(Task2, TestingFriendFunctions) {
	Account a1(5000, 1000), a2(4000, 1000);
	Account a3 = sumAccountsIntoNewAccount(a1, a2);
	EXPECT_EQ(5000, ~a1);
	EXPECT_EQ(4000, ~a2);
	EXPECT_EQ(9000, ~sumAccountsIntoNewAccount(a1, a2));
	a3 -= 4000;
	EXPECT_EQ(5000, ~a3);
}
