//#include <opencv2/opencv.hpp>
//#include "QuadTree.cpp"
//#include "TwoDLinkedList.cpp"
//#include <iostream>
//#include <fstream>
//using namespace std;
//using namespace cv;
//int main() {
//    Mat image = imread("D:/Softwares/Visual Studio/DATA STRUCTURES/Testing Console/Ass4/Test_Images/Student Test Images/t2.bmp", IMREAD_GRAYSCALE);
//    if (image.empty()) {
//        cout << "Error loading image" << endl;
//        return 1;
//    }
//    cout << "\n=======================================================\n";
//    cout << "Start of Part 2" << endl;
//    cout << "=======================================================\n";
//    // Read the QuadTree from the file
//    ifstream infile("quad.txt");
//    QuadTree quad2;
//    quad2.constructQuadFromFile(infile, 3);
//    infile.close();
//    // Print the reconstructed QuadTree
//    cout << "\nReconstructed QuadTree:" << endl;
//    //quad2.printQuadTree(quad2.getRoot());
//    quad2.print();
//    // Getting the size of the resulting image
//    cv::Size size = image.size();
//    int width = size.width;
//    int height = size.height;
//     // Traverse the QuadTree and regenerate the image
//     // Regenerate the image from the quad tree
//    Mat regenerated_image = quad2.regenerateImage(quad2.getRoot(), height, width);
//
//    // Write the regenerated image to disk
//    cv::imwrite("D:/Softwares/Visual Studio/DATA STRUCTURES/Testing Console/Ass4/Test_Images/Student Test Images/output.jpg", regenerated_image);
//    cout << "Image saved at output.jpg" << endl;
//    cout << "\n=======================================================\n";
//    cout << "End of Part 2" << endl;
//    cout << "=======================================================\n";
//    return 0;
//}