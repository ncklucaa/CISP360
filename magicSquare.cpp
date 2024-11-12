/*

Nick Luca
M07 Assignment
Lo Shu Magic Square – magicSquare.cpp

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAGIC_SQUARE = 3; /// because it's a 3 by 3 square
int squareTotal = 15; /// since all row, col, and diagonal has to addup to 15

bool isItLoShuMagicSquare(int array[MAGIC_SQUARE][MAGIC_SQUARE]);
void createLoShuMagicSquare(int array[MAGIC_SQUARE][MAGIC_SQUARE]);
void showLoShuMagicSquare(int array[MAGIC_SQUARE][MAGIC_SQUARE]);

int main()
{
    srand(time(0)); // seed random number generator

    int array[MAGIC_SQUARE][MAGIC_SQUARE];

    createLoShuMagicSquare(array);
    showLoShuMagicSquare(array);

    if (isItLoShuMagicSquare(array))
    {
        cout << "This is a Lo Shu Magic Square" << '\n';
    }
    else
    {
        cout << "This is not a Lo Shu Magic Square" << '\n';
    }

    return 0;
}

bool isItLoShuMagicSquare(int array[MAGIC_SQUARE][MAGIC_SQUARE])
{
    int total, row, col;

    for (row = 0; row < MAGIC_SQUARE; row++)
    {
        total = 0;
        for (col = 0; col < MAGIC_SQUARE; col++)
        {
            total += array[row][col];
        }
        if (total != squareTotal)
        {
            return false; /// if rows aren't equal to 15
        }
    }

    for (col = 0; col < MAGIC_SQUARE; col++)
    {
        total = 0;
        for (row = 0; row < MAGIC_SQUARE; row++)
        {
            total += array[row][col];
        }
        if (total != squareTotal)
        {
            return false; /// if cols aren't equal to 15
        }
    }

    if (array[0][0] + array[1][1] + array[2][2] != squareTotal || array[0][2] + array[1][1] + array[2][0] != squareTotal)
    {
        return false;
    }

    return true;
}



void createLoShuMagicSquare(int array[MAGIC_SQUARE][MAGIC_SQUARE])
{
    bool numsInSquare[10] = { false }; /// checks if numbers 1 through 9 already used

    int row, col, numGenerator;

    for (row = 0; row < MAGIC_SQUARE; row++)
    {
        for (col = 0; col < MAGIC_SQUARE; col++)
        {
            do
            {
                numGenerator = rand() % 9 + 1; /// create numbers between 1 and 9 for the square
            } while (numsInSquare[numGenerator]);

            numsInSquare[numGenerator] = true;
            array[row][col] = numGenerator;
        }
    }
}

void showLoShuMagicSquare(int array[MAGIC_SQUARE][MAGIC_SQUARE])
{
    int row, col;
    
    cout << "-------------" << '\n';
    for (row = 0; row < MAGIC_SQUARE; row++)
    {
        cout << "| ";
        for (col = 0; col < MAGIC_SQUARE; col++)
        {
            cout << array[row][col] << " | ";
        }
        cout << '\n' << "-------------" << '\n';
    }
}