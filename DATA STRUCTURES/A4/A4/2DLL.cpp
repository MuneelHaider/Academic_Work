#include <opencv2/opencv.hpp>

using namespace cv;






// TwoDNode class for a doubly linked list
class TwoDNode
{
public:


    int data;
    TwoDNode* next;
    TwoDNode* prev;


    TwoDNode(int data)  //constructor to inilialize data member
    {
        this->data = data;
        next = prev = nullptr;
    }

};




class TwoDLinkedList 
{
public:
    TwoDNode* head;


    TwoDLinkedList() 
    {
        head = new TwoDNode(0);
    }
    // Add a new row to the linked list with data from an array
    void addRow(int data[], int size) 
    {
        TwoDNode* current = head;
        TwoDNode* prev = nullptr;
        for (int i = 0; i < size; i++) 
        {
            TwoDNode* newTwoDNode = new TwoDNode(data[i]);
            current->next = newTwoDNode;
            newTwoDNode->prev = current;
            current = newTwoDNode;
            if (prev) 
            {
                prev = prev->next;
            }
        }
    }
    // Convert a 2D dynamic memory array into a 2D linked list
    void convertTo2dLL(int** array, int row, int col) 
    {
        // Iterate over each row of the input array
        for (int i = 0; i < row; i++) 
        {
            // Initialize variables to track contiguous blocks of white and black pixels
            int white_start = -1;
            int black_start = -1;
            int white_end = -2;
            int black_end = -2;
            int white_count = 0;
            int black_count = 0;
            int prev_pixel = -1;
            int* pixel_data = new int[col];
            int pixel_data_count = 0;
            // Iterate over each pixel in the row
            for (int j = 0; j < col; j++) 
            {
                int pixel = array[i][j];
                if (pixel == 255) 
                { // white pixel
                    white_count++;
                    // If this is the start of a new contiguous block of white pixels, record the start index
                    if (white_start == -1)   //starting
                    {
                        white_start = j;
                    }
                    // If the previous pixel was black, record the end index of the previous contiguous block of black pixels
                    if (prev_pixel == 0)  //black
                    {
                        pixel_data[pixel_data_count++] = black_start;
                        pixel_data[pixel_data_count++] = j - 1;
                        black_count = 0;
                        black_start = -1;
                    }
                    // Update the previous pixel value
                    prev_pixel = 255;
                }
                else
                { // black pixel
                    black_count++;
                    // If this is the start of a new contiguous block of black pixels, record the start index
                    if (black_start == -1) 
                    {
                        black_start = j;
                    }
                    // If the previous pixel was white, record the end index of the previous contiguous block of white pixels
                    if (prev_pixel == 255) 
                    {
                        pixel_data[pixel_data_count++] = white_start;
                        pixel_data[pixel_data_count++] = j - 1;
                        white_count = 0;
                        white_start = -1;
                    }
                    // Update the previous pixel value
                    prev_pixel = 0;
                }
            }
            // If there are any remaining contiguous blocks of white or black pixels, record their end indices
            if (white_count > 0)
            {
                pixel_data[pixel_data_count++] = white_start;
                pixel_data[pixel_data_count++] = col - 1;
            }




            if (black_count > 0)
            {
                pixel_data[pixel_data_count++] = black_start;
                pixel_data[pixel_data_count++] = col - 1;
            }
            pixel_data[pixel_data_count++] = white_end;
            pixel_data[pixel_data_count++] = black_end;
            addRow(pixel_data, pixel_data_count);
        }
    }
};