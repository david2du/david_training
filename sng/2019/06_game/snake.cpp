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
		if (exist)
		{
			gotoxy(x, y);
			putchar('O');
		}
	}		
};

const int LENGTH = 70;

struct Snake
{
	int len;
	int x[LENGTH];
	int y[LENGTH];
	int score;
	int eggs; 
	int grade;
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
const int X2 = 160;
const int Y1 = 3;
const int Y2 = 50;
const int CH = '#';

void pwall()
{
	system("chcp 437 > nul.");  
	system("color a") ;
	
	gotoxy(50, 1);
	cout << "SCORE : ";
	box(X1,Y1, X2,Y2,'#');
}

Egg eggs[NUMEGG];

void peggs()
{
	srand(time(0));
	for (int i = 0; i < NUMEGG; i++)
	{
		for ( ; true;)
		{
			eggs[i].x = rand() % (X2 - X1 - 1) + (X1 + 1);;
			eggs[i].y = rand() % (Y2 - Y1 - 1) + (Y1 + 1);;
			if (eggs[i].x % 2 == 1)
			{
				eggs[i].exist = true;
				eggs[i].pegg();
				break;
			}
			
		}
	}
}

Snake snake;

void pInitSnake()
{
	snake.eggs = 0;
	snake.score = 0;
	snake.len = 10;
	for (int i = 0; i < snake.len; i++)
	{
		snake.x[i] = ((X2 - X1) / 2 - 5 + i * 2);
		snake.y[i] = (Y2 - Y1) / 2;
	}
	snake.psnake(); 
}

bool score()
{
	int grade = 0;
	bool eaten = false; 
	for (int i = 0; i < 20; i++)
	{
		if ((eggs[i].x == snake.x[0]) && \
			(eggs[i].y == snake.y[0]) && \
			(eggs[i].exist))
		{
			
			snake.eggs++;
			
			if (snake.eggs <= 5)
			{
				snake.score += 2;
				if (snake.eggs == 5)
				{
					snake.grade = 1;
				} 
			}
			
			else if ((snake.eggs >= 6) && (snake.eggs <= 10))
			{
				snake.score += 3;
				if (snake.eggs == 10)
				{
					snake.grade = 2;
				}
			}
			
			else if ((snake.eggs >= 11) && (snake.eggs <= 15))
			{
				snake.score += 5;
				if (snake.eggs == 15)
				{
					snake.grade = 3;
				}
			}
			
			else
			{
				snake.score += 7;
				if (snake.eggs == 20)
				{
					snake.grade = 4;
				}
			}
			
			eggs[i].exist = false;
			eaten = true; 
			break;
		}
	}
	
	return eaten;
}
void pscore(bool eaten)
{
	if (snake.grade == 1)
	{
		gotoxy(60, 2);
		cout << "GOOD JOB!!!";
	}
	
	else if (snake.grade == 2)
	{
		gotoxy(60, 2);
		cout << "				" ;
		gotoxy(60, 2);
		cout << "AWSOME!!!";
	}
	
	else if (snake.grade == 3)
	{
		gotoxy(60, 2);
		cout << "				" ;
		gotoxy(60, 2);
		cout << "EXCELLENT!!!";
	}
	else if (snake.grade == 4)
	{
		gotoxy(60, 2);
		cout << "				" ;
		gotoxy(60, 2);
		cout << "GERNOUS!!!";
	}
	if(eaten)
	{
		gotoxy(60, 1);
		cout << snake.score << "	egg : " <<snake.eggs;
		
	}

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
				keydir = 0;
				break;
				
		}
	}
	else
	{
		keydir = dir;
	//	keydir = 0;
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
			snake.x[i] = snake.x[i - 1];
			snake.y[i] = snake.y[i - 1];		
		}
		else
		{
			snake.x[i] = snake.x[i] + x * 2; 
			snake.y[i] = snake.y[i] + y;
			
		}
	}
	
   int grade = score();
	pscore(grade);
	
}

void pl()
{
	system("cls");
	gotoxy(40, 13);
	//cout << "score" << endl;
	gotoxy(40, 14);
	cout << "GAME OVER	  DIED" ;
}

void pw()
{
	system("cls");
	gotoxy(40, 13);
	cout << "score" << " 20" << endl;
	gotoxy(40, 14);
	cout << "GAME OVER	  WIN" ;
}

void pend(bool win)
{
	if (win)
	{
		pw();
	}
	else
	{
		pl();
	}
	
	getch();
	return ;
}

bool finp()
{
	bool fin = false;
	
	if ((X1 >= snake.x[0]) || (X2 <= snake.x[0]))
	{
		fin = true;
	}
	
	if ((Y1 >= snake.y[0]) || (Y2 <= snake.y[0]))
	{
		fin = true;
	}
	
	for (int i = 1; i < snake.len; i++)
	{
		if ((snake.x[0] == snake.x[i]) && (snake.y[0] == snake.y[i]))
		{
			fin = true;
			break;
		}
	}
	
	return fin;
}

void move()
{
	int  x = 0, y = 0, dir = 0, a = 0; 
    int mx[5] = {0, 1, 0, -1, 0}, my[5] = {0, 0, -1, 0, 1}; 
    bool finish = false, win = false;
	
	while(!finish)
	{
		dir = kbh(dir);
		if(dir != 0)
		{
			movesnake(mx[dir], my[dir]);		
			
		}
		//finish = finp();
		
		if (finp())
		{
			break;
		}
		
		if (dir != 0)
		{
		
			snake.psnake();
		}
		
		Sleep(200);
		
	}
	
	pend(win);
}

int main()
{
	pwall();
	peggs();
	pInitSnake();
	move();
	
	getchar();
	return 0;
} 
