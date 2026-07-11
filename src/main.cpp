#include <iostream>

#include "ui.hpp"
#include "dice.hpp"

using namespace std;

int main()
{
    
    bool playAgain = true;

    while (playAgain)
    {
        clearScreen();

        printHeader();

        int option = showMenu();

        switch (option)
        {
            case 1:
                playGame();
                break;

            case 2:
                playAgain = false;
                break;

            default:
                cout << "\nInvalid option.\n";
                break;
        }

        
    }
}