// Tic Tac Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>
#include <windows.h>


using namespace std;

const char* const RED = "\x1b[91m";
const char* const BLUE = "\x1b[94m";
const char* const WHITE = "\x1b[97m";

const char* const CSI = "\x1b[";
const char* INDENT = "\x1b[5C";

//Creates what will be put into the spaces
const char* const PLAYER1 = "\x1b[91m[ X ]";
const char* const PLAYER2 = "\x1b[94m[ O ]";
const char* const EMPTY = "\x1b[97m[ - ]";

const char* const BLANK = "\n\n\n"; //creates a large amount of space between lines

const char* map[3][3];


bool gameover = false;
bool player1 = true;
bool m_winVertical = false;
bool m_winHorizontal = false;
bool m_winDiagonal = false;
bool m_tie = false;

//Creates the map and its spaces
void initializeMap()
{
	for (int y = 0; y < 3; y++)
	{		
		for (int x = 0; x < 3; x++)
		{
			  map[x][y] = EMPTY;
		}		
	}
}

void drawMap()
{
	for (int y = 0; y < 3; y++)
	{
		cout << INDENT;
		for (int x = 0; x < 3; x++)
		{
			
			cout << map[x][y];
		}
		cout << endl;
	}
	cout << BLANK;
}

//checks if either player has won vertically
bool winVertical()
{
	//Colomn 1 win
	if (map[0][0] == PLAYER1 && map[0][1] == PLAYER1 && map[0][2] == PLAYER1)
	{
		cout << RED << "Player 1 wins!" << endl;
		return m_winVertical = true;
		
	}
	else if (map[0][0] == PLAYER2 && map[0][1] == PLAYER2 && map[0][2] == PLAYER2)
	{
		cout << BLUE << "Player 2 wins!" << endl;
		return m_winVertical = true;
		
	}
	//Colomn 2 win
	else if (map[1][0] == PLAYER1 && map[1][1] == PLAYER1 && map[1][2] == PLAYER1)
	{
		cout << RED << "Player 1 wins!" << endl;
		return m_winVertical = true;
		
	}
	else if (map[1][0] == PLAYER2 && map[1][1] == PLAYER2 && map[1][2] == PLAYER2)
	{
		cout << BLUE << "Player 2 wins!" << endl;
		return m_winVertical = true;
		
	}
	//Colomn 3 win
	else if (map[2][0] == PLAYER1 && map[2][1] == PLAYER1 && map[2][2] == PLAYER1)
	{
		cout << RED << "Player 1 wins!" << endl;
		return m_winVertical = true;
		
	}
	else if (map[2][0] == PLAYER2 && map[2][1] == PLAYER2 && map[2][2] == PLAYER2)
	{
		cout << BLUE << "Player 2 wins!" << endl;
		return m_winVertical = true;
		
	}
}

//checks if either player has won horizontally
bool winHorizontal()
{
	//Row 1 win
	if (map[0][0] == PLAYER1 && map[0][1] == PLAYER1 && map[2][0] == PLAYER1)
	{
		cout << RED << "Player 1 wins!" << endl;
		return m_winHorizontal = true;
		
		
	}
	else if (map[0][0] == PLAYER2 && map[1][0] == PLAYER2 && map[2][0] == PLAYER2)
	{
		cout << BLUE << "Player 2 wins!" << endl;
		return m_winHorizontal = true;
		
	}
	//Row 2 win
	else if (map[0][1] == PLAYER1 && map[1][1] == PLAYER1 && map[2][1] == PLAYER1)
	{
		cout << RED << "Player 1 wins!" << endl;
		return m_winHorizontal = true;
		
	}
	else if (map[0][1] == PLAYER2 && map[1][1] == PLAYER2 && map[2][1] == PLAYER2)
	{
		cout << BLUE << "Player 2 wins!" << endl;
		return m_winHorizontal = true;
		
	}
	//Row 3 win
	else if (map[0][2] == PLAYER1 && map[1][2] == PLAYER1 && map[2][2] == PLAYER1)
	{
		cout << RED << "Player 1 wins!" << endl;
		return m_winHorizontal = true;
		
	}
	else if (map[0][2] == PLAYER2 && map[1][2] == PLAYER2 && map[2][2] == PLAYER2)
	{
		cout << BLUE << "Player 2 wins!" << endl;
		return m_winHorizontal = true;
		
	}
}

