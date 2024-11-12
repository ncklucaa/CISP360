/*

Nick Luca
Activity 22: Pointers and Functions (Individual Activity)

*/

#include <iostream>

using namespace std;

int doMultipleThings(int* numx, int* numy);  /// function provided by prof

int main()
{
    int x = 69;  /// two random numbers
    int y = 420;

    int* xPtr = &x;
    int* yPtr = &y;

    int total = doMultipleThings(xPtr, yPtr);

    cout << "the return value from the function: " << total << '\n';

    cout << "contents of the memory locations of xPtr and yPtr is" << '\n';

    cout << "xPtr: " << *xPtr << '\n';
    cout << "yPtr: " << *yPtr << '\n';

    return 0;
}

int doMultipleThings(int* numx, int* numy)
{
    int temp = *numx;
    *numx = *numy * 10;         /// prof gave us this in class on tuesday
    *numy = temp * 10;

    return *numx + *numy;
}