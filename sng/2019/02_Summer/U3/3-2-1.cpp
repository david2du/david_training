#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;
void gotoxy(int x,int y)
{    
    HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(hout,pos);
}

void box(int x1, int x2, int y1, int y2, int ch)
{
	int i = 0;
	
	int x , y; 
	 
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

int main()
{

	int i = 0;
	int ch = 42;
	int angle[5][4] = 
		{
			{3, 22, 3, 22},
			{5, 20, 5, 20},
			{7, 18, 7, 18},
			{9, 16, 9, 16},
			{11, 14, 11, 14}
		};
	
	for (i = 0; i < 5; i++)
	{
		box(angle[i][0], angle[i][1], angle[i][2], angle[i][3], ch);
	}
	gotoxy(22, 24);
	//box(8, 20, 3, 11, 64);
	getchar();
	
	return 0;
}
