#include <iostream>
#include <string>
using namespace std;

/*

    Muneel Haider
    21i-0640
    Assignment 3
    Algorithms - Section D

*/

/*                  Q1                      */

bool areEquivalent(const string& referenceDNA, const string& equivalentRule, const string& pairsToMatch) {

    int hyphenPos = equivalentRule.find('-');

    string part1 = equivalentRule.substr(0, hyphenPos);
    string part2 = equivalentRule.substr(hyphenPos + 1);

    if (part1.length() != referenceDNA.length() || part2.length() != referenceDNA.length()) {

        return false;
    }

    char translationMap[256] = { 0 };

    for (int i = 0; i < referenceDNA.length(); i++) {

        translationMap[part1[i]] = part2[i];
    }

    for (int i = 0; i < pairsToMatch.length(); i += 2) {

        if (i + 1 >= pairsToMatch.length()) {

            return false;
        }

        char translatedChar = translationMap[pairsToMatch[i]];

        if (translatedChar == 0 || translatedChar != pairsToMatch[i + 1]) {

            return false;
        }
    }

    return true;
}

/********************************************************************************************/
/********************************************************************************************/

/*                  Q2                      */
bool matchPattern(const string& text, const string& pattern) {

    int option = 0;
    int textLength = text.length();
    int patternLength = pattern.length();

    for (int i = 0; i < textLength; i++) {
        
        switch (option) {
        
        case 0:
        
            if (text[i] == 'b' && i + 1 < textLength && text[i + 1] == 'a') {
            
                option = 1;
                i++;
            }

            break;
        
        case 1:
        
            if (text[i] == 'a' || text[i] == 'b' || text[i] == 'c') {
            
                option = 2;
            }
            else {
             
                option = 0;
            }
            break;

        case 2:
            
            if (text[i] == 'd' && i + 1 < textLength && text[i + 1] == 'b') {
            
                return 1;
            }
            else if (text[i] != 'a' && text[i] != 'b' && text[i] != 'c') {
                
                option = 0;
            }
            
            break;
        }
    }

    return 0;
}

/********************************************************************************************/
/********************************************************************************************/

/*                  Q3                      */

string longestPalindromeSubsequence(const string& input) {
    
    int n = input.length();

    if (n == 0) {

        return "";
    }

    int dp[50][50] = { 0 };

    if (n > 50) {
        
        cout << "Input string is too long for the current implementation." << endl;
        return "";
    }

    for (int i = 0; i < n; i++) {
        
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        
        for (int i = 0; i <= n - len; i++) {
        
            int j = i + len - 1;
            
            if (input[i] == input[j] && len == 2) {
            
                dp[i][j] = 2;
            }
            else if (input[i] == input[j]) {
                
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    string result = "";
    
    int i = 0;
    int j = n - 1;
    
    while (i <= j) {
    
        if (input[i] == input[j]) {
        
            result += input[i];
            i++;
            j--;
        }
        else if (dp[i + 1][j] > dp[i][j - 1]) {
            
            i++;
        }
        else {
            
            j--;
        }
    }

    string reverseHalf = result;
    
    if (i - 1 >= 0 && j + 1 < n && input[i - 1] == input[j + 1]) {
    
        reverseHalf.erase(reverseHalf.length() - 1, 1);
    }

    for (int k = reverseHalf.length() - 1; k >= 0; k--) {
        
        result += reverseHalf[k];
    }

    return result;
}

/********************************************************************************************/
/********************************************************************************************/

/*                  Q4                      */

int longestContiguousSubstring(const string& input) {
   
    int n = input.length();
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
    
        string left = input.substr(0, i);
        string right = input.substr(i);
        
        reverse(right.begin(), right.end());

        int lenLeft = left.length();
        int lenRight = right.length();
        
        int dp[50][50] = { 0 };

        for (int l = 1; l <= lenLeft; l++) {
        
            for (int r = 1; r <= lenRight; r++) {
            
                if (left[l - 1] == right[r - 1]) {
                
                    dp[l][r] = dp[l - 1][r - 1] + 1;
                    maxLength = max(maxLength, dp[l][r]);
                }
                else {
                    
                    dp[l][r] = 0;
                }
            }
        }
    }

    return maxLength;
}