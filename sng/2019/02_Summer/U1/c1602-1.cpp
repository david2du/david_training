#include <bits/stdc++.h>
using namespace std;
/*
1 1 1 1 1
1 2 2 2 1
1 2 3 2 1
1 2 2 2 1
1 1 1 1 1
*/
int main()
{
	int sq[199][199] = {0};
	int n = 0, N = 0;
	int r = 0, c = 0, cycle = 0;
	
	for ( ; true; )
	{
		cin >> n;
		if ((n > 1) && (n < 101))
		{
			break;
		}
		else 
		{
			cout << "INPUT ERROR" << endl;
		}
	} 
	system("cls");
	N = n * 2 - 1;
	
	for (cycle = 0; cycle < n; cycle++)
	{
		for (r = 0; r < N; r++)
		{
			for (c = 0; c < N; c++)
			{
				if ((r == cycle) || (c == cycle) ||
				 (N - 1 - cycle == r) || (N - 1 - cycle == c))
				{
					if (sq[r][c] == 0)
					{
						sq[r][c] = cycle + 1;
					}
				}
			}
		}
	}
	
	for (r = 0; r < N; r++)
	{
		for (c = 0; c < N; c++)
		{
			cout << setw(5) << sq[r][c];
		}
		cout << endl;
	}
	
	return 0;
}
