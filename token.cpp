#include"token.h"
#include<iostream>
using namespace std;
//Move function
Token::Token(): position(-1), color(Red), token_ID(0){}
Token::Token(Color col, int id) :position(-1), color(col), token_ID(id) {}
bool Token:: canMove(int dicevalue)const {
	if (position == 57) {
		return false;
	}
	else if (position == -1) {
		if (dicevalue == 6) {
			return true;
		}
		else
			return false;
	}
	else  {
		if (position + dicevalue > 57) {
			return false;
		}
		else {
			return true;
		}
	}
	return false;
}

bool Token::move(int dicevalue) {
	if (position == -1) {
		if (dicevalue == 6) {
			position = 0;
			return true;

		}
		else {
			return false;
		}
	}
	else {
		if (position + dicevalue > 57) {
			return false;
		}


		position += dicevalue;
		return true;

	}
}

//Get position

int Token:: getposition()const {
	return position;
}
//Get color
Color Token::getcolor()const {
	return color;
}
//Get id
int Token::gettokenID()const {
	return token_ID;
}