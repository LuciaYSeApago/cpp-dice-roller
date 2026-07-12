#include <iostream>

//Dice limits
#include <limits>
//Double limits
#include <iomanip>
//Rolling animation
#include <thread>
#include <chrono>

#include "ui.hpp"
#include "colors.hpp"

using namespace std;

void printHeader()
{
    cout <<Color::PINK

         << "✿━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✿\n\n"
         << "            🎲 Dice Roller\n\n"
         << "               ݁₊ ⊹🌸⊹ ₊ ݁\n\n"
         << "✿━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✿\n\n"

         <<Color::RESET;
}

// int showMenu()
// {
//     int option;

//     cout << "⌞✿⁠⌝ Menu\n\n";
//     cout << "[1] 🎲 Roll dice\n";
//     cout << "[2] 🚪 Exit\n\n";
//     cout << "> ";

//     cin >> option;

//     //this ingnores whatever's left in memory
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');

//     return option;
//}

int showMainMenu()
{
    const string options[] =
    {
        "🎲 Roll Dice",
        "🚪 Exit"
    };
    
    return showMenu("⌞✿⌝ Main Menu", options, 2);
    
}

//In headers better to use std
int showMenu(const std::string& TITLE, const std::string OPTIONS[], int size )
{


    while (true)
    {
        clearScreen();
        
        cout <<Color:: LILAC 
             << TITLE << "\n\n"
             << Color::RESET;

        for(int i = 0; i < size; i++)
        {
            cout <<Color::CREAM
                 << i + 1 << ". "<< OPTIONS[i] << "\n"
                 << Color::RESET;
        }

        cout << "\n";

        int option;

        cin >> option;
        if (cin.fail())
        {
            cout << Color::MINT
                  << "\n❀ Please enter a valid number.\n\n"
                  << Color::RESET;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n> ";
        }
        else if (option > 0 && option <= size )
        {  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clearScreen();
            return option;
        }
        else
        {
            cout << Color::MINT
                 << "\n❀ Please choose an option between 1 and " << size <<".\n\n"
                 << Color::RESET;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n> ";
        }
    }
}

int chooseDice()
{
    const string OPTIONS [] =
     {
        "d4",
        "d6",
        "d8",
        "d10",
        "d12",
        "d20",
        "Back"
    };

    int option = showMenu("⌞✿⌝ Choose your dice", OPTIONS, 7);

    switch(option)
    {
        case 1: 
            return 4;

        case 2: 
            return 6;

        case 3: 
            return 8;

        case 4:     
            return 10;

        case 5: 
            return 12;

        case 6: 
            return 20;

        default: 
            return 0;
    
    }
}

void waitForEnter()
{   
    cout <<Color::PINK;
    cout << "Press ENTER to roll the dice.\n";

    // Wait for user input
    cin.get();
    cout << Color::RESET;
}

void printRollResult(int result, int sides)
{   
    cout <<Color::PINK
         << "✿ Your dice rolled...\n"
         << Color::RESET;

    if (sides == 6)
    {
        printDiceFace(result);
    }
    
    cout << Color::PINK
         << "🎲 d" << sides << "\n"
         << "✨ Result:  " << result << "\n"
         << Color::RESET;

}

void printStatistics(int rolls,int highest,int lowest,double average)
{
    cout << Color::PINK

         << "✿━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✿\n\n"
         << Color::RESET;

    cout <<Color::LILAC
         << "🌿 Session Stats \n\n"
         << Color::RESET;

    cout <<Color::PINK;
        cout << "🎲 Rolls      : "<< rolls <<"\n";
        cout << "✨ Highest    : "<< highest <<"\n";
        cout << "🌱 Lowest     : "<< lowest <<"\n";

        // Show the average with two decimal places
        cout << fixed << setprecision(2);
        cout << "🩷 Average    : " << average << "\n";
        cout << defaultfloat;
        cout << "✿━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✿\n\n";
        cout << '\n';
        cout <<Color::RESET; 
}

bool askPlayAgain()
{
    cout <<Color::PINK;
    bool playAgain = true;

    cout << "\nRoll again? (y/n): ";

    char response = cin.get();
    
    cout <<"\n";

    if (response != 'y')
        {
            playAgain =false;
        }

    //Ingnore whatever's left in memory
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout <<Color::RESET;

    return playAgain;
}

void printDiceFace(int value)
{
    switch(value)
    {
       
        case 1:
            cout <<Color::LILAC;
            
            cout <<"╭───────╮\n";
            cout <<"│       │\n";
            cout <<"│   ●   │\n";
            cout <<"│       │\n";
            cout <<"╰───────╯\n\n";
            cout << Color::RESET;
            break;

        case 2:
            cout <<Color::LILAC;
            
            cout <<"╭───────╮\n";
            cout <<"│ ●     │\n";
            cout <<"│       │\n";
            cout <<"│     ● │\n";
            cout <<"╰───────╯\n\n";
            cout << Color::RESET;
            break;

        case 3:
            cout <<Color::LILAC;
            
            cout <<"╭───────╮\n";
            cout <<"│ ●     │\n";
            cout <<"│   ●   │\n";
            cout <<"│     ● │\n";
            cout <<"╰───────╯\n\n";  
            cout << Color::RESET;
            break;

        case 4:
            cout <<Color::LILAC;
            
            cout <<"╭───────╮\n";
            cout <<"│ ●   ● │\n";
            cout <<"│       │\n";
            cout <<"│ ●   ● │\n";
            cout <<"╰───────╯\n\n";
            cout << Color::RESET;
            break;
            
        case 5:
            cout <<Color::LILAC;
            
            cout <<"╭───────╮\n";
            cout <<"│ ●   ● │\n";
            cout <<"│   ●   │\n";
            cout <<"│ ●   ● │\n";
            cout <<"╰───────╯\n\n";
            cout << Color::RESET;
            break;
            
        case 6:
            cout <<Color::LILAC;
        
            cout <<"╭───────╮\n";
            cout <<"│ ●   ● │\n";
            cout <<"│ ●   ● │\n";
            cout <<"│ ●   ● │\n";
            cout <<"╰───────╯\n\n";
            cout << Color::RESET;
            break;
            
         default:
            
            cout <<Color::MINT;
            cout << "Invalid dice value.\n";
            cout << Color::RESET;
                    break;
                 
    }

}

void clearScreen()
{
    cout << "\033[2J\033[H";
}

void rollingAnimation()
{
    
    //Same as using namespace std but for clocks
    using namespace std::chrono_literals;

    cout <<Color::MINT;
    cout << "\nRolling";

    for (int i = 0; i < 3; i++)
    {
        cout << ".";

        // Force the dots to appear immediately
        cout.flush();

        //Also works if you havent imported std
        //std::this_thread::sleep_for(300ms);

        this_thread::sleep_for(300ms);
    }
    cout << Color::RESET;
    cout << "\n\n";
}