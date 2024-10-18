#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <fstream>
using namespace std;

class QuadNode 
{
public:
    int color; // color of the node
    int x, y;  // position of the node in the image
    QuadNode* nw; //creating childs 
    QuadNode* ne;
    QuadNode* sw;
    QuadNode* se;
    bool isleaf;    // if it is leaf node or not (function prototype)


    QuadNode(int v)   //constructor
    {
        this->color = v;
        nw = nullptr;
        ne = nullptr;
        sw = nullptr;
        se = nullptr;
        isleaf = true;   //inilizing the the leaf node to true (bool type)
    }

    QuadNode(int color, int x, int y)  //constructor
    {
        this->color = color;
        this->x = x;
        this->y = y;
        nw = nullptr;
        ne = nullptr;
        sw = nullptr;
        se = nullptr;
        isleaf = true;
    }
   
    QuadNode()    //default constructor
    {
        nw = nullptr;
        ne = nullptr;
        sw = nullptr;
        se = nullptr;
        color = 0;
        isleaf = true;
    }







    bool isLeaf() 
    {   //checking leaf node when we get NULL 

        isleaf = nw == nullptr && sw == nullptr && ne == nullptr &&  se == nullptr;
        return isleaf;
    }


};










class QuadTree
{
private:
    QuadNode* root;
    int threshold;

public:
    QuadTree()   //default constructor
    {
        root == NULL;
        threshold = 0;
    } 

    QuadTree(int** image, int size, int threshold) //parametrized constructor
    {
        this->threshold = threshold;
        root = buildQuadTree(image, 0, 0, size, 0, 0);
    }

    ~QuadTree()   //deleting every quad tree 
    {   
        deleteTree(root);
    }
    void setRoot(QuadNode* x) 
    {
        root = x;
    }
    QuadNode* buildQuadTree(int** image, int x, int y, int size, int row, int col) 
    {
        if (size == 1)//base case (stopping condition)
        {
            return new QuadNode(image[x][y], row, col);
        }

        int sum = 0;// else 
        for (int i = x; i < x + size; i++)   //creating further sub quad nodes
        {
            for (int j = y; j < y + size; j++) 
            {
                sum += image[i][j];
            }
        }

        int avg = sum / (size * size);
        if (abs(avg - image[x][y]) <= threshold) 
        {
            return new QuadNode(image[x][y], row, col);
        }

        QuadNode* node = new QuadNode(-1, row, col);  //dividing the size to create further child 
        node->nw = buildQuadTree(image, x, y, size / 2, row, col);
        node->ne = buildQuadTree(image, x, y + size / 2, size / 2, row, col + size / 2);
        node->sw = buildQuadTree(image, x + size / 2, y, size / 2, row + size / 2, col);
        node->se = buildQuadTree(image, x + size / 2, y + size / 2, size / 2, row + size / 2, col + size / 2);
        return node;
    }

    void deleteTree(QuadNode* node) {
        if (node == nullptr) 
        {
            return;
        }

        deleteTree(node->nw);//deleting every child of quad treee
        deleteTree(node->ne);
        deleteTree(node->sw);
        deleteTree(node->se);

        delete node;
    }

    void printQuadTree(QuadNode* node)
    {
        if (node == nullptr) 
        {
            return;
        }

        if (node->isLeaf()) {   //when reach leaf nodes it print the respective colored node
            std::cout << node->color << " ";
            return;
        }

        cout << "-1 ";
        printQuadTree(node->nw);   //recursively printing every child after checking the leaf node
        printQuadTree(node->ne);
        printQuadTree(node->sw);
        printQuadTree(node->se);
    }
    void printQuadTree_again(QuadNode* tree, int depth)
    {
        if (tree == nullptr)
        {
            return;
        }
        for (int i = 0; i < depth; i++) 
        {
            cout << "  "; // making two spaces for each level of depth in quad tree
        }
        if (tree->isLeaf()) 
        {
            cout << "Leaf node: " << tree->color << endl;
        }
        else 
        {
            cout << "Parent node:" << endl;
            //recursively printing every child by incrementing the depth to 1 (move i step down  in tree)
            printQuadTree_again(tree->nw, depth + 1);  
            printQuadTree_again(tree->ne, depth + 1);
            printQuadTree_again(tree->sw, depth + 1);
            printQuadTree_again(tree->se, depth + 1);
        }
    }
    void writeQuadTree(QuadNode* node, int depth, ofstream& out) //writing the quad tree in output file 
    {
        if (node == nullptr) 
        {
            return;
        }

        if (node->isLeaf())
        {
            out << "Leaf node: value = " << node->color << ", x = " << depth << endl;
            return;
        }

        out << "Parent node:  " << depth << endl;
        writeQuadTree(node->nw, depth + 1, out);
        writeQuadTree(node->ne, depth + 1, out);
        writeQuadTree(node->sw, depth + 1, out);
        writeQuadTree(node->se, depth + 1, out);
    }




