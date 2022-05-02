#include <bits/stdc++.h>
using namespace std;

int num[10000] = {0};

int main()
{
	int m = 0, n = 0, x = 0;
	
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m * n; i++)
	{
		scanf("%d", &num[i]);
	}
	scanf("%d", &x);
	
	int lb = lower_bound(num, num + (m * n), x) - num;
	int ub = upper_bound(num, num + (m * n), x) - num;

	if (lb == ub)
	{
		printf("nothing\n");
		
		return 0;
	}
	
	for (int i = lb; i < ub; i++)
	{
		int row = i / n, col = i % n;
		
		printf("row=%d col=%d\n", row + 1, col + 1);
	}
	
	return 0;
}
