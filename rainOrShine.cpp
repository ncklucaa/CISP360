/*

Nick Luca
M07 Assignment
Rain or Shine – rainOrShine.cpp

*/

#include <iostream>
#include <fstream>

using namespace std;

const int DAYS_IN_MONTH = 30;  /// number of days in each month

void weatherCalc(const char monthsInfo[], int &rainy, int &cloudy, int &sunny); /// function prototype
void weatherReport(const char month_1[], const char month_2[], const char month_3[]);  /// three 30-element parallel arrays of characters

int main()
{
	char month_1[DAYS_IN_MONTH];   /// three 30-element parallel arrays of characters
	char month_2[DAYS_IN_MONTH];   /// to store data for 3 months
	char month_3[DAYS_IN_MONTH];

	ifstream RainOrShineFile("RainOrShine.txt");  /// opens the file provided from prof

	if (!RainOrShineFile)
	{
		cout << "Unable to open file" << '\n';
		return 0;  /// exit program if file is unable to be opened
	}

	for (int count = 0; count < DAYS_IN_MONTH; count++)  /// reads the data from the file and puts it into the arrays
	{
		RainOrShineFile >> month_1[count];
	}
	for (int count = 0; count < DAYS_IN_MONTH; count++)
	{
		RainOrShineFile >> month_2[count];
	}
	for (int count = 0; count < DAYS_IN_MONTH; count++)
	{
		RainOrShineFile >> month_3[count];
	}

	RainOrShineFile.close();  /// closes the file

	weatherReport(month_1, month_2, month_3);

	return 0;
}

void weatherCalc(const char monthsInfo[], int &rainy, int &cloudy, int &sunny)
{
	rainy = 0;
	cloudy = 0;
	sunny = 0;

	for (int count = 0; count < DAYS_IN_MONTH; count++)
	{
		if (monthsInfo[count] == 'R')
		{
			rainy++;
		}
		else if (monthsInfo[count] == 'C')
		{
			cloudy++;
		}
		else if (monthsInfo[count] == 'S')
		{
			sunny++;
		}
	}
}

void weatherReport(const char month_1[], const char month_2[], const char month_3[])
{
	int month_1_Rainy, month_1_Cloudy, month_1_Sunny;
	int month_2_Rainy, month_2_Cloudy, month_2_Sunny;
	int month_3_Rainy, month_3_Cloudy, month_3_Sunny;

	weatherCalc(month_1, month_1_Rainy, month_1_Cloudy, month_1_Sunny);  /// calculates the numbers of each type of day for each month
	weatherCalc(month_2, month_2_Rainy, month_2_Cloudy, month_2_Sunny);
	weatherCalc(month_3, month_3_Rainy, month_3_Cloudy, month_3_Sunny);

	int total_Rainy = month_1_Rainy + month_2_Rainy + month_3_Rainy;
	int total_Cloudy = month_1_Cloudy + month_2_Cloudy + month_3_Cloudy;
	int total_Sunny = month_1_Sunny + month_2_Sunny + month_3_Sunny;

	int totalRain = month_1_Rainy;
	int mostRainMonth = 1;  /// assuming month 1 has the most rain to check with the if-function

	if (month_2_Rainy > totalRain)
	{
		totalRain = month_2_Rainy;
		mostRainMonth = 2;
	}
	if (month_3_Rainy > totalRain)
	{
		totalRain = month_3_Rainy;
		mostRainMonth = 3;
	}

	cout << "--------------------------------------" << '\n';
	cout << "Weather Report" << '\n';
	cout << '\n'; /// display reasons

	cout << "Month 1 had " << month_1_Rainy << " rainy days, " << month_1_Cloudy << " cloudy days, and " << month_1_Sunny << " sunny days" << '\n';
	cout << "Month 2 had " << month_2_Rainy << " rainy days, " << month_2_Cloudy << " cloudy days, and " << month_2_Sunny << " sunny days" << '\n';
	cout << "Month 3 had " << month_3_Rainy << " rainy days, " << month_3_Cloudy << " cloudy days, and " << month_3_Sunny << " sunny days" << '\n';

	cout << '\n';  /// display reasons

	cout << "Total for all 3 Months there was: " << total_Rainy << " rainy days, " << total_Cloudy << " cloudy days, and " << total_Sunny << " sunny days.";

	cout << '\n';  /// display reasons
	cout << '\n';  /// display reasons

	cout << "Out of the three months, Month " << mostRainMonth << " had the most rain with " << totalRain << " rainy days" << '\n';
	cout << "--------------------------------------" << '\n';
}