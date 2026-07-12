#include <random>
#include <limits>
#include <iostream>
#include "dice.hpp"
#include "ui.hpp"

using namespace std;

int rollDice(int sides)
{
    // random number generator
    static random_device randomDevice;

    //generate random number
    static mt19937 gen(randomDevice()); 

    //limits of the dice
    uniform_int_distribution<> diceDistribution(1,sides); 

    // return a random number between 1 and 6
    return diceDistribution(gen); 
}

void playGame()
{
    bool playAgain = true;
    int rolls = 0;
    int highest = 0;
    int lowest = 0;
    double total = 0;

    while (playAgain)
    {
        int sides = chooseDice();

        if (sides == 0)
        {
            return;
        }

        cout <<"\n El usuario ha elegido un dado de "<< sides << " caras.\n\n";

        waitForEnter();

        int result = rollDice(sides);

        printRollResult(result, sides);

        if (rolls == 0)
        {
            highest = result;
            lowest = result;
        }

        rolls ++;
        total += result;

        if (result > highest)
        {
            highest = result;
        }

        if (result < lowest)
        {
            lowest = result;
        }

        double average = total / rolls;

        printStatistics(rolls, highest, lowest, average);

        playAgain = askPlayAgain();
    }
}