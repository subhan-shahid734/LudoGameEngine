#include"board.h"
#include<iostream>
#include <iomanip>
using namespace std;
Board::Board() {
    initializeTrack();
    initializeHomePaths();
    initializeBasePositions();
    initializeLayout();

}
void Board::initializeTrack()
{
	
        const Cell coordinates[52] =
{
    {6,1},   // 0
    {6,2},   // 1
    {6,3},   // 2
    {6,4},   // 3
    {6,5},   // 4

    {5,6},   // 5
    {4,6},   // 6
    {3,6},   // 7
    {2,6},   // 8
    {1,6},   // 9
    {0,6},   //10

    {0,7},   //11
    {0,8},   //12

    {1,8},   //13
    {2,8},   //14
    {3,8},   //15
    {4,8},   //16
    {5,8},   //17

    {6,9},   //18
    {6,10},  //19
    {6,11},  //20
    {6,12},  //21
    {6,13},  //22
    {6,14},  //23

    {7,14},  //24

    {8,14},  //25
    {8,13},  //26
    {8,12},  //27
    {8,11},  //28
    {8,10},  //29
    {8,9},   //30

    {9,8},   //31
    {10,8},  //32
    {11,8},  //33
    {12,8},  //34
    {13,8},  //35
    {14,8},  //36

    {14,7},  //37
    {14,6},  //38

    {13,6},  //39
    {12,6},  //40
    {11,6},  //41
    {10,6},  //42
    {9,6},   //43

    {8,5},   //44
    {8,4},   //45
    {8,3},   //46
    {8,2},   //47
    {8,1},   //48
    {8,0},   //49

    {7,0},   //50

    {6,0}    //51

};

	for (int i = 0; i < 52; i++)
	{
		track[i] = coordinates[i];
	}


}
void Board::initializeLayout()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            layout[i][j] = ' ';
        }
    }
    //red home 
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            if (i != 0 && i != 5 && j > 0 && j < 5)
            {
                layout[i][j] = ' ';
            }
            else
            {
                layout[i][j] = 'r';
            }
        }
    }
    //green
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 9; j <= 14; j++)
        {
            if (i != 0 && i != 5 && j > 9&& j < 14)
            {
                layout[i][j] = ' ';
            }
            else
            {
                layout[i][j] = 'g';
            }
        }
    }
    //yellow
    for (int i = 9; i <= 14; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            if (i != 9 && i != 14 && j > 0 && j < 5)
            {
                layout[i][j] = ' ';
            }
            else
            {
                layout[i][j] = 'y';
            }
        }
    }
    //blue
    for (int i = 9; i <= 14; i++)
    {
        for (int j = 9; j <= 14; j++)
        {
            if (i != 9 && i != 14 && j >9 && j <14)
            {
                layout[i][j] = ' ';
            }
            else
            {
                layout[i][j] = 'b';
            }
        }
    }
    //Movement paths
    for (int i = 0;i < 52;i++) {
        layout[track[i].row][track[i].col] = '.';
    }
    for (int i = 0; i < 5; i++) {
        layout[redHome[i].row][redHome[i].col] = 'r';
    }
    for (int i = 0; i < 5; i++) {
        layout[greenHome[i].row][greenHome[i].col] = 'g';
    }
    for (int i = 0; i < 5; i++) {
        layout[yellowHome[i].row][yellowHome[i].col] = 'y';
    }
    for (int i = 0; i < 5; i++) {
        layout[blueHome[i].row][blueHome[i].col] = 'b';
    }

    for (int i = 6;i <= 8;i++) {
        for (int j = 6;j <= 8;j++) {
            layout[i][j] = 'H';
        }
    }
}
void Board::initializeHomePaths() {
const Cell redCoordinates[5] =
{
    {7,1},
    {7,2},
    {7,3},
    {7,4},
    {7,5}
};

const Cell greenCoordinates[5] =
{
    {1,7},
    {2,7},
    {3,7},
    {4,7},
    {5,7}
};

const Cell yellowCoordinates[5] =
{
    {7,13},
    {7,12},
    {7,11},
    {7,10},
    {7,9}
};

const Cell blueCoordinates[5] =
{
    {13,7},
    {12,7},
    {11,7},
    {10,7},
    {9,7}
};

for (int i = 0; i < 5; i++)
{
    redHome[i] = redCoordinates[i];
    greenHome[i] = greenCoordinates[i];
    yellowHome[i] = yellowCoordinates[i];
    blueHome[i] = blueCoordinates[i];
}
}
void Board::initializeBasePositions() {
    const Cell redCoordinates[4] = {
        {1,1},{1,4},{4,1},{4,4}
    };
    const Cell greenCoordinates[4] = { {1,10},{1,13},{4,10},{4,13} };
    const Cell yellowCoordinates[4] = { {10,1},{10,4},{13,1},{13,4} };
    const Cell blueCoordinates[4] = { {10,10},{10,13},{13,10},{13,13} };
    for (int i = 0; i < 4; i++)
    {
        redBase[i] = redCoordinates[i];
        greenBase[i] = greenCoordinates[i];
        yellowBase[i] = yellowCoordinates[i];
        blueBase[i] = blueCoordinates[i];
    }
}

