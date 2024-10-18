#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/*
    Muneel Haider       21i-0640
    Muhammad Abdullah   21i-0643
    Abdullah Zahoor     21i-2481
    Algo Project - CS 23
*/

const int maximumNodes = 26;

int nodeToIndex(char node) {

    return node - 'A';
}

double calculateAverageTime(const string &filename) {

    ifstream file(filename);

    if (!file.is_open()) {

        cout << "Error opening file: " << filename << endl;
        return -1;
    }

    int distances[maximumNodes][maximumNodes] = {0};
    int sumOfTimes = 0, numberOfPaths = 0;
    
    string line;

    while (getline(file, line) && !line.empty()) {

        if (isdigit(line[0])) {
         
            break;
        }

        char node1, node2, hyphen;
        int distance;

        stringstream ss(line);
        
        ss >> node1 >> hyphen >> node2 >> distance;
        
        distances[nodeToIndex(node1)][nodeToIndex(node2)] = distance;
        distances[nodeToIndex(node2)][nodeToIndex(node1)] = distance;

        cout << "Distance: " << node1 << "-" << node2 << " = " << distance << endl;
    }

    while (getline(file, line)) {

        if (line.empty()) {
         
            continue;
        }
        if (isdigit(line[0])) {
         
            break;
        }

        stringstream ss(line);
        
        char node1, node2, hyphen;
        
        int pathCost = 0;
        
        ss >> node1;

        cout << "Path: " << node1;

        while (ss >> hyphen >> node2) {

            pathCost += distances[nodeToIndex(node1)][nodeToIndex(node2)];
            node1 = node2;
            cout << "-" << node2;
        }

        sumOfTimes += pathCost;
        numberOfPaths++;

        cout << " (Cost: " << pathCost << ")" << endl;
    }

    file.close();

    if (numberOfPaths == 0) {

        return 0;
    }

    return static_cast<double>(sumOfTimes) / numberOfPaths;
}

int main() {

    string filename = "testcase3.txt";

    double averageTime = calculateAverageTime(filename);

    if (averageTime >= 0) {

        cout << "Average Time to Move Between Locations: " << averageTime << " minutes" << endl << endl;
    }
    else {

        cout << "An error occurred." << endl;
    }

    return 0;
}