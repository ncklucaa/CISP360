/*

Nick Luca
M12 Assignment
Inventory.h

*/

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
	private:
		int itemNumber;
		int quantity;
		double cost;
		double totalCost;
	public:
		Inventory();
		Inventory(int itemNum, int qty, double itemCost);
		void setItemNumber(int itemNum);
		void setQuantity(int qty);
		void setCost(double itemCost);
		double getCost() const;
		double getTotalCost() const;
		int getItemNumber() const;
		int getQuantity() const;

};

#endif