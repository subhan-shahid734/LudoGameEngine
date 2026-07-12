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

//void Game::setupPlayers() {
//	cout << "Enter the number of players (2,4): ";
//	cin >> numberOfPlayers;
//	while(numberOfPlayers < 2 || numberOfPlayers>4) {
//		cout << "Invalid Input\n";
//		cout << "Enter the number of players:(2,4)";
//		cin >> numberOfPlayers;
//
//	}
//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//	for (int i = 0;i < numberOfPlayers;i++) {
//		cout <<endl<< "Enter the " << i + 1 << " name:";
//		string name;
//		getline(cin, name);
//		Color c = static_cast<Color>(i);
//		players[i] = Player(name, c);
//	}
//}
void Game::setupPlayers() {
	numberOfPlayers = graphics.getSelectedPlayers();

	for (int i = 0;i < numberOfPlayers;i++) {
		string name = graphics.getPlayerName(i);
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
					//bool exit = false;
					//for (int i = 0; i < numberOfPlayers; i++)
					//{
					//	if (i == currentPlayer)
					//	{
					//		continue;
					//	}

					//	for (int j = 0; j < 4; j++)
					//	{
					//		Token& opponentToken = players[i].gettoken(j);
					//		if (board.canCapture(token.getposition(), players[currentPlayer].getcolor(), opponentToken.getposition(), players[i].getcolor())) {
					//			opponentToken.sendToBase();
					//			cout << players[currentPlayer].getname()
					//				<< " captured "
					//				<< players[i].getname()
					//				<< "'s Token "
					//				<< j + 1 << "!" << endl;
					//			exit = true;
					//			break;
					//		}
					//	}
					//	if (exit)
					//		break;
					}

					cout << "Current Position: "
						<< token.getposition()
						<< endl;
					break;
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
		//
		graphics.processEvents();
		//
		if (graphics.isEnterPressed())
		{
			std::cout << "Enter Pressed!\n";
		}
		system("cls");
		board.displayBoard(players, numberOfPlayers);
		//
		graphics.clear();

		graphics.draw(
			players,
			numberOfPlayers,
			board,
			dice.getDiceValue(),
			currentPlayer,
			movableTokens);

		graphics.display();
		//
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
void Game::startSFMLGame()
{
	//setupPlayers();
	graphics.setStatusMessage("Press ENTER to Roll");
	//gameOver = true;
	//winner = &players[0];
	//graphics.playWinnerSound();
	while (graphics.isWindowOpen())
	{
		graphics.processEvents();
		if (graphics.getCurrentScreen() == ScreenState::MainMenu)
		{
			if (graphics.isStartButtonClicked())
			{
				graphics.setCurrentScreen(ScreenState::PlayerSelection);
			}

			if (graphics.isExitButtonClicked())
			{
				return;
			}

			graphics.clear();

			graphics.draw(
				players,
				numberOfPlayers,
				board,
				dice.getDiceValue(),
				currentPlayer,
				movableTokens);

			graphics.display();

			continue;
		}
		if (graphics.getCurrentScreen() == ScreenState::PlayerSelection)
		{

			if (graphics.isTwoPlayerButtonClicked())
			{
				graphics.setSelectedPlayers(2);
				graphics.setCurrentScreen(ScreenState::PlayerNameInput);
			}

			else if (graphics.isThreePlayerButtonClicked())
			{
				graphics.setSelectedPlayers(3);
				graphics.setCurrentScreen(ScreenState::PlayerNameInput);
			}

			else if (graphics.isFourPlayerButtonClicked())
			{
				graphics.setSelectedPlayers(4);
				graphics.setCurrentScreen(ScreenState::PlayerNameInput);
			}
		}

		if (graphics.getCurrentScreen() == ScreenState::PlayerNameInput)
		{
			if (graphics.isBackToSelectionButtonClicked())
			{
				graphics.setCurrentScreen(ScreenState::PlayerSelection);
			}
			//if (graphics.isStartGameButtonClicked())
			//{
			//	for (int i = 0; i < graphics.getSelectedPlayers(); i++)
			//	{
			//		std::cout << graphics.getPlayerName(i) << std::endl;
			//	}
			//}
			if (graphics.isStartGameButtonClicked())
			{
				setupPlayers();
				graphics.stopBackgroundMusic();
				graphics.setCurrentScreen(ScreenState::Playing);
			}
			graphics.updatePlayerNameSelection();

			graphics.clear();

			graphics.draw(
				players,
				numberOfPlayers,
				board,
				dice.getDiceValue(),
				currentPlayer,
				movableTokens);

			graphics.display();

			continue;
		}
		graphics.updateDiceAnimation();
		graphics.updateTokenAnimations();
		//if (gameOver)
		//{
		//	graphics.clear();

		//	graphics.draw(
		//		players,
		//		numberOfPlayers,
		//		board,
		//		dice.getDiceValue(),
		//		currentPlayer,
		//		movableTokens);

		//	graphics.display();

		//	continue;
		//}
		if (gameOver)
		{
			graphics.updateWinnerAnimation();

			graphics.drawWinner(*winner);

			continue;
		}

		bool enterPressed = graphics.isEnterPressed();

		if (gameState == WaitingForDice)
		{
			if (!graphics.isDiceAnimating())
			{
				if (enterPressed && !enterWasPressed)
				{
					graphics.playDiceSound();      // <-- add this
					graphics.startDiceAnimation();
				}
			}
		}
		if (gameState == WaitingForDice)
		{
			if (graphics.hasAnimationFinished())
			{
				rollDice();

				graphics.resetAnimationFinished();
			}
		}

		enterWasPressed = enterPressed;

		int pressedToken = graphics.getSelectedToken();

		if (gameState == WaitingForToken)
		{
			if (pressedToken != -1 && !numberKeyWasPressed)
			{
				selectedToken = pressedToken;

				if (moveToken(selectedToken))
				{
					finishTurn();
				}
			}
		}

		numberKeyWasPressed = (pressedToken != -1);

		// These MUST stay inside the while loop
		graphics.clear();

		graphics.draw(
			players,
			numberOfPlayers,
			board,
			dice.getDiceValue(),
			currentPlayer,
			movableTokens);

		graphics.display();
	}
}
void Game::updateMovableTokens()
{
	for (int i = 0; i < 4; i++)
	{
		Token& token = players[currentPlayer].gettoken(i);

		movableTokens[i] = token.canMove(dice.getDiceValue());
	}
}
void Game::rollDice()
{
	dice.roll();
	graphics.setDisplayedDiceValue(dice.getDiceValue());
	extraTurn = (dice.getDiceValue() == 6);
	updateMovableTokens();

	std::cout << "Dice = "
		<< dice.getDiceValue()
		<< std::endl;

	for (int i = 0; i < 4; i++)
	{
		std::cout << "Token "
			<< i + 1
			<< " : "
			<< movableTokens[i]
			<< std::endl;
	}

	std::cout << "----------------------" << std::endl;
	if (!hasMovableToken())
	{
		graphics.setStatusMessage("No Valid Moves");

		nextPlayer();

		gameState = WaitingForDice;
	}
	else
	{
		graphics.setStatusMessage("Select a Token");

		gameState = WaitingForToken;
	}
}
bool Game::moveToken(int tokenIndex)
{
	if (!movableTokens[tokenIndex])
	{
		graphics.setStatusMessage("Invalid Token");
		return false;
	}

	players[currentPlayer]
		.gettoken(tokenIndex)
		.move(dice.getDiceValue());
	checkCapture(tokenIndex);
	std::cout << "Position = "
		<< players[currentPlayer].gettoken(tokenIndex).getposition()
		<< std::endl;
	std::cout << "Moved Token "
		<< tokenIndex + 1
		<< std::endl;
	if (checkWinner())
	{
		gameOver = true;
		winner = &players[currentPlayer];

		graphics.playWinnerSound();

		graphics.setStatusMessage("Game Over");
	}

	return true;
}
void Game::checkCapture(int tokenIndex)
{
	Token& token = players[currentPlayer].gettoken(tokenIndex);
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

			if (board.canCapture(
				token.getposition(),
				players[currentPlayer].getcolor(),
				opponentToken.getposition(),
				players[i].getcolor()))
			{
				opponentToken.sendToBase();
				graphics.playCaptureSound();
				cout << players[currentPlayer].getname()
					<< " captured "
					<< players[i].getname()
					<< "'s Token "
					<< j + 1
					<< "!" << endl;

				exit = true;
				break;
			}
		}

		if (exit)
			break;
	}
}
bool Game::hasMovableToken() const
{
	for (int i = 0; i < 4; i++)
	{
		if (movableTokens[i])
		{
			return true;
		}
	}

	return false;
}
void Game::finishTurn()
{
	// Remove highlights
	for (int i = 0; i < 4; i++)
	{
		movableTokens[i] = false;
	}

	if (!extraTurn)
	{
		nextPlayer();

		graphics.setStatusMessage("Press ENTER to Roll");
	}
	else
	{
		std::cout << "Extra Turn!" << std::endl;

		graphics.setStatusMessage("Rolled 6! Extra Turn");
	}

	gameState = WaitingForDice;
	extraTurn = false;
}
