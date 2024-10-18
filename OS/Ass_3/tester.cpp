#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

// Function to generate random student data
void generateStudentData(std::ofstream& outFile) {
    int rollNo = rand() % 9000 + 1000; // Random 4-digit roll number

    // Sample Pakistani names (you can add more)
    std::string names[] = { "Ahmed", "Fatima", "Ali", "Aisha", "Usman", "Zainab", "Hassan", "Sara", "Bilal", "Mahnoor" };
    std::string name = names[rand() % 10]; // Random name

    std::string courses[] = { "Math", "Science", "History", "English" };
    std::string course = courses[rand() % 4]; // Random course

    std::string grades[] = { "A", "B", "C", "D" };
    std::string grade = grades[rand() % 4]; // Random grade

    int marks = rand() % 51 + 50; // Random marks between 50 and 100

    // Write the generated data to the CSV file
    outFile << rollNo << "," << name << "," << course << "," << grade << "," << marks << "\n";
}

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create and open the CSV file for writing
    std::ofstream outFile("student_data.csv");
    if (!outFile.is_open()) {
        std::cerr << "Failed to open the file for writing." << std::endl;
        return 1;
    }

    // Write the header row
    outFile << "RollNo,Name,Course,Grade,Marks\n";

    // Generate and write at least 20 student records
    int numRecords = 20;
    while (numRecords--) {
        generateStudentData(outFile);
    }

    // Close the file
    outFile.close();

    std::cout << "CSV file 'student_data.csv' has been created with at least 20 student records." << std::endl;

    return 0;
}
