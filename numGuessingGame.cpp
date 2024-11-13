/*

Number Guessing Game

*/

#include <iostream> // input/output
#include <cstdlib> // srand() and rand()
#include <ctime> // for time
#include <Windows.h> // for text colors

using namespace std;

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	srand(static_cast<int>(time(0)));

	int lowestNum = 1,
		highestNum = 100,
		guess,
		attempts = 0,
		randomNum = rand() % (highestNum - lowestNum + 1) + lowestNum;
	bool correctAnswer = false;

	cout << "Welcome" << endl;
	cout << "I have picked a random number between ";
	SetConsoleTextAttribute(h, 2);
	cout << lowestNum;
	SetConsoleTextAttribute(h, 7); // set color back to white
	cout << " and ";
	SetConsoleTextAttribute(h, 2);
	cout << highestNum << endl;
	SetConsoleTextAttribute(h, 7); // set color back to white
	cout << "Can you guess it";
	SetConsoleTextAttribute(h, 14); // set color to yellow
	cout << "?" << endl;
	SetConsoleTextAttribute(h, 7); // set color back to white

	while (!correctAnswer)
	{
		cout << endl;
		cout << "Enter your guess";
		SetConsoleTextAttribute(h, 14); // set color to yellow
		cout << ": ";
		SetConsoleTextAttribute(h, 7); // set color back to white
		cin >> guess;
		attempts++;

		if (guess > randomNum)
		{
			SetConsoleTextAttribute(h, 12); // set color to bright red
			cout << "Too high!" << endl;
			SetConsoleTextAttribute(h, 7); // set color back to white
		}
		else if (guess < randomNum)
		{
			SetConsoleTextAttribute(h, 9); // set color to bright blue
			cout << "Too low!" << endl;
			SetConsoleTextAttribute(h, 7); // set color back to white
		}
		else
		{
			SetConsoleTextAttribute(h, 13); // set color to pink/magenta
			cout << "Congratulation You Won!!!" << endl;
			SetConsoleTextAttribute(h, 7); // set color back to white
			cout << "You have guessed the number in ";
			SetConsoleTextAttribute(h, 10); // set color to bright green
			cout << attempts;
			SetConsoleTextAttribute(h, 7); // set color back to white
			cout << " attempts" << endl;
			correctAnswer = true;
		}
	}
	return 0;
}