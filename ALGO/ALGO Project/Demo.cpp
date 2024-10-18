#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool isPatternPresent(const vector<string>& text, const string& pattern, int minOccurrences) {
    int n = text.size();
    int m = pattern.size();

    int occurrences = 0;

    for (int i = 0; i <= n - m; ++i) {

        for (int j = 0; j <= n - m; ++j) {

            bool isMatch = true;

            for (int k = 0; k < m; ++k) {

                if (text[i + k].substr(j + k, m) != pattern) {

                    isMatch = false;
                    break;
                }
            }

            if (isMatch) {

                ++occurrences;
            }
        }
    }

    return occurrences >= minOccurrences;
}



bool readTestCase(const string& filename, vector<string>& text, string& pattern, int& minOccurrences) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }

    string line;
    getline(file, line); // Read the first line to get dimensions

    size_t pos1 = line.find('(');
    size_t pos2 = line.find('x', pos1);
    size_t pos3 = line.find(')', pos2);

    if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) {
        cerr << "Error reading dimensions from the file." << endl;
        return false;
    }

    int n = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
    text.resize(n);

    for (int i = 0; i < n; ++i) {
        if (!getline(file, text[i])) {
            cerr << "Error reading text from the file." << endl;
            return false;
        }
    }

    if (!(file >> pattern >> minOccurrences)) {
        cerr << "Error reading pattern and/or minimum occurrences from the file." << endl;
        return false;
    }

    cout << "Dimensions: " << n << "x" << n << endl;
    cout << "Text: " << endl;
    for (const string& lineItem : text) {
        cout << lineItem << endl;
    }
    cout << "Pattern: " << pattern << endl;
    cout << "Minimum Occurrences: " << minOccurrences << endl;

    return true;
}

int main() {
    vector<string> text;
    string pattern;
    int minOccurrences;

    if (readTestCase("TestCase2.txt", text, pattern, minOccurrences)) {
        cout << "Pattern is " << (isPatternPresent(text, pattern, minOccurrences) ? "" : "not ") << "present diagonally at least " << minOccurrences << " times." << endl;
    }

    return 0;
}
