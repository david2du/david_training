#include <bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

int j, i, x, y, xo, yo, r = 1, p = 0, nx, ny;
int s[100][3] = {0};
int mx[5] = {0};
int my[5] = {0};
int mg[16][16] = 
	{
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	    1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,
	    1,1,0,1,0,1,1,0,0,0,0,0,0,1,1,1,
	    1,1,0,0,0,1,1,0,0,0,0,0,0,0,1,1,
	    1,1,1,1,0,1,1,0,1,0,1,1,1,1,1,1,
	    1,1,0,1,0,1,0,0,1,1,0,1,0,0,0,1,
	    1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,
	    1,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,
	    1,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,
	    1,1,0,1,1,0,0,1,0,1,0,1,1,1,0,1,
	    1,1,0,1,1,1,1,0,1,0,0,1,0,1,0,1,
	    1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,1,
	    1,1,0,0,0,0,1,1,0,0,0,1,0,0,0,0,
	    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};

void gotoxy(int x, int y)
{    
     HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
     COORD pos;
     pos.X = x;
     pos.Y = y;
     SetConsoleCursorPosition(hout, pos);
}

void draw()
{
	system("chcp 437>nul."); 
	system("color a");
	
	for (i = 1; i < 16; i++)
	{
		for(j = 1; j < 16; j++)
		{
    		if (mg[i][j] == 1)
			{
				gotoxy(j, i);
				putchar(219);
			}
    	}
	}
}

int main()
{
   draw();
   gotoxy(x,y); putch('\002');

	while (p!=0)
	{  


    } while (!(nx==15 && ny==13) );
}
