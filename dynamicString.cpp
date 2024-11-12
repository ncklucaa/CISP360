/*

Nick Luca
M09 Assignment
Programming Assignment on Chapter 9

*/

#include <iostream>
#include <string>
#include <windows.h>  // was watching a video on how to change output color so just experimenting with that if thats ok

using namespace std;

void printMenu();
void printList(string* p, int size);
string* expand(string* p, int& size);
bool insertAtZero(string* p, string item, int count);
bool insertAt(string* p, string item, int index, int count);
bool insertAtEnd(string* p, string item, int count);
bool removeFromEnd(string* p, int& count);
bool removeFrom(string* p, int index, int count);
void sort(string* p, int count);

int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    int size = 2,
        count = 0,
        choice = 0,
        index;
    string* list = new string[size];
    string item;

    while (choice != 8) 
    {
        printMenu();
        cin >> choice; // users input choice

        if (cin.fail() || choice < 1 || choice > 8) 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "Invalid option please try again\n";
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else if (choice == 1) // insert at the end
        {
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "Enter text to be entered at end: ";
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cin >> item;

            if (count == size) 
            {
                list = expand(list, size);
            }
            if (insertAtEnd(list, item, count)) 
            {
                count++;
            }
        }
        else if (choice == 2) // insert at the beginning
        {
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "Enter text to be entered at the beginning: ";
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cin >> item;

            if (count == size) 
            {
                list = expand(list, size);
            }
            if (insertAtZero(list, item, count))
            {
                count++;
            }
        }
        else if (choice == 3) // insert at specific spot
        {
            cout << "Enter text: ";
            cin.ignore();
            getline(cin, item);
            
            cout << "Enter element[]: ";
            cin >> index;

            if (cin.fail() || index < 0 || index > count) 
            {
                cin.clear();
                cin.ignore(1000, '\n');
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << "Invalid element" << endl;
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else 
            {
                if (count == size) 
                {
                    list = expand(list, size);
                }
                if (insertAt(list, item, index, count)) 
                {
                    count++;
                }
            }
        }
        else if (choice == 4) // remove from end
        {
            if (removeFromEnd(list, count)) 
            {
                //count--;
            }
            else 
            {
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "List is already empty" << endl;
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        else if (choice == 5) // remove from specific index
        {
            cout << "Enter element to remove: ";
            cin >> index;

            if (cin.fail() || index < 0 || index >= count) 
            {
                cin.clear();
                cin.ignore(1000, '\n');
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << "Invalid index" << endl;
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else 
            {
                if (removeFrom(list, index, count))
                {
                    count--;
                }
            }
        }
        else if (choice == 6) // sort the list
        {
            sort(list, count);
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "List is sorted." << endl;
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else if (choice == 7) // print the list
        {
            printList(list, count);
        }
        else if (choice == 8) // exit
        {
            SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "Goodbye :)" << endl;
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    }

    delete[] list;
    return 0;
}

void printMenu() // menu options
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); // set color to blue
    cout << "\n==================== MENU ====================\n";
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // set color to default (white)
    cout << "\nPlease choose from the following menu choices:\n";
    cout << "1) Insert a new element to the end of the list.\n";
    cout << "2) Insert a new element at the beginning of the list.\n";
    cout << "3) Insert an element into the list at a given index.\n";
    cout << "4) Remove an element from the end of the list.\n";
    cout << "5) Remove an element from the list at a given index.\n";
    cout << "6) Sort the list.\n";
    cout << "7) Print the contents of the list.\n";
    cout << "8) Exit.\n";
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); // set color to blue
    cout << "==============================================\n";
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // set color to default (white)
    cout << "Choice: ";
}

void printList(string* p, int size) 
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    if (size == 0) 
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // set color to yellow
        cout << "List is empty\n";
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // set color to default (white)
        return;
    }

    for (int i = 0; i < size; i++) // 193
    {
        cout << *(p + i) << " ";
    }
    cout << '\n';
}

string* expand(string* p, int& size) 
{
    int doubleSize = size * 2;
    string* arrayTwo = new string[doubleSize];

    for (int i = 0; i < size; i++) 
    {
        *(arrayTwo + i) = *(p + i);
    }

    delete[] p;
    size = doubleSize;

    return arrayTwo;
}

bool insertAtZero(string* p, string item, int count) 
{
    for (int i = count; i > 0; i--) 
    {
        *(p + i) = *(p + i - 1);
    }

    *p = item;
    return true;
}

bool insertAt(string* p, string item, int index, int count) 
{    
    if (index < 0 || index > count)
    {
        return false; // invalid index
    }
    
    for (int i = count; i > index; i--)
    {
        p[i] = p[i - 1];
    }

    p[index] = item;
    return true;
}

bool insertAtEnd(string* p, string item, int count) 
{
    *(p + count) = item;
    return true;
}

bool removeFromEnd(string* p, int& count) 
{
    if (count == 0)
    {
        return false;
    }
    count--;
    return true;
}

bool removeFrom(string* p, int index, int count)
{
    if (index < 0 || index >= count) 
    {
        return false;
    }

    for (int i = index; i < count - 1; i++) 
    {
        *(p + i) = *(p + i + 1);
    }
    return true;
}

void sort(string* p, int count) 
{
    for (int i = 0; i < count - 1; i++) 
    {
        int minIndex = i;

        for (int j = i + 1; j < count; j++) 
        {
            if (p[j] < p[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i) 
        {
            string temp = *(p + i);
            p[i] = p[minIndex];
            p[minIndex] = temp;
        }
    }
}