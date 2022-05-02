#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <iostream>
using namespace std;

int x = 0, y, kb, step;
int xo = 4, yo = 0;
int qi[8][7] = {0};

const int RED_CHESS = 1;
const int YELLOW_CHESS = 2;
const int EMPTY = 0;

int chess = RED_CHESS;
int nextchess = RED_CHESS;

void gotoxy(int x, int y)
{
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ʵ�������
    COORD pos;                                     //��ʾһ���ַ��ڿ���̨��Ļ�ϵ�����
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hout, pos);
}

void textcolor(int c)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, c);
}

const int RED_COLOUR = 12;
const int YELLOW_COLOR = 14;

void printQi(int x, int y, int qi)
{

    gotoxy(10 + x * 2, 5 + y * 2);
    if (qi == YELLOW_CHESS)
        textcolor(YELLOW_COLOR);
    if (qi == RED_CHESS)
        textcolor(RED_COLOUR);

    putchar('@');
}

void clearQi(int x, int y)
{
    gotoxy(10 + x * 2, 5 + y * 2);
    putchar(32);
}

int win()//return : 0,  
{
    int i = 0, j = 0, p = 0; //person

    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            p = qi[i][j];
            if (p == 0)
            {
                continue;
            }
            if ((qi[i][j] == p) && (qi[i + 1][j + 1] == p) && (qi[i + 2][j + 2] == p) && (qi[i + 3][j + 3] == p))
            {
                gotoxy(2, 6);
                textcolor(10 + 2 * p);
                printf("-:@-Win!");

                gotoxy(9, 4);
                textcolor(13);
                printf("  BINGO GAME OVER!  ");
                Sleep(10 * 1000);
                getchar();
                return p;
            }
        }
    }

     for (i = 4; i <= 7; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            p = qi[i][j];
            if (p == 0)
            {
                continue;
            }

            if ((qi[i][j] == p) && (qi[i - 1][j + 1] == p) && (qi[i - 2][j + 2] == p) && (qi[i - 3][j + 3] == p))
            {
                gotoxy(2, 6);
                textcolor(10 + 2 * p);
                printf("-:@-Win!");

                gotoxy(9, 4);
                textcolor(13);
                printf("  BINGO GAME OVER!  ");
                Sleep(10 * 1000);
                getchar();
                return p;
            }
        }
    }

    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 6; j++)
        {
            p = qi[i][j];
            if (p == 0)
            {
                continue;
            }

            if ((qi[i][j] == p) && (qi[i + 1][j] == p) && (qi[i + 2][j] == p) && (qi[i + 3][j] == p))
            {
                gotoxy(2, 6);
                textcolor(10 + 2 * p);
                printf("-:@-Win!");

                gotoxy(9, 4);
                textcolor(13);
                printf("  BINGO GAME OVER!  ");
                Sleep(10 * 1000);
                getchar();
                return p;
            }
        }
    }

    for (i = 1; i <= 7; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            p = qi[i][j];
            if (p == 0)
            {
                continue;
            }

            if ((qi[i][j] == p) && (qi[i][j + 1] == p) && (qi[i][j + 2] == p) && (qi[i][j + 3] == p))
            {
                gotoxy(2, 6);
                textcolor(10 + 2 * p);
                printf("-:@-Win!");

                gotoxy(9, 4);
                textcolor(13);
                printf("  BINGO GAME OVER!  ");
                Sleep(10 * 1000);
                getchar();
                return p;
            }
        }
    }

    if (step == 42)
    {
        gotoxy(2, 6);
        textcolor(10 + 2 * p);
        printf("-:Draw!");

        gotoxy(9, 4);
        textcolor(13);
        printf("  BINGO GAME OVER!  ");
        Sleep(10 * 1000);
        getchar();
        return 0;
    }

    return -1;
}

int main()
{
    int winper = 0;

    system("chcp 437>nul.");
    system("color a");

    x = 11;
    y = 6;

    gotoxy(14, 3);
    printf("BINGO GAME \n");
    gotoxy(x, y + 0);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 187);
    gotoxy(x, y + 1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(x, y + 3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(x, y + 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(x, y + 7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(x, y + 9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(x, y + 11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 188);

    x = xo;
    y = yo;
    chess = RED_CHESS;
    nextchess = RED_CHESS;
    printQi(x, y, nextchess);

    while (1)
    {
        if (kbhit())
        {
            clearQi(x, y);
            chess = nextchess;
            kb = getch(); //接收一个按键的代码

            if (kb == 27)
                exit(0); //是ESC键则退出游戏

            if (kb == 77) //向前进一格
            {
                if (x < 7)
                    x++;
                printQi(x, y, chess);
            }
            if (kb == 75) //向后退一格
            {
                if (x > 1)
                    x--;
                printQi(x, y, chess);
            }
            if (kb == 13)
            {
                if (qi[x][y + 1] != EMPTY)
                    continue;
                while (y < 6 && (qi[x][y + 1] == EMPTY))
                {
                    y = y + 1;
                }
                //chess = step % 2 + 1;
                qi[x][y] = chess;
                if (qi[x][y] == RED_CHESS)
                {
                    printQi(x, y, RED_CHESS);
                }
                else
                {
                    printQi(x, y, YELLOW_CHESS);
                }

                x = xo, y = yo;
                step++; // next chess
                nextchess = step % 2 + 1;
                printQi(x, y, nextchess);
                winper = win();
                if (winper != -1)
                {
                    return 0;
                }
            }
            Sleep(200);
        }
        // gotoxy(10+x*2,y); putchar(2);Sleep(200);  //新位置上显示棋子
    }

    getchar();
    return 0;
}
