#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

struct Node
{
	int x;
	int y;
};

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

void pHorse(const int BOX_X, const int BOX_Y, int x, int y, int print)
{
	gotoxy(BOX_X + 2 * x, BOX_Y + 2 * y);

	cout << " ";
	cout << print;
}

const int DIRN = 8;								   // direction number
const int DX[9] = {0, 2, 1, -1, -2, -2, -1, 1, 2}; // direction
const int DY[9] = {0, -1, -2, -2, -1, 1, 2, 2, 1}; // direction

int dfs(Node start, const int PW, const int PL, const int PX, const int PY) // start-coordinate; point width, length(start from 0); start printing x, y
{
	int num;
	stack<Node> stk;
	bool vst[10][9] = {false};

	stk.push(start);
	vst[start.x][start.y] = true;

	while (!stk.empty())
	{
		Node now = stk.top();
		stk.pop();
		pHorse(PX, PY, now.x, now.y, ++num);
		vst[now.x][now.y] = true;

		for (int i = 0; i < DIRN; ++i)
		{
			int nx = now.x + DX[i], ny = now.y + DY[i]; // next x, y

			if (((nx >= 0) && (nx < PW)) && ((ny >= 0) && (ny < PL)) && (!vst[nx][ny]))
			{
				stk.push((Node){nx, ny});
			}
		}
	}

	return num;
}

int main()
{
	const int W = 9, L = 8;
	int num = 0;

	system("chcp 437>nul.");

	//cin >> w >> l;

	pBox(W, L, 1, 1);
	num = dfs((Node){0, 0}, W + 1, L + 1, 1, 1);

	gotoxy(10, 20);
	cout << "Steps : " << num << "ENDED" << endl;

	getchar();
	return 0;
}
