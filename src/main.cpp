#include <iostream>

#include "ui.hpp"
#include "dice.hpp"

using namespace std;

int main()
{
    printHeader();
    
    bool playAgain = true;

    while (playAgain)
    {
        waitForEnter();

        int result = rollDice();

        printRollResult();

        playAgain = askPlayAgain();
    }
    return 0;
}