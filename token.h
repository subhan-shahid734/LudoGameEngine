#pragma once
enum Color { Red, Blue, Green, Yellow };
class Token {
private:	
	int position;
	Color color;
	int token_ID;
public:
	Token( Color col, int id) :position(-1), color(col), token_ID(id){}
	bool move(int);

	int getposition()const;
	Color getcolor()const;
	int gettokenID()const;
};

