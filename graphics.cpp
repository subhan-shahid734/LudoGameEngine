#include "Graphics.h"
#include <filesystem>
#include<iostream>
Graphics::Graphics()
    : window(sf::VideoMode({ 1200, 800 }), "Ludo Game"),
    diceText(font), diceSound(diceBuffer)
{
    std::cout << "Working Directory: "
        << std::filesystem::current_path() << std::endl;
    for (int p = 0; p < 4; p++)
    {
        for (int t = 0; t < 4; t++)
        {
            tokenShapes[p][t].setRadius(20.f);

            switch (p)
            {
            case 0:
                tokenShapes[p][t].setFillColor(sf::Color::Red);
                break;

            case 1:
                tokenShapes[p][t].setFillColor(sf::Color::Green);
                break;

            case 2:
                tokenShapes[p][t].setFillColor(sf::Color::Yellow);
                break;

            case 3:
                tokenShapes[p][t].setFillColor(sf::Color::Blue);
                break;
            }
        }
    }

  
    if (!font.openFromFile("D:\\logic building\\LudoGameEngine\\assets\\calibri.ttf"))
    {
        std::cout << "Font failed to load\n";
    }
    else
    {
        std::cout << "Font loaded successfully\n";
    }
    startButton = new Button(
        font,
        "START GAME",
        { 300.f,80.f },
        { 600.f,360.f }
    );

    exitButton = new Button(
        font,
        "EXIT",
        { 300.f,80.f },
        { 600.f,470.f }
    );
    twoPlayerButton = new Button(
        font,
        "2 Players",
        { 300.f, 70.f },
        { 600.f, 250.f }
    );

    threePlayerButton = new Button(
        font,
        "3 Players",
        { 300.f, 70.f },
        { 600.f, 350.f }
    );

    fourPlayerButton = new Button(
        font,
        "4 Players",
        { 300.f, 70.f },
        { 600.f, 450.f }
    );

    backButton = new Button(
        font,
        "Back",
        { 220.f, 60.f },
        { 600.f, 600.f }
    );
    startGameButton = new Button(
        font,
        "START GAME",
        { 320.f, 70.f },
        { 600.f, 620.f }
    );

    backToSelectionButton = new Button(
        font,
        "BACK",
        { 220.f, 60.f },
        { 600.f, 710.f }
    );
    playerNameBoxes[0] = new TextBox(
        font,
        { 350.f, 60.f },
        { 600.f, 260.f }
    );

    playerNameBoxes[1] = new TextBox(
        font,
        { 350.f, 60.f },
        { 600.f, 400.f }
    );

    playerNameBoxes[2] = new TextBox(
        font,
        { 350.f, 60.f },
        { 600.f, 540.f }
    );

    playerNameBoxes[3] = new TextBox(
        font,
        { 350.f, 60.f },
        { 600.f, 680.f }
    );
    if (!menuBackgroundTexture.loadFromFile(
        "D:\\logic building\\LudoGameEngine\\assets\\Images\\image1.png"))
    {
        std::cout << "Menu background failed to load\n";
    }
    else
    {
        std::cout << "Menu background loaded successfully\n";

    }
    if (!playerSelectionTexture.loadFromFile(
        "D:\\logic building\\LudoGameEngine\\assets\\Images\\player_selection_background.png"))
    {
        std::cout << "Player Selection background failed to load\n";
    }
    else
    {
        std::cout << "Player Selection background loaded successfully\n";
    }
    if (!playerNameTexture.loadFromFile(
        "D:\\logic building\\LudoGameEngine\\assets\\Images\\player_name_background.png"))
    {
        std::cout << "Player Name background failed to load\n";
    }
    else
    {
        std::cout << "Player Name background loaded successfully\n";
    }
    if (!backgroundMusic.openFromFile(
        "D:\\logic building\\LudoGameEngine\\assets\\music\\background_music.mp3"))
    {
        std::cout << "Menu music failed to load\n";
      
    }
    else
    {
        std::cout << "Menu music loaded successfully\n";
        backgroundMusic.setLooping(true);
        backgroundMusic.setVolume(25.f);
        backgroundMusic.play();
    }
    if (!diceBuffer.loadFromFile("D:\\logic building\\LudoGameEngine\\assets\\Sounds\\dice_sound.ogg"))
    {
        std::cout << "Dice sound failed to load\n";
    }
    else
    {
        std::cout << "Dice sound loaded successfully\n";
    }
    if (!captureBuffer.loadFromFile(
        "D:\\logic building\\LudoGameEngine\\assets\\Sounds\\capture.ogg"))
    {
        std::cout << "Capture sound failed to load\n";
    }
    else
    {
        std::cout << "Capture sound loaded successfully\n";
    }
    if (!winnerBuffer.loadFromFile(
        "D:\\logic building\\LudoGameEngine\\assets\\Sounds\\victory.ogg"))
    {
        std::cout << "Winner sound failed to load\n";
    }
    else
    {
        std::cout << "Winner sound loaded successfully\n";
    }

    winnerSound.setVolume(80.f);

    captureSound.setVolume(75.f);

    diceSound.setBuffer(diceBuffer);
    diceSound.setVolume(70.f);
    diceText.setCharacterSize(40);
    diceText.setFillColor(sf::Color::Black);
    currentTurnText.setCharacterSize(28);
    currentTurnText.setFillColor(sf::Color::Black);
    currentTurnText.setString("Current Turn");
    currentTurnText.setPosition({ 800.f, 40.f });

    turnColorText.setCharacterSize(28);
    turnColorText.setFillColor(sf::Color::Black);
    turnColorText.setPosition({ 830.f, 90.f });
}
void Graphics::playDiceSound()
{
    diceSound.play();
}
void Graphics::startDiceAnimation()
{
    diceAnimating = true;
    animationFinished = false;
    displayedDiceValue = rand() % 6 + 1;

    lastFaceChange = 0.f;

    diceClock.restart();
}
void Graphics::updateDiceAnimation()
{
    if (!diceAnimating)
        return;

    float elapsed = diceClock.getElapsedTime().asSeconds();

    // Change the displayed face every few milliseconds
    if (elapsed - lastFaceChange >= faceChangeInterval)
    {
        displayedDiceValue = rand() % 6 + 1;

        lastFaceChange = elapsed;
    }

    // Stop animation after the animation duration
    if (elapsed >= animationDuration)
    {
        diceAnimating = false;
        animationFinished = true;
    }
}
bool Graphics::isDiceAnimating() const
{
    return diceAnimating;
}
int Graphics::getDisplayedDiceValue() const
{
    return displayedDiceValue;
}
bool Graphics::hasAnimationFinished() const
{
    return animationFinished;
}
void Graphics::resetAnimationFinished()
{
    animationFinished = false;
}
void Graphics::setDisplayedDiceValue(int value)
{
    displayedDiceValue = value;
}
bool Graphics::isWindowOpen() const
{
    return window.isOpen();
}

