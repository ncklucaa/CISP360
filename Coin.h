//**************
// Coin.h     **
//**************

#ifndef COIN_H // if not defined
#define COIN_H // define if not defined

class Coin // class
{
	private:
		int sideUp; // sideUp member variable will hold either 1 to indicate “heads” or 0 to indicate “tails”
	public:
		Coin(); // default constructor
		void Toss(); // simulates the tossing of the coin
		int getSideUp() const; // that returns the value of the sideUp member variable
};

#endif // end the ifndef