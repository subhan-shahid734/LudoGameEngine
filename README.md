# Development Log

---

# Day 1 — Project Planning & Core Design

## Objectives

- Planned the architecture of the Ludo Game Engine.
- Decided to build a reusable game engine before adding a graphical interface.
- Established the project development workflow.

## Completed

- Designed and implemented the `Token` class.
- Implemented token movement logic.
- Added support for:
  - Base position (`-1`)
  - Starting position (`0`)
  - Home position (`57`)
- Added getters for token information.
- Designed and implemented the `Player` class.
- Each player owns four tokens.
- Implemented player win condition (`hasWon()`).

## Design Decisions

- `Player` owns all four `Token` objects.
- `Token` is responsible only for its own state.
- `Game` will control all gameplay.
- Followed encapsulation and clean OOP principles.

## Testing

- Tested token movement.
- Verified player initialization.
- Verified win-condition logic.

---

# Day 2 — Dice & Board Architecture

## Objectives

- Design and implement the `Dice` component.
- Begin designing the `Board` architecture.

## Completed

- Designed and implemented the `Dice` class.
- Added:
  - Constructor
  - Dice rolling logic
  - Current dice value storage
  - Getter function
- Successfully tested multiple random dice rolls.

## Design Decisions

- Dice stores only the latest rolled value.
- Random seed (`srand(time(NULL))`) is initialized once in `main()`.
- `Board` will not own tokens.
- `Player` continues to own all tokens.
- `Board` will only analyze board-related rules.
- Decided to keep the `Board` stateless (no data members).

## Board Responsibilities (Planned)

- Detect safe squares.
- Detect home position.
- Validate board-related rules.
- Handle board logic without owning game objects.

## Testing

- Verified dice values remain between **1–6**.
- Confirmed the getter returns the latest rolled value.

### 🚀 Next Goal

- Design the `Game` class.
- Complete the `Board` class.
- Connect all engine components.

---

# Day 3 — Player Setup & Game Initialization

## Objectives

- Begin implementing the `Game` class.
- Connect previously developed engine components.

## Completed

### Game Class

- Implemented the default `Game` constructor.
- Implemented `setupPlayers()`.
- Added input validation for the number of players (2–4).
- Implemented player name input using `getline()`.
- Automatically assigned player colors using the `Color` enum.
- Initialized player objects using the parameterized `Player` constructor.

### Player Class

- Added a default constructor.
- Parameterized constructor initializes all four tokens.
- Verified player creation and token initialization.

### Token Class

- Added a default constructor for compatibility with default `Player` objects.
- Corrected the default token position to **-1** (inside the base).

### Dice Class

- Verified random dice generation using `rand()` and `srand()`.

## Testing

Temporary testing in `main.cpp` verified:

- Player creation
- Token movement
- Dice rolling
- `Game::setupPlayers()`

Temporary testing code:

```cpp
Game game;
game.setupPlayers();
```

### 🚀 Next Goal

- Implement the core game loop.
- Make the `Game` class the central controller of the engine.

---

# Day 4 — Core Game Loop & Engine Integration

## Objectives

- Implement the central game control flow.
- Integrate all previously developed engine components.

## Completed

### Game Class

- Implemented `Game::startGame()`.
- Added a professional welcome screen.
- Connected `setupPlayers()` with the game engine.
- Implemented the main game loop.
- Added temporary implementations of:
  - `playTurn()`
  - `checkWinner()`
  - `nextPlayer()`
- Successfully connected all engine components.

### Main Function

Simplified `main.cpp`.

The program now starts through the `Game` class instead of testing individual classes.

```cpp
int main()
{
    srand(time(nullptr));

    Game game;
    game.startGame();

    return 0;
}
```

## Design Decisions

- `Game` is now the central controller of the application.
- `main()` contains no gameplay logic.
- `currentPlayer` is managed entirely by the `Game` class.
- The game loop is implemented using an infinite loop (`while(true)`).
- The game terminates using `break` when a winner is found.
- `playTurn()` is responsible for one complete player turn.
- `nextPlayer()` is executed only if no player has won.

## Testing

Successfully verified:

- Welcome screen displays correctly.
- Player setup works correctly.
- Multiple-word player names are accepted.
- `startGame()` executes functions in the correct order.
- Winner announcement displays correctly.
- Game terminates correctly after a winner is found.
- `main()` successfully launches the complete game engine.

## Lessons Learned

During implementation, two different game loop designs were evaluated:

```cpp
while (!checkWinner())
```

and

```cpp
while (true)
```

After discussing both approaches, the second design was selected because it better represents the natural lifecycle of a Ludo game:

1. A player takes a turn.
2. Check whether the player has won.
3. If a winner exists, terminate the game.
4. Otherwise, move to the next player.

This approach also avoids performing an unnecessary winner check before the first turn begins.

## 🚀 Next Goal

Implement `Game::playTurn()`.

Planned responsibilities:

- Roll the dice.
- Display the dice value.
- Allow the current player to select a token.
- Move the selected token.
- Handle extra turns after rolling a **6**.
- Integrate board validation.

---

# Current Project Status

```text
Version 1.0 – Console Ludo Engine

✅ Token Class
✅ Player Class
✅ Dice Class
✅ Initial Board Design
✅ Game::setupPlayers()
✅ Game::startGame()

⬜ Game::playTurn()
⬜ Game::nextPlayer()
⬜ Game::checkWinner()
⬜ Board Integration
⬜ Complete Gameplay
```
