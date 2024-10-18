#include "pch.h"
#include <gtest/gtest.h>
#include <cstring>

#include "i21-0640_Assignment3.h".h"

//----------Problem No. 1----------
// 0 -> False
// 1 -> Yes

TEST(Q1, first) {
    
    string referenceDNA = "ATCGTA";
    string equivalentRule = "ATCGTA-TACGAT";
    string pairsToMatch = "AATCGTA-TTACGAT";

    int expected = 1;
    ASSERT_EQ(expected, areEquivalent(referenceDNA, equivalentRule, pairsToMatch));
}

TEST(Q1, second) {

    string referenceDNA = "ACCTAG";
    string equivalentRule = "ACCTAG-TGGATC";
    string pairsToMatch = "ACCTAGTGGATC-TGGATCTAGGCT";

    int expected = 0;
    ASSERT_EQ(expected, areEquivalent(referenceDNA, equivalentRule, pairsToMatch));
}

TEST(Q1, third) {

    string referenceDNA = "TCGA";
    string equivalentRule = "TCGA-AGCT";
    string pairsToMatch = "TACGAGCT-TAGAGCTC";

    int expected = 0;
    ASSERT_EQ(expected, areEquivalent(referenceDNA, equivalentRule, pairsToMatch));
}

TEST(Q1, fourth) {

    string referenceDNA = "ACGT";
    string equivalentRule = "ACGT-TGCA";
    string pairsToMatch = "ACGTTGCA-TGCAGACTG";

    int expected = 0;
    ASSERT_EQ(expected, areEquivalent(referenceDNA, equivalentRule, pairsToMatch));
}

TEST(Q1, fifth) {

    string referenceDNA = "AGC";
    string equivalentRule = "AGC-TCG";
    string pairsToMatch = "AGCTCG-TCGTGC";

    int expected = 1;
    ASSERT_EQ(expected, areEquivalent(referenceDNA, equivalentRule, pairsToMatch));
}




//
////----------Problem No. 2----------
// Text file (regularExpression.txt)
TEST(Q2, Pattern1String1) {
    EXPECT_TRUE(matchPattern("ababbabcabcbdbbc", "ba(a|b|c)+db"));
}

// Test case for the pattern "ba(a|b|c)+db" and string "abacccccba"
TEST(Q2, Pattern1String2) {
    EXPECT_FALSE(matchPattern("abacccccbabd", "ba(a|b|c)+db"));
}

// Test case for the pattern "ba(a|b|c)+db+(d|a)+bc" and string "ababbabcabcbdbaaddadadabcde"
TEST(Q2, Pattern2String2) {
    EXPECT_TRUE(matchPattern("ababbabcabcbdbaaddadadabcde", "ba(a|b|c)+db+(d|a)+bc"));
}

// Test case for the pattern "ba(a|b|c)+db+(d|a)+bc" and string "aabaccdbddaabbc"
TEST(Q2, Pattern2String1) {
    EXPECT_FALSE(matchPattern("aabaccdbddaabbc", "ba(a|b|c)+db+(d|a)+bc"));
}
//
//
//
//
//
//
////----------Problem No. 3----------
TEST(Q3, SingleCharacter) {
    string input = "a";
    string expected = "a";
    ASSERT_EQ(expected, longestPalindromeSubsequence(input));
}

TEST(Q3, BasicCase) {
    string input = "character";
    string expected = "carac";
    ASSERT_EQ(expected, longestPalindromeSubsequence(input));
}

TEST(Q3, BasicCase2) {
    string input = "programming";
    string expected = "gmmg";  // The correct expected result
    ASSERT_EQ(expected, longestPalindromeSubsequence(input));
}

TEST(Q3, PalindromeItself) {
    string input = "AibohphobiA";
    string expected = "AibohphobiA";
    ASSERT_EQ(expected, longestPalindromeSubsequence(input));
}

TEST(Q3, NoPalindrome) {
    string input = "abcdefgh";
    string expected = "a";
    ASSERT_EQ(expected, longestPalindromeSubsequence(input));
}
//
//
//
//
//
////----------Problem No. 4----------
TEST(Q4, NoCommonSubstring) {
    string input = "ALGORITHM";
    int expected = 0;
    ASSERT_EQ(expected, longestContiguousSubstring(input));
}

TEST(Q4, SingleCharacter) {
    string input = "RECURSION";
    int expected = 1;
    ASSERT_EQ(expected, longestContiguousSubstring(input));
}

TEST(Q4, CommonSubstring) {
    string input = "DYNAMICPROGRAMMINGMANYTIMES";
    int expected = 4;
    ASSERT_EQ(expected, longestContiguousSubstring(input));
}

TEST(Q4, CommonSubstring2) {
    string input = "MISSISSIPPI";
    int expected = 3;
    ASSERT_EQ(expected, longestContiguousSubstring(input));
}

TEST(Q4, EntireString) {
    string input = "LEVEL";
    int expected = 2;
    ASSERT_EQ(expected, longestContiguousSubstring(input));
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
