/*

Nick Luca
Activity 19: Two-dimensional arrays - Manipulation (Individual work)

*/

#include <iostream>

using namespace std;

/// function prototypes
void arraya(int twod[][10], int rows, int columns);
void arrayb(int twod[][10], int rows, int columns);
void arrayc(int twod[][10], int rows, int columns);
void arrayd(int twod[][10], int rows, int columns);
void arraye(int twod[][10], int rows, int columns);

int main()
{
    int array[6][10] =   /// 6 by 10 array
    {
        {8, 0, 3, 6, 3},
        {1, 3, 1, 0, 7},
        {2, 7, 9, 4, 5}
    };

    cout << "a." << '\n'; /// a
    arraya(array, 3, 5);
    cout << '\n';

    cout << "b." << '\n'; /// b
    arrayb(array, 3, 5);
    cout << '\n';

    cout << "c." << '\n'; /// c
    arrayc(array, 3, 5);
    cout << '\n';

    cout << "d." << '\n'; /// d
    arrayd(array, 3, 5);
    cout << '\n';

    cout << "e." << '\n'; /// e
    arraye(array, 3, 5);
    cout << '\n';

    return 0;
}

void arraya(int twod[][10], int rows, int columns)
{
    for (int col = 0; col < columns; col++) {
        for (int row = 0; row < rows; row++)
            cout << " " << twod[row][col];
        cout << '\n';
    }
}

void arrayb(int twod[][10], int rows, int columns)
{
    for (int row = 0; row < rows; row++) {
        for (int col = columns - 1; col >= 0; col--)
            cout << " " << twod[row][col];
        cout << '\n';
    }
}

void arrayc(int twod[][10], int rows, int columns)
{
    for (int row = rows - 1; row >= 0; row--) {
        for (int col = 0; col < columns; col++)
            cout << " " << twod[row][col];
        cout << '\n';
    }
}

void arrayd(int twod[][10], int rows, int columns)
{
    for (int col = 0; col < columns; col++) {
        for (int row = rows - 1; row >= 0; row--)
            cout << " " << twod[row][col];
        cout << '\n';
    }
}

void arraye(int twod[][10], int rows, int columns)
{
    for (int row = rows - 1; row >= 0; row--) {
        for (int col = columns - 1; col >= 0; col--)
            cout << " " << twod[row][col];
        cout << '\n';
    }
}