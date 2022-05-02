#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

int x = 0, y = 0, kb = 0, step = 0;
int xo = 4, yo = 5;
int color = 2;
int qi[8][7] = {0}; //yellow : 1, red : 2
int top[8] = {0};

void gotoxy(int x, int y)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
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

void pbox()
{
	int x_box = 0, y_box = 0;

	system("chcp 437>nul.");
	system("color a");

	x_box = 11;
	y_box = 6;

	gotoxy(14, 3);
	printf("BING GAME \n");
	gotoxy(x_box, y_box + 0);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 209, 205, 187);
	gotoxy(x_box, y_box + 1);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
	gotoxy(x_box, y_box + 2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
	gotoxy(x_box, y_box + 3);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
	gotoxy(x_box, y_box + 4);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
	gotoxy(x_box, y_box + 5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
	gotoxy(x_box, y_box + 6);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
	gotoxy(x_box, y_box + 7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
	gotoxy(x_box, y_box + 8);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
	gotoxy(x_box, y_box + 9);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
	gotoxy(x_box, y_box + 10);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 199, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 197, 196, 182);
	gotoxy(x_box, y_box + 11);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 179, 32, 186);
	gotoxy(x_box, y_box + 12);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 207, 205, 188);
	x = xo;
	y = yo;
	gotoxy(10 + x * 2, y);
	putchar('Q');

	getchar();
}

void cleanQi(int x, int y)
{
	gotoxy(10 + x * 2, y * 2 + 5);
	putch(32);
}

void printQi(int x, int y, int qi) //dir : 1,left ; 2,right ; 3, drop ; 0, no
{
	int color = 0;

	if (qi == 1)
	{
		color = 6;
	}
	if (qi == 2)
	{
		color = 12;
	}

	gotoxy(10 + x * 2, y * 2 + 5);
	textcolor(color);
	putch(qi+'0');
}

void left()
{
	if (x > 1)
	{
		x--;
		printQi(x, y, (step + 1) % 2 + 1);
	}

	return;
}

void right()
{
	if (x < 7)
	{
	//cleanQi(x, y);
		x++;
		printQi(x, y, (step + 1) % 2 + 1);
	}

	return;
}

void down()
{
	int i = 0;

	top[x]++;
	y = 7 - top[x];
	if (y < 0)
	{
		return;
	}
	step++;
	qi[x][y] = step % 2 + 1;

	/*for (i = 1; i < y; i++)
	{
		printQi(x, i, step % 2 + 1);
		Sleep(30);
		cleanQi(x, i);
	}*/
	printQi(x, y, step % 2 + 1);
	x = xo;
	y = yo;
	printQi(x, y, 2);

	return;
}

const int LEFT = 75;
const int RIGHT = 77;
const int ESC = 27;
const int ENT = 13;

void kbi()
{
	int kb = 0;

	if (kbhit())
	{
		kb = getch();
		cleanQi(x, y);
		switch (kb)
		{
			case LEFT:
				left();
				break;
	
			case RIGHT:
				right();
				break;
	
			case ENT:
				down();
				break;
	
			default:
				break;
		}
	}
}

int main()
{
	pbox();

	while (1)
	{
		kbi();
		Sleep(30);
	}

	return 0;
}
