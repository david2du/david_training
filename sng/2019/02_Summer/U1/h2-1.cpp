#include <bits/stdc++.h>
using namespace std;
/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1 
*/
int main()
{
	int tr[100][100] = {0};
	int r = 0, c = 0;
	int n = 0;
	
	do
	{
		cin >> n;
		if ((n > 0) || (n > 101))
		{
			break;
		}
		else 
		{
			cout << "INPUT ERROR" << endl;
		}
	}
	while(true);
	
	for (r = 0; r < n; r++)
	{
		tr[r][0] = 1;
	}
	
	for (r = 1; r < n; r++)
	{
		for (c = 1; c < r + 1; c++)
		{
			tr[r][c] = tr[r - 1][c - 1] + tr[r - 1][c];
		}
	}
	
	for (r = 0; r < n; r++)
	{
		for (c = 0; c < r + 1; c++)
		{
			cout << setw(10) << tr[r][c];
		}
		cout << endl;
	}
	
	return 0;
}
