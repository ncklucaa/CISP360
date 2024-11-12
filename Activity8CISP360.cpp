// Nick Luca, Diljot Singh, Anexa Thammavangsa

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const double STATE_SALE_TAX = 0.04, COUNTY_SALE_TAX = 0.02, TOTAL_SALE_TAX = 0.06, TOTAL_TAX = 1.06;
	double salesAmount, totalCollected, sales, countySaleTax, stateSaleTax, totalSaleTax;

	string month;
	int year;

	cout << "Enter the month: ";
	cin >> month;
	cout << "Enter the year: ";
	cin >> year;

	cout << "What was the total amount collected: ";
	cin >> totalCollected; // Total Collected

	salesAmount = (totalCollected) / (TOTAL_TAX); // Sales
	countySaleTax = (salesAmount) * (COUNTY_SALE_TAX); // County Sales Tax
	stateSaleTax = (salesAmount) * (STATE_SALE_TAX); // State Sales Tax
	totalSaleTax = (countySaleTax) + (stateSaleTax); // Sum of last two values (countySaleTax and stateSaleTax)


	cout << "\nReporting period: " << setw(13) << right << month << " " << year << endl;
	cout << "------------------------------------" << endl;

	cout << fixed << setprecision(2); 

	cout << setw(20) << left << "Total Collected:" << setw(6) << right << "$ " << setw(10) << totalCollected << endl;
	cout << setw(20) << left << "Sales:" << setw(6) << right << "$ " << setw(10) << salesAmount << endl;
	cout << setw(20) << left << "County Sales Tax:" << setw(6) << right << "$ " << setw(10) << countySaleTax << endl;
	cout << setw(20) << left << "State Sales Tax:" << setw(6) << right << "$ " << setw(10) << stateSaleTax << endl;
	cout << setw(20) << left << "Total Sales Tax:" << setw(6) << right << "$ " << setw(10) << totalSaleTax << endl;


	return 0;
}