/*

Nick Luca
M12 Assignment
InventoryProgram.cpp

*/

#include "Inventory.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int numItems, itemNum, qty;
	double itemCost;

	do
	{
		cout << "Enter the number of items in your inventory: ";
		cin >> numItems;

		if (numItems <= 0)
		{
			cout << "Invalid input, the number in your inventory cannot be negative, please enter a positive number" << endl;

		}
	} while (numItems <= 0);

	Inventory* InventoryList = new Inventory[numItems];

	for (int i = 0; i < numItems; i++)
	{
		cout << "\nInputting details for item #" << (i + 1) << ": " << endl;

		do
		{
			cout << "Enter the item #";
			cin >> itemNum;

			if (itemNum < 0)
			{
				cout << "Invalid input, item number cannot be negative, please enter a positive number" << endl;
			}
		} while (itemNum < 0);

		do
		{
			cout << "Enter the quantity: ";
			cin >> qty;

			if (qty < 0)
			{
				cout << "Invalid input, your quantity cannot be negative, please enter a positive number" << endl;
			}
		} while (qty < 0);

		do
		{
			cout << "Enter the price per item $";
			cin >> itemCost;

			if (itemCost < 0)
			{
				cout << "Invalid input, item cost cannot be negative, please enter a positive number" << endl;
			}
		} while (itemCost < 0);

		InventoryList[i].setItemNumber(itemNum);
		InventoryList[i].setQuantity(qty);
		InventoryList[i].setCost(itemCost);
	}

	cout << "\nInventory List:" << endl;
	cout << "---------------------------------------------" << endl;
	cout << setw(10) << left << "Item #" << setw(10) << left << "Quantity" << setw(15) << left << "Cost" << setw(15) << left << "Total Cost" << endl;
	cout << "---------------------------------------------" << endl;

	for (int i = 0; i < numItems; i++)
	{
		cout << setw(10) << left << InventoryList[i].getItemNumber()
			<< setw(10) << left << InventoryList[i].getQuantity()
			<< setw(15) << left << fixed << setprecision(2) << InventoryList[i].getCost()
			<< "$" << setw(14) << left << InventoryList[i].getTotalCost() << endl;
	}

	cout << "---------------------------------------------" << endl;

	delete[] InventoryList;

	return 0;
}