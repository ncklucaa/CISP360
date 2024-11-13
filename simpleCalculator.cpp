/*

will update more later on

*/

#include <iostream> // input/output
#include <cmath> // for math will update with other operators and functions later
#include <Windows.h> // for text color
#include <iomanip> // for personal visual on screen

using namespace std;

int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // for text colors
    double num1, num2, total;
    char option;

    do
    {
        SetConsoleTextAttribute(h, 14); // set color to yellow
        cout << "What would you like to do? (+, -, *, /): "; // asking user which math operation they would like to use
        SetConsoleTextAttribute(h, 7); // set color back to white
        cin >> option; // user input for specific operation type

        cout << "Enter the first number: ";
        cin >> num1; // user input for first number

        cout << "Enter the second number: ";
        cin >> num2; // user input for second number

        switch (option)
        {
        case '+':
            total = num1 + num2; // num1 plus num2
            cout << num1 << " + " << num2 << " = ";
            SetConsoleTextAttribute(h, 2); // set color to green
            cout << total << endl;
            SetConsoleTextAttribute(h, 7); // set color back to white
            break;
        case '-':
            total = num1 - num2; // num1 minus num2
            cout << num1 << " - " << num2 << " = ";
            SetConsoleTextAttribute(h, 2); // set color to green
            cout << total << endl;
            SetConsoleTextAttribute(h, 7); // set color back to white
            break;
        case '*':
            total = num1 * num2; // num1 times num2
            cout << num1 << " * " << num2 << " = ";
            SetConsoleTextAttribute(h, 2); // set color to green
            cout << total << endl;
            SetConsoleTextAttribute(h, 7); // set color back to white
            break;
        case '/':
            if (num2 == 0) // if num2 is equal to zero
            {
                SetConsoleTextAttribute(h, 4); // set color to red
                cout << "Error: cannot divide by 0" << endl; // cannot divide by 0
                SetConsoleTextAttribute(h, 7); // set color back to white
            }
            else
            {
                total = num1 / num2; // num1 divided by num2
                cout << num1 << " / " << num2 << " = ";
                SetConsoleTextAttribute(h, 2); // set color to green
                cout << total << endl;
                SetConsoleTextAttribute(h, 7); // set color back to white
            }
            break;
        default:
            SetConsoleTextAttribute(h, 4); // set color to red
            cout << "Invalid operator" << endl; // if user picks anything other than the 4 options provided
            SetConsoleTextAttribute(h, 7); // set color back to white
        }
        SetConsoleTextAttribute(h, 14); // set color to yellow
        cout << "Do you want to perform another calculation? (Y/N): "; // asking user if they want to perform another calculation
        SetConsoleTextAttribute(h, 7); // set color back to white
        cin >> option; // user input

    } 
    while (option == 'y' || option == 'Y'); // if yes/y/Y program runs again if not exits

    SetConsoleTextAttribute(h, 2); // set color to green
    cout << "Goodbye :)"; // if user chose N/n 
    SetConsoleTextAttribute(h, 7); // set color back to white

    return 0;
}
