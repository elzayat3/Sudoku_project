#ifndef SUDOKU_H
#define SUDOKU_H

#define SIZE 9

void printBoard(void);
int isValid(int row, int col, int num);
int isFull(void);
void initBoard(void);


#endif // SUDOKU_H
