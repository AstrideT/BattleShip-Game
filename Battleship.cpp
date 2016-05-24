#include "Battleship.h"
#include<iostream>
#include<fstream>
using namespace std;

void BattleShip::IntroduceGame()
{
	cout << "This is a game battleship program " << endl;
	cout << "You have to guess the position of " << shipCount << " ships" << endl;
	cout << "Rows are from 1 to " << ROW_MAX << " and columns from 1 to " << COL_MAX << endl;
	cout << "The game will end only when all the ships are hit" << endl << endl;
	cout << "HINT:There are 2 ships on each row" << endl << endl;
}

void BattleShip::Fire()
{

	if (board[userPosX - 1][userPosY - 1] == '#')
	{
		cout << "A SHIP WAS HIT" << endl;
		board[userPosX - 1][userPosY - 1] = 'H';//Indicates it was hit
		shipHit++;
		Console[userPosX - 1][userPosY - 1] = '#';
		DrawConsole();

	}
	else if (board[userPosX - 1][userPosY - 1] == '~')
		cout << "MISS" << endl;
	else if (board[userPosX - 1][userPosY - 1] == 'H')
	{
		cout << "HIT AGAIN" << endl;
	}

}

bool BattleShip::FleetSunk()
{
	return (shipHit == shipCount);
}

void BattleShip::ReadChar()
{	
	ifstream inFile;
	inFile.open("game.in");
	for (X = 0; X < ROW_MAX; X++)
		for (Y = 0; Y < COL_MAX; Y++)
			inFile >> board[X][Y];
}
void  BattleShip::PromptColumnInput() {

	cout << "Enter the possible column of a ship: ";
	cin >> userPosY;
		while (cin.fail())

		{
			cout << "Column number must be an integer" << endl << endl;;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter the possible column of a ship: ";
			cin >> userPosY;
		}
		

}

void  BattleShip::PromptRowInput() {

	cout << "Enter the possible row of a ship: ";
	cin >> userPosX;
	
	while (cin.fail())
		{
			cout << "Row number must be an integer" << endl << endl;;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter the possible row of a ship: ";
			cin >> userPosX;
		}
	

}
void BattleShip::CountShips()
{
	for (X = 0; X < ROW_MAX; X++)
	{
		for (Y = 0; Y < COL_MAX; Y++)
			if (board[X][Y] == '#')
				shipCount++;
	}
}

void BattleShip::PromptInput()
{
	PromptRowInput();
	PromptColumnInput();
}

void BattleShip::DrawConsole()
{
	for (X = 0; X < ROW_MAX; X++)
	{
		for (Y = 0; Y < COL_MAX; Y++)
			cout << Console[X][Y];
		cout << endl;
	}
}

void BattleShip::InitConsole()
{
	for (X = 0; X < ROW_MAX; X++)
	{
		for (Y = 0; Y < COL_MAX; Y++)
			Console[X][Y] = '~';
		
	}
}

void BattleShip::EndOfGame()
{
	cout << "They were " << shipCount << "Ships" << endl;
	cout << "All the " << shipHit << "Ships were hit" << endl;
	cout << "The fleet was destroyed" << endl;
	cout << "This was what the battleship looked like" << endl;
	DrawConsole();
}


