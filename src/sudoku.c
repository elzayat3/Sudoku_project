#include <stdio.h>
#include "sudoku.h"

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
    int flag=1;
    printf("\033[2J\033[H");

    printf("\n\033[1;36m            S U D O K U  G A M E\033[0m\n\n");
    printf("   Mistakes: \033[1;31m%d\033[0m\n\n", mistakes);

    for (int i = 0; i < SIZE; i++)
    {
        /* Top border every 3 rows */
        if (i%3==0 && 1==flag)
        {
            flag=0;
            printf("   ╔═══════════╦═══════════╦═══════════╗\n");
        }
        else if(i%3==0 && 0==flag)
        {
            printf("   ╠═══════════╬═══════════╬═══════════╣\n");
        }
        else
        {
            printf("   ╠═══════════╬═══════════╬═══════════╣\n");
        }

        printf("   ║");

        for (int j=0; j<SIZE; j++)
        {
            int isCursor = (i == cursorRow && j == cursorCol);

            char cell[4];

            if (board[i][j] == 0)
            {
                sprintf(cell, "   ");
            }
            else
            {
                sprintf(cell, " %d ", board[i][j]);
            }
            if (isCursor)
            {
                printf("\033[41m%s\033[0m", cell);
            }
            else if (original[i][j] != 0)
            {
                printf("\033[1;34m%s\033[0m", cell);
            }
            else
            {
                printf("\033[1;32m%s\033[0m", cell);
            }
            if ((j + 1) % 3 == 0)
            {
                printf("║");
            }
            else
            {
                printf("│");
            }
        }

        printf("\n");
    }

    printf("   ╚═══════════╩═══════════╩═══════════╝\n");
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
