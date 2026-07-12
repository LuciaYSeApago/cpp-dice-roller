#pragma once

#ifndef UI_HPP
#define UI_HPP

#include <string>

void waitForEnter();
void printHeader();
bool askPlayAgain();
void clearScreen();
int chooseDice();

void printRollResult(int result, int sides);
void printDiceFace(int value);
void printStatistics(int rolls,int highest,int lowest,double average);

int showMenu(const std::string& TITLE, const std::string OPTIONS[], int size );
int showMainMenu();

void rollingAnimation();
#endif