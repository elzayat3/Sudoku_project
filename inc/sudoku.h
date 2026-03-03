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




/**
 * @brief Checks whether the Sudoku board is completely filled.
 *
 * @details
 * This function scans the entire 9x9 board to determine
 * whether any empty cells (represented by value 0) still exist.
 *
 * It is typically used in the main game loop to detect
 * when the player has filled all cells.
 *
 * @return int
 * @retval 1 If the board contains no empty cells.
 * @retval 0 If at least one empty cell still exists.
 *
 * @note
 * This function does not verify whether the solution is correct.
 * It only checks whether the board is fully filled.
 *
 * @warning
 * A full board does not necessarily mean a valid solution
 * unless all moves were previously validated using isValid().
 */
int isFull(void);




/**
 * @brief Attempts to place a number in a specific Sudoku cell.
 *
 * @details
 * This function handles the logic of performing a player move.
 * It first checks whether the selected cell is editable
 * (i.e., not part of the original predefined puzzle).
 *
 * If the cell is editable, the function validates the move
 * using the isValid() function to ensure Sudoku rules are not violated.
 *
 * If the move is valid:
 * - The board is updated with the new number.
 *
 * If the move is invalid:
 * - The mistake counter is incremented.
 *
 * @param row The row index of the target cell (0–8).
 * @param col The column index of the target cell (0–8).
 * @param num The number to insert (1–9).
 *
 * @return int
 * @retval 1  Move was successful and the board was updated.
 * @retval 0  Move was invalid (rule violation).
 * @retval -1 Attempted to modify an original puzzle cell.
 *
 * @note
 * This function modifies the board state only if the move is valid.
 *
 * @warning
 * The function assumes that the board has been initialized
 * before being called.
 */
int makeMove(int row, int col, int num);



#endif
