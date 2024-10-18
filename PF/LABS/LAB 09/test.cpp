#include "pch.h"
#include "Part A.h"
#include "Part B.h"

TEST(Task1, Test1) {
    Distance d1(11, 11);
    ++d1;
    EXPECT_EQ(13, d1.getFeets());
    EXPECT_EQ(0, d1.getInches());
}

TEST(Task1, Test2) {
    Distance d2(12, 11);
    d2++;
    EXPECT_EQ(14, d2.getFeets());
    EXPECT_EQ(0, d2.getInches());
}

TEST(Task1, Test3) {
    Distance d2(12, 11);
    d2--;
    EXPECT_EQ(11, d2.getFeets());
    EXPECT_EQ(10, d2.getInches());
}

TEST(Task1, Test4) {
    Distance d2(12, 11);
    --d2;
    EXPECT_EQ(11, d2.getFeets());
    EXPECT_EQ(10, d2.getInches());
}

TEST(Task2, Test1) {
    Student s1("Muneel", 0640, 2, 3);

    cout << endl << endl;

    cin >> s1;

    cout << endl << endl << s1 << endl;
}