#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

int x, y, kb, step;
int color = 2;
int qi[8][7] = {1};//yellow : 1, red : 2
int top[8] = {0};

void gotoxy(int x,int y)
{    
     HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); 
     COORD pos;
     pos.X = x;
     pos.Y = y;
     SetConsoleCursorPosition(hout,pos);
}

int textcolor(int c)  
{  
    HANDLE hConsole;  
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
    SetConsoleTextAttribute(hConsole, c);  
}  

void pbox()
{
   
	system("chcp 437>nul."); //修改当前cmd窗口代码页
	system("color a") ;

  	x = 11;
	y = 6;
  
  // x=0;y=0;
  gotoxy(14,3); printf("BING GAME \n");  
  gotoxy(x,y+0); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,209,205,209,205,209,205,209,205,209,205,209,205,187);
  gotoxy(x,y+1); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,179, 32,179, 32,186);
  gotoxy(x,y+2); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,197,196,197,196,182);
  gotoxy(x,y+3); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,179, 32,179, 32,186);
  gotoxy(x,y+4); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,197,196,197,196,182);
  gotoxy(x,y+5); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,179, 32,179, 32,186);
  gotoxy(x,y+6); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,197,196,197,196,182);
  gotoxy(x,y+7); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,179, 32,179, 32,186);
  gotoxy(x,y+8); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,197,196,197,196,182);
  gotoxy(x,y+9); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,179, 32,179, 32,186);
  gotoxy(x,y+10);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,197,196,197,196,182);
  gotoxy(x,y+11);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,179, 32,179, 32,186);
  gotoxy(x,y+12);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,207,205,207,205,207,205,207,205,207,205,207,205,188);   
 
	getchar();  
}

void pqi()
{
	int x1 = 1, y1 = 1;
	
	for (x1 = 1; x1 < 8; x1++)
	{
		for (y1 = 1; y1 < 9; y1++)
		{
			gotoxy(10 + x1 * 2, y1);
			textcolor(qi[x1][y1] + 11);
			putchar(qi[x1][y1]);
		}
	} 	
}

void left()
{
	x--;
	
	return;
}

void right()
{
	x++;
	
	return;
}

void down()
{
	y = ++top[x];
	
	return;
}

const int LEFT = 75;
const int RIGHT = 77;
const int ESC = 27;
const int ENT = 13;

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
				down();
				break;
	
			default:
				break;
		}
		pqi();
	}
}   

int main()
{	
	pbox();
	pqi();
	while(1)
	{
		kbi();
	}
	
	return 0;
} 
