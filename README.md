Development Log
Day 1 — Project Planning & Core Design
Objectives
Planned the architecture of the Ludo Game Engine.
Decided to build a reusable game engine before adding a graphical interface.
Established the project development workflow.
Completed
Designed and implemented the Token class.
Implemented token movement logic.
Added support for:
Base position (-1)
Starting position (0)
Home position (57)
Added getters for token information.
Designed and implemented the Player class.
Each player owns four tokens.
Implemented player win condition (hasWon()).
Design Decisions
Player owns all four Token objects.
Token is responsible only for its own state.
Game will control all gameplay.
Followed encapsulation and clean OOP principles.
Testing
Tested token movement.
Verified player initialization.
Verified win-condition logic.
Day 2 — Dice & Board Architecture
Objectives
Design and implement the Dice component.
Begin designing the Board architecture.
Completed
Designed and implemented the Dice class.
Added:
Constructor
Dice rolling logic
Current dice value storage
Getter function
Successfully tested multiple random dice rolls.
Design Decisions
Dice stores only the latest rolled value.
Random seed (srand(time(NULL))) is initialized once in main().
Board will not own tokens.
Player continues to own all tokens.
Board only analyzes board-related rules.
Decided to keep the Board stateless (no data members).
Board Responsibilities (Planned)
Detect safe squares.
Detect home position.
Validate board-related rules.
Handle board logic without owning game objects.
Testing
Verified dice values remain between 1–6.
Confirmed the getter returns the latest rolled value.
🚀 Next Goal
Design the Game class.
Complete the Board class.
Connect all engine components.
Day 3 — Player Setup & Game Initialization
Objectives
Begin implementing the Game class.
Connect previously developed engine components.
Completed
Game Class
Implemented the default Game constructor.
Implemented setupPlayers().
Added validation for the number of players (2–4).
Implemented player name input using getline().
Automatically assigned player colors using the Color enum.
Initialized Player objects using the parameterized constructor.
Player Class
Added a default constructor.
Parameterized constructor initializes all four tokens.
Token Class
Added a default constructor for compatibility with default Player objects.
Corrected the default token position to -1 (inside the base).
Dice Class
Verified random dice generation using rand() and srand().
Testing

Created a temporary testing environment inside main.cpp to verify:

Player creation
Token movement
Dice rolling
Game::setupPlayers()

This testing code is temporary and will later be replaced by:

Game game;
game.startGame();
🚀 Next Goal
Implement the core game loop.
Make the Game class the central controller of the engine.
Day 4 — Core Game Loop & Engine Integration
Objectives
Implement the central game control flow.
Integrate all previously developed engine components.
Completed
Game Class
Implemented Game::startGame().
Added a professional welcome screen.
Connected setupPlayers() with the game engine.
Designed and implemented the main game loop.
Added temporary implementations of:
playTurn()
checkWinner()
nextPlayer()
Verified the interaction between all game components.
Main Function
Simplified main.cpp.
main() now only creates the Game object and starts the engine.
int main()
{
    srand(time(nullptr));

    Game game;
    game.startGame();

    return 0;
}
Design Decisions
Game is now the central controller of the application.
main() should not contain gameplay logic.
currentPlayer is managed entirely by the Game class.
Implemented the game loop using an infinite loop (while(true)) with termination through break when a winner is found.
playTurn() is responsible for one complete player turn.
nextPlayer() is called only if no player has won.
Testing

Successfully verified:

Welcome screen display.
Player setup flow.
Multiple-word player names.
Correct execution order of the game loop.
Winner announcement.
Proper game termination.
Lessons Learned

During the design discussion, we compared two different game loop structures:

while (!checkWinner())
while (true) with break

After evaluating both approaches, we selected the second design because it more naturally represents the lifecycle of a game: a player takes a turn, the winner is checked, and the game ends only when a winning condition is reached.

🚀 Next Goal

Implement the complete Game::playTurn() function, including:

Dice rolling
Token selection
Token movement
Extra turns after rolling a 6
Board rule integration
