#include <bits/stdc++.h>
#include <windows.h>
#include <WinBase.h>
#include <conio.h>
using namespace std;

const int YELLOW1 = 236;
const int YELLOW2 = 14;
const int GREEN = 295;
const int BLUE = 9;
const int NORMAL = 15;

void gotoxy(int x,int y)
{    
     HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
     COORD pos;
     pos.X=x;
     pos.Y=y;
     SetConsoleCursorPosition(hout,pos);
}
void color(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) ,a);
}
int main()
{
	int score = 0 ,tScore = 0 ,n = 0 ;
	int x = 0 ,y = 0 ;
	int count = 1;
	
	srand(time(0));
	gotoxy(70 ,2);
	color(YELLOW2);
	cout << "Score : " << score << endl;
	for (x = 0; x < 80; x++)
	{
		gotoxy(x ,3);
		color(YELLOW1);
		cout << "#"; 
	}
	for (x = 0; x < 80; x++)
	{
		gotoxy(x ,23);
		color(YELLOW1);
		cout << "#"; 
	}
	for (n = 1; n < 11; n++)
	{
		gotoxy(80 ,n + 3);
		color(GREEN);
		cout << n << endl; 
	}
	for (n = 1; n < 10; n++)
	{
		gotoxy(80 ,n + 13);
		color(GREEN);
		cout << 10 - n << endl; 
	}
	
	while(count < 4)
	{
		color(BLUE);
		y=rand()%19+4;       
	    for(x=1;x < 78;x++)      
	    {
	        gotoxy(x-1,y); 
			cout << "   ";  
	        gotoxy(x,y); 
			cout << ">->";  
	        Sleep(30);                           
	    }
	    gotoxy(78 ,2);
	    if(y < 14)
	    {
	    	score = y - 3;
		}
		else
		{
			score = 23 - y;
		}
		color(YELLOW2);
		tScore = tScore + score;
		cout << tScore;
	    count++;
	}
		
	getchar();
	getchar();
	return 0;
}
