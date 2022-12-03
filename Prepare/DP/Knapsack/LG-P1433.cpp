#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

const int N = 15 + 10;
double x[N], y[N];
double f[N][1 << 20];
double dst[N][N];

int main()
{
	int n = 0;
	
	cin >> n;
	for (int i = 2; i <= n + 1; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = 1; j <= n + 1; j++)
			dst[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
	}
	for (int i = (1 << 1); i < (1 << (n + 2)); i++)
	{
		int a = i;
		int pos = a & (-a) - 1;
		
		while (pos)
		{
			f[i][pos] = 1e9;
			printf("Hello World! %d %d\n", i, pos);
			a ^= (1 << pos);
			pos = a & (-a) - 1;
		}
	}
	for (int i = 1; i <= (n + 1); i++)
		f[i][1 << i + 1] = dst[0][i];
	for (int i = 3; i < (1 << (n + 2)); i++)
	{
		int a = i;
		int pos = a & (-a) - 1;
		
		while (pos)
		{
			int b = i ^ pos;
			int id = b & (-b) - 1;
			while (id)
			{
				f[pos][id] = min(f[pos][id], f[id][i ^ pos] + dst[id][pos]);
				b ^= (1 << id)id;
				id = b & (-b) - 1;
			}
			a ^= pos;
			pos = a & (-a) - 1;
		}
	}
	
	double ans = 1e9;
	for (int i = 2; i <= n + 1; i++)
		ans = min(ans, f[i][(1 << (n + 2)) - 1]);
	cout << fixed << setprecision(2) << ans << endl;
	
	return 0;
}
