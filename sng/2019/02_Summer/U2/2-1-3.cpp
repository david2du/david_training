#include <bits/stdc++.h>
#include <windows.h>
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

int rnd = 0;
int cursorX = 17, cursorY = 12;
int c[5][5][5] = 
	{
		{{1,1,0,1,1},{1,0,1,0,1},{0,1,1,1,0},{1,0,1,0,1},{1,1,0,1,1}},
		{{0,1,0,1,0},{1,1,0,1,1},{0,1,0,1,0},{1,0,1,0,1},{1,0,1,0,1}},
        {{1,1,0,1,1},{0,0,0,0,0},{1,1,0,1,1},{0,0,0,0,1},{1,1,0,0,0}},
        {{1,0,0,0,1},{1,1,0,1,1},{0,0,1,0,0},{1,0,1,0,0},{1,0,1,1,0}},
        {{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}}
	};
	
int t[5][5][5] = 
	{
		{{1,1,0,1,1},{1,0,1,0,1},{0,1,1,1,0},{1,0,1,0,1},{1,1,0,1,1}},
		{{0,1,0,1,0},{1,1,0,1,1},{0,1,0,1,0},{1,0,1,0,1},{1,0,1,0,1}},
        {{1,1,0,1,1},{0,0,0,0,0},{1,1,0,1,1},{0,0,0,0,1},{1,1,0,0,0}},
        {{1,0,0,0,1},{1,1,0,1,1},{0,0,1,0,0},{1,0,1,0,0},{1,0,1,1,0}},
        {{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}}
	};		

/*void pcover()
{
	gotoxy(14, 6);
	cout << "ALLOUT" << endl;
	getchar();
}*/

void plight()
{
	int i = 0, j = 0;
	int k = rnd, x = 13, y = 8; 
	for( i = 0; i < 5; i++)
    {
    	for(j = 0; j < 5; j++)
        { 
        	gotoxy(13 + j * 2, 8 + i * 2);
	        if(c[k][i][j] == 1) 
			{
				cout << "O";
			} 
	        if(c[k][i][j] == 0) 
	        {
	        	cout << " ";
			}
        }
	}
	gotoxy(cursorX, cursorY);
}

void pwall()
{
	int x = 12,y = 7,i = 0,j = 0,k = 0;
	
	system("chcp 437 > nul.");  
	system("color a") ;
	
	gotoxy(14,4);
	cout << "ALLOUT" << "	round " << rnd + 1 << endl;
	
	gotoxy(x,y+0);
	printf("%c%c%c%c%c%c%c%c%c%c%c\n",201,205,209,205,209,205,209,205,209,205,187);
	
	gotoxy(x,y+1);
	printf("%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,186);
	
	gotoxy(x,y+2);
	printf("%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,182);
	
	gotoxy(x,y+3);
	printf("%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,186);
	
	gotoxy(x,y+4);
	printf("%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,182);
	
	gotoxy(x,y+5);
	printf("%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,186);
	
	gotoxy(x,y+6);
	printf("%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,182);
	
	gotoxy(x,y+7);
	printf("%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,186);
	
	gotoxy(x,y+8);
	printf("%c%c%c%c%c%c%c%c%c%c%c\n",199,196,197,196,197,196,197,196,197,196,182);
	
	gotoxy(x,y+9);
	printf("%c%c%c%c%c%c%c%c%c%c%c\n",186, 32,179, 32,179, 32,179, 32,179, 32,186);
	
	gotoxy(x,y+10);
	printf("%c%c%c%c%c%c%c%c%c%c%c\n",200,205,207,205,207,205,207,205,207,205,188);
	
	cout << endl;
}

void initCursor()
{
	gotoxy(cursorX, cursorY);
}

const int XMIN = 13;
const int XMAX = 21;  
const int YMIN = 8;
const int YMAX = 16;

void up()
{
	cursorY -= 2;
	if (cursorY < YMIN)
	{
		cursorY = YMAX;
	}
	gotoxy(cursorX, cursorY);
}

void down()
{
	cursorY += 2;
	if (cursorY > YMAX)
	{
		cursorY = YMIN;
	}
	gotoxy(cursorX, cursorY);
}

void left()
{
	cursorX -= 2;
	if (cursorX < XMIN)
	{
		cursorX = XMAX;
	}
	gotoxy(cursorX, cursorY);
}

void right()
{
	cursorX += 2;
	if (cursorX > XMAX)
	{
		cursorX = XMIN;
	}
	gotoxy(cursorX, cursorY);
}

void reset()
{
	int i = 0, j = 0;
	//memcpy(c, t, 5 * 5 * 5);
	//memcpy(&c[rnd], &t[rnd], 5 * 5);
 
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5 ; j++)
		{
			c[rnd][i][j] = t[rnd][i][j];
		}
	}
	//pwall();
	plight();
}

int y2i()
{
	int i = 0;
	i = (cursorY - YMIN) / 2;
	return i;
}

int x2j()
{
	int j = 0;
	j = (cursorX - XMIN) / 2;
	return j;
}

void ent()
{
	int i = 0, j = 0;
	
	i = y2i();
	j = x2j();
	c[rnd][i][j] = !c[rnd][i][j];
	
	if(j + 1 < 5)
	{
		c[rnd][i][j + 1] = !c[rnd][i][j + 1];
	}
	if(j - 1 > -1)
	{
		c[rnd][i][j - 1] = !c[rnd][i][j - 1];
	}
	if (i + 1 < 5)
	{
		c[rnd][i + 1][j] = !c[rnd][i + 1][j];
	}
	if (i - 1 > -1)
	{
		c[rnd][i - 1][j] = !c[rnd][i - 1][j];
	}
	
	plight();
}

int finp()
{
	int i = 0, j = 0, n = 0;
	bool finish = false;
	
	for(i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (c[rnd][i][j] == 0)
			{
				n++;
			}
		}
	}
	if (n == 5 * 5)
	{
		finish = true;
	}
	
	return finish;
}

const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;
const int ESC = 27;
const int ENT = 13;
const int SPACE	= 32;

void kbi()
{
	bool finish = false;
	int kb = 0;
	int t0 = 0, t1 = 0; 
	
	t0 = clock();
	gotoxy(1, 1);
	cout << "TIME : " ;  
	
	initCursor();
	while(!finish)
	{
		t1 = clock();
		gotoxy(8, 1);
		cout << (t1 - t0) / CLK_TCK << " s" ;
		Sleep(10);
		gotoxy(cursorX, cursorY);
		
		if (finp() == true)
		{
			finish = true;
		}
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
					up();
					break;
					
				case DOWN :
					down();
					break;
					
				case LEFT :
					left();
					break;
					
				case RIGHT :
					right();
					break;
				
				case ENT :
					ent();
					break;
					
				case SPACE :
					reset();
					t0 = t1;
					break;	
					
				default : 
					break;				
			}
		}
	}
}

int main()
{
	for (rnd = 0; rnd < 5; rnd++)
	{
		pwall();
		plight(); 
		kbi();
		system("cls");
	
	}
	
	getchar();
	return 0;
}
