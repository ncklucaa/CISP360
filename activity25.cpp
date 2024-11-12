/*
Nick Luca
Activity 25: Insert in a dynamic array (Individual work)
*/

#include <iostream>
#include <string>

using namespace std;

bool insertAt(string* p, string item, int index, int count);

const int ARR_SIZE = 8;

int main()
{
    string* p = new string[ARR_SIZE]; // setting up the array
    int count = 0;

    for (int i = 0; i < ARR_SIZE; i++) // array with empty strings
    {
        p[i] = "";
    }

    if (insertAt(p, "zero", 0, count)) // insert at the beginning of array
    {
        count++;
    }

    if (insertAt(p, "two", count, count)) // insert at the end of array
    {
        count++;
    }

    if (insertAt(p, "one", 1, count)) // insert at element[1] or the "middle"
    {
        count++;
    }

    cout << "array: ";
    for (int i = 0; i < count; i++) // printing the array
    {
        cout << p[i] << ", ";
    }
    cout << '\n';

    delete[] p; // free the dynamic memory allocation
    return 0;
}

bool insertAt(string* p, string item, int index, int count)
{
    if (count >= ARR_SIZE) // check if array is full
    {
        return false;
    }

    if (index < 0 || index > count) // check if index is out of bounds
    {
        return false;
    }

    if (index == 0)
    {
        for (int i = count; i > 0; i--) // insert whatever at the beginning
        {
            p[i] = p[i - 1];
        }
        p[0] = item;
        return true;
    }

    if (index == count) // insert whatever at the end
    {
        p[count] = item;
        return true;
    }

    for (int i = count; i > index; i--) // insert at any other position
    {
        p[i] = p[i - 1];
    }
    p[index] = item;
    return true;
}
