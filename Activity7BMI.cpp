// Nick Luca, Diljot Singh, Anexa Thammavangsa

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double weight, height, BMI;
	const int BODY_MAX_INDEX = 703;

	cout << "Body Max Index (BMI) Calculator\n\n";

	cout << "Enter your weight in pounds: ";
	cin >> weight;

	cout << "Enter your height in inches: ";
	cin >> height;

	cout << fixed << setprecision(1);
	
	BMI = (weight * BODY_MAX_INDEX) / pow(height, 2);

	if (BMI < 18.5)
	{
		cout << "You are Underweight";
	}
	else if (BMI >= 18.5 && BMI < 25.0)
	{
		cout << "You are Optimal";
	}
	else if (BMI >= 25.0 && BMI < 30.0)
	{
		cout << "You are Overweight";
	}
	else if (BMI >= 30.0)
	{
		cout << "You are Obese";
	}

	return 0;

}