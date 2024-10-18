#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

/*
    Muneel Haider       21i-0640
    Muhammad Abdullah   21i-0643
    Abdullah Zahoor     21i-2481
    Algo Project - CS 23

    Iterative Bottom-Up Algorithm with Optimization
*/

const int maximumSize = 250;
const int maximumPrices = 50;

// The name of the file from which we will read
string filename = "TestCase1.txt";

int prices[maximumPrices][3];
int arrayProfit[(maximumSize + 1) * (maximumSize + 1)];

int max(int a, int b) {

    if (a > b) {

        return a;
    }
    else {

        return b;
    }
}

void parseLine(string line, int (&priceEntries)[maximumPrices][3], int& numEntries) {

    stringstream ss(line);
    char ch;

    int length = 0, width = 0, price = 0;
    int lastPrice = -1;

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

            for (int i = 0; i < currentDimensions; ++i) {

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

int maxProfit(int length, int width, int priceEntries[maximumPrices][3], int numEntries) {

    int pieceLength = 0;
    int pieceWidth = 0;
    int piecePrice = 0;

    for (int i = 0; i <= length; i++) {
        for (int j = 0; j <= width; j++) {

            arrayProfit[i * (width + 1) + j] = 0;
        }
    }

    for (int i = 1; i <= length; i++) {
        for (int j = 1; j <= width; j++) {
            for (int k = 0; k < numEntries; k++) {

                pieceLength = priceEntries[k][0];
                pieceWidth = priceEntries[k][1];
                piecePrice = priceEntries[k][2];

                if ((i % pieceLength == 0) && (j % pieceWidth == 0)) {

                    int count = (i / pieceLength) * (j / pieceWidth);

                    arrayProfit[i * (width + 1) + j] = max(arrayProfit[i * (width + 1) + j], count * piecePrice);
                }

                if (i >= pieceLength) {

                    arrayProfit[i * (width + 1) + j] = max(arrayProfit[i * (width + 1) + j], arrayProfit[(i - pieceLength) * (width + 1) + j] + piecePrice * (j / pieceWidth));
                }

                if (j >= pieceWidth) {

                    arrayProfit[i * (width + 1) + j] = max(arrayProfit[i * (width + 1) + j], arrayProfit[i * (width + 1) + (j - pieceWidth)] + piecePrice * (i / pieceLength));
                }
            }
        }
    }

    return arrayProfit[length * (width + 1) + width];
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
    cout << maxProfit(length, width, priceEntries, numEntries) << endl;

    return 0;
}