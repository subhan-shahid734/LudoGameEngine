#pragma once

#include "dice.h"
#include "player.h"
#include "board.h"
#include"token.h"
#include "Graphics.h"
enum GameState
{
    WaitingForDice,
    WaitingForToken,
    
};
class Game
{
private:
    Dice dice;
    Player players[4];
    bool movableTokens[4] = { false, false, false, false };
    Board board;
    Token token;
    Graphics graphics;
    int currentPlayer;
    int numberOfPlayers;
    bool enterWasPressed = false;
    bool numberKeyWasPressed = false;
    int selectedToken = -1;
    GameState gameState = WaitingForDice;
    
    bool extraTurn = false;
    bool gameOver = false;
    Player* winner = nullptr;
public:
    Game();

    void startGame();
    void startSFMLGame();
    void setupPlayers();
    void playTurn();
    void checkCapture(int tokenIndex);
    void nextPlayer();
    bool checkWinner() const;
    void updateMovableTokens();
    void rollDice();
    bool moveToken(int tokenIndex);
    bool hasMovableToken() const;
    void finishTurn();

};