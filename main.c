#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "inc\sudoku.h"

#define MAX_MISTAKES 3

void soundStart();
void soundCorrect();
void soundWrong();
void soundBlocked();
void soundWin();
void soundLose();
int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    /* Hide blinking console cursor */
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    int level;
    int cursorRow = 0, cursorCol = 0;
    int result;
    int key;

    printf("Select Difficulty:\n");
    printf("1 - Easy\n");
    printf("2 - Medium\n");
    printf("3 - Hard\n");
    printf("Choice: ");

    if (scanf("%d", &level) != 1)
    {
        level = 1;
    }
    while (getchar() != '\n');

    if (level < 1 || level > 3)
    {
        level = 1;
    }
    initBoard(level);

    /* Clear screen once */
    printf("\033[2J");

    soundStart();

    while (1)
    {
        printBoard(cursorRow, cursorCol);

        /* Game Over Condition */
        if (getMistakes() >= MAX_MISTAKES)
        {
            soundLose();
            printf("\n\033[1;31mGAME OVER! You reached %d mistakes.\033[0m\n", MAX_MISTAKES);
            getch();
            break;
        }

        /*  Win Condition */
        if (isFull())
        {
            soundWin();
            printf("\n\033[1;32mCongratulations! You solved the puzzle!\033[0m\n");
            getch();
            break;
        }

        key = getch();

        /* Arrow Keys */
        if (key == 0 || key == 224)
        {
            key = getch();

            switch (key)
            {
            case 72:
                if (cursorRow > 0) cursorRow--;
                break; // Up
            case 80:
                if (cursorRow < 8) cursorRow++;
                break; // Down
            case 75:
                if (cursorCol > 0) cursorCol--;
                break; // Left
            case 77:
                if (cursorCol < 8) cursorCol++;
                break; // Right
            }
        }
        /* Number Input */
        else if (key >= '1' && key <= '9')
        {
            result = makeMove(cursorRow, cursorCol, key - '0');

            if (result == -1)
            {
                soundBlocked();
                printf("\n\033[1;33mCannot modify original cell!\033[0m");
                Sleep(600);
            }
            else if (result == 0)
            {
                soundWrong();
                printf("\n\033[1;31mInvalid move!                   \033[0m");
                Sleep(600);
            }
            else if (result == 1)
            {
                soundCorrect();
            }
        }
        /* Exit */
        else if (key == 'q' || key == 'Q')
        {
            break;
        }
    }

    return 0;
}



void soundStart()
{
    Beep(800, 100);
    Beep(1000, 200);
    Beep(1200, 300);
    Beep(1400, 400);
}

void soundCorrect()
{
    Beep(1200, 200);
    Beep(1500, 300);
}

void soundWrong()
{
    Beep(400, 300);
    Beep(400, 300);
}

void soundBlocked()
{
    Beep(600, 150);
    Beep(600, 150);
}

void soundWin()
{
    Beep(800, 100);
    Beep(1000, 100);
    Beep(1200, 200);
}

void soundLose()
{
    Beep(700, 200);
    Beep(500, 300);
    Beep(300, 400);
}
