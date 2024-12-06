/*

Nick Luca
Activity 31: Working with Binary Files and Structs
main.cpp

*/

#include "act31.h"

using namespace std;

int main()
{
	int choice;

	do
	{
		cout << "Inventory Records" << endl;
		cout << "1. Add new records to the file" << endl;
		cout << "2. Display all records in the file" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice >= 1 && choice <= 2)
		{
			if (choice == 1)
			{
				addNewRecords();
			}
			else if (choice == 2)
			{
				showAllRecords();
			}
		}
		else
		{
			cout << "Invalid choice, please try again" << endl;
		}
	} while (choice != 2);

	return 0;
}
// end of main.cpp