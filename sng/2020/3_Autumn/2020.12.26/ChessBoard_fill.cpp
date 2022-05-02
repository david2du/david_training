#include <bits/stdc++.h>
using namespace std;

int cb[1024][1024];

/*
 _ _   _ _ 
|_|_| |_|_|
|_|_| |X|_|
 _ _   _ _
|_|_| |_|_|
|_|_| |_|_|
*/

void fun(int ltx, int rbx, int lty, int rby, int x, int y, int now) //top, bottom, left, right, empty_X, empty_Y
{
	if ((rbx - ltx + 1) <= 2)
	{
		cb[ltx][lty] = now;
		cb[ltx][lty + 1] = now;
		cb[ltx + 1][lty] = now;
		cb[ltx + 1][lty + 1] = now;
		
		cb[x][y] = 0;
		
		return;
	}
	
	const int midx = (rbx - ltx) / 2 + ltx;
	const int midy = (rby - lty) / 2 + lty;
	
	if ((x <= midx) && (y <= midy))
	{
		fun(ltx, midx, lty, midy, x, y, now + 1);
		fun(ltx, midx, midy + 1, rby, midx, midy + 1, now + 2);
		fun(midx + 1, rbx, lty, midy, midx + 1, midy, now + 3);
		fun(midx + 1, rbx, midy + 1, rby, midx + 1, midy + 1, now + 4);
		
		cb[midx][midy + 1] = now;
		cb[midx + 1][midy] = now;
		cb[midx + 1][midy + 1] = now;
	}
	else if ((x <= midx) && (y > midy))
	{
		fun(ltx, midx, lty, midy, midx - 1, midy + 1, now + 1);
		fun(ltx, midx, midy + 1, rby, x, y, now + 2);
		fun(midx + 1, rbx, lty, midy, midx + 1, midy, now + 3);
		fun(midx + 1, rbx, midy + 1, rby, midx + 1, midy + 1, now + 4);
		
		cb[midx - 1][midy + 1] = now;
		cb[midx + 1][midy] = now;
		cb[midx + 1][midy + 1] = now;
	}
	else if ((x > midx) && (y <= midy))
	{
		fun(ltx, midx, lty, midy, midx - 1, midy + 1, now + 1);
		fun(ltx, midx, midy + 1, rby, midx, midy + 1, now + 2);
		fun(midx + 1, rbx, lty, midy, x, y, now + 3);
		fun(midx + 1, rbx, midy + 1, rby, midx + 1, midy + 1, now + 4);
		
		cb[midx - 1][midy + 1] = now;
		cb[midx + 1][midy] = now;
		cb[midx + 1][midy + 1] = now;
	}
	else if ((x > midx) && (y > midy))
	{
		fun(ltx, midx, lty, midy, midx - 1, midy + 1, now + 1);
		fun(ltx, midx, midy + 1, rby, midx, midy + 1, now + 2);
		fun(midx + 1, rbx, lty, midy, midx + 1, midy, now + 3);
		fun(midx + 1, rbx, midy + 1, rby, x, y, now + 4);
		
		cb[midx - 1][midy + 1] = now;
		cb[midx][midy + 1] = now;
		cb[midx + 1][midy] = now;
	}
	else
	{
		cerr << "midx: " << midx << ", midy: " << midy << endl << "Error." << endl;
		exit(0);
	}
}

int main()
{
	int n = 0;
	int x = 0, y = 0;
	
	ifstream fin("input.in");
	ofstream fout("Answer_Chess_Board.csv");
	
	fin >> n >> x >> y;
	
	const int Len = pow(2, n);
	
	fun(0, Len - 1, 0, Len - 1, x, y, 1);
	
	for (int i = 0; i < Len; i++)
	{
		for (int j = 0; j < Len; j++)
		{			
			if (j == 0)
			{
				fout << cb[i][j];
			}
			else
			{
				fout << "," << cb[i][j];
			}
		}
		fout << endl;
	}
	
	return 0;
}
