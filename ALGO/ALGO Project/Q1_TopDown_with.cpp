//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <cstring> // For memset
//using namespace std;
//
///*
//    Recursive Top-Down Algorithm with Memoization
//*/
//
//const int MAX_SIZE = 250;
//const int MAX_PRICES = 50;
//
//int prices[MAX_PRICES][3];
//int memo[MAX_SIZE + 1][MAX_SIZE + 1];
//
//int max(int a, int b) {
//    return (a > b) ? a : b;
//}
//
//void parseLine(string line, int(&priceEntries)[MAX_PRICES][3], int& numEntries) {
//    stringstream ss(line);
//    char ch;
//
//    int length = 0, width = 0, price = 0;
//    int lastPrice = -1; // To keep track of the last inserted price entry
//
//    int lengths[MAX_PRICES];
//    int widths[MAX_PRICES];
//    int currentDimensions = 0;
//
//    while (ss >> ch) {
//        if (ch == '(') {
//            ss >> length >> ch >> width >> ch;
//            lengths[currentDimensions] = length;
//            widths[currentDimensions] = width;
//            currentDimensions++;
//        }
//        else if (ch == '{') {
//            ss >> price >> ch;
//
//            for (int i = 0; i < currentDimensions; ++i) {
//                if (numEntries < MAX_PRICES) {
//                    priceEntries[numEntries][0] = lengths[i];
//                    priceEntries[numEntries][1] = widths[i];
//                    priceEntries[numEntries][2] = price;
//
//                    cout << priceEntries[numEntries][0] << endl << priceEntries[numEntries][1] << endl << priceEntries[numEntries][2] << endl << endl;
//
//                    numEntries++;
//                }
//            }
//            currentDimensions = 0;
//            lastPrice = price;
//        }
//    }
//}
//
//int calculateMaxProfit(int length, int width, int priceEntries[MAX_PRICES][3], int numEntries) {
//    if (length <= 0 || width <= 0) {
//        return 0;
//    }
//
//    if (memo[length][width] != -1) {
//        return memo[length][width];
//    }
//
//    int maxProfit = 0;
//
//    for (int k = 0; k < numEntries; ++k) {
//        int pieceLength = priceEntries[k][0];
//        int pieceWidth = priceEntries[k][1];
//        int piecePrice = priceEntries[k][2];
//
//        if (length % pieceLength == 0 && width % pieceWidth == 0) {
//            int count = (length / pieceLength) * (width / pieceWidth);
//            maxProfit = max(maxProfit, count * piecePrice);
//        }
//
//        if (length >= pieceLength) {
//            maxProfit = max(maxProfit, calculateMaxProfit(length - pieceLength, width, priceEntries, numEntries) + piecePrice * (width / pieceWidth));
//        }
//
//        if (width >= pieceWidth) {
//            maxProfit = max(maxProfit, calculateMaxProfit(length, width - pieceWidth, priceEntries, numEntries) + piecePrice * (length / pieceLength));
//        }
//    }
//
//    memo[length][width] = maxProfit;
//    return maxProfit;
//}
//
//int main() {
//    // Initialize memoization array with -1
//    memset(memo, -1, sizeof(memo));
//
//    ifstream file("TestCase1.txt");
//    if (!file) {
//        cout << "File could not be opened." << endl;
//        return 1;
//    }
//
//    string line;
//    int priceEntries[MAX_PRICES][3];
//    int numEntries = 0;
//
//    getline(file, line);
//    int n_area;
//    stringstream(line) >> n_area;
//    int n_length = 10, n_width = n_area / n_length;
//
//    while (getline(file, line)) {
//        parseLine(line, priceEntries, numEntries);
//    }
//
//    cout << "Maximum Profit for a burfi of size " << n_length << "cm x " << n_width << "cm: ";
//    cout << calculateMaxProfit(n_length, n_width, priceEntries, numEntries) << endl;
//
//    return 0;
//}
