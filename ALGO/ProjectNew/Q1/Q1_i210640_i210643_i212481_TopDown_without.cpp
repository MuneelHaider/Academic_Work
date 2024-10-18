#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

/*
    Muneel Haider       21i-0640
    Muhammad Abdullah   21i-0643
    Abdullah Zahoor     21i-2481
    Algo Project - CS 23

    Recursive Top-Down Algorithm without Memoization
*/

const int maximumSize = 250;
const int maximumPrices = 50;

string filename = "TestCase3.txt";

int prices[maximumPrices][3];

int max(int a, int b) {

    if (a > b) {

        return a;
    }
    else {

        return b;
    }
}

void parseLine(string line, int(&priceEntries)[maximumPrices][3], int& numEntries) {

    stringstream ss(line);
    
    char ch;

    int length = 0, width = 0, price = 0;
    int lastPrice = -1; // To keep track of the last inserted price entry

    int lengths[maximumPrices];
    int widths[maximumPrices];
    int currentDimensions = 0;

    while (ss >> ch) {
    
        if (ch == '(') {
    
            ss >> length >> ch >> width >> ch;
            lengths[currentDimensions] = length;
            widths[currentDimensions] = width;
            currentDimensions++;
        }
        else if (ch == '{') {
    
            ss >> price >> ch;

            for (int i = 0; i < currentDimensions; i++) {
    
                if (numEntries < maximumPrices) {
    
                    priceEntries[numEntries][0] = lengths[i];
                    priceEntries[numEntries][1] = widths[i];
                    priceEntries[numEntries][2] = price;

                    cout << priceEntries[numEntries][0] << endl << priceEntries[numEntries][1] << endl << priceEntries[numEntries][2] << endl << endl;

                    numEntries++;
                }
            }
    
            currentDimensions = 0;
            lastPrice = price;
        }
    }
}

int calculateMaxProfit(int length, int width, int priceEntries[maximumPrices][3], int numEntries) {
   
    int pieceLength = 0;
    int pieceWidth = 0;
    int piecePrice = 0;

    if (length <= 0 || width <= 0) {
    
        return 0;
    }

    int maxProfit = 0;

    for (int k = 0; k < numEntries; k++) {
    
        pieceLength = priceEntries[k][0];
        pieceWidth = priceEntries[k][1];
        piecePrice = priceEntries[k][2];

        if ((length % pieceLength == 0) && (width % pieceWidth == 0)) {
    
            int count = (length / pieceLength) * (width / pieceWidth);
    
            maxProfit = max(maxProfit, count * piecePrice);
        }

        if (length >= pieceLength) {
    
            maxProfit = max(maxProfit, calculateMaxProfit(length - pieceLength, width, priceEntries, numEntries) + piecePrice * (width / pieceWidth));
        }

        if (width >= pieceWidth) {
    
            maxProfit = max(maxProfit, calculateMaxProfit(length, width - pieceWidth, priceEntries, numEntries) + piecePrice * (length / pieceLength));
        }
    }

    return maxProfit;
}

int main() {
   
    ifstream file(filename);
    
    if (!file) {
    
        cout << "File could not be opened." << endl;
        return 1;
    }

    string line;
    
    int priceEntries[maximumPrices][3];
    
    int numEntries = 0;

    getline(file, line);
    
    int area;
    
    stringstream(line) >> area;
    
    int length = 10, width = area / length;

    while (getline(file, line)) {
    
        parseLine(line, priceEntries, numEntries);
    }

    cout << "Maximum Profit for a burfi of size " << length << "cm x " << width << "cm: ";
    
    cout << calculateMaxProfit(length, width, priceEntries, numEntries) << endl;

    return 0;
}