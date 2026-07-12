#include "Button.h"
Button::Button(
    sf::Font& font,
    const std::string& text,
    sf::Vector2f size,
    sf::Vector2f position)
    : font(font),
    buttonText(font)
{
    buttonShape.setSize(size);

    buttonShape.setPosition(position);
    buttonShape.setOrigin(
        {
            size.x / 2.f,
            size.y / 2.f
        });

    buttonShape.setFillColor(sf::Color(60, 60, 60));

    buttonShape.setOutlineThickness(3.f);

    buttonShape.setOutlineColor(sf::Color::White);
    buttonText.setString(text);

    buttonText.setCharacterSize(32);

    buttonText.setFillColor(sf::Color::White);
    sf::FloatRect textBounds = buttonText.getLocalBounds();

    buttonText.setOrigin(
        {
            textBounds.position.x + textBounds.size.x / 2.f,
            textBounds.position.y + textBounds.size.y / 2.f
        });

    buttonText.setPosition(position);
    normalColor = sf::Color(60, 60, 60);

    hoverColor = sf::Color(100, 100, 100);
}
void Button::draw(sf::RenderWindow& window)
{
    window.draw(buttonShape);
    window.draw(buttonText);
}
bool Button::isMouseOver(sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    return buttonShape.getGlobalBounds().contains(
        sf::Vector2f(mousePos));
}
void Button::update(sf::RenderWindow& window)
{
    if (isMouseOver(window))
    {
        buttonShape.setFillColor(hoverColor);

        buttonShape.setScale({ hoverScale, hoverScale });

        buttonText.setScale({ hoverScale, hoverScale });
    }
    else
    {
        buttonShape.setFillColor(normalColor);

        buttonShape.setScale({ normalScale, normalScale });

        buttonText.setScale({ normalScale, normalScale });
    }
}
bool Button::isClicked(sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        return isMouseOver(window);
    }

    return false;
}