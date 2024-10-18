//#include <opencv2/opencv.hpp>
//#include "QuadTree.cpp"
//#include "TwoDLinkedList.cpp"
//#include <iostream>
//#include <fstream>
//using namespace std;
//using namespace cv;
//int main() {
//    // Reading the original and the regenerated image
//    Mat image = imread("D:/Softwares/Visual Studio/DATA STRUCTURES/Testing Console/Ass4/Test_Images/Student Test Images/t2.bmp", IMREAD_GRAYSCALE);
//    if (image.empty()) {
//        cout << "Error loading image" << endl;
//        return 1;
//    }
//    Mat regenerated_image = imread("output.jpg", IMREAD_GRAYSCALE);
//    if (image.empty()) {
//        cout << "Error loading image" << endl;
//        return 1;
//    }
//    cout << "\n=======================================================\n";
//    cout << "Start of Part 3" << endl;
//    cout << "=======================================================\n";
//    double sum_error = 0.0;
//    int num_rows = image.rows;
//    int num_cols = image.cols;
//    int n = num_rows * num_cols;  // total number of pixels in the image
//
//    // calculate the accuracy of the decoded image
//    for (int i = 0; i < num_rows; i++) {
//        for (int j = 0; j < num_cols; j++) {
//            double X = abs(image.at<uchar>(i, j) - regenerated_image.at<uchar>(i, j));
//            double Z = 255.0;
//            sum_error += X / (Z * n);
//        }
//    }
//
//    double accuracy = 1.0 - sum_error;
//
//    // output the accuracy
//    cout << "Accuracy: " << accuracy * 100 << endl;
//    cout << "\n=======================================================\n";
//    cout << "End of Part 3" << endl;
//    cout << "=======================================================\n";
//
//    return 0;
//}
