#pragma once
#include"token.h"
#include"player.h"
struct Cell {
	int row;
	int col;
};

class Board {
private:
	Cell track[52];

	Cell redBase[4];
	Cell greenBase[4];
	Cell yellowBase[4];
	Cell blueBase[4];

	Cell redHome[5];
	Cell greenHome[5];
	Cell yellowHome[5];
	Cell blueHome[5];
	char layout[15][15];
	void initializeTrack();
	
	void initializeHomePaths();
	void initializeBasePositions();
	void initializeLayout();
public:
	Board();
	int getGlobalPosition(int relativePositon, Color Color)const;
	bool isSafeSquare(int position,Color color)const;
	bool canCapture(int position1,Color color1, int position2, Color color2)const;
	bool isHomePath(int relativePosition)const;
	bool isHome(int relativePosition)const;
	void displayBoard(Player players[], int numberOfPlayers) const;
	const Cell* getRedBase() const;
	const Cell* getGreenBase() const;
	const Cell* getYellowBase() const;
	const Cell* getBlueBase() const;
	const Cell* getTrack() const;
	const Cell* getRedHome() const;
	const Cell* getGreenHome() const;
	const Cell* getYellowHome() const;
	const Cell* getBlueHome() const;
	const char (*getLayout() const)[15];
	//bool isValidMove(int position)const;
};



