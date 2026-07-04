#include"token.h"
#include<iostream>
using namespace std;
//Move function
 
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