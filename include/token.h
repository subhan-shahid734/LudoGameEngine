#pragma once
enum Color { Red, Green, Yellow,Blue};
class Token {
private:	
	int position;
	Color color;
	int token_ID;
public:
	Token();
	Token(Color col, int id);
	bool canMove(int diceValue)const;
	bool move(int);
	bool moveOneStep();
	int getposition()const;
	Color getcolor()const;
	int gettokenID()const;
	void sendToBase();
};

