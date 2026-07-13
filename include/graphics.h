#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"
#include <SFML/Audio.hpp>
#include "Button.h"
#include "TextBox.h"
#include <optional>
enum class ScreenState
{
    MainMenu,
    PlayerSelection,
    PlayerNameInput,
    Playing,
    Winner
};
class Graphics
{
private:
    sf::RenderWindow window;

    sf::CircleShape tokenShapes[4][4];

    sf::Font font;
    sf::Texture menuBackgroundTexture;
    sf::Texture playerSelectionTexture;
    sf::Texture playerNameTexture;
    sf::Text currentTurnText{ font };
    sf::Text diceText{ font };
    //sf::Text diceText;
    sf::Text turnColorText{ font };
    std::string statusMessage = "Press ENTER to Roll";
    bool diceAnimating = false;
    bool animationFinished = false;
    sf::Clock diceClock;

    int displayedDiceValue = 1;

    float animationDuration = 0.6f;

    float faceChangeInterval = 0.08f;

    float lastFaceChange = 0.f;
    sf::SoundBuffer diceBuffer;
    sf::Sound diceSound;
    sf::SoundBuffer captureBuffer;
    sf::Sound captureSound{ captureBuffer };
    sf::SoundBuffer winnerBuffer;
    sf::Sound winnerSound{ winnerBuffer };
    float winnerScale = 1.f;

    bool scaleUp = true;

    sf::Clock winnerAnimationClock;
    struct TokenAnimation
    {
        bool active = false;

        sf::Vector2f startPosition;
        sf::Vector2f targetPosition;

        float duration = 0.25f;
        sf::Clock clock;
    };
    TokenAnimation tokenAnimations[4][4];
    ScreenState currentScreen = ScreenState::MainMenu;
    int selectedPlayers = 0;
    Button* startButton = nullptr;
    Button* exitButton = nullptr;
    bool mouseClicked = false;
    //
    int clickedToken = -1;
    //
    sf::Music backgroundMusic;
    Button* twoPlayerButton = nullptr;

    Button* threePlayerButton = nullptr;

    Button* fourPlayerButton = nullptr;

    Button* backButton = nullptr;
    Button* startGameButton = nullptr;

    Button* backToSelectionButton = nullptr;
    TextBox* playerNameBoxes[4] = { nullptr, nullptr, nullptr, nullptr };

    TextBox* getSelectedTextBox();
    sf::Texture starTexture;
    std::optional<sf::Sprite> starSprite;


public:
    Graphics();

    bool isWindowOpen() const;

    void processEvents();
    bool isEnterPressed();
    int getSelectedToken();
    void clear();

    void drawBoard(const Board& board);
    void drawMainMenu();
    void drawPlayerSelection();
    void drawPlayerNameInput();
    void drawInfoPanel(const Player& currentPlayer, int diceValue);

    void draw(Player players[],
        int numberOfPlayers,
        const Board& board,
        int diceValue,
        int currentPlayer,
        bool movableTokens[]);
    void drawDice(int diceValue);
    void drawWinnerScreen(const Player& winner);
    void setStatusMessage(const std::string& message);

    void display();
    void drawWinner(const Player& winner);
    void startDiceAnimation();
    void updateDiceAnimation();
    void startTokenAnimation(
        int player,
        int token,
        sf::Vector2f start,
        sf::Vector2f target);
    void updateTokenAnimations();
    bool isDiceAnimating() const;
    int getDisplayedDiceValue() const;
    void setDisplayedDiceValue(int value);
    bool hasAnimationFinished() const;
    void resetAnimationFinished();
    void playDiceSound();
    void playCaptureSound();
    void updateWinnerAnimation();
    void playWinnerSound();
    ScreenState getCurrentScreen() const;
    void setCurrentScreen(ScreenState screen);
    bool isStartButtonClicked();

    bool isExitButtonClicked();
    bool wasMouseClicked() const;
    void setSelectedPlayers(int players);

    int getSelectedPlayers() const;


    bool isButtonClicked(Button* button);
    bool isTwoPlayerButtonClicked();
    void updatePlayerNameSelection();
    void handleTextEntered(char c);

    void handleBackspace();
    TextBox* getPlayerNameBox(int index);
    bool isBackToSelectionButtonClicked();

    bool isStartGameButtonClicked();
    std::string getPlayerName(int index) const;
    void stopBackgroundMusic();
    bool isThreePlayerButtonClicked();

    bool isFourPlayerButtonClicked();
    int getClickedToken() const;

    void resetClickedToken();
    void updateTokenClick(int currentPlayer);
};