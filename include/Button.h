#pragma once

#include <SFML/Graphics.hpp>
#include <string>
class Button
{
private:
	sf::RectangleShape buttonShape;

	sf::Text buttonText;

	sf::Font& font;
	sf::Color normalColor;

	sf::Color hoverColor;
	float normalScale = 1.f;
	float hoverScale = 1.05f;
public:
	Button(
		sf::Font& font,
		const std::string& text,
		sf::Vector2f size,
		sf::Vector2f position);
	void draw(sf::RenderWindow& window);

	bool isMouseOver(sf::RenderWindow& window);

	void update(sf::RenderWindow& window);
	bool isClicked(sf::RenderWindow& window);
};