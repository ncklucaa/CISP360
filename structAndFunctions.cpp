/*

Nick Luca
Activity 27: Structures and Functions (Individual Work)

*/

#include <iostream>

using namespace std;

struct Numlist {
    float* list;   /* list of values - must be dynamically allocated */
    int   len;     /* count of values in list   */
    float min,     /* the minimal value in list */
        max,     /* the maximal value in list */
        avg;     /* the mean of the numbers   */
};

void getInput(Numlist &num)
{
    int i;
    
    cout << "How big would you like your list size to be? (minimum 3): ";
    cin >> num.len;

    while (num.len < 3)
    {
        cout << "Too short enter another number (minimum 3): ";
        cin >> num.len;
    }

    num.list = new float[num.len];

    cout << "Enter " << num.len << " numbers" << endl;
    cout << "_____________________________________" << endl;

    for (i = 0; i < num.len; i++)
    {
        cout << "Element " << "[" << i << "]" << " = ";
        cin >> num.list[i];
    }

    num.min = num.list[0];
    num.max = num.list[0];
    num.avg = 0;

    for (i = 0; i < num.len; i++)
    {
        if (num.list[i] < num.min)
        {
            num.min = num.list[i];
        }
        if (num.list[i] > num.max)
        {
            num.max = num.list[i];
        }
        num.avg += num.list[i];
    }
    num.avg /= num.len;
}

void display(const Numlist &num)
{
    int i;

    cout << endl;
    cout << "Numbers in the list: ";

    for (i = 0; i < num.len; i++)
    {
        cout << num.list[i] << " ";
    }

    cout << endl;
    cout << "Total Elements: " << num.len << endl; // how many numbers
    cout << "Minimum Value: " << num.min << endl; // min
    cout << "Maximum Value: " << num.max << endl; // max
    cout << "Average Value: " << num.avg << endl; // mean
}

int main()
{
    Numlist num;

    getInput(num);

    display(num);

    delete[] num.list;

    return 0;
}