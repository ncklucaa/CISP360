/*

Nick Luca
Activity 18: Two-dimensional arrays - Computation (individual work)

*/

#include <iostream>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

int getTotal(int arr[ROWS][COLS]);
double getAverage(int arr[ROWS][COLS]);
int getRowTotal(int arr[ROWS][COLS], int rows);
int getColumnTotal(int arr[ROWS][COLS], int cols);
int getHighestInRow(int arr[ROWS][COLS], int rows);
int getLowestInRow(int arr[ROWS][COLS], int rows);

int main()
{
	int arr[ROWS][COLS] = {
		{11, 22, 33, 44, 55},
		{69, 420, 555, 212, 333},
		{1, 24, 8, 99, 101},
		{17, 38, 360, 64, 88},
		{9, 10, 21, 808, 71}
	};

	cout << "the total of all the values in the array is: " << getTotal(arr) << '\n';
	cout << "the average of all the values in the array is: " << getAverage(arr) << '\n';
	cout << "the total of the values in the specified row (row 2) is: " << getRowTotal(arr, 1) << '\n';
	cout << "total of the values in the specified column (column 5) is: " << getColumnTotal(arr, 4) << '\n';
	cout << "the highest value in the specified row of the array (row 5) is: " << getHighestInRow(arr, 4) << '\n';
	cout << "the lowest value in the specified row of the array (row 3) is: " << getLowestInRow(arr, 2) << '\n';

		return 0;
}

int getTotal(int arr[ROWS][COLS])
{
	int arrayTotal = 0;

	for (int count1 = 0; count1 < ROWS; count1++)
	{
		for (int count2 = 0; count2 < COLS; count2++)
		{
			arrayTotal += arr[count1][count2];
		}
	}
	return arrayTotal;
}

double getAverage(int arr[ROWS][COLS])
{
	int arrayAvg = getTotal(arr);
	
	return static_cast<double>(arrayAvg) / (ROWS * COLS);
}

int getRowTotal(int arr[ROWS][COLS], int rows)
{
	int arrayRowTotal = 0;
	
	for (int count = 0; count < COLS; count++)
	{
		arrayRowTotal += arr[rows][count];
	}
	return arrayRowTotal;
}

int getColumnTotal(int arr[ROWS][COLS], int cols)
{
	int arrayColTotal = 0;

	for (int count = 0; count < ROWS; count++)
	{
		arrayColTotal += arr[count][cols];
	}
	return arrayColTotal;
}

int getHighestInRow(int arr[ROWS][COLS], int rows)
{
	int highestInArr = arr[rows][0];

	for (int count = 1; count < COLS; count++)
	{
		if (arr[rows][count] > highestInArr)
		{
			highestInArr = arr[rows][count];
		}
	}
	return highestInArr;
}

int getLowestInRow(int arr[ROWS][COLS], int rows)
{
	int lowestInArr = arr[rows][0];

	for (int count = 1; count < COLS; count++)
	{
		if (arr[rows][count] < lowestInArr)
		{
			lowestInArr = arr[rows][count];
		}
	}
	return lowestInArr;
}