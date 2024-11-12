/*

Nick Luca
Activity 26: C-Strings (individual activity)

the setw() is only aligned in the middle if you use the default small screen that popups not fullscreen
and if you go over 15 characters you will be able to tell

*/

#include <iostream>
#include <iomanip>
#include <Windows.h> // text colors

using namespace std;

const int MAX_INPUT = 15; // Make sure you input no more than 15 characters

struct userInput
{
	char userInputArray[MAX_INPUT + 1]; // +1 because '\0' null terminator at the end of array
	int total; // stores the total
};

void calculateTotal(userInput& digits)
{
	digits.total = 0;
	int index;

	for (index = 0; digits.userInputArray[index] != '\0'; index++)
	{
		if (digits.userInputArray[index] >= '0' && digits.userInputArray[index] <= '9')
		{
			digits.total += static_cast<int>(digits.userInputArray[index]) - static_cast<int>('0'); // characters to ints
		}
	}
}

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	userInput digits;

	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // set color to yellow
	cout << "Enter up to 15 characters whatever you want (numbers and letters): ";
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // set color to default (white)
	cin >> setw(MAX_INPUT + 1) >> digits.userInputArray; // make sure it doesnt count anything more than 15 characters

	calculateTotal(digits); // call the void function

	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); // set color to blue
	cout << setw(80) << "=============================================" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // set color to default (white)
	cout << setw(65) << "You have entered: ";
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // set color to green
	cout << digits.userInputArray << endl; // display what the user has input
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // set color to default (white)
	cout << setw(78) << "The total for all the numbers you have is: ";
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // set color to green
	cout << digits.total << endl; // displays total of all the numbers added up
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // set color to default (white)
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); // set color to blue
	cout << setw(80) << "=============================================" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // set color to default (white)

	return 0;
}