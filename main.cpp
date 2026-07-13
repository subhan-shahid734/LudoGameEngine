
#include <iostream>
#include "player.h"
#include <cstdlib>
#include <ctime>
#include "dice.h"
#include "game.h"

using namespace std;


int main()
{
    srand(time(nullptr));

    Game game;

    int choice;
    cout << "====================================" << endl;
    cout << "          LUDO GAME ENGINE          " << endl;
    cout << "====================================" << endl;
    cout << "====================================" << endl;
    cout << "          WELCOME TO THE GAME       " << endl;
    cout << "====================================" << endl;
    cout << "1. Console Mode\n";
    cout << "2. SFML Mode\n";
    cout << "Enter Choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        game.startGame();
    }
    else if (choice == 2)
    {
        game.startSFMLGame();
    }

    return 0;
}


