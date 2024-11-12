/*

Nick Luca
Activity 23: Dynamic Array Using Pointers (Individual Work)

I changed my original code and listened to the feedback of my classmate because I realized I didn't do the assignment right, should be right now? I HOPE SO
I can say though using vector was a good idea just not what the prof asked for :(

*/

#include <iostream>
#include <iomanip> /// for fixed and setprecision

using namespace std;

double* reverseArray(double *array, int SIZE);

int main()
{
    int SIZE = 10;
    double *array = new double[SIZE] { 69.0, 420.0, 666.0, 1738.0, 555.0, 777.0, 21.0, 9.0, 10.0, 123.0 };

    cout << "------------------------------------------------------------------------" << '\n'; /// output display reasons

    cout << "original array: ";

    cout << fixed << setprecision(1);
    for (int index = 0; index < SIZE; index++)
    {
        cout << array[index] << " ";
    }
    cout << '\n';

    double* reversed = reverseArray(array, SIZE);

    cout << "backwards array: ";

    for (int index = 0; index < SIZE; index++)
    {
        cout << reversed[index] << " ";
    }
    cout << '\n';

    delete[] reversed;

    cout << "------------------------------------------------------------------------" << '\n'; /// output display reasons

    return 0;
}

double* reverseArray(double *array, int SIZE)
{
    double *reversed = new double[SIZE];

    for (int index = 0; index < SIZE; index++)
    {
        reversed[index] = array[SIZE - 1 - index];
    }

    delete[] array; /// deletes old array

    return reversed;
}