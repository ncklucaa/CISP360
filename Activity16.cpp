/*

Nick Luca
Activity 16: One-dimensional arrays - Lottery (individual work)

YES I DO KNOW THE PROGRAM BASICALLY BREAKS IF YOU INPUT A LETTER

*/


#include <iostream>
#include <ctime>  /// for time()
#include <cstdlib>  /// for srand() and rand()

using namespace std;

void compareUserInputAndLottery(int lottery[], int userIntInput[], int& matchingNumbers);
void createLotteryNums(int lottery[]);
void getUserIntInput(int userIntInput[]);

const int SIZE = 5;  /// for array of 5 integers

int main()
{
	int lottery[SIZE];
	int userIntInput[SIZE];

	int matchingNumbers = 0;

	createLotteryNums(lottery);  /// picks 5 random numbers for the lottery

	getUserIntInput(userIntInput);  /// getting user input

	compareUserInputAndLottery(lottery, userIntInput, matchingNumbers);  /// comapres the numbers

	cout << "--------------------------------------" << '\n';  /// for display reasons

	cout << "Lottery numbers: ";
	for (int count = 0; count < SIZE; count++)
	{
		cout << lottery[count] << " ";
	}

	cout << '\n';  /// for display reasons

	cout << "You matched " << matchingNumbers << " numbers" << '\n';

	if (matchingNumbers == SIZE)  /// checks if numbers are matching
	{
		cout << "Congrats!" << '\n';
	}
	else
	{
		cout << "Better luck next time!" << '\n';
	}

	cout << "--------------------------------------" << '\n';  /// for display reasons

	return 0;
}

void compareUserInputAndLottery(int lottery[], int userIntInput[], int& matchingNumbers)  /// void function to compare the numbers
{
	for (int count = 0; count < SIZE; count++)
	{
		if (userIntInput[count] == lottery[count])
		{
			matchingNumbers++;
		}
	}
}

void createLotteryNums(int lottery[])  /// void function to create the 5 random lottery numbers
{
	srand(static_cast<int>(time(0)));  /// seed the random number generator

	for (int count = 0; count < SIZE; count++)
	{
		lottery[count] = rand() % 10;  /// picks random numbers between 0 and 9
	}
}

void getUserIntInput(int userIntInput[])  /// void function to get user input
{
	cout << "Enter five numbers between 0 and 9 for the lottery (space between each number)" << '\n';

	cout << "Your lottery numbers: ";

	for (int count = 0; count < SIZE; count++)
	{
		cin >> userIntInput[count];

		while (userIntInput[count] < 0 || userIntInput[count] > 9)
		{
			cout << "Number out of range, enter a number between 0 and 9: ";
			cin >> userIntInput[count];
			cout << '\n';
		}
	}
}