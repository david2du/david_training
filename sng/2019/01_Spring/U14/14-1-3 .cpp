#include <bits/stdc++.h>
#include <windows.h>
#include <WinBase.h>
#include <conio.h>
using namespace std;
/*
移动光标函数
input: x坐标 ,y坐标
return: void  
*/ 
void gotoxy(int x,int y)
{    
    HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(hout,pos);
}

/*
结构体 Rice
属性：
	x坐标 ,y坐标
	存在标志 
方法：
	void draw()
*/
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
		cout << "M";
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
		cout << "C";
		Sleep(100);
	}
	
	void clean()
	{
		gotoxy(x, y);
		cout << " ";
	}
	void move(int mx, int my)
	{
		clean();
		int fx = mx - x;
		int fy = my - y;
		
		if (abs(fx) >= abs(fy))
		{
			if(mx > x)
			{
				x+=2;
			}
			else
			{
				x-=2;
			}
		} 
		else
		{
			if(my > y)
			{
				y+=2;
			}
			else
			{
				y-=2;
			}
		}
	}
	
	bool catchm( int mx, int my)
	{
		int fx = mx - x;
		int fy = my - y;
		
		if ((abs(fx) <= 1) && (abs(fy) <= 1))
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
	
};

void pcover()
{
	gotoxy(35, 12);
	cout << "-- CAT CATCHES MOUSE --" << endl;
	getchar();
	system("cls");
}
void pend(bool catw, bool mousew)
{
	system ("cls");
	gotoxy(35, 12);

	if (mousew)
	{
		cout << "MOUSE WINS!!" << endl << setw(39) << "OVER";
	}
	else if (catw)
	{
		cout << "CAT WINS!!" << endl << setw(39) << "OVER";
	}
	else
	{
		cout << "GAME OVER!!" << endl;
	}

	getchar();
	system("cls");
}

const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;
const int ESC = 27;
const int NUM = 5;

int main()
{
	char kb;
	bool catw = false, mousew = false;
	bool finish = false;
	
	srand(time(0));
	
	pcover();
	cout << setw(80) << "SCORE : 0";
	
	Mouse mouse;
	mouse.x = 1;
	mouse.y = 1;
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
					//mouse.draw();
					break;
					
				case DOWN :
					mouse.down();
					//mouse.draw();
					break;
					
				case LEFT :
					mouse.left();
				//	mouse.draw();
					break;
					
				case RIGHT :
					mouse.right();
				//	mouse.draw();
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
				//	mouse.pscore();
					break;
				}
			}	
		}
		
		//cat.catchm(mouse.x, mouse.y);
		cat.move(mouse.x, mouse.y);
		for (int i = 0; i < 50; i++)
		{
			if (rice[i].exist)
			{
				rice[i].draw();
			}
		}
		mouse.draw();
		mouse.pscore();		
		cat.draw();
		
		if (mouse.score >= NUM)
		{
			mousew = true;
			finish = true;
		}
		if(cat.catchm(mouse.x, mouse.y))
		{
			catw = true;
			finish = true;
		}
	}
	pend(catw, mousew);
	
	return 0;
}
