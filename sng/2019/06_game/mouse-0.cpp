#include <bits/stdc++.h>
#include <windows.h>
#include <WinBase.h>
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

struct Rice
{
	int x;
	int y;
	bool exist;
	void draw()
	{
		gotoxy(x, y);
		cout << ".";
	}
};

struct Mouse
{
	int x;
	int y;
	int score;
	bool exist;
	void draw()
	{
		gotoxy(x, y);
		cout << "@";
	}
	void clean()
	{
		gotoxy(x, y);
		cout << " ";
	}
	void right()
	{
		clean();
		if (x < 80)
		{
			x++;
		}
		else 
		{
			x = 0;
		}
	}
	void left()
	{
		clean();
		if (x > 0)
		{
			x--;
		}
		else 
		{
			x = 80;
		}
	}
	void up()
	{
		clean();
		if (y > 2)
		{
			y--;
		}
		else 
		{
			y = 24;
		}
	} 
	void down()
	{
		clean();
		if (y < 24)
		{
			y++;
		}
		else 
		{
			y = 2;
		}
	}
	void pscore()
	{
		gotoxy(0, 0);
		cout << setw(80) << "SCORE : " << score;
	} 
};

struct Cat
{
	int x;
	int y;	
	void draw()
	{
		gotoxy(x, y);
		cout << "&";
	}
};

void pcover()
{
	gotoxy(35, 12);
	cout << "-- CAT CATCHES MOUSE --" << endl;
	getchar();
	system("cls");
}

const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;
const int ESC = 27;

int main()
{
	char kb;
	bool finish = false;
	int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
	
	srand(time(0));
	
	pcover();
	cout << setw(80) << "SCORE : 0";
	
	Mouse mouse;
	mouse.x = 2;
	mouse.y = 2;
	mouse.score = 0;
	mouse.exist = true;
	
	Cat cat;
	cat.x = 50;
	cat.y = 20;
	
	Rice rice[50] = {{0, 0, false}};

	for (int i = 0; i < 50; i++)
	{
		rice[i].x = rand() % 81;
		rice[i].y = rand() % 23 + 2;
		rice[i].exist = true;
	}
	for (int i = 0; i < 50; i++)
	{
		rice[i].draw();
	}
	mouse.draw();
	cat.draw();
	
	while(!finish)
	{
		if (kbhit())
		{
			kb = getch();
			switch(kb)
			{
				case ESC :
					finish = true;
					system("cls");
					break;
				
				case UP :
					
					mouse.up();
					mouse.draw();
					break;
					
				case DOWN :
					mouse.down();
					mouse.draw();
					break;
					
				case LEFT :
					mouse.left();
					mouse.draw();
					break;
					
				case RIGHT :
					mouse.right();
					mouse.draw();
					break;
				
				default : 
					break;				
			}
			for (int i = 0; i < 50; i++)
			{
				if ((mouse.x == rice[i].x) && \
				(mouse.y == rice[i].y) && \
				(rice[i].exist == true))
				{
					rice[i].exist = false;
					mouse.score++;
					mouse.pscore();
					break;
				}
			}	
		}
	}
	
	return 0;
}
