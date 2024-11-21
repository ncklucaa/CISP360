//**************
// Coin.cpp   **
//**************

#include "Coin.h" // header file
#include <cstdlib>
#include <ctime>

Coin::Coin() // constructor
{
    srand(time(0)); // seed the random number generator
    sideUp = rand() % 2; // coin starts at either 1 or 0 aka heads or tails
}

void Coin::Toss() // tossing coin
{
    sideUp = rand() % 2; // 1 or 0 to represent heads or tails side
}

int Coin::getSideUp() const // getting the side
{
    return sideUp; // returned either 1 or 0
}