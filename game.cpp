//#include"token.h"
//#include<iostream>
//using namespace std;
//if (token.move(dicevalue)) {
//	cout<<"sucess"
//}

#include"game.h"
#include<iostream>
#include<string>
#include <limits>

using namespace std;
Game::Game() :currentPlayer(0), numberOfPlayers(0) {}

void Game::setupPlayers() {
	cout << "Enter the number of players (2,4): ";
	cin >> numberOfPlayers;
	while(numberOfPlayers < 2 || numberOfPlayers>4) {
		cout << "Invalid Input\n";
		cout << "Enter the number of players:(2,4)";
		cin >> numberOfPlayers;

	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0;i < numberOfPlayers;i++) {
		cout <<endl<< "Enter the " << i + 1 << " name:";
		string name;
		getline(cin, name);
		Color c = static_cast<Color>(i);
		players[i] = Player(name, c);
	}
}

void Game::playTurn() {
	bool rollAgain =true;

	cout << "====================================" << endl;
	cout << "          " << players[currentPlayer].getname() << "'s Turn" << endl;
	cout << "====================================" << endl;
	while (rollAgain) {
		cout << "Press ENTER to Roll the Dice..." << endl;
		cin.get();

		dice.roll();
		int diceValue = dice.getDiceValue();

		cout << "\n Dice: " << diceValue << endl;
		rollAgain = false;
		bool anyMove = false;

		cout << "\nMovable Tokens\n";

		for (int i = 0; i < 4; i++) {

			Token& token = players[currentPlayer].gettoken(i);

			if (token.canMove(diceValue)) {

				anyMove = true;

				cout << i + 1 << ": Token " << i + 1 << " (";

				if (token.getposition() == -1)
					cout << "Base";
				else if (token.getposition() == 57)
					cout << "Home";
				else
					cout << "Position: " << token.getposition();

				cout << ")" << endl;
			}


		}
		if (!anyMove) {
			cout << "\nNo valid moves." << endl;
			cout << "Turn skipped." << endl;
			return;
		}
		int choice;
		cout << "Enter the choice (1,2,3,4): ";
		do {

			cin >> choice;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl;
			if (choice < 1 || choice > 4) {
				cout << "Enter Valid Choice: ";

			}
			else {
				Token& token = players[currentPlayer].gettoken(choice - 1);

				if (!token.canMove(diceValue)) {
					cout << "Token " << choice << " Cannot Move." << endl;
					cout << "Enter a valid token(1 - 4) : ";
				}
				else {
					token.move(diceValue);
					bool exit = false;
					for (int i = 0; i < numberOfPlayers; i++)
					{
						if (i == currentPlayer)
						{
							continue;
						}

						for (int j = 0; j < 4; j++)
						{
							Token& opponentToken = players[i].gettoken(j);
							if (board.canCapture(token.getposition(), players[currentPlayer].getcolor(), opponentToken.getposition(), players[i].getcolor())) {
								opponentToken.sendToBase();
								cout << players[currentPlayer].getname()
									<< " captured "
									<< players[i].getname()
									<< "'s Token "
									<< j + 1 << "!" << endl;
								exit = true;
								break;
							}
						}
						if (exit)
							break;
					}

					cout << "Current Position: "
						<< token.getposition()
						<< endl;
					break;
				}
				

			}
		} while (true);

		
		if (diceValue == 6) {
			
				cout << "\nYou rolled a 6!" << endl;
				cout << "You get another turn." << endl;
			
			rollAgain = true;
		}

	}
}


bool Game::checkWinner()const {
	return players[currentPlayer].haswon();
}
void Game::nextPlayer() {
	currentPlayer++;
	if (currentPlayer == numberOfPlayers) {
		currentPlayer = 0;
	}
}
void Game::startGame() {
	cout << "====================================" << endl;
	cout << "          LUDO GAME ENGINE          " << endl;
	cout << "====================================" << endl;
	cout << "====================================" << endl;
	cout << "          WELCOME TO THE GAME       " << endl;
	cout << "====================================" << endl;

	setupPlayers();
	cout << "====================================" << endl;
	cout << "             LUDO BOARD        " << endl;
	cout << "====================================" << endl;
	cout << endl;

	while (true) {
		system("cls");
		board.displayBoard(players, numberOfPlayers);
		cout << endl;

		playTurn();
		if (checkWinner()) {
			cout << players[currentPlayer].getname() << " has Won the Game" << endl;
			break;
		}
		
		nextPlayer();
		
	}
	cout << "====================================" << endl;
	cout << "              GAME OVER             " << endl;
	cout << "====================================" << endl;

}