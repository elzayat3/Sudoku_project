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


# 🔹 printBoard() Function Explanation

## 📌 Purpose

The `printBoard()` function is responsible for displaying the current state of the Sudoku board in the console.

It provides a formatted 9×9 grid layout so the player can clearly see the game progress.

---

## ⚙️ What the Function Does

1. Iterates through all rows and columns of the internal board.
2. Prints each cell value to the console.
3. Displays empty cells (internally stored as `0`) as blank spaces or placeholders.
4. Draws horizontal and vertical borders to simulate a grid.
5. Visually separates every 3 rows and 3 columns to represent the 3×3 subgrids.

---

## 🧠 Internal Logic

- Uses nested `for` loops to traverse the 2D board array.
- Uses conditional statements to decide whether to print a number or an empty cell.
- Prints ASCII characters to create a simple console-based GUI.
- Does not modify the board state; it only reads and displays it.

---

## 🎯 Role in the Game

- Called inside the main game loop.
- Displays the updated board after each player move.
- Improves clarity and usability of the console interface.

---

## 🚫 What It Does NOT Do

- It does not validate moves.
- It does not change the board.
- It does not check whether the puzzle is solved.

Its sole responsibility is rendering the board visually.
