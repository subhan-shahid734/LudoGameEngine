#pragma once
class Dice {
private:
	int diceValue;
public:
	Dice();
	void roll();
	int getDiceValue()const;
};