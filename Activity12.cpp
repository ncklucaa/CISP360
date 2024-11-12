/// Nick Luca
/// Activity 12: Write to File (Individual work)
/// It's unnecessary for me to use void functions and exit(); but I just wanted to for practice

#include <iostream>
#include <fstream>  /// For File
#include <cstdlib>  /// For exit(0);

using namespace std;

const int MIN_RANGE = -50, MAX_RANGE = 50;  /// Minimum and Maximum range that the user can input

void if_File_Open(ofstream& output_File);
void file_Input(ofstream& output_File);

int main()
{
    ofstream output_File;
    output_File.open("output.txt");  /// Opens the output.txt file

    if_File_Open(output_File);

    file_Input(output_File);

    output_File.close();

    return 0;
}

void if_File_Open(ofstream& output_File)
{
    if (!output_File)  /// Checks if the file is opened or not
    {
        cout << "Unable to open the file\n";  /// If file isn't found or doesn't exist
        exit(0);   /// Exits the program if file wasn't able to be opened
    }
}

void file_Input(ofstream& output_File)
{
    char LOOP_AGAIN = 'y';

    while (LOOP_AGAIN != 'n' && LOOP_AGAIN != 'N')  /// If user wants to quit input n/N
    {
        int user_Input;

        cout << "Enter a number between " << MIN_RANGE << " and " << MAX_RANGE << ": ";
        cin >> user_Input;  /// User inputs a number between [-50] and [50]

        while (cin.fail() || user_Input < MIN_RANGE || user_Input > MAX_RANGE)
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "invalid input (outside of range) or a text input\n";  /// If user inputs letter
            }
            else
            {
                cout << "Enter a number in the range of " << MIN_RANGE << " and " << MAX_RANGE << " : ";  /// Tells user to input a number in the appropiate range of [-50] and [50]
            }

            cin >> user_Input;  /// Retry user input
        }

        output_File << user_Input << endl;
        cout << "Number: " << user_Input << " is inside the file\n";

        cout << "Want to enter another number? (y/n): ";
        cin >> LOOP_AGAIN;

        while (cin.fail() || (LOOP_AGAIN != 'y' && LOOP_AGAIN != 'Y' && LOOP_AGAIN != 'n' && LOOP_AGAIN != 'N'))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "invalid input, enter (y/n): "; /// If user inputs something besides y/Y or n/N
            cin >> LOOP_AGAIN;
        }
    }
}
