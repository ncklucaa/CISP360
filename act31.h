/*

Nick Luca
Activity 31: Working with Binary Files and Structs
act31.h

*/

#ifndef ACT31_H
#define ACT31_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Inventory
{
	char itemDescription[50];
	char productID[20];
	int quantityOnHand;
	double wholesaleCost;
	double retailCost;

};

void addNewRecords();
void showAllRecords();

#endif
// end of act31.h