/*

Nick Luca
Activity 24: Dynamic memory expansion (Individual work)

*/

#include <iostream>
#include <string>

using namespace std;

string* expandArray(string* smallArr, int SIZE); /// function prototype

int main() 
{
    int SIZE = 11; /// size of original array

    string* ogArr = new string[SIZE]{ "hello", "im", "nick", "and", "i", "like", "to", "sleep", "like", "a", "lot"}; /// me yapping

    string* expandedArr = expandArray(ogArr, SIZE); /// call function for doubling the size of the original array

    cout << "contents of the new array" << '\n'; /// display reasons
    cout << "-------------------------" << '\n'; /// display reasons

    for (int index = 0; index < SIZE * 2; index++)
    {
        cout << "element [" << index << "] : "; /// display is cooler like this

        if (index < SIZE)
        {
            cout << expandedArr[index] << " ";
        }
        else
        {
            cout << " ";
        }
        cout << '\n';
    }

    delete[] ogArr; /// free the dynamic memory allocation
    delete[] expandedArr;

    return 0;
}

string* expandArray(string* smallArr, int SIZE)
{
    string* newArr = new string[SIZE * 2];

    for (int index = 0; index < SIZE; index++) 
    {
        newArr[index] = smallArr[index];
    }

    for (int index = SIZE; index < SIZE * 2; index++) /// elements to empty string
    {
        newArr[index] = "";
    }
    return newArr;
}