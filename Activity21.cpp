/*

Nick Luca
Activity 21: Pointer and Arrays (Individual Work)

*/

#include <iostream>

using namespace std;

const int SIZE = 5;

void arrayNumbers(int* array, int SIZE);

int main() 
{
    int number;  /// an integer called number
    int* ptr = nullptr;  ///  pointer to an integer called ptr
    int numbers[SIZE] = { 1, 2, 3, 4, 5 };  /// an array to an integer called numbers that has a size of 5 and assign values to the 5 elements of the array - they can be any values

    ptr = &number;  /// Make ptr point to number

    cout << "enter a number: ";
    cin >> number;  /// Get an input in number

    *ptr *= 100;  /// Multiply the value stored in number by 100 

    cout << *ptr << '\n';  /// Display the contents of number by de-referencing ptr

    ptr = numbers;  /// Now make ptr point to the start of the numbers array

    arrayNumbers(ptr, 5);  /// Display the contents of numbers using pointer notation using ptr - you can write a function  (optional) that takes an array and its size as the arguments and display the content using a pointer

    return 0;
}

void arrayNumbers(int* array, int SIZE)
{
    for (int index = 0; index < SIZE; index++) 
    {
        cout << *(array + index) << " ";
    }
    cout << '\n';
}

/*

added notes because was just following the instructions of the assignment since this is a very easy assignment, im honestly expection everybodies code to look alike


*/