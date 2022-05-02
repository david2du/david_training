#include <bits/stdc++.h>
using namespace std;

/*
3 6
1 3 4 6 5 2
7 3 2 5 6 4
7 9 6 3 10 0
*/

struct Coor // Coordinate
{
	int row;
	int column;
	
	bool operator<(const Coor &A) const
	{
		return row < A.row;
	}
	
	bool operator==(const Coor &A) const
	{
		return ((row == A.row) && (column == A.column));
	}
};

int num[128][128];
int n, m;
set<Coor> ans;

int Min_Ele(const int &row)
{
	int col = 0;
	int minn = INT_MAX;
	
	for (int i = 0; i < m; i++)
	{
		if (num[row][i] < minn)
		{
			minn = num[row][i];
			col = i;
		}
	}
	
	return col;
}

void fun(const Coor &LT, const Coor &RB) // Left-Top, Right-Bottom
{
	if (RB < LT)
	{
		return;
	}
	
	//printf("\n\nLT:%d, %d\n", LT.row, LT.column);
	//printf("RB:%d, %d\n", RB.row, RB.column);
	
	int midLine = LT.row + ((RB.row - LT.row) / 2);
	//printf("midLine: %d\n", midLine);
	
	//Coor minEle = (Coor){midLine, (min_element(num + (midLine * m), num + (midLine * m) + m) - (num + (midLine * m)))};
	Coor minEle = (Coor){midLine, Min_Ele(midLine)};
		
	ans.insert(minEle);
	//printf("\nPush:%d, %d\n\n", minEle.row, minEle.column);
	
	//printf("\n(%d, %d), (%d, %d)\n", LT.row, LT.row, minEle.row - 1, minEle.column - 1);
	//printf("(%d, %d), (%d, %d)\n\n\n", minEle.row + 1, minEle.column + 1, RB.row, RB.column);
	
	fun(LT, (Coor){minEle.row - 1, minEle.column - 1});
	fun((Coor){minEle.row + 1, minEle.column + 1}, RB);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> num[i][j];
		}
	}
	
	fun((Coor){0, 0}, (Coor){n - 1, m - 1});
	
	set<Coor>::iterator it;
	for (it = ans.begin(); it != ans.end(); it++)
	{
		cout << it -> row << ", " << it -> column << endl;
		cout << num[it -> row][it -> column] << endl << endl;
	}
	
	return 0;
}
