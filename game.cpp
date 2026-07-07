//#include"token.h"
//#include<iostream>
//using namespace std;
//if (token.move(dicevalue)) {
//	cout<<"sucess"
//}

#include"game.h"
#include<iostream>
#include<string>
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
	cin.ignore();

	for (int i = 0;i < numberOfPlayers;i++) {
		cout <<endl<< "Enter the " << i + 1 << " name:";
		string name;
		getline(cin, name);
		Color c = static_cast<Color>(i);
		players[i] = Player(name, c);
	}
}
void Game::playTurn() {
	cout << "Player Turn has been called" << endl;
}
bool Game::checkWinner()const {
	cout << "check winner is called " << endl;
	return 1;
}
void Game::nextPlayer() {
	cout << "Nect player has been called  " << endl;
}
void Game::startGame() {
	cout << "====================================" << endl;
	cout << "          LUDO GAME ENGINE          " << endl;
	cout << "====================================" << endl;
	cout << "====================================" << endl;
	cout << "          WELCOME TO THE GAME       " << endl;
	cout << "====================================" << endl;

	setupPlayers();
	while (true) {
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