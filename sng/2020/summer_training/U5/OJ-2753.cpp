//#include <bits/stdc++.h>
#include <queue>
#include <iostream>
using namespace std;

/**
 * Coordinate
*/
struct Coor
{		   
	int r; // row
	int c; // column
	int step; // step
};

const int MAX = 64;
bool vst[MAX][MAX];
bool rd[MAX][MAX]; // road. True: Road; False: Wall

int r, c;

const int DR[4] = {-1, 1, 0, 0}, DC[4] = {0, 0, -1, 1};

int bfs(int br, int bc) // begin row, begin column
{
	const int BR = br, BC = bc;			  // begin row, begin column
	const int ER = (r - 1), EC = (c - 1); // end row, end column

	queue<Coor> q;

	q.push((Coor){BR, BC, 1});
	vst[BR][BC] = true;

	while (!(q.empty()))
	{
		Coor now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nr = now.r + DR[i], nc = now.c + DC[i];

			if ((nr >= 0) && (nr < r) && (nc >= 0) && (nc < c) && (!vst[nr][nc]) && (rd[nr][nc]))
			{
				vst[nr][nc] = true;

				q.push((Coor){nr, nc, now.step + 1});
			}
			if ((nr == ER) && (nc == EC) && (rd[nr][nc]))
			{
				return now.step + 1;
			}
		}
	}

	return -1;
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char c;
			cin >> c;

			rd[i][j] = (c == '.');
		}
	}

	cout << bfs(0, 0) << endl;

	return 0;
}