void Graphics::processEvents()
{
    mouseClicked = false;
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        if (event->is<sf::Event::MouseButtonPressed>())
        {
            const auto* mouse =
                event->getIf<sf::Event::MouseButtonPressed>();

            if (mouse->button == sf::Mouse::Button::Left)
            {
                mouseClicked = true;
            }
        }
        if (const auto* textEvent = event->getIf<sf::Event::TextEntered>())
        {
            char c = static_cast<char>(textEvent->unicode);

            if (c >= 32 && c <= 126)
            {
                handleTextEntered(c);
            }
        }
        if (const auto* key = event->getIf<sf::Event::KeyPressed>())
        {
            if (key->code == sf::Keyboard::Key::Backspace)
            {
                handleBackspace();
            }
        }
    }
}

void Graphics::clear()
{
    window.clear();
}

void Graphics::draw(
    Player players[],
    int numberOfPlayers,
    const Board& board,
    int diceValue,
    int currentPlayer,
    bool movableTokens[])
{
    if (currentScreen == ScreenState::MainMenu)
    {
        drawMainMenu();
        return;
    }
    if (currentScreen == ScreenState::PlayerSelection)
    {
        drawPlayerSelection();
        return;
    }
    if (currentScreen == ScreenState::PlayerNameInput)
    {
        drawPlayerNameInput();
        return;
    }
    drawBoard(board);
    
    drawInfoPanel(players[currentPlayer], diceValue);
    const float CELL_SIZE = 45.f;
    for (int p = 0; p < numberOfPlayers; p++)
    {
        for (int t = 0; t < 4; t++)
        {
            Token& token = players[p].gettoken(t);

            int row = -1;
            int col = -1;

            // We'll continue here next.
            if (token.getposition() == -1)
            {
                switch (players[p].getcolor())
                {
                case Red:
                    row = board.getRedBase()[t].row;
                    col = board.getRedBase()[t].col;
                    break;

                case Green:
                    row = board.getGreenBase()[t].row;
                    col = board.getGreenBase()[t].col;
                    break;

                case Yellow:
                    row = board.getYellowBase()[t].row;
                    col = board.getYellowBase()[t].col;
                    break;

                case Blue:
                    row = board.getBlueBase()[t].row;
                    col = board.getBlueBase()[t].col;
                    break;
                }
            }
            else if (token.getposition() < 52)

            {
                //std::cout << "MAIN TRACK : "
                //    << token.getposition()
                //    << std::endl;
                int global = board.getGlobalPosition(
                    token.getposition(),
                    players[p].getcolor());

                row = board.getTrack()[global].row;
                col = board.getTrack()[global].col;
               
            }
            
            else if (token.getposition() < 57)
            {
                //std::cout << "HOME PATH : "
                //    << token.getposition()
                //    << std::endl;
                int homeIndex = token.getposition() - 52;

                switch (players[p].getcolor())
                {
                case Red:
                    row = board.getRedHome()[homeIndex].row;
                    col = board.getRedHome()[homeIndex].col;
                    break;

                case Green:
                    row = board.getGreenHome()[homeIndex].row;
                    col = board.getGreenHome()[homeIndex].col;
                    break;

                case Yellow:
                    row = board.getYellowHome()[homeIndex].row;
                    col = board.getYellowHome()[homeIndex].col;
                    break;

                case Blue:
                    row = board.getBlueHome()[homeIndex].row;
                    col = board.getBlueHome()[homeIndex].col;
                    break;
                }

            }
            else if (token.getposition() == 57)
            {
                row = -1;
                col = -1;
            }
            if (row != -1 && col != -1)
            {
                const float TOKEN_RADIUS = 20.f;

                tokenShapes[p][t].setPosition({
                    col * CELL_SIZE + (CELL_SIZE - TOKEN_RADIUS * 2) / 2,
                    row * CELL_SIZE + (CELL_SIZE - TOKEN_RADIUS * 2) / 2
                    });
            }
        }
    }
    drawDice(diceValue);

    for (int p = 0; p < numberOfPlayers; p++)
    {
        for (int t = 0; t < 4; t++)
        {
            // Highlight only the current player's movable tokens
            if (p == currentPlayer && movableTokens[t])
            {
                tokenShapes[p][t].setOutlineThickness(5.f);
                tokenShapes[p][t].setOutlineColor(sf::Color::Cyan);
            }
            else
            {
                tokenShapes[p][t].setOutlineThickness(0.f);
            }

            if (players[p].gettoken(t).getposition() != 57)
            {
                window.draw(tokenShapes[p][t]);
            }
        }
    }
}
//void Graphics::drawBoard()
//{
//    const float CELL_SIZE = 40.f;
//
//    for (int row = 0; row < 15; row++)
//    {
//        for (int col = 0; col < 15; col++)
//        {
//            sf::RectangleShape cell;
//
//            cell.setSize({ CELL_SIZE, CELL_SIZE });
//
//            cell.setPosition({
//                col * CELL_SIZE,
//                row * CELL_SIZE
//                });
//
//            cell.setFillColor(sf::Color::White);
//
//            cell.setOutlineThickness(1.f);
//
//            cell.setOutlineColor(sf::Color::Black);
//
//            window.draw(cell);
//        }
//    }
//}
void Graphics::drawBoard(const Board& board)
{
    const float CELL_SIZE = 45.f;

    const char (*layout)[15] = board.getLayout();

    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 15; col++)
        {
            sf::RectangleShape cell;

            cell.setSize({ CELL_SIZE, CELL_SIZE });

            cell.setPosition({
                col * CELL_SIZE,
                row * CELL_SIZE
                });

            switch (layout[row][col])
            {
            case 'r':
                cell.setFillColor(sf::Color(220, 40, 40));
                break;

            case 'g':
                cell.setFillColor(sf::Color(40, 180, 40));
                break;

            case 'y':
                cell.setFillColor(sf::Color(240, 220, 40));
                break;

            case 'b':
                cell.setFillColor(sf::Color(40, 80, 220));
                break;

            case '.':
                cell.setFillColor(sf::Color::White);
                break;

            case 'H':
                cell.setFillColor(sf::Color(230, 230, 230));
                break;

            default:
                cell.setFillColor(sf::Color::White);
                break;
            }

            cell.setOutlineThickness(0.5f);
            cell.setOutlineColor(sf::Color(170, 170, 170));
          //  cell.setOutlineColor(sf::Color::Black);

            window.draw(cell);
        }
    }
}
void Graphics::drawInfoPanel(const Player& currentPlayer, int diceValue)
{
    sf::RectangleShape panel;

    panel.setSize({ 480.f,675.f });

    panel.setPosition({ 690.f,20.f });

    panel.setFillColor(sf::Color(245, 245, 245));

    panel.setOutlineThickness(2.f);

    panel.setOutlineColor(sf::Color::Black);

    window.draw(panel);
    sf::RectangleShape line1;
    line1.setSize({ 400.f,2.f });
    line1.setFillColor(sf::Color(170, 170, 170));
    line1.setPosition({ 730.f,190.f });

    window.draw(line1);
    sf::RectangleShape line2;
    line2.setSize({ 400.f,2.f });
    line2.setFillColor(sf::Color(170, 170, 170));
    line2.setPosition({ 730.f,340.f });

    window.draw(line2);
    sf::RectangleShape line3;
    line3.setSize({ 400.f,2.f });
    line3.setFillColor(sf::Color(170, 170, 170));
    line3.setPosition({ 730.f,520.f });

    window.draw(line3);

    sf::Text title(font);

    title.setString("Current Turn");

    title.setCharacterSize(30);

    title.setFillColor(sf::Color::Black);

    auto titleBounds = title.getLocalBounds();

    title.setOrigin(
        sf::Vector2f(
            titleBounds.position.x + titleBounds.size.x / 2.f,
            titleBounds.position.y + titleBounds.size.y / 2.f
        )
    );

    title.setPosition(sf::Vector2f(930.f, 70.f));

    window.draw(title);
    switch (currentPlayer.getcolor())
    {
    case Red:
        turnColorText.setString("RED");
        turnColorText.setFillColor(sf::Color::Red);
        break;

    case Green:
        turnColorText.setString("GREEN");
        turnColorText.setFillColor(sf::Color::Green);
        break;

    case Yellow:
        turnColorText.setString("YELLOW");
        turnColorText.setFillColor(sf::Color::Yellow);
        break;

    case Blue:
        turnColorText.setString("BLUE");
        turnColorText.setFillColor(sf::Color::Blue);
        break;
    }

   // turnColorText.setPosition({ 810.f,110.f });
    auto turnBounds = turnColorText.getLocalBounds();

    turnColorText.setOrigin(
        sf::Vector2f(
            turnBounds.position.x + turnBounds.size.x / 2.f,
            turnBounds.position.y + turnBounds.size.y / 2.f
        )
    );

    turnColorText.setPosition(sf::Vector2f(930.f, 130.f));
    window.draw(turnColorText);
    //
    sf::Text playerTitle(font);

    playerTitle.setString("Player");

    playerTitle.setCharacterSize(30);

    playerTitle.setFillColor(sf::Color::Black);

    playerTitle.setPosition({ 830.f, 230.f });

    window.draw(playerTitle);
    sf::Text playerName(font);

    playerName.setString(currentPlayer.getname());

    playerName.setCharacterSize(28);

    playerName.setFillColor(sf::Color::Black);

    auto playerBounds = playerName.getLocalBounds();

    playerName.setOrigin(
        sf::Vector2f(
            playerBounds.position.x + playerBounds.size.x / 2.f,
            playerBounds.position.y + playerBounds.size.y / 2.f
        )
    );

    playerName.setPosition(sf::Vector2f(930.f, 290.f));

    window.draw(playerName);
    //
    //window.draw(title);

    sf::Text diceTitle(font);

    diceTitle.setString("Dice");

    diceTitle.setCharacterSize(30);

    diceTitle.setFillColor(sf::Color::Black);

    diceTitle.setPosition({ 830.f,360.f });

    window.draw(diceTitle);
    //
    // ================= Status Title =================

    sf::Text statusTitle(font);

    statusTitle.setString("Status");

    statusTitle.setCharacterSize(30);

    statusTitle.setFillColor(sf::Color::Black);

    auto statusTitleBounds = statusTitle.getLocalBounds();

    statusTitle.setOrigin(
        sf::Vector2f(
            statusTitleBounds.position.x + statusTitleBounds.size.x / 2.f,
            statusTitleBounds.position.y + statusTitleBounds.size.y / 2.f
        )
    );

    statusTitle.setPosition(sf::Vector2f(930.f, 540.f));

    window.draw(statusTitle);
    sf::Text statusText(font);

    statusText.setString(statusMessage);

    statusText.setCharacterSize(24);

    statusText.setFillColor(sf::Color(60, 60, 60));

    auto statusBounds = statusText.getLocalBounds();

    statusText.setOrigin(
        sf::Vector2f(
            statusBounds.position.x + statusBounds.size.x / 2.f,
            statusBounds.position.y + statusBounds.size.y / 2.f
        )
    );

    statusText.setPosition(sf::Vector2f(930.f, 590.f));

    window.draw(statusText);
}
void Graphics::drawDice(int diceValue)
{
    sf::RectangleShape dice;

    dice.setSize({ 70.f, 70.f });
    dice.setPosition({ 900.f,410.f });

    dice.setFillColor(sf::Color::White);
    dice.setOutlineThickness(3.f);
    dice.setOutlineColor(sf::Color::Black);

    // Draw rectangle FIRST
    window.draw(dice);

    // Update text
    diceText.setString(std::to_string(displayedDiceValue));

    // Center it in the box
    diceText.setPosition({ 925.f,420.f });

    // Draw text AFTER rectangle
    window.draw(diceText);
}
void Graphics::display()
{
    window.display();
}
bool Graphics::isEnterPressed()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);
}
int Graphics::getSelectedToken()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
        return 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
        return 1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3))
        return 2;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4))
        return 3;

    return -1;
}
void Graphics::drawWinnerScreen(const Player& winner)
{
    sf::RectangleShape background;

    background.setSize({ 1200.f,800.f });
    background.setFillColor(sf::Color(40, 40, 40));

    window.draw(background);

    sf::Text title(font);

    title.setString("WINNER!");
    title.setCharacterSize(60);
    title.setFillColor(sf::Color::White);
    auto titleBounds = title.getLocalBounds();

    title.setOrigin(
        sf::Vector2f(
            titleBounds.position.x + titleBounds.size.x / 2.f,
            titleBounds.position.y + titleBounds.size.y / 2.f
        )
    );

    title.setPosition({ 600.f,150.f });

    window.draw(title);

    sf::Text winnerName(font);

    winnerName.setString(winner.getname());
    winnerName.setCharacterSize(50);
    winnerName.setStyle(sf::Text::Bold);
    switch (winner.getcolor())
    {
    case Red:
        winnerName.setFillColor(sf::Color::Red);
        break;

    case Green:
        winnerName.setFillColor(sf::Color::Green);
        break;

    case Yellow:
        winnerName.setFillColor(sf::Color::Yellow);
        break;

    case Blue:
        winnerName.setFillColor(sf::Color::Blue);
        break;
    }
    auto winnerBounds = winnerName.getLocalBounds();

    winnerName.setOrigin(
        sf::Vector2f(
            winnerBounds.position.x + winnerBounds.size.x / 2.f,
            winnerBounds.position.y + winnerBounds.size.y / 2.f
        )
    );

    winnerName.setPosition(sf::Vector2f(600.f, 290.f));
    //
    sf::RectangleShape winnerBox;

    winnerBox.setSize(sf::Vector2f(480.f, 110.f));

    winnerBox.setOrigin(
        sf::Vector2f(
            winnerBox.getSize().x / 2.f,
            winnerBox.getSize().y / 2.f));

    winnerBox.setPosition(sf::Vector2f(600.f, 280.f));
    switch (winner.getcolor())
    {
    case Red:
        winnerBox.setFillColor(sf::Color(180, 40, 40));
        winnerBox.setOutlineThickness(4.f);
        winnerBox.setOutlineColor(sf::Color(240, 240, 240));
        break;

    case Green:
        winnerBox.setFillColor(sf::Color(40, 180, 40));
        winnerBox.setOutlineThickness(4.f);
        winnerBox.setOutlineColor(sf::Color(240, 240, 240));
        break;

    case Yellow:
        winnerBox.setFillColor(sf::Color(220, 220, 40));
        winnerBox.setOutlineThickness(4.f);
        winnerBox.setOutlineColor(sf::Color(240, 240, 240));
        break;

    case Blue:
        winnerBox.setFillColor(sf::Color(40, 40, 220));
        winnerBox.setOutlineThickness(4.f);
        winnerBox.setOutlineColor(sf::Color(240, 240, 240));
        break;
    }
    //
    winnerBox.setScale({ winnerScale, winnerScale });
    window.draw(winnerBox);
    winnerName.setScale({ winnerScale, winnerScale });
    window.draw(winnerName);

    sf::Text exitText(font);

    exitText.setString("Press ESC to Exit");
    exitText.setCharacterSize(30);
    exitText.setFillColor(sf::Color::White);
    auto exitBounds = exitText.getLocalBounds();

    exitText.setOrigin(
        sf::Vector2f(
            exitBounds.position.x + exitBounds.size.x / 2.f,
            exitBounds.position.y + exitBounds.size.y / 2.f
        )
    );
    exitText.setPosition({ 600.f,500.f });

    window.draw(exitText);
}
void Graphics::drawWinner(const Player& winner)
{
    clear();

    drawWinnerScreen(winner);

    display();
}
void Graphics::setStatusMessage(const std::string& message)
{
    statusMessage = message;
}
void Graphics::startTokenAnimation(
    int player,
    int token,
    sf::Vector2f start,
    sf::Vector2f target)
{
    tokenAnimations[player][token].active = true;

    tokenAnimations[player][token].startPosition = start;

    tokenAnimations[player][token].targetPosition = target;

    tokenAnimations[player][token].clock.restart();
}
void Graphics::updateTokenAnimations()
{
    for (int p = 0; p < 4; p++)
    {
        for (int t = 0; t < 4; t++)
        {
            if (!tokenAnimations[p][t].active)
                continue;

            float elapsed =
                tokenAnimations[p][t].clock.getElapsedTime().asSeconds();

            float progress =
                elapsed / tokenAnimations[p][t].duration;

            if (progress >= 1.f)
            {
                progress = 1.f;
                tokenAnimations[p][t].active = false;
            }

            sf::Vector2f position =
                tokenAnimations[p][t].startPosition +
                (tokenAnimations[p][t].targetPosition -
                    tokenAnimations[p][t].startPosition) * progress;

            tokenShapes[p][t].setPosition(position);
        }
    }
}
void Graphics::playCaptureSound()
{
    captureSound.play();
}
void Graphics::updateWinnerAnimation()
{
    if (winnerAnimationClock.getElapsedTime().asSeconds() < 0.03f)
        return;

    winnerAnimationClock.restart();

    if (scaleUp)
    {
        winnerScale += 0.02f;

        if (winnerScale >= 1.10f)
            scaleUp = false;
    }
    else
    {
        winnerScale -= 0.02f;

        if (winnerScale <= 1.0f)
            scaleUp = true;
    }
}
void Graphics::playWinnerSound()
{
    winnerSound.play();
}
void Graphics::drawMainMenu()
{
    sf::Sprite background(menuBackgroundTexture);

    background.setScale(
        {
            1200.f / menuBackgroundTexture.getSize().x,
            800.f / menuBackgroundTexture.getSize().y
        });

    window.draw(background);
    startButton->update(window);
    startButton->draw(window);

    exitButton->update(window);
    exitButton->draw(window);
}
void Graphics::drawPlayerSelection()
{
    sf::Sprite background(playerSelectionTexture);

    background.setScale(
        {
            1200.f / playerSelectionTexture.getSize().x,
            800.f / playerSelectionTexture.getSize().y
        });

    window.draw(background);
    twoPlayerButton->update(window);
    twoPlayerButton->draw(window);

    threePlayerButton->update(window);
    threePlayerButton->draw(window);

    fourPlayerButton->update(window);
    fourPlayerButton->draw(window);

    backButton->update(window);
    backButton->draw(window);
}
void Graphics::drawPlayerNameInput()
{
    sf::Sprite background(playerNameTexture);

    background.setScale(
        {
            1200.f / playerNameTexture.getSize().x,
            800.f / playerNameTexture.getSize().y
        });

    window.draw(background);
    for (int i = 0; i < selectedPlayers; i++)
    {
        playerNameBoxes[i]->draw(window);
    }
    startGameButton->update(window);
    startGameButton->draw(window);

    backToSelectionButton->update(window);
    backToSelectionButton->draw(window);
}
ScreenState Graphics::getCurrentScreen() const
{
    return currentScreen;
}