//checks if either player has won diagonally
bool winDiagonal()
{
	if (map[0][0] == PLAYER1 && map[1][1] == PLAYER1 && map[2][2] == PLAYER1)
	{
		cout << RED << "Player 1 wins!" << endl;
		return m_winDiagonal= true;
		
	}
	else if (map[0][0] == PLAYER2 && map[1][1] == PLAYER2 && map[2][2] == PLAYER2)
	{
		cout << BLUE << "Player 2 wins!" << endl;
		return m_winDiagonal = true;
		
	}
	//Row 2 win
	else if (map[2][0] == PLAYER1 && map[1][1] == PLAYER1 && map[0][2] == PLAYER1)
	{
		cout << RED << "Player 1 wins!" << endl;
		return m_winVertical = true;
		
	}
	else if (map[2][0] == PLAYER2 && map[1][1] == PLAYER2 && map[0][2] == PLAYER2)
	{
		cout << BLUE << "Player 2 wins!" << endl;
		return m_winVertical = true;
		
	}
}

//checks if the players tie
bool tie()
{
	if (m_winDiagonal == false && m_winHorizontal == false && m_winDiagonal == false && map[0][0] != EMPTY && map[1][0] != EMPTY && map[2][0] != EMPTY && map[0][1] != EMPTY && map[1][1] != EMPTY && map[2][1] != EMPTY && map[0][2] != EMPTY && map[1][2] != EMPTY && map[2][2] != EMPTY)
	{
		cout << WHITE << "No one wins, you both suck" << endl;
	
		return m_tie = true;
	}
}

