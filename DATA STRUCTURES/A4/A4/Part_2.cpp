//
////Momina Ali
////21i-2521
//
//#include <opencv2/opencv.hpp>
//#include "QT_Struct.cpp"
//#include "2DLL.cpp"
//#include <iostream>
//#include <fstream>
//using namespace std;
//using namespace cv;
//int main() 
//{
//    Mat image = imread("D:/Softwares/Visual Studio/DATA STRUCTURES/Testing Console/Ass4/Test_Images/Student Test Images/t2.bmp", IMREAD_GRAYSCALE);
//    if (image.empty()) 
//    {
//        cout << "Error image" << endl;
//        return 1;
//    }
//   
//    cout << "Part 2" << endl;
//    
//    // Read the QuadTree from the file
//    ifstream infile("quad.txt");
//    QuadTree quad2;
//    quad2.constructQuadFromFile(infile, 3);
//    infile.close();
//    // Print the reconstructed QuadTree
//    cout << "\nconstructed QuadTree:" << endl;
//    //quad2.printQuadTree(quad2.getRoot());
//    quad2.print();
//    // Getting the size of the resulting image
//    cv::Size size = image.size();
//    int width = size.width;
//    int height = size.height;
//    // Traverse the QuadTree and regenerate the image
//    // Regenerate the image from the quad tree
//    Mat regenerated_image = quad2.regenerateImage(quad2.getRoot(), height, width);
//
//    // Write the regenerated image to disk
//    cv::imwrite("output.jpg", regenerated_image);
//    cout << "Image saved.jpg" << endl;
//    
//    cout << "end" << endl;
//   
//    return 0;
//}