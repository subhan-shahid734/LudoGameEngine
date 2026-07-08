#pragma once

#include "dice.h"
#include "player.h"
#include "board.h"
#include"token.h"

class Game
{
private:
    Dice dice;
    Player players[4];
    Board board;
    Token token;

    int currentPlayer;
    int numberOfPlayers;

public:
    Game();

    void startGame();
    void setupPlayers();
    void playTurn();
    void nextPlayer();
    bool checkWinner() const;
};