    QuadNode* getRoot()   //getter
    {
        return root;
    }



    void constructQuadFromFile(ifstream& infile, int level) 
    {
        root = constructQuadFromFileHelper(infile, level);
    }



    QuadNode* constructQuadFromFileHelper(ifstream& infile, int level) 
    {
        std::string line;
        QuadNode* node = nullptr;
        while (std::getline(infile, line)) {
            if (line.find("Parent node") != std::string::npos)   //to avoid exception when reading a file we use npos
            {
                int x_pos = line.find("x = ");
                int x_val = std::stoi(line.substr(x_pos + 4));
                node = new QuadNode(-1, x_val, level);
                node->nw = constructQuadFromFileHelper(infile, level + 1);
                node->ne = constructQuadFromFileHelper(infile, level + 1);
                node->sw = constructQuadFromFileHelper(infile, level + 1);
                node->se = constructQuadFromFileHelper(infile, level + 1);
                return node;
            }
            else if (line.find("Leaf node") != std::string::npos) {
                int val_pos = line.find("value = ");
                int x_pos = line.find(", x = ");
                int val = std::stoi(line.substr(val_pos + 8, x_pos - val_pos - 8));
                int x_val = std::stoi(line.substr(x_pos + 6));
                return new QuadNode(val, x_val, level);
            }
        }
        return nullptr;
    }
    // Function to print the QuadTree
    void print() {
        printH(root, "");
    }

    // Recursive helper function to print the QuadTree
    void printH(QuadNode* node, string indent) {
        if (node == nullptr) {
            return;
        }

        if (node->isLeaf()) {
            cout << indent << "- ,.;'" << node->color << endl;
        }
        else {
            cout << indent << "NODE" << endl;
            printH(node->nw, indent + "  ");
            printH(node->ne, indent + "  ");
            printH(node->sw, indent + "  ");
            printH(node->se, indent + "  ");
        }
    }

    // Recursive function to traverse the QuadTree and regenerate the image
    void regenerateImageHelper(QuadNode* node, cv::Mat& image, int x, int y, int width) {
        if (node == nullptr) {
            return;
        }

        if (node->isLeaf()) {
            // Assign the color of the leaf node to the corresponding pixels in the image
            cv::Vec3b color(node->color, node->color, node->color);
            for (int i = x; i < x + width; i++) {
                for (int j = y; j < y + width; j++) {
                    image.at<cv::Vec3b>(i, j) = color;
                }
            }
        }
        else {
            // Recursively traverse the QuadTree
            int halfWidth = width / 2;
            regenerateImageHelper(node->nw, image, x, y, halfWidth);
            regenerateImageHelper(node->ne, image, x, y + halfWidth, halfWidth);
            regenerateImageHelper(node->sw, image, x + halfWidth, y, halfWidth);
            regenerateImageHelper(node->se, image, x + halfWidth, y + halfWidth, halfWidth);
        }
    }

    // Function to regenerate the image from the QuadTree
    cv::Mat regenerateImage(QuadNode* root, int height, int width) {
        // Create an empty image with the specified size
        cv::Mat image(height, width, CV_8UC3, cv::Scalar(0, 0, 0));

        // Traverse the QuadTree and regenerate the image
        regenerateImageHelper(root, image, 0, 0, width);

        return image;
    }
};
