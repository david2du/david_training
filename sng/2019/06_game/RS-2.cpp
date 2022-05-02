#include <bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
#include <WinBase.h>
using namespace std;

const int SYM ='#' ;

void move();
bool dropOneBlk();
void gotoxy(int x,int y)
{    
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;  
	pos.Y = y;
    SetConsoleCursorPosition(hout, pos);
}

void color(int c)  
{  
    HANDLE hConsole;  
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
    SetConsoleTextAttribute(hConsole, c);  
}

int gi = 0,gj = 0,gch = 0,gs = 0;
int gfx = 0,gfy = 0;
int gmap[25][28] = {0};
int gkillLines = 0; 
//int gScores = 0; 

int gx0[7][4] = 
	{
		{ 0,-2,-1, 0},
		{ 0, 0, 1, 2},
		{ 0, 0, 0, 0},
		{ 0,-1, 0, 1},
		{ 0, 0, 1, 1},
		{ 0,-1, 0, 1},
		{ 0,-1, 0, 1}
	};
int gy0[7][4]=
	{
    	{ 0, 0, 0, 1},
    	{ 0, 1, 0, 0},
    	{ 0,-1, 1, 2},
		{ 0, 0, 1, 1},
        { 0, 1, 0, 1},
        { 0, 1, 1, 0},
        { 0, 0, 1, 0}
	};


 
int gx[7][4]= {0};
int gy[7][4]= {0};

int gm_blks[24] = {0};

void pSmallBox(int x1, int x2, int y1, int y2)
{
	gotoxy(50, 8);
	int i = 0;
	
	int x , y; 
	 
	x = x1, y = y1; 
	for ( i = x1; i < (x2 + 1); i++)
	{
		gotoxy(x, y);
		putchar('-');
		x++;
	}
	
	x = x1;
	y = y2; 
	for ( i = x1; i < (x2 + 1); i++)
	{
		gotoxy(x, y);
		putchar('-');
		x++;
	}
	
	
	x = x1;
	y = y1; 
	for (i = y1; i < (y2 + 1); i++)
	{
		gotoxy(x, y);
		putchar('|');
		y++;
	}
	
	x = x2; 
	y = y1; 
	for (i = y1; i < (y2 + 1); i++)
	{
		gotoxy(x, y);
		putchar('|');
		y++;
	}

}

void displayNext(int i, char ch)
{
	int j, setx, sety;
    for(j = 0; j < 4; j++)
    {          
        color(i + 8);
        setx = 54 + gx[i][j];  
		sety = 14 + gy[i][j];
        gotoxy(setx, sety); 
		putchar(ch);  
    }
}

const int X1 = 50;
const int X2 = 58;
const int Y1 = 10;
const int Y2 = 18;
int gni = 0;
	
void pnext()
{
	displayNext(gi, 32);
	gni = rand() % 7;
	
	pSmallBox(X1, X2, Y1, Y2);
	displayNext(gni, 219);
	gi = gni;
}

void display(int i,char ch) 
{ 
	int j, setx, sety;
    for(j = 0; j < 4; j++)
    {          
        color(i + 8);
        setx = gfx + gx[i][j];  
		sety = gfy + gy[i][j];
        gotoxy(setx, sety); 
		putchar(ch);  
    }
}

void pbox()
{
	int fx = 0, fy = 0;	
	
	system("chcp 437"); 
	system("cls"); 
	srand(time(0));
  
	for(fy = 4; fy <= 24; fy++)
    {  
		gotoxy(10, fy);  
		putchar(SYM); 
		gmap[fy][10] = 1;
	   
    	gotoxy(27, fy);  
		putchar(SYM); 
		gmap[fy][27] = 1;
    }
	for( fx = 10; fx <= 27; fx++)
    {
    	gotoxy(fx,24);  
		putchar(SYM); 
		gmap[24][fx] = 1;
    }


	for (fy=22; fy < 24; fy++)
	{
		for (fx = 11; fx < 27; fx++)
		{
			gotoxy(fx,24);  
			putchar(SYM); 
			gmap[fy][fx] = 1;
			gm_blks[fy] = 16; 
		}
	}
}

bool finDrop()
{
	int fx = 0, fy = 0;
	int i = gi, j = 0;
	bool fin = false;
	
	for (j = 0; j < 4; j++)
	{
		fx = gfx + gx[i][j];
		fy = gfy + gy[i][j];
		
		if (gmap[fy + 1][fx] == 1)
		{
			fin = true;
			break;
		}
	}

	return fin;
}



