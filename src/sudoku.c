#include <stdio.h>
#include "..\inc\sudoku.h"

static int board[SIZE][SIZE];
static int original[SIZE][SIZE];
static int mistakes = 0;

/* ================= LEVELS ================= */

static int easy[SIZE][SIZE] =
{
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};

static int medium[SIZE][SIZE] =
{
    {0,0,0,0,7,0,0,0,0},
    {6,0,0,1,0,5,0,0,0},
    {0,9,0,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {0,0,0,8,0,3,0,0,0},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,0,9,0,0,5},
    {0,0,0,0,8,0,0,7,0}
};

static int hard[SIZE][SIZE] =
{
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,5,0,0,0},
    {0,9,0,0,0,0,0,6,0},
    {0,0,0,0,6,0,0,0,3},
    {0,0,0,8,0,3,0,0,0},
    {7,0,0,0,2,0,0,0,0},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,0,9,0,0,0},
    {0,0,0,0,8,0,0,7,0}
};
/* ================= INIT ================= */

void initBoard(int level)
{
    int (*selected)[SIZE];

    if (level == 1)
    {
        selected = easy;
    }
    else if (level == 2)
    {
        selected = medium;
    }
    else
    {
        selected = hard;
    }
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            board[i][j] = selected[i][j];
            original[i][j] = selected[i][j];
        }
    }
    mistakes = 0;
}

/* ================= PRINT ================= */

void printBoard(int cursorRow, int cursorCol)
{
    printf("\033[H");

    printf("\n\033[1;36m            S U D O K U  G A M E\033[0m\n\n");
    int remaining = 3 - getMistakes();

    printf("   Mistakes: \033[1;31m%d\033[0m / 3",getMistakes());

    if (remaining == 1)
    {
        printf("   \033[1;33m(Last chance!)\033[0m");
    }
    else if (remaining == 0)
    {
        printf("   \033[1;31m(No chances left!)\033[0m");
    }
    printf("\n\n");

    printf("   ┏━━━━━━━━━━━┳━━━━━━━━━━━┳━━━━━━━━━━━┓\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("   ┃");

        for (int j = 0; j < SIZE; j++)
        {
            int isCursor = (i == cursorRow && j == cursorCol);
            int block = (i / 3 + j / 3) % 2;

            char cell[4];

            if (board[i][j] == 0)
            {
                sprintf(cell, "   ");
            }
            else
            {
                sprintf(cell, " %d ", board[i][j]);
            }

            /* Apply block background */
            if (block == 0)
            {
                printf("\033[48;5;230m");
            }
            else
            {
                printf("\033[48;5;234m");
            }
            /* Cursor */
            if (isCursor)
            {
                printf("\033[41m");
            }
            /* Original numbers */
            if (!isCursor && original[i][j] != 0)
            {
                printf("\033[1;34m");
            }
            /* Player numbers */
            else if (!isCursor)
            {
                printf("\033[1;32m");
            }
            printf("%s\033[0m", cell);

            if ((j + 1) % 3 == 0)
            {
                printf("┃");
            }
            else
            {
                printf("│");
            }
        }

        printf("\n");

        if (i == 8)
        {
            printf("   ┗━━━━━━━━━━━┻━━━━━━━━━━━┻━━━━━━━━━━━┛\n");
        }
        else if ((i + 1) % 3 == 0)
        {
            printf("   ┣━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┫\n");
        }
        else
        {
            printf("   ┃───────────┼───────────┼───────────┃\n");
        }
    }
}
}

/* ================= LOGIC ================= */

int isValid(int row, int col, int num)
{
    for (int i=0; i<SIZE; i++)
    {
        if (board[row][i]==num || board[i][col]==num)
        {
            return 0;
        }
        else {;}
    }

    int startRow=row-row%3;
    int startCol=col-col%3;

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (board[startRow+i][startCol+j] == num)
            {
                return 0;
            }
            else {;}
        }
    }
    return 1;
}
int isFull(void)
{
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                return 0;
            }
            else {;}
        }
    }
    return 1;
}
int makeMove(int row, int col, int num)
{
    if (original[row][col] != 0)
    {
       return -1;
    }
    if (!isValid(row, col, num))
    {
        mistakes++;
        return 0;
    }
    board[row][col] = num;
    return 1;
}
