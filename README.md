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
