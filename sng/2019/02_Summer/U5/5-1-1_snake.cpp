#include <bits/stdc++.h>
#include <Windows.h>
#include <conio.h>
using namespace std;
void gotoxy(int x,int y)
{    
    HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(hout,pos);
}

const int NUMEGG = 20;

struct Egg
{
	bool exist ;
	int x;
	int y;
	void pegg()
	{
		gotoxy(x, y);
		putchar('O');
	}		
};

const int LENGTH = 70;

struct Snake
{
	int len;
	int x[LENGTH];
	int y[LENGTH];
	void psnake()
	{

		for (int i = 0; i < len; i++)
		{
			gotoxy(x[i], y[i]);
			//system("chcp 437 > nul.");  
			//system("color a") ;
			if (i == 0)
			{
				putchar(219);
			} 				
			else if (i == len - 1)
			{
				putchar(247);
			}
			else
			{
				putchar(178);
			}
		}
		
	}
};

void box(int x1, int y1,int x2,  int y2, int ch)
{
	int i = 0;
	int x = 0, y = 0; 
 
	x = x1, y = y1; 
	for ( i = x1; i < (x2 + 1); i++)
	{
		gotoxy(x, y);
		putchar(ch);
		x++;
	}
	
	x = x1;
	y = y2; 
	for ( i = x1; i < (x2 + 1); i++)
	{
		gotoxy(x, y);
		putchar(ch);
		x++;
	}
	
	
	x = x1;
	y = y1; 
	for (i = y1; i < (y2 + 1); i++)
	{
		gotoxy(x, y);
		putchar(ch);
		y++;
	}
	
	x = x2; 
	y = y1; 
	for (i = y1; i < (y2 + 1); i++)
	{
		gotoxy(x, y);
		putchar(ch);
		y++;
	}

}

const int X1 = 3;
const int X2 = 110;
const int Y1 = 3;
const int Y2 = 27;
const int CH = '#';

void pwall()
{
	system("chcp 437 > nul.");  
	system("color a") ;
	box(X1,Y1, X2,Y2,'#');
}

Egg eggs[NUMEGG];

void peggs()
{
	srand(time(0));
	for (int i = 0; i < NUMEGG; i++)
	{
		eggs[i].x = rand() % (X2 - X1 - 1) + (X1 + 1);
		eggs[i].y = rand() % (Y2 - Y1 - 1) + (Y1 + 1);
		eggs[i].exist = true;
		eggs[i].pegg();
	}
}

Snake snake;

void psnake()
{
	snake.len = 10;
	for (int i = 0; i < snake.len; i++)
	{
		snake.x[i] = ((X2 - X1) / 2 - 5 + i * 2);
		snake.y[i] = (Y2 - Y1) / 2;
	}
	snake.psnake(); 
}

const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;
const int ESC = 27;
const int ENT = 13;
const int SPACE	= 32;

int  kbh( int dir)
{ 
	int kb = 0;
	int keydir = dir; 
	
	if(kbhit())
    {
    	kb = getch();
    	switch (kb)
    	{
    		case ESC :
    			exit (0);
    		
			case RIGHT :
				keydir = 1;
				break;  
			
			case UP:
				keydir = 2; 
				break;
				
			case LEFT:
				keydir = 3; 
				break;
			
			case DOWN:
				keydir = 4;
				break;
				
			default:
				keydir = dir;
				break;
				
		}
	}
	else
	{
		keydir = dir;
	}
	
	return keydir;
}

void movesnake(int x, int y)
{
	int i = 0;
	int tail = snake.len; 
	gotoxy(snake.x[tail-1], snake.y[tail-1]);
	cout << "  " ;
	for (i = snake.len - 1; i >= 0; i--) 
	{
		if(i > 0)
		{
			snake.x[i] = snake.x[i-1];
			snake.y[i] = snake.y[i-1];		
		}
		else
		{
			snake.x[i] = snake.x[i] + x * 2; 
			snake.y[i] = snake.y[i] + y * 2;
		}
	}
	snake.psnake();
}

void move()
{
	int  x = 0, y = 0, dir = 0, a = 0; 
    int mx[5] = {0, 1, 0, -1, 0}, my[5] = {0, 0, -1, 0, 1}; 
    bool finish = false;
	
	while(!finish)
	{
		dir = kbh(dir);
		if(dir != -1)
			movesnake(mx[dir], my[dir]);
		Sleep(250);
	}

}

int main()
{
	pwall();
	peggs();
	psnake();
	move();
	
	getchar();
	return 0;
} 
