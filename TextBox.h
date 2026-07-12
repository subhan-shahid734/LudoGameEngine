#pragma once

#include <SFML/Graphics.hpp>
#include <string>
class TextBox
{
private:
	sf::RectangleShape box;

	sf::Text text;

	sf::Font& font;

	std::string inputText;

	bool selected = false;
public:
	TextBox(
		sf::Font& font,
		sf::Vector2f size,
		sf::Vector2f position);
	void draw(sf::RenderWindow& window);

	void setSelected(bool value);

	bool isSelected() const;

	std::string getText() const;
	bool isMouseOver(sf::RenderWindow& window);
	void addCharacter(char c);
	void removeLastCharacter();
	void updateTextPosition();
};