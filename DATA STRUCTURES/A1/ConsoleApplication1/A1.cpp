/*      Muneel Haider       
        21i-0640        
        Task 1          
        Data Structures     */    

#include <iostream>
#include <string>
#include <fstream>
#include "Task1.h"
#include "Task2.h"
using namespace std;

int main() {

    /*********************************************************************************************/

    // Uncomment this section for Task 1

        //ifstream File("driver-data.csv");

        //if (!File.is_open()) {

        //    cout << "ERROR Opening File." << endl << endl;
        //}
    
        //// Extra values so that i may read the file
        //string id, mean_dist, mean_over_speed_perc;
        //int counter = 0;

        //// Temporary string arrays which will read their respective data
        //// These string arrays will later be converted into float array for calculations
        //string IDArray[4004];
        //string MeanDArray[4004];
        //string MeanPArray[4004];

        //while (File.good()) {

        //    // Reading file
        //    getline(File, id, ',');
        //    getline(File, mean_dist, ',');
        //    getline(File, mean_over_speed_perc, '\n');

        //    if (id != "") {

        //        cout << "ID:\t\t\t\t" << id << endl;
        //        cout << "Mean_Dit:\t\t\t" << mean_dist << endl;
        //        cout << "Mean_over_Speed_percentage:\t" << mean_over_speed_perc << endl << endl;

        //        IDArray[counter] = id;
        //        MeanDArray[counter] = mean_dist;
        //        MeanPArray[counter] = mean_over_speed_perc;

        //        counter++;
        //    }
        //}

        //File.close();

        //// I made a second function similar to main to reduce and divide my code
        //// Open Task1.h file
        //MyFunction(IDArray, MeanDArray, MeanPArray, counter);

    /***********************************************************************************************************/

    // Uncomment this section for task 2

        ifstream t2("segmented_customers-1.csv");

        if (!t2.is_open()) {

            cout << "ERROR Opening File." << endl << endl;
        }

        string id, g, a, annual, spending;
        int counter = 0;

        string CustomerID[205];
        string gender[205];
        string age[205];
        string annualincome[205];
        string spendingscore[205];

        while (t2.good()) {

             
                getline(t2, id, ',');
            
            getline(t2, g, ',');
            getline(t2, a, ',');
            getline(t2, annual, ',');
            getline(t2, spending, '\n');

            cout << id << "\t" << g << "\t" << a << "\t" << annual << "\t" << spending << endl;

            CustomerID[counter] = id;
            gender[counter] = g;
            age[counter] = a;
            annualincome[counter] = annual;
            spendingscore[counter] = spending;

            counter++;
        }

        MyFunctionTask2(age, annualincome, spendingscore, counter, CustomerID, gender);

    /*****************************************************************************************************/

    return 0;

}