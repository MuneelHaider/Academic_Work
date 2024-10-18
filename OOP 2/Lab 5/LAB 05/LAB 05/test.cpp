#include "pch.h"
#include "Muneel Haider 21i-0640 LAB 05.h"

TEST(Task1, Test1) {

    ASSERT_EQ(60, LCM(15,20));
}
TEST(Task1, Test2) {

    ASSERT_EQ(75, LCM(15, 25));
}
TEST(Task1, Test3) {

    ASSERT_EQ(35, LCM(5, 7));
}

TEST(Task2, Test1) {

    ASSERT_EQ(16, Power(4, 2));
}
TEST(Task2, Test2) {

    ASSERT_EQ(1, Power(3, 0));
}
TEST(Task2, Test3) {

    ASSERT_EQ(32, Power(2, 5));
}

TEST(Task3, Test1) {
    char** sentence = new char* [3];
    for (int i = 0; i < 3; i++)
    {
        *(sentence + i) = new char[7];
    }
    *sentence = "Cat";
    *(sentence + 1) = "is";
    *(sentence + 2) = "running";
    sentence = reverse_sentence(sentence, 3, 7);

    ASSERT_EQ(sentence[0][0], 'r');
    ASSERT_EQ(sentence[0][1], 'u');
    ASSERT_EQ(sentence[0][2], 'n');
    ASSERT_EQ(sentence[0][3], 'n');
    ASSERT_EQ(sentence[0][4], 'i');
    ASSERT_EQ(sentence[0][5], 'n');
    ASSERT_EQ(sentence[0][6], 'g');

    ASSERT_EQ(sentence[1][0], 'i');
    ASSERT_EQ(sentence[1][1], 's');

    ASSERT_EQ(sentence[2][0], 'C');
    ASSERT_EQ(sentence[2][1], 'a');
    ASSERT_EQ(sentence[2][2], 't');


}
TEST(Task3, Test2) {
    char** sentence = new char* [4];
    for (int i = 0; i < 5; i++)
    {
        *(sentence + i) = new char[7];
    }
    *sentence = "This";
    *(sentence + 1) = "is";
    *(sentence + 2) = "a";
    *(sentence + 3) = "flower";
    int i = 0; //for indexing
    sentence = reverse_sentence(sentence, 4, 7);

    ASSERT_EQ(sentence[0][0], 'f');
    ASSERT_EQ(sentence[0][1], 'l');
    ASSERT_EQ(sentence[0][2], 'o');
    ASSERT_EQ(sentence[0][3], 'w');
    ASSERT_EQ(sentence[0][4], 'e');
    ASSERT_EQ(sentence[0][5], 'r');

    ASSERT_EQ(sentence[1][0], 'a');

    ASSERT_EQ(sentence[2][0], 'i');
    ASSERT_EQ(sentence[2][1], 's');

    ASSERT_EQ(sentence[3][0], 'T');
    ASSERT_EQ(sentence[3][1], 'h');
    ASSERT_EQ(sentence[3][2], 'i');
    ASSERT_EQ(sentence[3][3], 's');
}

TEST(Task4, Test1) {
    int* result = new int[10];
    result = sequence(13, result, 10);
    ASSERT_EQ(result[0], 13);
    ASSERT_EQ(result[1], 40);
    ASSERT_EQ(result[2], 20);
    ASSERT_EQ(result[3], 10);
    ASSERT_EQ(result[4], 5);
    ASSERT_EQ(result[5], 16);
    ASSERT_EQ(result[6], 8);
    ASSERT_EQ(result[7], 4);
    ASSERT_EQ(result[8], 2);
    ASSERT_EQ(result[9], 1);
}
 
TEST(Task4, Test2) {

    int* result = new int[16];
    result = sequence(7, result, 16);
    ASSERT_EQ(result[0], 7);
    ASSERT_EQ(result[1], 22);
    ASSERT_EQ(result[2], 11);
    ASSERT_EQ(result[3], 34);
    ASSERT_EQ(result[4], 17);
    ASSERT_EQ(result[5], 52);
    ASSERT_EQ(result[6], 26);
    ASSERT_EQ(result[7], 13);
    ASSERT_EQ(result[8], 40);
    ASSERT_EQ(result[9], 20);
    ASSERT_EQ(result[10], 10);
    ASSERT_EQ(result[11], 5);
    ASSERT_EQ(result[12], 16);
    ASSERT_EQ(result[13], 8);
    ASSERT_EQ(result[14], 4);
    ASSERT_EQ(result[15], 2);
    ASSERT_EQ(result[16], 1);
} 