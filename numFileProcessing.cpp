/*

Nick Luca
M05 Assignment
numFileProcessing.cpp

*/

#include <iostream>
#include <fstream>  // For files
#include <iomanip>  // For setprecision and fixed

using namespace std;

int main()
{
    ifstream inputFile;
    int num;
    int num_Count = 0;  // To count the total of numbers in the file
    int num_Sum = 0;  // To add all the numbers in the file together
    double num_Average = 0.0;  // For average

    inputFile.open("Random.txt");  // Opens the file

    if (!inputFile)  // Checks if the file is opened
    {
        cout << "Unable to open the file" << endl;  // If file isn't found or doesn't exist
        return 0;
    }

    while (inputFile >> num)
    {
        num_Count++;  // Everytime a number is read from the file the number count goes up
        num_Sum += num;
    }

    inputFile.close();  // Closes the file

    if (num_Count > 0)
    {
        num_Average = static_cast<double>(num_Sum) / num_Count;  // Because sum and count are both ints
    }

    cout << "The number of numbers in the file: " << num_Count << endl;
    cout << "The sum of all the numbers in the file (a running total): " << num_Sum << endl;
    cout << "The average of all the numbers in the file: " << fixed << setprecision(1) << num_Average << endl;  // I know you didn't ask use to use setprecision but I just did it for output display reasons

    return 0;
}