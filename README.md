#  Development Log



##  Day 1 — Project Planning & Core Design

### Objectives
- Planned the architecture of the Ludo Game Engine.
- Decided to build a reusable game engine before adding a graphical interface.
- Established the project development workflow.

###  Completed
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

###  Design Decisions
- `Player` owns all four `Token` objects.
- `Token` is responsible only for its own state.
- `Game` will control all gameplay.
- Followed encapsulation and clean OOP principles.

###  Testing
- Tested token movement.
- Verified player initialization.
- Verified win-condition logic.



##  Day 2 — Dice & Board Architecture

### Objectives
- Design and implement the Dice component.
- Begin designing the Board architecture.

### Completed
- Designed and implemented the `Dice` class.
- Added:
  - Constructor
  - Dice rolling logic
  - Current dice value storage
  - Getter function
- Successfully tested multiple random dice rolls.

### Design Decisions
- `Dice` stores only the latest rolled value.
- Random seed (`srand(time(NULL))`) will be initialized once in `main()`.
- `Board` will **not own tokens**.
- `Player` continues to own all tokens.
- `Board` will only analyze board-related rules.
- Decided to keep the Board stateless (no data members).

### Board Responsibilities (Planned)
- Detect safe squares.
- Detect home position.
- Validate board-related rules.
- Handle board logic without owning game objects.

### Testing
- Verified dice values remain between **1–6**.
- Confirmed getter returns the latest rolled value.

### 🚀 Next Goal
- Design the `Game` class.
- Complete the `Board` class.
- Connect all engine components.

---
