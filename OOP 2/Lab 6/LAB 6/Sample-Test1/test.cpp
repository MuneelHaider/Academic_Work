#include "pch.h"
#include "LAB 06.h"

//---Tests for Task02---//
TEST(Lab06, Task01_1) {
    Marks m1;
    float arr1[] = { 44.53, 76.35, 81.03, 67.64 };
    EXPECT_EQ(assignMarks("Salman-Iqbal", m1, arr1), true);
    EXPECT_EQ(getName(m1), "Salman-Iqbal");
}
TEST(Lab06, Task01_2) {
    Marks t1;
    float arr[] = { 44.53, 76.35, 81.03, 67.64 };
    assignMarks("Salman-Iqbal", t1, arr);
    EXPECT_EQ(getTotal(t1), 268);
}
TEST(Lab06, Task01_3) {
    Marks s1;
    float arr[] = { 44.53, 76.35, 81.03, 67.64 };
    assignMarks("Salman-Iqbal", s1, arr);
    EXPECT_EQ((int)getPercentage(s1), 67);
}

//---Tests for Task03---//
Time a, b, c;
TEST(Lab06, Task03_1) {
    EXPECT_EQ(initialize(a, 03, 05, 17), true);
    EXPECT_EQ(initialize(b, 01, 37, 54), true);
    EXPECT_EQ(initialize(c, 07, 44, 62), false);
}
TEST(Lab06, Task03_2) {
    c = difference(a, b);
    EXPECT_EQ(c.hours, 2);
    EXPECT_EQ(c.minutes, 32);
    EXPECT_EQ(c.seconds, 37);
}

////---Test for Task04---//
//TEST(Lab06, Task04) {
//    Item item1, item2, item3;
//    writeItem(item1, "Oranges", 3, 10);
//    writeItem(item2, "Banana", 8, 31);
//    writeItem(item3, "Oranges", 17, 30);
//    EXPECT_EQ(sumItems(item1, item3), true);
//    EXPECT_EQ(item1.count.dozen, 23);
//    EXPECT_EQ(item1.count.units, 4);
//    EXPECT_EQ(sumItems(item2, item1), false);
//    EXPECT_EQ(item2.count.dozen, 8);
//    EXPECT_EQ(item2.count.units, 31);
//}