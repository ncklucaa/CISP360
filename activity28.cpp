/*

Nick Luca
Activity 28: Pointers to Structure (Individual Work)

*/

#include <iostream>

using namespace std;

struct Numlist {
    float* list;   /* list of values */
    int   len;     /* count of values in list   */
    float min,     /* the minimal value in list */
        max,     /* the maximal value in list */
        avg;     /* the mean of the numbers   */
};

int computeStats(Numlist* numlist)
{
    int i;
    float val;
    
    if (numlist == nullptr)
    {
        return -1;
    }
    if (numlist->list == nullptr)
    {
        return -2;
    }
    if (numlist->len <= 0)
    {
        return -3;
    }

    float min = numlist->list[0];
    float max = numlist->list[0];
    float sum = 0.0;

    for (i = 0; i < numlist->len; i++)
    {
        val = numlist->list[i];

        if (val < min)
        {
            min = val;
        }
        if (val > max)
        {
            max = val;
        }
        sum += val;
    }

    numlist->min = min;
    numlist->max = max;
    numlist->avg = sum / numlist->len;

    return 0;
}

int main()
{
    float list_3[] = { 69.0, 420.0, 333.0 };
    float list_4[] = { 55.5, 57.2, 18.8, 35.1, 62.0 };
    int result = computeStats(nullptr);

    if (result == -1)
    {
        cout << "Code -1 nullptr structure pointer received" << endl;
    }

    Numlist nullListPtrCase = { nullptr, 5, 0.0, 0.0, 0.0 };
    result = computeStats(&nullListPtrCase);

    if (result == -2)
    {
        cout << "Code -2 number list pointer is nullptr" << endl;
    }

    Numlist invalidLen = { list_3, 0, 0.0, 0.0, 0.0 };
    result = computeStats(&invalidLen);

    if (result == -3)
    {
        cout << "Code -3 length of list is invalid; must be larger than 0" << endl;
    }

    Numlist inputValid = { list_4, 5, 0.0, 0.0, 0.0 };
    result = computeStats(&inputValid);

    if (result == 0)
    {
        cout << "no error" << endl;
        cout << "min: " << inputValid.min << endl;
        cout << "max: " << inputValid.max << endl;
        cout << "avg: " << inputValid.avg << endl;
    }
    else
    {
        cout << "error" << endl;
    }

    return 0;
}