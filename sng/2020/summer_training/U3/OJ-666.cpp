#include <bits/stdc++.h>
using namespace std;

int opr(int n, int m)
{
	int f[16][16] = {0};

	for (int i = 1; i <= n; i++)
	{
		f[i][1] = 1;
	}
	for (int j = 2; j <= m; j++)
	{
		for (int i = j; i <= n; i++)
		{
			f[i][j] = f[i - 1][j - 1] + f[i - j][j];
		}
	}

	int ans = 0;
	for (int j = 1; j < n; j++)
	{
		ans += f[n][j];
	}

	return ans;
}

int main()
{
	int n = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;

		cout << opr(a, b) << endl;
	}

	return 0;
}
