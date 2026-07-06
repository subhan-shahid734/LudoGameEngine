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
	cout << "Enter the number of players:(2,4)";
	cin >> numberOfPlayers;
	while(numberOfPlayers < 2 || numberOfPlayers>4) {
		cout << "Invalid Input\n";
		cout << "Enter the number of players:(2,4)";
		cin >> numberOfPlayers;

	}
	cin.ignore();

	for (int i = 0;i < numberOfPlayers;i++) {
		cout << "Enter the " << i + 1 << " name:";
		string name;
		getline(cin, name);
		Color c = static_cast<Color>(i);
		players[i] = Player(name, c);
	}
}
