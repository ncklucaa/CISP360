// Nick Luca, Diljot Singh, Anexa Thammavangsa

#include <iostream>
#include <cstdlib>  // for srand() and rand()
#include <ctime>

using namespace std;

const int MIN_NUMBER = 1, MAX_NUMBER = 12;

int main()
{
    srand(time(0));  // Seed the random number generator and prof asked to use this

    int num_1, num_2, student_Answer, correct_Answer;

    while (true)
    {
        num_1 = rand() % MAX_NUMBER + MIN_NUMBER;  // Generates two random numbers between 1 and 12
        num_2 = rand() % MAX_NUMBER + MIN_NUMBER;

        correct_Answer = num_1 * num_2;

        cout << "What is " << num_1 << " X " << num_2 << "? (Enter -1 to exit the quiz)" << endl;

        bool answer_correct = false;

        while (!answer_correct)
        {
            cin >> student_Answer;

            if (!cin.fail())  // Check if input is integer
            {
                if (student_Answer == -1)  // If student wants to exit the quiz enter [-1]
                {
                    cout << "Exiting" << endl;
                    return 0;  // [-1] got entered and exits the program
                }

                if (student_Answer == correct_Answer)  // Check if the student's answer is correct
                {
                    cout << "Very good!" << endl;
                    answer_correct = true;
                }
                else
                {
                    cout << "Incorrect Answer. Please try again." << endl;
                }
            }
            else  // Checks for inputs that are non integers ex: if student enters a letter
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter a valid integer: ";
            }
        }
    }

    return 0;
}
