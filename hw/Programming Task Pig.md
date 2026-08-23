# Programming Task: Pig

## Assignment Overview

Create a C++ version of the dice game Pig. This is the first programming task of the course and is intended as a refresher from the prerequisite class. The human player competes against a simple computer opponent.

The first player to reach 100 grand points wins. During a turn, the active player may roll or hold. Rolling a 1 loses the turn and adds no turn points to the player’s grand total. Rolling 2 through 6 adds the roll to the player’s turn total. Holding adds the turn total to the player’s grand total and passes control to the other player.

## Common Program Standards

- Compile with C++17 or greater in a Linux environment.
- Include a source-file header and a Program Greeting.
- Place function prototypes above `main()` and definitions below `main()`.
- Keep `main()` as the program coordinator and avoid global variables, including `#define` constants.
- Use named constants, meaningful function names, clear comments, and readable spacing.
- Do not use `<vector>`, `<array>`, maps, stacks, queues, or other library containers. This task does not require a collection data structure.
- Use whole-line comments for specification sections. End-of-line comments are permitted only beside variable declarations.

## Technical Requirements: 7 Program Tasks

### Task 1: Establish the Game and Player Identity

- **1.1.** Add a source-file header containing the program name, your name, course, and assignment due date.
- **1.2.** Create and immediately call a `void ProgramGreeting()` function.
- **1.3.** Display the game title, objective, and basic instructions from the greeting or an immediately following instruction function.
- **1.4.** Read the human player’s first and last name into one string variable after the greeting and use the name later in the output.
- **1.5.** Declare a named constant for the winning score of 100 and initialize the players’ grand scores before the first game.

### Task 2: Build and Protect the Random-Number Functions

- **2.1.** Use an unsigned seed variable with a fixed integer value so the random sequence is repeatable while debugging.
- **2.2.** Create `int D6()` that returns a random integer from 1 through 6 every time it is called.
- **2.3.** Create `int RandomNumber(int lo, int hi)` that returns a random integer in the requested inclusive range.
- **2.4.** Protect `RandomNumber()` with an `if` statement: return `-1` when `hi` is not greater than `lo`, `lo` is less than 1, or `hi` is greater than 100.
- **2.5.** Exercise all three invalid-argument rules from `ProgramGreeting()` or a dedicated test function before the game begins.

### Task 3: Run the Human Player’s Turn

- **3.1.** Display a numeric menu with exactly these actions: `1. Roll`, `2. Hold`, and `3. Quit`.
- **3.2.** Validate the menu choice and re-prompt until the human enters 1, 2, or 3.
- **3.3.** When the human rolls, call `D6()` and display the result.
- **3.4.** Add rolls from 2 through 6 to the human player’s turn total, but discard the turn total when the roll is 1.
- **3.5.** When the human holds, add the turn total to the human player’s grand score and end the turn; when the human quits, end the current game cleanly.

### Task 4: Run the Computer Player’s Turn

- **4.1.** Create a separate function for the computer’s turn.
- **4.2.** Have the computer make a decision by calling `D6()` or an equivalent six-sided random decision.
- **4.3.** Make the computer hold on rolls 1 through 3 and roll again on rolls 4 through 6.
- **4.4.** Apply the same Pig scoring rules to the computer: a roll of 1 loses turn points, while a roll from 2 through 6 adds to the turn total.
- **4.5.** Display the computer’s rolls, decision, turn total, and updated grand score so the behavior can be checked.

### Task 5: Track and Display Turn Statistics

- **5.1.** Track each player’s turn total separately from the player’s grand total.
- **5.2.** Display both players’ turn and grand totals after each completed turn.
- **5.3.** Check for a winner after a held score is added.
- **5.4.** End the game when either player reaches 100 grand points and identify the winner.
- **5.5.** Keep the displayed totals logically correct when a player rolls a 1 or quits.

### Task 6: Support Multiple Games and a Heap-Based High Score

- **6.1.** Allocate an integer named `hiScore` on the heap before the first game.
- **6.2.** Update `hiScore` when a completed game produces a higher winning score.
- **6.3.** Offer another game after a game ends, while preserving the high score across games.
- **6.4.** Display `hiScore` after the game session ends.
- **6.5.** Release the heap memory for `hiScore` before the program quits.

### Task 7: Organize, Document, and Test the Program

- **7.1.** Use at least six programmer-defined functions, including `ProgramGreeting()`, `D6()`, and `RandomNumber(int, int)`.
- **7.2.** Place prototypes above `main()` and definitions below `main()`; keep `main()` as the coordinator.
- **7.3.** Add whole-line comments immediately before the principal code for the required features, using labels such as `// Specification C1 - Fixed Seed`.
- **7.4.** Test the fixed random sequence, invalid menu choices, all three `RandomNumber()` error rules, rolling a 1, holding, computer decisions, multiple games, high-score updates, and memory cleanup.
- **7.5.** Compile with warnings enabled, confirm that the output is logically correct, and verify the specification comments with `grep -i "specification" homework.cpp`.

## Required Specification Comments

Use the following labels immediately before the first code implementing each feature:

```cpp
// Specification C1 - Fixed Seed
// Specification C2 - Student Name
// Specification C3 - Numeric Menu
// Specification C4 - ProgramGreeting
// Specification B1 - Display Turn Stats
// Specification B2 - Source File Header
// Specification B3 - hiScore on Heap
// Specification B4 - Display hiScore
// Specification A1 - D6() function
// Specification A2 - RandomNumber() function
// Specification A3 - Protect RandomNumber() input
// Specification A4 - Input Validation
```

Do not bunch all specification comments at the top of the source file. Place each label directly above the feature it documents.

## Submission Requirements

Submit the completed C++ source file through Canvas by **August 29, 2026**. Compile and test the game before uploading. Rename the source file from `.cpp` to `.txt` only when preparing the Canvas upload. Follow the syllabus for submission and late-policy requirements.

## Final Reminder

Keep this first task focused on refreshing procedural C++ skills. The required game rules, computer decision strategy, random-number functions, high-score storage, and specification comments provide the structure; your output wording and presentation can be personalized.
