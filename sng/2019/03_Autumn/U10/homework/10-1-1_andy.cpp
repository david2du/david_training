#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <iostream>
using namespace std;

int x = 12, y = 7;

void gotoxy(int x, int y)
{
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hout, pos);
}

void queen(int qx, int qy)
{
    gotoxy(x + qx * 2 - 1, y + qy * 2 - 1);
    printf("Q");
}

int q[9] = {0};
int i = 0;
int j = 0;

int place()
{
    int k = 0;
    for (k = i - 1; k >= 1; k--)
    {
        if (q[i] == q[k] || abs(k - i) == abs(q[k] - q[i]))
            return (0);
    }
    return (1);
}

void pbox()
{

    gotoxy(14, 4);
    printf("     queen \n");
    gotoxy(x, y + 0);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 187);
    gotoxy(x, y + 1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(x, y + 3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(x, y + 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(x, y + 7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(x, y + 9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(x, y + 11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(x, y + 13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(x, y + 15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(x, y + 16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 188);
}
void pqueen()
{
    int n = 0;
    for (n = 1; n <= 8; n++)
    {
        queen(q[n], n);
    }
    gotoxy(x, y + 18);
    j++;
    printf("< %2d >", j);
    getch();
}

int main()
{
    system("chcp 437>nul."); //�޸ĵ�ǰcmd���ڴ���ҳ
    system("color a");

    i = 1;
    q[i] = 0;
    int n = 0;
    while (i > 0)
    {
        do
        {
            q[i]++;
        } while (place() == 0 && q[i] <= 8);

        if (q[i] <= 8)
        {
            if (i == 8)
            {
                pbox();
                pqueen();
            }
            else
            {
                i++;
                q[i] = 0;
            }
        }
        else
        {
            i--;
        }
    }

    getchar();
    return 0;
}
