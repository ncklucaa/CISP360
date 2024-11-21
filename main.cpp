//**************
// main.cpp   **
//**************

#include "Coin.h" // header file
#include <iostream> // we all know what this is for
#include <iomanip> // for output purposes

using namespace std;

int main() 
{
    const int TOSSES = 3; // for simulating 3 tosses as prof asked
    int p1Heads = 0, p2Heads = 0, p1Tails = 0, p2Tails = 0, i;
    
    Coin p1, p2; // player 1 and player 2

    cout << "Player 1 side is ";
    if (p1.getSideUp() == 1) // display the side that it is facing up for player 1
    {
        cout << "\033[38;5;3m" << "Heads" << "\033[0m" << endl;
    }
    else
    {
        cout << "\033[38;5;3m" << "Tails" << "\033[0m" << endl;
    }

    cout << "Player 2 side is ";
    if (p2.getSideUp() == 1) // display the side that it is facing up for player 2
    {
        cout << "\033[38;5;2m" << "Heads" << "\033[0m" << endl;
        cout << endl;
    }
    else
    {
        cout << "\033[38;5;2m" << "Tails" << "\033[0m" << endl;
        cout << endl;
    }

    for (i = 0; i < TOSSES; i++) // simulating the coin toss
    {
        p1.Toss();
        p2.Toss();

        if (p1.getSideUp() == 1)
        {
            p1Heads++;
        }
        else
        {
            p1Tails++;
        }

        if (p2.getSideUp() == 1)
        {
            p2Heads++;
        }
        else
        {
            p2Tails++;
        }

        cout << "\033[38;5;13m" << "Toss " << "\033[0m" << i + 1 << endl;

        cout << "Player 1 = ";
        if (p1.getSideUp() == 1) // results
        {
            cout << "\033[38;5;3m" << "Heads" << "\033[0m" << endl;
        }
        else
        {
            cout << "\033[38;5;3m" << "Tails" << "\033[0m" << endl;
        }

        cout << "Player 2 = ";
        if (p2.getSideUp() == 1) // results
        {
            cout << "\033[38;5;2m" << "Heads" << "\033[0m" << endl;
            cout << endl;
        }
        else
        {
            cout << "\033[38;5;2m" << "Tails" << "\033[0m" << endl;
            cout << endl;
        }
    }

    cout << "Winner is ";
    
    if (p1Heads > p2Heads) // winner
    {
        cout << "\033[38;5;10m" << "Player 1" << "\033[0m" << endl;
        cout << endl;
    }
    else
    {
        cout << "\033[38;5;10m" << "Player 2" << "\033[0m" << endl;
        cout << endl;
    }

    // scoreboard
    cout << setw(18) << "\033[38;5;11m" << "Scoreboard" << "\033[0m" << endl;
    cout << "\033[38;5;12m" << "----------------------------" << "\033[0m" << endl;
    cout << "\033[38;5;3m" << "Player 1 " << "\033[0m" << "- Heads: " << p1Heads << " Tails: " << p1Tails << endl;
    cout << "\033[38;5;2m" << "Player 2 " << "\033[0m" << "- Heads: " << p2Heads << " Tails: " << p2Tails << endl;

    return 0;
}