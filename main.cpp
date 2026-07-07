// LudoGameEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include "player.h"
#include <cstdlib>
#include <ctime>
#include "dice.h"
#include "game.h"

using namespace std;

//int main()
//{
//    Player p("Subhan", Red);
//
//    cout << p.getname() << endl;
//
//    cout << p.gettoken(0).getposition() << endl;
//
//    p.gettoken(0).move(6);
//
//    cout << p.gettoken(0).getposition() << endl;
//
//
//    srand(time(NULL));
//
//    Dice dice;
//
//    for (int i = 0; i < 10; i++)
//    {
//        dice.roll();
//        cout << dice.getDiceValue() << " ";
//    }
//
//    cout << endl;
//        Game game;
//        game.setupPlayers();
//
//    
//    return 0;
//
//
//}
int main()
{
    srand(time(nullptr));

    Game game;
    game.startGame();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


