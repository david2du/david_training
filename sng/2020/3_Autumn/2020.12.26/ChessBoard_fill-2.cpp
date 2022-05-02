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

int now;

void fun(int ltx, int rbx, int lty, int rby, int x, int y) //top, bottom, left, right, empty_X, empty_Y
{
	now++;
	const int N = now;
	
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
		fun(ltx, midx, lty, midy, x, y);
		fun(ltx, midx, midy + 1, rby, midx, midy + 1);
		fun(midx + 1, rbx, lty, midy, midx + 1, midy);
		fun(midx + 1, rbx, midy + 1, rby, midx + 1, midy + 1);
		
		cb[midx][midy + 1] = N;
		cb[midx + 1][midy] = N;
		cb[midx + 1][midy + 1] = N;
	}
	else if ((x <= midx) && (y > midy))
	{
		fun(ltx, midx, lty, midy, midx - 1, midy + 1);
		fun(ltx, midx, midy + 1, rby, x, y);
		fun(midx + 1, rbx, lty, midy, midx + 1, midy);
		fun(midx + 1, rbx, midy + 1, rby, midx + 1, midy + 1);
		
		cb[midx - 1][midy + 1] = N;
		cb[midx + 1][midy] = N;
		cb[midx + 1][midy + 1] = N;
	}
	else if ((x > midx) && (y <= midy))
	{
		fun(ltx, midx, lty, midy, midx - 1, midy + 1);
		fun(ltx, midx, midy + 1, rby, midx, midy + 1);
		fun(midx + 1, rbx, lty, midy, x, y);
		fun(midx + 1, rbx, midy + 1, rby, midx + 1, midy + 1);
		
		cb[midx - 1][midy + 1] = N;
		cb[midx + 1][midy] = N;
		cb[midx + 1][midy + 1] = N;
	}
	else if ((x > midx) && (y > midy))
	{
		fun(ltx, midx, lty, midy, midx - 1, midy + 1);
		fun(ltx, midx, midy + 1, rby, midx, midy + 1);
		fun(midx + 1, rbx, lty, midy, midx + 1, midy);
		fun(midx + 1, rbx, midy + 1, rby, x, y);
		
		cb[midx - 1][midy + 1] = N;
		cb[midx][midy + 1] = N;
		cb[midx + 1][midy] = N;
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
	
	fun(0, Len - 1, 0, Len - 1, x, y);
	
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
