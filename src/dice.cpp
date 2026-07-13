#include"dice.h"
#include <cstdlib>
Dice::Dice():diceValue(0){}

void Dice::roll(){
	diceValue = rand() % 6 + 1;

}

int Dice::getDiceValue()const {
	return diceValue;
}