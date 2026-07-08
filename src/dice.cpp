#include <random>
#include <limits>
#include "dice.hpp"

using namespace std;

int rollDice()
{
    // random number generator
    static random_device randomDevice;

    //generate random number
    static mt19937 gen(randomDevice()); 

    //limits of the dice
    static uniform_int_distribution<> diceDistribution(1,6); 

    // return a random number between 1 and 6
    return diceDistribution(gen); 
}