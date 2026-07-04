#pragma once
#include"token.h"
#include<string>
using namespace std;
class Player {
private:
	string name;
	Color color;
	Token tokens[4];
public:
    Player(string nm, Color clr);
	string getname()const;
	Color getcolor()const;
	Token& gettoken(int index);
	bool haswon()const;
};