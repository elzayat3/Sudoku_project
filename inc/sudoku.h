#ifndef SUDOKU_H
#define SUDOKU_H

#define SIZE 9

/**
 * @brief Initializes the Sudoku board based on the selected difficulty level.
 *
 * @details
 * This function loads one of the predefined Sudoku puzzles
 * (Easy, Medium, or Hard) into the internal static game board.
 * The selected puzzle is copied into both:
 * - The active board array used during gameplay.
 * - The original board array used to prevent modification
 *   of predefined cells.
 *
 * The function also resets the mistake counter.
 *
 * @param level Difficulty level selector:
 *        - 1 : Easy
 *        - 2 : Medium
 *        - 3 : Hard
 *
 * @note
 * If an invalid level is provided, the Hard level
 * puzzle is selected by default.
 *
 * @warning
 * This function must be called before starting
 * the main game loop.
 */
void initBoard(int level);
/**
 * @brief Renders the Sudoku board to the console.
 *
 * @details
 * This function clears the console screen and prints the
 * current state of the Sudoku board using a formatted
 * grid layout with visual separators between 3x3 subgrids.
 *
 * The function also:
 * - Displays the current mistake counter.
 * - Highlights predefined (original) cells in blue.
 * - Displays player-entered values in green.
 * - Highlights the current cursor position using
 *   a colored background.
 *
 * @param cursorRow The current row index of the cursor (0–8).
 * @param cursorCol The current column index of the cursor (0–8).
 *
 * @note
 * This function is responsible only for rendering (UI layer)
 * and does not modify the board state.
 *
 * @warning
 * The cursor indices must be within valid board bounds
 * to ensure correct highlighting behavior.
 */
void printBoard(int cursorRow, int cursorCol);
/**
 * @brief Checks whether a number can be placed in a specific cell.
 *
 * @details
 * This function validates if the given number can be inserted at
 * the specified row and column without violating Sudoku rules.
 *
 * The validation ensures that:
 * - The number does not already exist in the same row.
 * - The number does not already exist in the same column.
 * - The number does not already exist in the corresponding 3x3 subgrid.
 *
 * @param row The row index of the target cell (0–8).
 * @param col The column index of the target cell (0–8).
 * @param num The number to validate (1–9).
 *
 * @return int
 * @retval 1 If the placement is valid.
 * @retval 0 If the placement violates Sudoku constraints.
 *
 * @note
 * This function assumes that the board has already been initialized.
 * It does not modify the board state.
 */
int isValid(int row, int col, int num);
int isFull(void);
int makeMove(int row, int col, int num);

#endif
