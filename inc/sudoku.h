#ifndef SUDOKU_H
#define SUDOKU_H

#define SIZE 9

/**
 * @brief Initializes the Sudoku game board.
 *
 * @details
 * This function loads a predefined 9x9 Sudoku puzzle into the
 * internal static board array used by the game module.
 * Empty cells in the puzzle are represented using the value 0.
 *
 * The puzzle is first stored in a temporary local array,
 * then copied into the internal board to prepare the initial
 * game state before starting the main game loop.
 *
 * @note
 * The board array is declared as static inside sudoku.c,
 * ensuring encapsulation and preventing direct external access.
 *
 * @par Design Rationale
 * Using a temporary array improves modularity and allows:
 * - Adding multiple difficulty levels
 * - Loading puzzles from external files
 * - Resetting the game state
 * - Future puzzle generation support
 *
 * @warning
 * This function must be called before starting the game loop.
 */
void initBoard(void);


/**
 * @brief Displays the current state of the Sudoku board.
 *
 * @details
 * This function prints the 9x9 Sudoku board in a formatted
 * ASCII grid layout to the console.
 * 
 * Empty cells (represented internally as 0) are displayed
 * as blank spaces or placeholders to improve readability.
 *
 * The board is rendered with visible borders to simulate
 * a simple console-based graphical layout.
 *
 * @note
 * This function does not modify the board state.
 */
void printBoard(void);
int isValid(int row, int col, int num);
int isFull(void);


#endif // SUDOKU_H