bool gameOver()
{
	if (m_winDiagonal == true || m_winHorizontal == true || m_winVertical == true || m_tie == true)
	{
		cout << endl << INDENT << "Press 'Enter' to exit the program.";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin.get(); 
		return gameover== true;
	}
}
//Gets the players command
void getCommand()
{
	//Wont read commands longer than 10
	char input[10] = "\0";
	// jump to the correct location 
	std::cout << CSI << 19 << ";" << 0 << "H";
	//clears existing text
	cout << CSI << "5M";

	std::cout << INDENT << WHITE << "Enter a coordinate.";

	// move cursor to position for player to enter input
	std::cout << CSI << 19 << ";" << 30 << "H" ;
	std::cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> input;


	//For if Player 1 is going
	if (player1 == true)
	{ 
		while (input)
		{
			

			if (strcmp(input, "00") == 0 && map[0][0] == EMPTY || strcmp(input, "0,0") == 0 && map[0][0] == EMPTY)
			{
				map[0][0] = PLAYER1;
			}
			else if (strcmp(input, "01") == 0 && map[0][1] == EMPTY || strcmp(input, "0,1") == 0 && map[0][1] == EMPTY)
			{
				map[0][1] = PLAYER1;
			}
			else if (strcmp(input, "02") == 0 && map[0][2] == EMPTY || strcmp(input, "0,2") == 0 && map[0][2] == EMPTY)
			{
				map[0][2] = PLAYER1;
			}
			else if (strcmp(input, "10") == 0 && map[1][0] == EMPTY || strcmp(input, "1,0") == 0 && map[1][0] == EMPTY)
			{
				map[1][0] = PLAYER1;
			}
			else if (strcmp(input, "11") == 0 && map[1][1] == EMPTY || strcmp(input, "1,1") == 0 && map[1][1] == EMPTY)
			{
				map[1][1] = PLAYER1;
			}
			else if (strcmp(input, "12") == 0 && map[1][2] == EMPTY || strcmp(input, "1,2") == 0 && map[1][2] == EMPTY)
			{
				map[1][2] = PLAYER1;
			}
			else if (strcmp(input, "20") == 0 && map[2][0] == EMPTY || strcmp(input, "2,0") == 0 && map[2][0] == EMPTY)
			{
				map[2][0] = PLAYER1;
			}
			else if (strcmp(input, "21") == 0 && map[2][1] == EMPTY || strcmp(input, "2,1") == 0 && map[2][1] == EMPTY)
			{
				map[2][1] = PLAYER1;
			}
			else if (strcmp(input, "22") == 0 && map[2][2] == EMPTY || strcmp(input, "2,2") == 0 && map[2][2] == EMPTY)
			{
				map[2][2] = PLAYER1;
			}
			else
			{
				cout << INDENT << WHITE << "You have entered invalid input or tried to take a spot thats already occupied. You lose your turn" << endl;
			}
			
			char next = cin.peek();
			player1 = false;
			
			

			if (winVertical() == true)
			{
				winVertical();
				gameOver();
				break;
			}

			if (m_winHorizontal == true)
			{
				winHorizontal();
				gameOver();
				break;
			}

			if (m_winDiagonal == true)
			{
				winDiagonal();
				gameOver();
				break;
			}

			if (m_tie == true)
			{
				tie();
				gameOver();
				break;
			}


			if (next == '\n' || next == EOF)
				break;

			cin >> input;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cin.get();
		}
	}

	else //if (player1 == false)
	{
		while (input)
		{
			if (strcmp(input, "00") == 0 && map[0][0] == EMPTY || strcmp(input, "0,0") == 0 && map[0][0] == EMPTY)
			{				
				map[0][0] = PLAYER2;
			}
			else if (strcmp(input, "01") == 0 && map[0][1] == EMPTY || strcmp(input, "0,1") == 0 && map[0][1] == EMPTY)
			{
				map[0][1] = PLAYER2;
			}
			else if (strcmp(input, "02") == 0 && map[0][2] == EMPTY || strcmp(input, "0,2") == 0 && map[0][2] == EMPTY)
			{
				map[0][2] = PLAYER2;
			}
			else if (strcmp(input, "10") == 0 && map[1][0] == EMPTY || strcmp(input, "1,0") == 0 && map[1][0] == EMPTY)
			{
				map[1][0] = PLAYER2;
			}
			else if (strcmp(input, "11") == 0 && map[1][1] == EMPTY || strcmp(input, "1,1") == 0 && map[1][1] == EMPTY)
			{
				map[1][1] = PLAYER2;
			}
			else if (strcmp(input, "12") == 0 && map[1][2] == EMPTY || strcmp(input, "1,2") == 0 && map[1][2] == EMPTY)
			{
				map[1][2] = PLAYER2;
			}
			else if (strcmp(input, "20") == 0 && map[2][0] == EMPTY || strcmp(input, "2,0") == 0 && map[2][0] == EMPTY)
			{
				map[2][0] = PLAYER2;
			}
			else if (strcmp(input, "21") == 0 && map[2][1] == EMPTY || strcmp(input, "2,1") == 0 && map[2][1] == EMPTY)
			{
				map[2][1] = PLAYER2;
			}
			else if (strcmp(input, "22") == 0 && map[2][2] == EMPTY || strcmp(input, "2,2") == 0 && map[2][2] == EMPTY)
			{
				map[2][2] = PLAYER2;
			}
			else
			{
				cout << INDENT << WHITE << "You have entered invalid input or tried to take a spot thats already occupied. You lose your turn" << endl;
			}
			char next = cin.peek();
			player1 = true;
			



			if (next == '\n' || next == EOF)
				break;
			
			cin >> input;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cin.get();
		}
	}
}

void Game() 
{

	initializeMap();

	while (m_winVertical == false || m_winHorizontal == false || m_winDiagonal == false || tie == false)
	{ 
		cout << endl;
			cout << endl;
			cout << INDENT << WHITE << "Welcome to Tic Tac Toe. \n" << INDENT << "To play type in the coordinate (ex. 00 or 0,0 both work) you want to place your token and press enter to confirm." << endl;
			cout << INDENT << WHITE << "Do be warned, placing a token in a place you can't will make you lose your turn. You also cannot put spaces in the coordinate";
			cout << INDENT << WHITE << "Red Player (X) goes first" << endl;
			cout << BLANK;

		drawMap();

		if (winVertical() == true)
		{
			gameOver();
		}

		if (winHorizontal() == true)
		{
			gameOver();
		}

		if (winDiagonal() == true)
		{
			gameOver();
		}

		if (tie() == true)
		{
			gameOver();
		}

		getCommand();

		
		
			
		system("pause");
		system("cls");
	}

}

int main()
{
	DWORD dwMode = 0;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);

	//Welcome message
	

	Game();
	


	std::cin.clear(); 
	std::cin.ignore(std::cin.rdbuf()->in_avail()); 
	std::cin.get();
}

