#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool matchFirstPattern(const string& str) {
    int state = 0;
#include <iostream>
#include <string>

    using namespace std;

    bool areEquivalent(const string & referenceDNA, const string & equivalentRule, const string & pairsToMatch) {
        int ruleLength = equivalentRule.length();

        // Check if the length of the reference DNA and equivalent rule are the same
        if (referenceDNA.length() != ruleLength) {
            return false;
        }

        // Create a translation map based on the reference DNA and equivalent rule
        char translationMap[256] = { 0 };
        for (int i = 0; i < ruleLength; ++i) {
            translationMap[referenceDNA[i]] = equivalentRule[i];
        }

        // Iterate through the pairs to match and check equivalence
        int pairLength = pairsToMatch.length();
        int i = 0, j = 0;
        while (i < pairLength) {
            char seq1Char = pairsToMatch[i];
            char seq2Char = pairsToMatch[i + 1];

            // Check if both characters are valid DNA nucleotides
            if (seq1Char != 'A' && seq1Char != 'T' && seq1Char != 'C' && seq1Char != 'G' &&
                seq2Char != 'A' && seq2Char != 'T' && seq2Char != 'C' && seq2Char != 'G') {
                return false;
            }

            // Translate seq1Char using the translation map
            char translatedSeq1Char = translationMap[seq1Char];

            // Check if the translation matches seq2Char
            if (translatedSeq1Char != seq2Char) {
                return false;
            }

            i += 2;
        }

        return true;
    }

    for (char ch : str) {
        switch (state) {
        case 0: if (ch == 'b') state = 1; break;
        case 1: if (ch == 'a') state = 2; break;
        case 2: if (ch == 'a' || ch == 'b' || ch == 'c') state = 3; else return false; break;
        case 3:
            if (ch == 'd') state = 4;
            else if (ch != 'a' && ch != 'b' && ch != 'c') return false;
            break;
        case 4: if (ch == 'b') return true; else return false;
        }
    }
    return false;
}

bool matchSecondPattern(const string& str) {
    int state = 0;

    for (char ch : str) {
        switch (state) {
        case 0: if (ch == 'b') state = 1; break;
        case 1: if (ch == 'a') state = 2; break;
        case 2: if (ch == 'a' || ch == 'b' || ch != 'c') state = 3; else return false; break;
        case 3:
            if (ch == 'd') state = 4;
            else if (ch != 'a' && ch != 'b' && ch != 'c') return false;
            break;
        case 4:
            if (ch == 'b') state = 5;
            else if (ch != 'd' && ch != 'a') return false;
            break;
        case 5:
            if (ch == 'd' || ch == 'a') state = 6;
            else return false;
            break;
        case 6:
            if (ch == 'b') state = 7;
            else if (ch != 'd' && ch != 'a') return false;
            break;
        case 7: if (ch == 'c') return true; else return false;
        }
    }
    return false;
}

int main() {
    ifstream file("Problem2.txt");
    if (!file) {
        cerr << "File could not be opened" << endl;
        return 1;
    }

    string line, pattern, str;
    int expectedOutput;

    while (getline(file, line)) {
        // Check if the line is a pattern
        if (line.find('+') != string::npos || line.find('(') != string::npos) {
            pattern = line;
            continue;
        }

        // Read the test string and expected output
        str = line;
        if (!(file >> expectedOutput)) break;
        file.ignore(); // To ignore the newline after the integer

        bool result;
        if (pattern == "ba(a|b|c)+db") {
            result = matchFirstPattern(str);
        }
        else if (pattern == "ba(a|b|c)+db+(d|a)+bc") {
            result = matchSecondPattern(str);
        }
        else {
            cerr << "Unknown pattern: " << pattern << endl;
            continue;
        }

        cout << "String: " << str << " - Pattern Match: " << result;
        cout << " - Expected: " << expectedOutput << (result == expectedOutput ? " (Pass)" : " (Fail)") << endl;
    }

    file.close();
    return 0;
}
