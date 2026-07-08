#include <iostream>

#include "ui.hpp"
#include "dice.hpp"

using namespace std;

int main()
{
    printHeader();
    cout << "Press ENTER to roll the dice.\n";

    // Wait for user input
    cin.get();

    cout << "\nYou rolled a " << rollDice() << "!\n";
    return 0;
}