bool getOneBlk()
{
	bool ok = true;
	int i = 0, fx = 0, fy = 0;
	
	//memcpy(gx, gx0, 28);
    //memcpy(gy, gy0, 28);
    int m = 0, n = 0; 
    for(m = 0; m < 7; m++)
    {
    	for (n = 0; n < 4; n++)
    	{
    		gx[m][n] = gx0[m][n];
    		gy[m][n] = gy0[m][n];
		}
	}
	
	i = rand() % 7;
	//i = 4; 
	
	for (int j = 0; j < 4; j++)
	{
		fx = 20 + gx[i][j];
		fy = 3 + gy[i][j];
		
		if (gmap[fy][fx] == 1)
		{
			ok = false;
			break;
		}
	}
	if (ok)
	{
		gi = i;
	}
	
	return ok;	
}

const int SPEED = 150;

void clearScr() 
{
	int x; 
	int y; 

	for (y = 0 ; y < 25 ; y++)
	{
		for (x = 0; x < 28 ; x++)
		{
			gotoxy(x,y); 
			putchar(' ');
		}
	}
}

int score()
{
	int scores = 0;	
	
	/*
	if (gkillLines == 1)
	{
	scores += 3; 
	}
	else if (gkillLines == 2)
	{
	scores += 5;
	}
	else if (gkillLines == 3)
	{
		scores += 8;
	}
	else if (gkillLines == 4)
	{
		scores += 13;
	}
	else
	{
		scores += 10;
	}
	*/
	
	scores = (gkillLines - 1) * gkillLines + 1;
	
	return scores;
}

void pscores()
{
	int scores = 0;
	
	scores = score();
	 
	gotoxy (60 , 3);
	cout << "SCORES :	" << scores ; 
	
}
void refreshScr() 
{
	int x; 
	int y; 

	for (y = 0 ; y < 25 ; y++)
	{
		for (x = 0; x < 28 ; x++)
		{
			if(gmap[y][x] != 0)
			{
				gotoxy(x,y); 
				putchar(SYM);
			}
				
		}
	}
	
}

void rmFullBlks() 
{
	int j = 0; 
	for (j = 24; j > 0; j--)
	{
		//rm full blok lines
		if (gm_blks[j] == 16 )
		{
			clearScr();
			gkillLines++ ;
			for (int i = 11; i < 27; i++ )
			{
				gmap[j][i] = 0; 
				gm_blks[j] = 0; 
			}	

			for (int mj = j - 1; mj > 0; mj--)
			{
				for (int mi = 0; mi < 27; mi++)
				{
					gmap[mj + 1][mi] = gmap[mj][mi];
					gm_blks[mj + 1] = gm_blks[mj]; 

				}
			}
			refreshScr();	
			pscores();	
		}
	}

}

bool dropOneBlk()
{
	gfx = 20; 
	gfy = 3; 
	//gi = rand() % 7;
	bool finish = false;
	
	do
	{
		display(gi, SYM); 
		Sleep(SPEED);
		finish = finDrop();
		if (!finish)
		{
			display(gi, ' ');
			gfy++;
			move();
		}
	
    }
	while(!finish);
	
    
    int j = 0, fx = 0, fy = 0;
	for (j = 0; j < 4; j++)
	{
		fx = gfx + gx[gi][j];
		fy = gfy + gy[gi][j];
		
		gmap[fy][fx] = 1;
		gm_blks[fy]++; // add block number
	}
	
	return true;
}

void dropBlks()
{
	
	do
	{
		if(!getOneBlk())
		{
			break;
		}
		pnext();
		dropOneBlk();
		rmFullBlks();
		//refresh();
	}
	while(true);
}

void clean()
{
	display(gi, ' ');
}

void left()
{
	if (gfx > 12)
	{	
		gfx--;
	}
	//display(gi, '#');
}

void right()
{
	if(gfx < 25)
	{
		gfx++;
	}
	
	//display(gi, '#');
}

void down()
{
	//dropOneBlk();
}

void spin()
{
	int tmpx, tmpy;
	
	for (int j = 0; j < 4; j++)
	{
		tmpx = gx[gi][j];
		tmpy = gy[gi][j];
		
		gx[gi][j] = -tmpy;
		gy[gi][j] = tmpx;
	}
	
}

const int LEFT = 75;
const int RIGHT = 77;
const int ESC = 27;
const int ENT = 13;
//const int SPACE = 32;

void kbi()
{
	int kb = 0, dir = 0;
	
	if (kbhit())
	{
		kb = getch();
		switch(kb)
		{
			case LEFT :
				left();
				break;
			
			case RIGHT :
				right();
				break;
			
			case ENT :
				spin();
				break;
				
			default :
				down();
				break;
		}
	}	
}	

void move()
{
	kbi();
}

void pend()
{
	system("color 4");
	system("cls");
	gotoxy(50, 10);
	cout << "GAME	OVER";
	gotoxy(50, 13);
	cout << "BLOCKS   FULL";
}

int main()
{
	getchar();
	pbox();
	dropBlks();
	pend();
   
	getchar();  
    return 0;
}
