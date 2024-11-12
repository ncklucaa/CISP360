/*

Nick Luca
M05 Assignment
Pattern Display – patternDisplay.cpp

*/

#include <iostream>

using namespace std;

int main()
{
	int rows;

	do
	{
		cout << "Enter the number of rows you would like to be displayed (1 to 20): ";  // Asks user how many rows they want
		cin >> rows;

		if (rows < 1 || rows > 20)
		{
			cout << "Invalid input, please enter a number between 1 and 20" << endl;
		}
	}

	while (rows < 1 || rows > 20);

	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j < i; j++) {
			cout << "*";
		}

		cout << "#" << endl;  // Prints at the end of each row
	}
}