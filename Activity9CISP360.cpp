// Nick Luca, Diljot Singh, Anexa Thammavangsa

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string color_1, color_2;

	cout << "Enter the first color (red, blue, yellow): ";
	cin >> color_1;  // Pick the first color

	if (color_1 != "red" && color_1 != "blue" && color_1 != "yellow")
	{
		cout << "Invalid color picked";  // If the first color the user entered is not (red, blue, or yellow) program ends
	}
	else
	{
		cout << "Enter the second color (red, blue, yellow): ";
		cin >> color_2;  // Pick the second color

		if (color_2 != "red" && color_2 != "blue" && color_2 != "yellow")
		{
			cout << "Invalid color picked";  // If the second color the user entered is not (red, blue, or yellow) program ends
		}
		else
		{
			if ((color_1 == "red" && color_2 == "blue") || (color_1 == "blue" && color_2 == "red"))
			{
				cout << "When you mix red and blue, you get purple." << endl;  // Output for choosing red and blue
			}
			else if ((color_1 == "red" && color_2 == "yellow") || (color_1 == "yellow" && color_2 == "red"))
			{
				cout << "When you mix red and yellow, you get orange." << endl;  // Output for choosing red and yellow
			}
			else if ((color_1 == "blue" && color_2 == "yellow") || (color_1 == "yellow" && color_2 == "blue"))
			{
				cout << "When you mix blue and yellow, you get green." << endl;  // Output for choosing blue and yellow
			}
			else
			{
				cout << "You entered same color twice" << endl;  // Output if user has entered same color twice
			}
		}
	}

	return 0;
}