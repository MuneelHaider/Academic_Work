//#include <iostream>
//#include <fstream>
//#include <sstream>
//using namespace std;
//
///*
//    Iterative Bottom-Up Algorithm with Memoization
//
//    Time Complexity: O(n^3)
//*/
//
//const int MAX_SIZE = 250;
//const int MAX_PRICES = 50;
//
//int prices[MAX_PRICES][3];
//int dp[MAX_SIZE + 1][MAX_SIZE + 1];
//
//int max(int a, int b) {
//
//    return (a > b) ? a : b;
//}
//
//void parseLine(string line, int (&priceEntries)[MAX_PRICES][3], int &numEntries) {
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
//        } else if (ch == '{') {
//            ss >> price >> ch;
//
//            for (int i = 0; i < currentDimensions; ++i) {
//                if (numEntries < MAX_PRICES) {
//                    priceEntries[numEntries][0] = lengths[i];
//                    priceEntries[numEntries][1] = widths[i];
//                    priceEntries[numEntries][2] = price;
//
//                    cout << "(" << priceEntries[numEntries][0] << "," << priceEntries[numEntries][1] << ") : " << priceEntries[numEntries][2] << endl << endl;
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
//
//int maxProfit(int length, int width, int priceEntries[MAX_PRICES][3], int numEntries) {
//    for (int i = 0; i <= length; ++i) {
//        for (int j = 0; j <= width; ++j) {
//            dp[i][j] = 0;
//        }
//    }
//
//    for (int i = 1; i <= length; ++i) {
//        for (int j = 1; j <= width; ++j) {
//            for (int k = 0; k < numEntries; ++k) {
//                int pieceLength = priceEntries[k][0];
//                int pieceWidth = priceEntries[k][1];
//                int piecePrice = priceEntries[k][2];
//
//                if (i % pieceLength == 0 && j % pieceWidth == 0) {
//                    int count = (i / pieceLength) * (j / pieceWidth);
//                    dp[i][j] = max(dp[i][j], count * piecePrice);
//                }
//
//                if (i >= pieceLength) {
//                    dp[i][j] = max(dp[i][j], dp[i - pieceLength][j] + piecePrice * (j / pieceWidth));
//                }
//
//                if (j >= pieceWidth) {
//                    dp[i][j] = max(dp[i][j], dp[i][j - pieceWidth] + piecePrice * (i / pieceLength));
//                }
//            }
//            // Consider the best profit achievable for the remaining area
//            for (int p = 1; p < i; ++p) {
//                dp[i][j] = max(dp[i][j], dp[p][j] + dp[i - p][j]);
//            }
//            for (int q = 1; q < j; ++q) {
//                dp[i][j] = max(dp[i][j], dp[i][q] + dp[i][j - q]);
//            }
//        }
//    }
//    return dp[length][width];
//}
//
//int main() {
//
//    cout << endl << endl;
//
//    ifstream file("TestCase3.txt");
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
//
//    cout << "Reading dimensions and their prices from file:" << endl;
//
//    while (getline(file, line)) {
//        parseLine(line, priceEntries, numEntries);
//    }
//
//    cout << "Maximum Profit for a burfi of size " << n_length << "cm x " << n_width << "cm: ";
//    cout << maxProfit(n_length, n_width, priceEntries, numEntries) << endl;
//
//    cout << endl << endl;
//
//    return 0;
//}
