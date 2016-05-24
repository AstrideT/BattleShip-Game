#pragma once
#include<fstream>
using namespace std;

const  int ROW_MAX = 4;
const int COL_MAX = 4;
class	BattleShip {
public:
	
	void IntroduceGame();
	void Fire();                   //User selects a char from battleship
	bool FleetSunk();                         //Determines if all ships are sumk
	void ReadChar();   //Reads and stores every value of the input file
	void PromptColumnInput();
	void PromptRowInput();
	void CountShips();                //Counts the "#" characters representing ships
	int shipHit = 0, shipCount = 0;               //Variables used in determing when to stop program
	void PromptInput();      //Asks user for input
	void DrawConsole();      //At the end shows the user how the program looked like
	void InitConsole();
	void EndOfGame();

	bool OutOfBound;
	
	
private:
	char board[ROW_MAX][COL_MAX]; //Array of characters
	char Console[ROW_MAX][COL_MAX];
	int X, Y;                                   //Coordinates
	int userPosX, userPosY;                     //User's coordinates
	bool OutBound;
};