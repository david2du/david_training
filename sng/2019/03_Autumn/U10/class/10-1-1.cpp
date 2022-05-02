#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

void gotoxy(int x,int y)
{    
     HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD pos;
     pos.X = x;
     pos.Y = y;
     SetConsoleCursorPosition(hout,pos);
}

const int X = 2, Y = 1;

void pbox()
{
 
	system("chcp 437>nul.");
	system("color a") ;

	gotoxy(14,4);
	printf("     queen \n");
	  
	gotoxy(X, Y + 0);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,209,205,209,205,209,205,209,205,209,205,209,205,209,205,187);
	gotoxy(X, Y + 1);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179,32,179, 32,179, 32,179, 32,186);
	gotoxy(X, Y + 2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,182);
	gotoxy(X, Y + 3);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,179, 32,179, 32,179, 32,186);
	gotoxy(X, Y + 4);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,182);
	gotoxy(X, Y + 5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179,32,179, 32,179, 32,179, 32,186);
	gotoxy(X, Y + 6);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,182);
	gotoxy(X, Y + 7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,179, 32,179, 32,179, 32,186);
	gotoxy(X, Y + 8);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,182);
	gotoxy(X, Y + 9);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179,32,179, 32,179, 32,179, 32,186);
	gotoxy(X, Y + 10);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,182);
	gotoxy(X, Y + 11);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,179, 32,179, 32,179, 32,186);
	gotoxy(X, Y + 12);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,182);
	gotoxy(X, Y + 13);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179,32,179, 32,179, 32,179, 32,186);
   	gotoxy(X, Y + 14);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,197,196,197,196,197,196,182);
	gotoxy(X, Y + 15);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179,32,179, 32,179, 32,179, 32,186);
    gotoxy(X, Y + 16);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,207,205,207,205,207,205,207,205,207,205,207,205,207,205,188);   
}

void pqueen(int qx,int qy)
{
	gotoxy(X + qx * 2 - 1, Y + qy * 2 - 1);
	printf("Q");
}

int q[8] = {0};

bool fight(int i)//true : fight, false : don't fight
{
	int j = 0;
	
	for(k = i - 1; k >= 1; k--)
    {  
		if((q[i]==q[k]) || (abs(k - i) == abs(q[k] - q[i]))
		{
			return true;
		}
    }
    
	return false;
}

int main()
{
	int i = 0, j = 0;
	int a = 0, b = 0;
	
	for (a = 0; a < 8; a++)
	{
		q[0] = a;
		for (b = 0; b < 8; b++)
		{
			q[1] = b;
			if ()
		}
	}
	
	return 0;
}
