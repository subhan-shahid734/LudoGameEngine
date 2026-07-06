#pragma once
enum Color { Red, Blue, Green, Yellow };
class Token {
private:	
	int position;
	Color color;
	int token_ID;
public:
	Token();
	Token(Color col, int id);
	bool move(int);

	int getposition()const;
	Color getcolor()const;
	int gettokenID()const;
};

