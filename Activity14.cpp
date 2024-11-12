/// Nick Luca
/// Activity 14: Functions, Nested Repetition (individual work)

#include <iostream>

using namespace std;

/// Global constants prof gave us
const int MAX_WIDTH = 40;
const int MAX_HEIGHT = MAX_WIDTH / 2;

int width;

/// Functions provided by the prof
void getWidth(int &width);
void checkerboard(int width);

int main()
{
	getWidth(width);
	checkerboard(width);

	return 0;
}

void getWidth(int &width)  /// Getting width input from user
{
	cout << "Enter a width between 1 and " << MAX_WIDTH << ": ";

	cin >> width;

	while (cin.fail() || width < 1 || width > MAX_WIDTH)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input, enter a NUMBER between 1 and " << MAX_WIDTH << ": ";  /// If its not a number asks user to input again a NUMBER
		}
		else if (width < 1 || width > MAX_WIDTH)
		{
			cout << "Input is out of range, please input a number between 1 and " << MAX_WIDTH << ": "; /// If number that was input was out of the range between 1 and 40
		}

		cin >> width;  /// If user inputs aren't correct
	}
}

void checkerboard(int width)
{
	for (int row = 0; row < MAX_HEIGHT; row++)
	{
		for (int columns = 0; columns < MAX_WIDTH; columns++)
		{
			if (((row / width) % 2) == ((columns / width) % 2))
			{
				cout << '.';
			}
			else
			{
				cout << '*';
			}
		}
		
		cout << endl;
	}
}