#include <iostream>
#include <limits>
#include "ui.hpp"

using namespace std;

void printHeader()
{
    cout << "✿━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✿\n\n";
    cout << "            🎲 Dice Roller\n\n";
    cout << "               ݁₊ ⊹🌸⊹ ₊ ݁\n\n";
    cout << "✿━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✿\n\n";

}

void waitForEnter()
{
    cout << "Press ENTER to roll the dice.\n";

        // Wait for user input
        cin.get();
}

void printRollResult(int result)
{
    printDiceFace(result);

    cout << "✿ You rolled a " << result << "!\n";

}

bool askPlayAgain()
{
    bool playAgain = true;

    cout << "\nRoll again? (y/n): ";

    char response = cin.get();
    
    cout <<"\n";

    if (response != 'y')
        {
            playAgain =false;
        }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return playAgain;
}

void printDiceFace(int value)
{
    switch(value)
    {
       
        case 1:
        
            cout <<
            "╭───────╮\n"
            "│       │\n"
            "│   ●   │\n"
            "│       │\n"
            "╰───────╯\n\n";
            break;
            
        case 2:

            cout <<
            "╭───────╮\n"
            "│ ●     │\n"
            "│       │\n"
            "│     ● │\n"
            "╰───────╯\n\n";
            break;

        case 3:

            cout <<
            "╭───────╮\n"
            "│ ●     │\n"
            "│   ●   │\n"
            "│     ● │\n"
            "╰───────╯\n\n";   
            break;

        case 4:

            cout <<
            "╭───────╮\n"
            "│ ●   ● │\n"
            "│       │\n"
            "│ ●   ● │\n"
            "╰───────╯\n\n";
            break;

        case 5:

            cout <<
            "╭───────╮\n"
            "│ ●   ● │\n"
            "│   ●   │\n"
            "│ ●   ● │\n"
            "╰───────╯\n\n";
            break;

        case 6:

            cout <<
            "╭───────╮\n"
            "│ ●   ● │\n"
            "│ ●   ● │\n"
            "│ ●   ● │\n"
            "╰───────╯\n\n";
            break;

         default:
            cout << "Invalid dice value.\n";
            break;

    }
}