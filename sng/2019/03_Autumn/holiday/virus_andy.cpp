#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Coor // Coordinate
{
	int x;
	int y;
	int status;
};

void gotoxy(int x, int y)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hout, pos);
}

void textcolor(int c)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c);
}

int vrs[512][512]; // virus
int w, l;		   // width, length

const int YELLOW = 14;
const int RED = 12;
const int GREEN = 10;
const int WHITE = 15;

const int BLANK = 0;
const int HEALTHY = 1;
const int INFECTED = 2;
const int ILL = 3;

int healthyPeople = 0;
int infectedPeople = 0;
int illPeople = 0;
int blank = 0;

vector<Coor> vILLPersons;


void pBox(int x, int y)
{
	gotoxy(x, y);

	for (int i = 0; i < (2 * w + 1); ++i)
	{
		for (int j = 0; j < (2 * l + 1); ++j)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					putchar(201);
				}
				else if (j == (2 * l + 1 - 1))
				{
					putchar(187);
				}
				else if ((j > 0) && (j < (2 * l + 1)))
				{
					if (j % 2 == 0)
					{
						putchar(209);
					}
					else
					{
						putchar(205);
					}
				}
				else
				{
					printf("pBox() ERROR, i: %d, j: %d\n", i, j);
					return;
				}
			}
			else if (i == (2 * w + 1 - 1))
			{
				if (j == 0)
				{
					putchar(200);
				}
				else if (j == (2 * l + 1 - 1))
				{
					putchar(188);
				}
				else if ((j > 0) && (j < (2 * l + 1)))
				{
					if (j % 2 == 0)
					{
						putchar(207);
					}
					else
					{
						putchar(205);
					}
				}
				else
				{
					printf("pBox() ERROR, i: %d, j: %d\n", i, j);
					return;
				}
			}
			else if ((i > 0) && (i < (2 * w + 1 - 1)))
			{
				if (i % 2 == 0)
				{
					if (j % 2 == 0)
					{
						if (j == (2 * l + 1 - 1))
						{
							putchar(182);
						}
						else if (j == 0)
						{
							putchar(199);
						}
						else
						{
							putchar(197);
						}
					}
					else
					{
						putchar(196);
					}
				}
				else
				{
					if (j % 2 == 0)
					{
						if ((j == 0) || (j == (2 * l + 1 - 1)))
						{
							putchar(186);
						}
						else
						{
							putchar(179);
						}
					}
					else
					{
						putchar(32);
					}
				}
			}
			else
			{
				printf("pBox() ERROR, i: %d, j: %d\n", i, j);
				return;
			}
		}

		gotoxy(x, ++y);
	}
}

const int BOX_X = 4;
const int BOX_Y = 10;

void pPpl(int y, int x, int status) // print people
{
	int color = 0;
	gotoxy(2 * x + BOX_X + 1, 2 * y + BOX_Y + 1);

	if (status == ILL)
	{
		color = RED;
	}
	else if (status == INFECTED)
	{
		color = YELLOW;
	}
	else if (status == HEALTHY)
	{
		color = GREEN;
	}
	else 
	{
		return;
	}
	
	textcolor(color);
	printf("@");
}

void pStatus(int day)
{
	textcolor(WHITE);

	gotoxy(30, 3);
	printf("							");
	gotoxy(30, 4);
	printf("							");
	gotoxy(30, 5);
	printf("							");

	gotoxy(30, 3);
	textcolor(GREEN);
	printf("Healthy People : %d", healthyPeople);
	gotoxy(30, 4);
	textcolor(YELLOW);
	printf("Infected People : %d", infectedPeople);
	gotoxy(30, 5);
	textcolor(RED);
	printf("ILL People : %d", illPeople);

	gotoxy(BOX_X, BOX_Y + 2 * w + 5);

	printf("							");
	printf("Day : %d", day);
}

void initMap() // Print the Title and the Box
{
	//system("chcp 437>nul.");
	gotoxy(3, 1);
	textcolor(WHITE);
	printf("Virus Broadcast\n");
	printf("Color : \n");
	textcolor(GREEN);
	printf("	Green : Healthy\n");
	textcolor(YELLOW);
	printf("	Yellow : Infected\n");
	textcolor(RED);
	printf("	Red : ILL\n");

	pBox(BOX_X, BOX_Y);
	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < l; ++j)
		{
			pPpl(i, j, vrs[i][j]);
			if (vrs[i][j] == ILL)
			{
				illPeople++;
				Coor illPerson = {i, j, ILL};
				vILLPersons.push_back(illPerson);
			}
			else if (vrs[i][j] == HEALTHY)
			{
				healthyPeople++;
			}
			else if (vrs[i][j] == INFECTED)
			{
				infectedPeople++;
			}
			else
				continue;
		}
	}
	pStatus(0);
}

const int DX[4] = {-1, 0, 1, 0}, DY[4] = {0, 1, 0, -1}; // direction x, y
const int SLLEEPSEC = 3;								// Sleeping Second

void oneDayVirus(int day, vector<Coor> vProblem /*Color : YELLOW -> RED*/)
{
	if (vProblem.empty())
	{
		return;
	}

	for (int i = 0; i < vProblem.size(); ++i)
	{
		Coor person =  vProblem[i];

		//turn infected to ill
		if (person.status == INFECTED)
		{
			vrs[person.x][person.y] = ILL;
			person.status = ILL; 
			pPpl(person.x,person.y,ILL);
			++illPeople;
		}
	}

	vector<Coor> vNewInfected;

	while (!vProblem.empty())
	{
		Coor now = vProblem.back();
		vProblem.pop_back();

		//turn healthy to infected.
		for (int i = 0; i < 4; ++i)
		{
			int nx = now.x + DX[i], ny = now.y + DY[i];

			if (((nx >= 0) && (nx < w)) && ((ny >= 0) && (ny < l)) &&
				(vrs[nx][ny] == HEALTHY))
			{
				vNewInfected.push_back((Coor){nx, ny,INFECTED});
				++infectedPeople;
				--healthyPeople;
				vrs[nx][ny] = INFECTED;
				pPpl(nx, ny, INFECTED);
			}
		}
	}

	//infectedPeople = vNewInfected.size();
	//healthyPeople -= vNewInfected.size(); /*(w * l) - blank - (infectedPeople + illPeople)*/

	pStatus(++day);
	getch();
	oneDayVirus(day, vNewInfected);
}

void broadcast()
{
	oneDayVirus(0, vILLPersons);
	printf("\n\n");
}


void init()
{
	scanf("%d%d", &w, &l);
	if ((w > 512) || (l > 512))
	{
		printf("Input ERROR\n");
		return;
	}

	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < l; ++j)
		{
			scanf("%d", &vrs[i][j]);
		}
	}

	system("cls");

	initMap();
	getch();
}

int main()
{
	system("chcp 437>nul.");
	init();
	broadcast();

	gotoxy(0, w + 25);
	textcolor(15); // White

	return 0;
}
