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

- This function handles only rendering (UI layer).
- It does not modify the board state.
- Cursor indices must be within valid board bounds.
