// Nick Luca, Diljot Singh, Anexa Thammavangsa

#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

int main()
{
	const int MAX_LIMIT = 12, MIN_LIMIT = 2;
	const int RANGE = MAX_LIMIT - MIN_LIMIT + 1;
	double value;
	int random_number;

	srand(time(0));
	random_number = rand() % RANGE + MIN_LIMIT;
	cout << random_number << endl;

	const int MAX_LIMIT = 6, MIN_LIMIT = 1;


}