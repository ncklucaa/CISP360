/*

Nick Luca
Activity 31: Working with Binary Files and Structs
activity31.cpp

*/

#include "act31.h"
#include <iomanip>

using namespace std;

void addNewRecords()
{
	ofstream outFile("inventory.dat", ios::app | ios::binary);

	if (!outFile)
	{
		cout << "Unable to open file for input" << endl;
		return;
	}
	
	Inventory item;

	cin.ignore();

	cout << "Enter the Item Description: ";
	cin.getline(item.itemDescription, sizeof(item.itemDescription));
	cout << endl;

	cout << "Enter the Product ID: ";
	cin.getline(item.productID, sizeof(item.productID));
	cout << endl;

	cout << "Enter the Quantity you have on hand: ";
	cin >> item.quantityOnHand;
	cin.ignore();
	cout << endl;

	cout << "Enter the Wholesale Price: ";
	cin >> item.wholesaleCost;
	cin.ignore();
	cout << endl;

	cout << "Enter the Retail Price: ";
	cin >> item.retailCost;
	cin.ignore();
	cout << endl;

	outFile.write(reinterpret_cast<char*>(&item), sizeof(item));
	outFile.close();

	cout << "Record added to inventory" << endl;
	cout << endl;
}

void showAllRecords()
{
	char choice;
	
	ifstream inFile("inventory.dat", ios::binary);

	if (!inFile)
	{
		cout << "Unable to open file for output";
		return;
	}

	Inventory item;
	cout << endl;

	cout << setw(45) << "Inventory Records" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << left << setw(15) << "Description" << setw(15) << "Product ID" << setw(12) << "Quantity" << setw(20) << "Wholesale Price" << setw(15) << "Retail Price" << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	while (inFile.read(reinterpret_cast<char*>(&item), sizeof(item)))
	{
		cout << left << setw(15) << item.itemDescription << setw(15) << item.productID << setw(12) << item.quantityOnHand << setw(20) << fixed << setprecision(2) << item.wholesaleCost
			<< setw(15) << fixed << setprecision(2) << item.retailCost << endl;
	}

	cout << endl;

	do
	{
		cout << "Would you like to add another record? (Y/N): ";
		cin >> choice;
		//cin.ignore();
		choice = toupper(choice);

		if (choice == 'Y')
		{
			addNewRecords();
		}
		else if (choice != 'N')
		{
			cout << "Invalid option, please pick Yes or No" << endl;
		}
	} while (choice != 'Y' && choice != 'N');

}
// end of activity31.cpp