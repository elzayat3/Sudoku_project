# Sudoku_project
This project implements a Sudoku game using  c language
# initBoard() Function Explanation

## Purpose

The initBoard() function is responsible for initializing the Sudoku board before the game starts.  
It loads a predefined 9×9 puzzle into the internal board used by the game logic.

This function prepares the initial state of the game.

---

## What the Function Does

1. Creates a temporary 9×9 array containing a predefined Sudoku puzzle.
2. Uses the value 0 to represent empty cells.
3. Copies all values from the temporary array into the internal board array.
4. Ensures the game starts with a valid initial configuration.

---

## Internal Design Details

- The actual game board is declared as a static array inside sudoku.c.
- Because it is static, it cannot be accessed directly from other files.
- The initBoard() function acts as a controlled initializer for this internal board.
- Data copying is performed using nested for loops.

---

## Why Use a Temporary Array?

Instead of directly initializing the internal board, a temporary array is used to:

- Separate initialization logic from variable declaration.
- Allow easier reset of the game.
- Support future extensions (multiple levels or loading from file).
- Improve code modularity and maintainability.

---

## Technical Concepts Used

- Two-dimensional arrays (2D arrays)
- Nested loops
- Encapsulation using static
- Separation of concerns

---

##  Summary
initBoard() does not perform validation or gameplay logic.  
Its only responsibility is to load the initial Sudoku puzzle into memory and prepare the board for the game loop.
