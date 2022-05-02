#include <bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
#include <WinBase.h>
using namespace std;
void move();
bool dropOneBlk();
void gotoxy(int x, int y)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hout, pos);
}

int color(int c)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c);
}

int gi = 0, gj = 0, gch = 0, gs = 0;
int gfx = 0, gfy = 0;
int gmap[25][28] = {0};
int gx0[7][4] =
	{
		{0, -2, -1, 0},
		{0, 0, 1, 2},
		{0, 0, 0, 0},
		{0, -1, 0, 1},
		{0, 0, 1, 1},
		{0, -1, 0, 1},
		{0, -1, 0, 1}};
int gy0[7][4] =
	{
		{0, 0, 0, 1},
		{0, 1, 0, 0},
		{0, -1, 1, 2},
		{0, 0, 1, 1},
		{0, 1, 0, 1},
		{0, 1, 1, 0},
		{0, 0, 1, 0}};

int gx[7][4] = {0};
int gy[7][4] = {0};

void display(int i, char ch)
{
	int j, setx, sety;
	for (j = 0; j < 4; j++)
	{
		color(i + 8);
		setx = gfx + gx[i][j];
		sety = gfy + gy[i][j];
		gotoxy(setx, sety);
		putchar(ch);
	}
}

void pbox()
{
	int fx = 0, fy = 0;

	system("chcp 437");
	system("cls");
	srand(time(0));

	for (fy = 4; fy <= 24; fy++)
	{
		gotoxy(10, fy);
		putchar('#');
		gmap[fy][10] = 1;

		gotoxy(27, fy);
		putchar('#');
		gmap[fy][27] = 1;
	}
	for (fx = 10; fx <= 27; fx++)
	{
		gotoxy(fx, 24);
		putchar('#');
		gmap[24][fx] = 1;
	}
}

bool finDrop()
{
	int fx = 0, fy = 0;
	int i = gi, j = 0;
	bool fin = false;

	for (j = 0; j < 4; j++)
	{
		fx = gfx + gx[i][j];
		fy = gfy + gy[i][j];

		if (gmap[fy + 1][fx] == 1)
		{
			fin = true;
			break;
		}
	}

	return fin;
}

bool getOneBlk()
{
	bool ok = true;
	int i = 0, fx = 0, fy = 0;

	//memcpy(gx, gx0, 28);
	//memcpy(gy, gy0, 28);
	int m = 0, n = 0;
	for (m = 0; m < 7; m++)
	{
		for (n = 0; n < 4; n++)
		{
			gx[m][n] = gx0[m][n];
			gy[m][n] = gy0[m][n];
		}
	}

	i = rand() % 7;

	for (int j = 0; j < 4; j++)
	{
		fx = 20 + gx[i][j];
		fy = 3 + gy[i][j];

		if (gmap[fy][fx] == 1)
		{
			ok = false;
			break;
		}
	}
	if (ok)
	{
		gi = i;
	}

	return ok;
}

const int SPEED = 100;

bool dropOneBlk()
{
	gfx = 20;
	gfy = 3;
	//gi = rand() % 7;
	bool finish = false;

	do
	{
		display(gi, '#');
		Sleep(SPEED);
		finish = finDrop();
		if (!finish)
		{
			display(gi, ' ');
			gfy++;
			move();
		}

	} while (!finish);

	int j = 0, fx = 0, fy = 0;
	for (j = 0; j < 4; j++)
	{
		fx = gfx + gx[gi][j];
		fy = gfy + gy[gi][j];

		gmap[fy][fx] = 1;
	}

	return true;
}

void dropBlks()
{

	do
	{
		if (!getOneBlk())
		{
			break;
		}
		dropOneBlk();
	} while (true);
}

void clean()
{
	display(gi, ' ');
}

void left()
{
	if (gfx > 12)
	{
		gfx--;
	}
	//display(gi, '#');
}

void right()
{
	if (gfx < 25)
	{
		gfx++;
	}

	//display(gi, '#');
}

void down()
{
	//dropOneBlk();
}

void spin()
{
	int tmpx, tmpy;

	for (int j = 0; j < 4; j++)
	{
		tmpx = gx[gi][j];
		tmpy = gy[gi][j];

		gx[gi][j] = -tmpy;
		gy[gi][j] = tmpx;
	}
}

const int LEFT = 75;
const int RIGHT = 77;
const int ESC = 27;
const int ENT = 13;
//const int SPACE = 32;

int kbi()
{
	int kb = 0, dir = 0;

	if (kbhit())
	{
		kb = getch();
		switch (kb)
		{
		case LEFT:
			left();
			break;

		case RIGHT:
			right();
			break;

		case ENT:
			spin();
			break;

		default:
			down();
			break;
		}
	}
}

void move()
{
	kbi();
}

int main()
{
	getchar();

	pbox();
	dropBlks();

	getchar();
	return 0;
}
