#include <stdio.h>
#include <conio.h>
#include <time.h>
#include<windows.h>
#include<iostream>
using namespace std;

int x = 1, y = 1, h[6][6], j, i, p[65], px[65], py[65], n = 5, u, v, k;
int mx[9] = {0, 2, 1,-1,-2,-2,-1,1,2};
int my[9] = {0,-1,-2,-2,-1, 1, 2,2,1};

void gotoxy(int x,int y)
{    
     HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
     COORD pos;
     pos.X=x;
     pos.Y=y;
     SetConsoleCursorPosition(hout,pos);
}

void bg()
{
	system("chcp 437>nul."); 
	system("color a") ;
	printf("                 ");printf("\n");	
	printf(" зддбддбддбддбдд©");printf("\n");
	printf(" Ё  Ё  Ё  Ё  Ё  Ё");printf("\n");
	printf(" цддеддеддеддедд╢");printf("\n");
	printf(" Ё  Ё  Ё  Ё  Ё  Ё");printf("\n");
	printf(" цддеддеддеддедд╢");printf("\n");
	printf(" Ё  Ё  Ё  Ё  Ё  Ё");printf("\n");
	printf(" цддеддеддеддедд╢");printf("\n");
	printf(" Ё  Ё  Ё  Ё  Ё  Ё");printf("\n");
	printf(" цддеддеддеддедд╢");printf("\n");
	printf(" Ё  Ё  Ё  Ё  Ё  Ё");printf("\n");
	printf(" юддаддаддаддадды");printf("\n");
}

int main()
{	  
	gotoxy(1,1);
	bg();
	
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			h[i][j]=0;
		}
	}
    i = 1;
	x = 1;
	y = 1;
	k = 0;
	px[1] = x;
	py[1] = y;
	h[x][y] = 1;
	p[1] = 0;
	gotoxy(x * 3 - 1, y * 2);
	printf("1");

	while(i > 0)
	{
		k++;
		if(k > 8)
		{
			gotoxy(x * 3 - 1, y * 2);
			printf("  ");
			h[x][y] = 0;
		    i--;
			k = ++p[i];
			x = px[i];
			y = py[i];
		  }
    	u = x + mx[k];
		v = y + my[k];
    	if ((u >= 1) && (u <= n) && (v >= 1) && (v <= n) && (h[u][v] == 0))
		{
			p[i] = k;
			i++;
			h[u][v] = i;
			px[i] = u;
			py[i] = v;
			gotoxy(u * 3 - 1, v * 2);
			printf("%2d",i);
			//getch();
		}
	    else
	    {
	    	continue;
		}
	    if (i < n * n) 
		{
			x=u;
			y=v;
			k=0;
			continue;
		}
	    else 
		{
			gotoxy(14, 14);
			system("pause");
		};
    }
}
