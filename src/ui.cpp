#include <iostream>
#include <limits>
#include "ui.hpp"
#include "colors.hpp"

using namespace std;

void printHeader()
{
    cout <<Color::PINK;

    cout << "✿━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✿\n\n";
    cout << "            🎲 Dice Roller\n\n";
    cout << "               ݁₊ ⊹🌸⊹ ₊ ݁\n\n";
    cout << "✿━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✿\n\n";

    cout <<Color::RESET;
}

int showMenu()
{
    int option;

    cout << "⌞📎⌝ Menu\n\n";
    cout << "[1] 🎲 Roll dice\n";
    cout << "[2] 🚪 Exit\n\n";
    cout << "> ";

    cin >> option;

    //this ingnores whatever's left in memory
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return option;
}

void waitForEnter()
{
    cout << "Press ENTER to roll the dice.\n";

        // Wait for user input
        cin.get();
}

void printRollResult(int result)
{
    cout << "✿ Your dice rolled...\n";

    printDiceFace(result);

    cout << Color::MINT;
    cout << "✿ Result:  " << result << "!\n";
    cout << Color::RESET;

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

    //this ingnores whatever's left in memory
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return playAgain;
}

void printDiceFace(int value)
{
    switch(value)
    {
       
        case 1:
            cout << Color::LILAC;
            cout <<
            "╭───────╮\n"
            "│       │\n"
            "│   ●   │\n"
            "│       │\n"
            "╰───────╯\n\n";
            break;
            cout << Color::RESET;

        case 2:
            cout << Color::LILAC;
            cout <<
            "╭───────╮\n"
            "│ ●     │\n"
            "│       │\n"
            "│     ● │\n"
            "╰───────╯\n\n";
            break;
            cout << Color::RESET;

        case 3:
            cout << Color::LILAC;
            cout <<
            "╭───────╮\n"
            "│ ●     │\n"
            "│   ●   │\n"
            "│     ● │\n"
            "╰───────╯\n\n";   
            break;
            cout << Color::RESET;

        case 4:
            cout << Color::LILAC;
            cout <<
            "╭───────╮\n"
            "│ ●   ● │\n"
            "│       │\n"
            "│ ●   ● │\n"
            "╰───────╯\n\n";
            break;
            cout << Color::RESET;

        case 5:
            cout << Color::LILAC;
            cout <<
            "╭───────╮\n"
            "│ ●   ● │\n"
            "│   ●   │\n"
            "│ ●   ● │\n"
            "╰───────╯\n\n";
            break;
            cout << Color::RESET;

        case 6:
            cout << Color::LILAC;
            cout <<
            "╭───────╮\n"
            "│ ●   ● │\n"
            "│ ●   ● │\n"
            "│ ●   ● │\n"
            "╰───────╯\n\n";
            break;
            cout << Color::RESET;

         default:
            cout << "Invalid dice value.\n";
            break;

    }

}

void clearScreen()
{
    cout << "\033[2J\033[H";
}