/*

Nick Luca
Activity 17

*/

#include <iostream>

using namespace std;

const int SIZE = 8;  /// 8 numbers the user can input

/// functions
void populate(int array[], int size);
void find3SmallestNumbers(int array[], int size, long long &smallest1, long long &smallest2, long long &smallest3);

int main()
{
	int nums[SIZE]; // array size of 8 elements

	populate(nums, SIZE); // so size = SIZE;

	cout << "--------------------------------" << '\n'; /// display reasons

	cout << "numbers: ";  /// numberes entered by the user
	for (int count = 0; count < SIZE; count++)
	{
		cout << nums[count] << " ";
	}
	cout << '\n';

	long long smallest1, smallest2, smallest3;

	find3SmallestNumbers(nums, SIZE, smallest1, smallest2, smallest3);

	cout << "the three smallest numbers are: " << smallest1 << " " << smallest2 << " and " << smallest3 << '\n';

	cout << "--------------------------------" << '\n'; /// display reasons

	return 0;
}

void populate(int array[], int size)
{
	cout << "Enter " << size << " random numbers: ";
	for (int count = 0; count < size; count++)
	{
		cin >> array[count];
	}
}

void find3SmallestNumbers(int array[], int size, long long &smallest1, long long &smallest2, long long &smallest3)
{
	smallest1 = smallest2 = smallest3 = 100000000000000000; // just incase you guys pick huge numbers

	for (int count = 0; count < size; count++)
	{
		if (array[count] < smallest1)
		{
			smallest3 = smallest2;
			smallest2 = smallest1;
			smallest1 = array[count];
		}
		else if (array[count] < smallest2)
		{
			smallest3 = smallest2;
			smallest2 = array[count];
		}
		else if (array[count] < smallest3)
		{
			smallest3 = array[count];
		}
	}
}