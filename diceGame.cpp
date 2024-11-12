/* ------------------------------------------------
   CONTINUING OFF THE MY ACTIVITY 10 DICE GAME CODE
*/

// Nick Luca
// M05 Assignment
// diceGame.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int MAX_DICE = 6,   // Highest number/points you can get on ONE dice
		  MIN_DICE = 1,   // Lowest number/points you can get on ONE dice
		  TOTAL_TURNS = 11;   // Number of rounds played

int main()
{

	int player_1_Points = 0, player_2_Points = 0;   // Both players start with 0 points
	int player_1_Wins = 0, player_2_Wins = 0;   // Both players start at 0 wins and to keep track if the game keeps going
	int dice_1, dice_2, total_Score;
	
	char play_Again;

	srand(time(0));   // Seed the random number generator

	do
	{
		for (int player_Turn = 1; player_Turn <= TOTAL_TURNS; player_Turn++)
		{
			dice_1 = rand() % MAX_DICE + MIN_DICE;
			dice_2 = rand() % MAX_DICE + MIN_DICE;

			total_Score = dice_1 + dice_2;   // Calculates the sum of both dices

			cout << "Turn: " << player_Turn << setw(11) << " Dice 1: " << dice_1 << setw(11) << " Dice 2: " << dice_2 << setw(17) << " Total score: " << total_Score << endl;
			// Added setw just because easier on the eye when displays since its not all clumped up together

			if (total_Score % 2 == 0)   // Checks if the total is even or odd
			{
				player_1_Points++;
				cout << "Player 1 has gained a point!" << endl;   // Player 1 gets a point if total is even
			}
			else
			{
				player_2_Points++;
				cout << "Player 2 has gained a point!" << endl;   // Player 2 gets a point if total is odd
			}
		}

		cout << "\n";   // For display reasons

		cout << "Player 1 Total Score: " << player_1_Points << endl;   // Player 1 Total Score
		cout << "Player 2 Total Score: " << player_2_Points << endl;   // Player 2 Total Score

		if (player_1_Points > player_2_Points)   // Checks if Player 1 has more points they win if not Player 2 wins
		{
			cout << "Player 1 Wins!" << endl;
			player_1_Wins++;
		}
		else
		{
			cout << "Player 2 Wins!" << endl;
			player_2_Wins++;
		}

		cout << "\nDo you want to play again (y/n): ";
		cin >> play_Again;

	}

	while (play_Again == 'y' || play_Again == 'Y');   // Repeats the game

	cout << "\nFinal Score:" << endl;
	cout << "Player 1 has won " << player_1_Wins << " games" << endl;
	cout << "Player 2 has won " << player_2_Wins << " games" << endl;

	if (player_1_Wins > player_2_Wins)
	{
		cout << "Player 1 has won more games!" << endl;
	}
	else if (player_2_Wins > player_1_Wins)
	{
		cout << "Player 2 has won more games!" << endl;
	}
	else
	{
		cout << "The series of games ended in a tie!" << endl;
	}

	return 0;
}