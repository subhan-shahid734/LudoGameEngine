#include "TextBox.h"
TextBox::TextBox(
    sf::Font& font,
    sf::Vector2f size,
    sf::Vector2f position)
    : font(font),
    text(font)
{
    box.setSize(size);

    box.setOrigin(
        {
            size.x / 2.f,
            size.y / 2.f
        });

    box.setPosition(position);

    box.setFillColor(sf::Color(250, 250, 250));

    box.setOutlineThickness(3.f);

    box.setOutlineColor(sf::Color::Black);
    text.setCharacterSize(28);

    text.setFillColor(sf::Color::Black);

    text.setPosition(position);
    updateTextPosition();
}
void TextBox::draw(sf::RenderWindow& window)
{
    window.draw(box);
    window.draw(text);
}
void TextBox::setSelected(bool value)
{
    selected = value;

    if (selected)
    {
        box.setOutlineColor(sf::Color::Blue);
    }
    else
    {
        box.setOutlineColor(sf::Color::Black);
    }
}
bool TextBox::isSelected() const
{
    return selected;
}
std::string TextBox::getText() const
{
    return inputText;
}
bool TextBox::isMouseOver(sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    return box.getGlobalBounds().contains(
        sf::Vector2f(mousePos));
}
void TextBox::addCharacter(char c)
{
    if (inputText.length() >= 12)
        return;

    inputText += c;

    text.setString(inputText);
    updateTextPosition();
}
void TextBox::removeLastCharacter()
{
    if (!inputText.empty())
    {
        inputText.pop_back();
        text.setString(inputText);
        updateTextPosition();
    }
}
void TextBox::updateTextPosition()
{
    sf::FloatRect textBounds = text.getLocalBounds();
    sf::FloatRect boxBounds = box.getGlobalBounds();

    text.setOrigin(
        {
            textBounds.position.x + textBounds.size.x / 2.f,
            textBounds.position.y + textBounds.size.y / 2.f
        });

    text.setPosition(
        {
            boxBounds.position.x + boxBounds.size.x / 2.f,
            boxBounds.position.y + boxBounds.size.y / 2.f
        });
}