void Board::displayBoard(Player players[], int numberOfPlayers) const
{
    cout << "\n\n";
    cout << "============================================ LUDO BOARD ============================================\n\n";

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            bool tokenFound = false;

            string tokensOnCell[16];
            int tokenCount = 0;

            for (int p = 0; p < numberOfPlayers; p++)
            {
                for (int t = 0; t < 4; t++)
                {
                    Token& token = players[p].gettoken(t);

                    int row = -1;
                    int col = -1;

                    if (token.getposition() == -1)
                    {
                        switch (players[p].getcolor())
                        {
                        case Red:
                            row = redBase[t].row;
                            col = redBase[t].col;
                            break;

                        case Green:
                            row = greenBase[t].row;
                            col = greenBase[t].col;
                            break;

                        case Yellow:
                            row = yellowBase[t].row;
                            col = yellowBase[t].col;
                            break;

                        case Blue:
                            row = blueBase[t].row;
                            col = blueBase[t].col;
                            break;
                        }
                    }
                    else if (token.getposition() < 52)
                    {
                        int global =
                            getGlobalPosition(token.getposition(),
                                players[p].getcolor());

                        row = track[global].row;
                        col = track[global].col;
                    }
                    else if (token.getposition() < 57)
                    {
                        int homeIndex = token.getposition() - 52;

                        switch (players[p].getcolor())
                        {
                        case Red:
                            row = redHome[homeIndex].row;
                            col = redHome[homeIndex].col;
                            break;

                        case Green:
                            row = greenHome[homeIndex].row;
                            col = greenHome[homeIndex].col;
                            break;

                        case Yellow:
                            row = yellowHome[homeIndex].row;
                            col = yellowHome[homeIndex].col;
                            break;

                        case Blue:
                            row = blueHome[homeIndex].row;
                            col = blueHome[homeIndex].col;
                            break;
                        }
                    }
                    else
                    {
                        continue;
                    }

                    if (row == i && col == j)
                    {
                        tokenFound = true;

                        char colorChar;

                        switch (players[p].getcolor())
                        {
                        case Red:    colorChar = 'R'; break;
                        case Green:  colorChar = 'G'; break;
                        case Yellow: colorChar = 'Y'; break;
                        case Blue:   colorChar = 'B'; break;
                        }

                        tokensOnCell[tokenCount] =
                            string(1, colorChar) +
                            char('0' + token.gettokenID());

                        tokenCount++;
                    }
                }
            }

            if (tokenFound)
            {
                string output;

                if (tokenCount == 1)
                {
                    output = tokensOnCell[0];
                }
                else
                {
                    bool sameColor = true;

                    for (int k = 1; k < tokenCount; k++)
                    {
                        if (tokensOnCell[k][0] != tokensOnCell[0][0])
                        {
                            sameColor = false;
                            break;
                        }
                    }

                    if (sameColor)
                    {
                        output = string(1, tokensOnCell[0][0]);
                        output += "(";
                        output += to_string(tokenCount);
                        output += ")";
                    }
                    else
                    {
                        bool used[4] = { false, false, false, false };

                        for (int k = 0; k < tokenCount; k++)
                        {
                            char c = tokensOnCell[k][0];

                            int index;

                            switch (c)
                            {
                            case 'R': index = 0; break;
                            case 'G': index = 1; break;
                            case 'Y': index = 2; break;
                            case 'B': index = 3; break;
                            }

                            if (!used[index])
                            {
                                output += c;
                                used[index] = true;
                            }
                        }
                    }
                }

                cout << setw(6) << output;
            }
            else
            {
                cout << setw(6) << layout[i][j];
            }
        }

        cout << endl;
    }

    cout << endl;
}
int Board::getGlobalPosition(int relativePosition, Color color)const {
	int start = color * 13;
	int globalPosition;
	globalPosition = relativePosition + start;
	if (globalPosition >= 52) {
		return globalPosition % 52;
	}
	return globalPosition;
}
bool Board::isSafeSquare(int position, Color color)const {
	int global = Board::getGlobalPosition(position, color);
	const int safeSquares[8] = { 0, 8, 13, 21, 26, 34, 39, 47 };
	for (int i = 0;i < 8;i++) {
		if (global == safeSquares[i]) {
			return true;
		}
	}
	return false;
}
bool Board::canCapture(int position1, Color color1, int position2, Color color2)const {
	if (color1 == color2)
	{
		return false;
	}
	if (position1 == -1 || position2 == -1 || position1 >= 52 || position2 >= 52) {
		return false;
	}
	int globalPos1 = getGlobalPosition(position1, color1);
	int globalPos2 = getGlobalPosition(position2, color2);
	if (globalPos1 == globalPos2) {
		if (isSafeSquare(position1, color1)) {
			return false;
		}
		return true;
	}
	return false;

}

bool Board::isHomePath(int relativePosition)const {
	if (relativePosition >= 52 && relativePosition < 57) {
		return true;
	}
	return false;
}
bool Board::isHome(int relativePosition)const {
	if (relativePosition == 57) {
		return true;
	}
	return false;
}
const Cell* Board::getRedBase() const
{
    return redBase;
}

const Cell* Board::getGreenBase() const
{
    return greenBase;
}

const Cell* Board::getYellowBase() const
{
    return yellowBase;
}

const Cell* Board::getBlueBase() const
{
    return blueBase;
}
const Cell* Board::getTrack() const
{
    return track;
}
const Cell* Board::getRedHome() const
{
    return redHome;
}

const Cell* Board::getGreenHome() const
{
    return greenHome;
}

const Cell* Board::getYellowHome() const
{
    return yellowHome;
}

const Cell* Board::getBlueHome() const
{
    return blueHome;
}
const char (*Board::getLayout() const)[15]
{
    return layout;
}