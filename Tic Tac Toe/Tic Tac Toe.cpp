// Tic Tac Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

const char* INDENT = "\x1b[5C";
const char* const RED = "\x1b[91m";
const char* const BLUE = "\x1b[94m";
const char* const WHITE = "\x1b[97m";

const char const PLAYER1 = 'X';
const char const PLAYER2 = 'O';
const char const EMPTY = '-';

const char* const BLANK = "\n\n\n\n"; //creates a large amount of space between lines

const char* map[3][3];


bool gameOver;
bool player1;


void initializeMap()
{
	for (int y = 0; y < 3; y++)
	{
		cout << INDENT;
		for (int x = 0; x < 3; x++)
		{
			cout << " [ " << map[y][x] = EMPTY << " ] ";
		}
		cout << std::endl;
	}
}

void drawMap()
{
	for (int y = 0; y < 3; y++)
	{
		cout << INDENT;
		for (int x = 0; x < 3; x++)
		{
			cout << " [ " << map[y][x] << " ] ";
		}
		cout << std::endl;
	}
}

void getCommand()
{

}

int main()
{
	cout << endl;
	cout << endl;
	cout << INDENT << "Welcome to Tic Tac Toe. To play use the arrow keys to move your token and press enter to confirm." << endl;
	cout << INDENT << "Red Player (X) goes first" << endl;
	cout << BLANK;

	drawMap();


	std::cin.clear(); 
	std::cin.ignore(std::cin.rdbuf()->in_avail()); 
	std::cin.get();
}

