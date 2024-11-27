/*

Nick Luca
M12 Assignment
Inventory.cpp

*/

#include "Inventory.h"

Inventory::Inventory()
{
	itemNumber = 0;
	quantity = 0;
	cost = 0.0;
	totalCost = 0.0;
}

Inventory::Inventory(int itemNum, int qty, double itemCost)
{
	itemNumber = itemNum;
	quantity = qty;
	cost = itemCost;
	totalCost = quantity * cost;
}

void Inventory::setItemNumber(int itemNum)
{
	itemNumber = itemNum;
}

void Inventory::setQuantity(int qty)
{
	quantity = qty;
	totalCost = quantity * cost;
}

void Inventory::setCost(double itemCost)
{
	cost = itemCost;
	totalCost = quantity * cost;
}

double Inventory::getCost() const
{
	return cost;
}

double Inventory::getTotalCost() const
{
	return totalCost;
}

int Inventory::getItemNumber() const
{
	return itemNumber;
}

int Inventory::getQuantity() const
{
	return quantity;
}