# Sudoku_project
This project implements a Sudoku game using  c language
# Core Functions Documentation

## 🔹 initBoard(int level)

### 📌 Description
Initializes the Sudoku board based on the selected difficulty level.

### ⚙️ Behavior
- Loads a predefined puzzle (Easy, Medium, or Hard).
- Copies the selected puzzle into the internal game board.
- Stores the original puzzle separately to prevent modification of predefined cells.
- Resets the mistake counter.

### 🎯 Parameters

| Parameter | Type | Description |
|-----------|------|-------------|
| level     | int  | Difficulty selector: 1 = Easy, 2 = Medium, 3 = Hard |

### 📝 Notes
- If an invalid level is provided, the Hard level is selected by default.
- This function must be called before starting the main game loop.
- It prepares the initial state of the game.

---

## 🔹 printBoard(int cursorRow, int cursorCol)

### 📌 Description
Renders the current state of the Sudoku board to the console.

### ⚙️ Behavior
- Clears the console screen before rendering.
- Displays the formatted 9×9 Sudoku grid.
- Highlights:
  - Original puzzle values in blue.
  - Player-entered values in green.
  - Current cursor position with a colored background.
- Shows the current mistake counter.

### 🎯 Parameters

| Parameter  | Type | Description |
|------------|------|-------------|
| cursorRow  | int  | Current cursor row index (0–8) |
| cursorCol  | int  | Current cursor column index (0–8) |

### 📝 Notes
- This function handles only rendering (UI layer).
- It does not modify the board state.
- Cursor indices must be within valid board bounds.
  
---
  
## 🔹 isValid(int row, int col, int num)

### 📌 Description

Checks whether a number can be placed in a specific cell without violating Sudoku rules.

This function validates the move before allowing it to be applied to the board.

---

### ⚙️ Validation Rules

The function ensures that:

1. The number does **not** already exist in the same row.
2. The number does **not** already exist in the same column.
3. The number does **not** already exist in the corresponding 3×3 subgrid.

If any of these conditions fail, the move is considered invalid.

---

### 🎯 Parameters

| Parameter | Type | Description |
|-----------|------|-------------|
| row       | int  | Row index of the target cell (0–8) |
| col       | int  | Column index of the target cell (0–8) |
| num       | int  | Number to validate (1–9) |

---

### 🔁 Return Value

| Return | Meaning |
|--------|----------|
| 1      | The move is valid |
| 0      | The move violates Sudoku constraints |

---

### 🧠 Design Notes

- This function **does not modify** the board.
- It only performs rule validation.
- It is used internally by makeMove() to ensure safe gameplay.
- Time complexity is constant (O(1)), since it checks fixed-size structures (9 cells per rule).

---

### 💡 Why It Matters

isValid() guarantees that the player cannot break Sudoku rules, ensuring the integrity and correctness of the game.

---

# 🔹 isFull(void)

## 📌 Overview

The isFull() function determines whether the Sudoku board is completely filled.

In this project, empty cells are represented by the value 0.  
If no cell contains 0, the board is considered full.

This function is used to detect when the game should end.

---

## 🧠 Purpose

The primary purpose of isFull() is to control the game flow.

It allows the game loop to continue running until all cells are filled.

Example usage:

`c
while (!isFull())
{
    // Game continues
}

## ⚙️ How It Works

1. The function iterates through all rows (0–8).
2. For each row, it iterates through all columns (0–8).
3. If any cell contains 0, it immediately returns 0.
4. If no empty cells are found after scanning the entire board, it returns 1.

---

## 🔁 Return Value

| Return | Meaning |
|--------|----------|
| 1 | The board is completely filled |
| 0 | At least one empty cell still exists |

---

## 🎯 Importance in Game Design

- Acts as the game completion detector.
- Prevents infinite loops in the main game loop.
- Keeps the main function clean and readable.
- Separates board state validation from gameplay logic.

---

## ⚠ Important Note

isFull() does NOT verify whether the solution is mathematically correct.  
It only checks whether the board contains empty cells.

However, since every move is validated using isValid(),  
a full board in this project guarantees a valid solution.

---
# 🔹 makeMove(int row, int col, int num)

## 📌 Overview

The makeMove() function handles the logic of applying a player's move to the Sudoku board.

It ensures that the move follows the game rules and prevents modification of predefined puzzle cells.

This function acts as the core gameplay controller for player interactions.

---

## 🧠 Purpose

The purpose of makeMove() is to:

- Prevent modification of original puzzle cells.
- Validate the move using isValid().
- Update the board if the move is correct.
- Increment the mistake counter if the move is invalid.

It separates **game rule enforcement** from user input handling.

---

## ⚙️ How It Works

1. Checks whether the selected cell belongs to the original puzzle.
   - If yes → returns -1 (move rejected).
2. Calls isValid() to verify Sudoku constraints.
   - If invalid → increments mistake counter and returns 0.
3. If valid → updates the board with the new number and returns 1.

---

## 🔁 Return Value

| Return | Meaning |
|--------|----------|
| 1  | Move successful and board updated |
| 0  | Invalid move (rule violation) |
| -1 | Attempted to modify original puzzle cell |

---

## 🎯 Importance in Game Design

- Enforces Sudoku rules.
- Protects predefined puzzle data.
- Tracks player mistakes.
- Centralizes move validation logic.
- Keeps main() clean and simple.

---

## 🔐 Design Concept

makeMove() follows the principle of **Separation of Concerns**:

- isValid() → Handles rule validation.
- makeMove() → Handles gameplay logic.
- printBoard() → Handles rendering.

Each function has a clear and isolated responsibility.



# 🔹 getMistakes(void)

## 📌 Overview

The getMistakes() function returns the current number of mistakes
made by the player during the game.

This function provides controlled, read-only access to the internal
mistake counter stored inside the Sudoku module.

---

## 🧠 Purpose

The purpose of getMistakes() is to allow the application layer
(main.c) to monitor player performance without directly accessing
or modifying internal module variables.

It supports the implementation of gameplay rules such as:

- Limiting the number of allowed mistakes
- Triggering a "Game Over" condition
- Displaying the current mistake count in the UI

---

## ⚙️ How It Works

The mistake counter is defined inside sudoku.c as:
static int mistakes = 0;
## 🔁 Return Value

| Return Type | Description |
|-------------|-------------|
| int         | The current mistake count |

---

## 🎯 Design Advantages

- Preserves encapsulation of the internal mistakes variable.
- Prevents direct external modification of game state.
- Keeps module boundaries clean and well-defined.
- Supports modular and maintainable architecture.
- Allows flexible game rules (e.g., limiting mistakes).

---

## 🔐 Important Note

getMistakes() does not modify the game state.  
It only returns the current value of the mistake counter.

All updates to the mistake count are handled internally
within the makeMove() function.