void Graphics::setCurrentScreen(ScreenState screen)
{
    currentScreen = screen;
}
bool Graphics::isStartButtonClicked()
{
    return mouseClicked && startButton->isMouseOver(window);
}

bool Graphics::isExitButtonClicked()
{
    return mouseClicked && exitButton->isMouseOver(window);
}
bool Graphics::wasMouseClicked() const
{
    return mouseClicked;
}
void Graphics::setSelectedPlayers(int players)
{
    selectedPlayers = players;
}

int Graphics::getSelectedPlayers() const
{
    return selectedPlayers;
}
bool Graphics::isButtonClicked(Button* button)
{
    return mouseClicked && button->isMouseOver(window);
}
bool Graphics::isTwoPlayerButtonClicked()
{
    return isButtonClicked(twoPlayerButton);
}
void Graphics::updatePlayerNameSelection()
{
    if (!mouseClicked)
        return;

    for (int i = 0; i < selectedPlayers; i++)
    {
        playerNameBoxes[i]->setSelected(false);
    }

    for (int i = 0; i < selectedPlayers; i++)
    {
        if (playerNameBoxes[i]->isMouseOver(window))
        {
            playerNameBoxes[i]->setSelected(true);
            break;
        }
    }
}
TextBox* Graphics::getSelectedTextBox()
{
    for (int i = 0; i < 4; i++)
    {
        if (playerNameBoxes[i]->isSelected())
            return playerNameBoxes[i];
    }

    return nullptr;
}
void Graphics::handleTextEntered(char c)
{
    TextBox* selected = getSelectedTextBox();

    if (selected != nullptr)
    {
        selected->addCharacter(c);
    }
}
void Graphics::handleBackspace()
{
    TextBox* selected = getSelectedTextBox();

    if (selected != nullptr)
    {
        selected->removeLastCharacter();
    }
}
TextBox* Graphics::getPlayerNameBox(int index)
{
    return playerNameBoxes[index];
}
bool Graphics::isBackToSelectionButtonClicked()
{
    return isButtonClicked(backToSelectionButton);
}

bool Graphics::isStartGameButtonClicked()
{
    return isButtonClicked(startGameButton);
}
std::string Graphics::getPlayerName(int index) const
{
    return playerNameBoxes[index]->getText();
}
void Graphics::stopBackgroundMusic()
{
    backgroundMusic.stop();
}
bool Graphics::isThreePlayerButtonClicked()
{
    return isButtonClicked(threePlayerButton);
}

bool Graphics::isFourPlayerButtonClicked()
{
    return isButtonClicked(fourPlayerButton);
}
int Graphics::getClickedToken() const
{
    return clickedToken;
}

void Graphics::resetClickedToken()
{
    clickedToken = -1;
}
void Graphics::updateTokenClick()
{
    if (!mouseClicked)
        return;

    clickedToken = -1;

    sf::Vector2f mousePos =
    {
        static_cast<float>(sf::Mouse::getPosition(window).x),
        static_cast<float>(sf::Mouse::getPosition(window).y)
    };

    for (int t = 0; t < 4; t++)
    {
        if (tokenShapes[0][t].getGlobalBounds().contains(mousePos))
        {
            clickedToken = t;
            break;
        }
    }
}