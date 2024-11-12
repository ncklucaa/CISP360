// Nick Luca, Diljot Singh, Anexa Thammavangsa

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int m, n;							// don't need constant in this problem
	double side1, side2, hypotenuse;

	cout << "Enter m: ";
	cin >> m;

	cout << "Enter n: ";
	cin >> n;

	side1 = pow(m, 2) - pow(n, 2);    // equation for side 1

	side2 = 2 * m * n;				// equation for side 2

	hypotenuse = sqrt(pow(side1, 2) + pow(side2, 2)); // equation for hypotenuse

	cout << fixed << setprecision(2); // display the result as floating-point numbers. 
	cout << "m = " << m << "n = " << n << "generates the triples " << side1 << "," << side2 << "," << hypotenuse << endl;

	return 0;

}