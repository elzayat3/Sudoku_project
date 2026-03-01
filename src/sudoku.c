#include<stdio.h>
#include"sudoku.h"

static int board[SIZE][SIZE];
static int original[SIZE][SIZE];
static int mistakes = 0;


void initBoard(void)
{
    int temp[SIZE][SIZE]=
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

    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            board[i][j] = temp[i][j];
            original[i][j] = temp[i][j];
        }
    }
}

void printBoard(void)
{
    printf("\033[2J\033[H");  /*clear the screen */

    printf("\n\033[1;36m");
    printf("\t\t\tS U D O K U  G A M E\n");
    printf("\033[0m\n");

    printf("   Mistakes: \033[1;31m%d\033[0m\n\n", mistakes);

    for (int i=0; i<SIZE;i++)
    {
        if (i%3==0)
        {
            printf("    ===========================================================\n");
        }

        for (int line=0; line<3;line++)
        {
            printf("   ");

            for (int j=0; j<SIZE;j++)
            {
                if (j%3==0)
                    printf(" || ");

                if (line==1)
                {
                    if (board[i][j]==0)
                    {
                        printf("     ");
                    }
                    else
                    {
                        if (original[i][j] != 0)
                        {
                            printf("  \033[1;34m%d\033[0m  ", board[i][j]);
                        }
                        else
                        {
                            printf("  \033[1;32m%d\033[0m  ", board[i][j]);
                        }
                    }
                }
                else
                {
                    printf("     ");
                }
            }

            printf(" ||\n");
        }
    }

    printf("    ===========================================================\n");
}
