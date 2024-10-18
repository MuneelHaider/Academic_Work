
//Momina Ali
//21i-2521

#include <opencv2/opencv.hpp>
#include "QT_Struct.cpp"
#include "2DLL.cpp"
#include <iostream>
#include <fstream>
using namespace std;
using namespace cv;
int main() 
{    
    cout << "Part 1" << endl;
 
    Mat image = imread("D:/Softwares/Visual Studio/DATA STRUCTURES/Testing Console/Ass4/Test_Images/Student Test Images/t2.bmp", IMREAD_GRAYSCALE);   //storing image in image variable of MAT 
    if (image.empty()) {
        cout << "Error loading image" << endl;
        return 1;
    }

    // Convert the image to a 2D array of pixel values
    int rows = image.rows;                     //inilizing 
    int cols = image.cols;
    int** pixel_data = new int* [rows];
    for (int i = 0; i < rows; i++) {
        pixel_data[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            pixel_data[i][j] = image.at<uchar>(i, j);
        }
    }

    // Build the quadtree from the pixel data
    int threshold = 10;
    QuadTree quad(pixel_data, rows, threshold);
    cout << "Writing Quadtree in files" << endl;
    ofstream out("quad.txt");
    if (!out.is_open()) {
        cout << "Error creating output file" << endl;
        return 1;
    }
    quad.writeQuadTree(quad.getRoot(), 0, out);
    out.close();
    cout << "\nOriginal QuadTree from image" << endl;
    //quad.printQuadTree(quad.getRoot());
    quad.print();
    
    cout << "end" << endl;
   
    return 0;
}