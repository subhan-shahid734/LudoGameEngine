#include"player.h"
Player::Player(string nm, Color clr)
    : name(nm),
    color(clr),
    tokens{
        Token(clr, 1),
        Token(clr, 2),
        Token(clr, 3),
        Token(clr, 4)
    }
{}

string Player::getname()const {
    return name;

}
Color Player::getcolor()const {
    return color;
}
Token& Player::gettoken(int index) {
    return tokens[index];
}



bool Player::haswon()const {
    for (int i = 0;i < 4;i++) {
        if (tokens[i].getposition() != 57)
            return false;
    }
    return true;
}