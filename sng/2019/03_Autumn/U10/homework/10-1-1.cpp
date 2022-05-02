#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

class Stack
{
private:
    int x = 0, y = 0;

public:
    vector<int> queen;

    void push_back(int n)
    {
        queen.push_back(n);
    }

    void pop_back()
    {
        queen.pop_back();
    }

    int top()
    {
        return queen.back();
    }

    int size()
    {
        return queen.size();
    }

    bool fight() //true : fight, false : don't fight
    {
        int i = 0;

        for (i = top() - 1; i >= 1; i--)
        {
            if((queen[i] == queen[top()]) || (abs(top() - i) == abs(queen[top()] - queen[i])))
            {
                return true;
            }
        }

        return false;
    }
};

void gotoxy(int x, int y)
{
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hout, pos);
}

const int X = 2, Y = 1;

void pbox()
{

    system("chcp 437>nul.");
    system("color a");

    gotoxy(14, 4);
    printf("     queen \n");

    gotoxy(X, Y + 0);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 187);
    gotoxy(X, Y + 1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(X, Y + 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(X, Y + 3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(X, Y + 4);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(X, Y + 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(X, Y + 6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(X, Y + 7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(X, Y + 8);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(X, Y + 9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(X, Y + 10);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(X, Y + 11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(X, Y + 12);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(X, Y + 13);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(X, Y + 14);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
    gotoxy(X, Y + 15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
    gotoxy(X, Y + 16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 188);
}

void pqueen(int qx, int qy)
{
    gotoxy(X + qx * 2 - 1, Y + qy * 2 - 1);
    printf("Q");
}

void pcnt(int cnt)
{
    gotoxy(7, 18);
    printf("< %2d >", cnt);
    getchar();
}

int main()
{
    Stack s;

    int i = 0, cnt = 0;
    int n = 0;

    i = 1;
    s.queen[i] = 0;
    while (i > 0)
    {
        do
        {
            s.queen[i]++;
        } while (s.fight() == 0 && s.queen[i] <= 8);

        if (s.queen[i] <= 8)
        {
            if (i == 8)
            {
                for (n = 1; n <= 8; n++)
                {
                    pqueen(s.queen[n] * 2, n * 2);
                }

                cnt++;
                pcnt(cnt);
            }
            else
            {
                i++;
                s.queen[i] = 0;
            }
        }
        else
        {
            i--;
        }
    }

    return 0;
}