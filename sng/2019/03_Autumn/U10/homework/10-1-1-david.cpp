#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

class Stack
{
private:
	int x = 0, y = 0;
	int top = 0;
	vector<int> queen;

public:
	void push_back()
	{
		queen.pop_back();
		top++;
	}

	void pop_back(int n)
	{
		queen.pop_back();
		top--;
	}

	int top_f()
	{ 
		return top;
	}

	bool empty()
	{
		if(queen.size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}

	bool fight()
	{
		int i = 0;

		for (i = i - 1; i >= 1; i--)
		{
			if (queen[i] == queen[top] || abs(top - i) == abs(queen[top] - queen[i]))
			{
				return true;
			}
		}
		return false;
	}
}
;

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

int main()
{
	
	return 0;
}