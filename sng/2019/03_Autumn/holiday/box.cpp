#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hout, pos);
}

void pBox(int w, int l, int x, int y)
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
int main()
{
	int w = 0, l = 0;

	system("chcp 437>nul.");

	cin >> w >> l;

	pBox(w, l, 5, 5);

	return 0;
}