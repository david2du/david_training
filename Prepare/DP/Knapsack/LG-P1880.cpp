#include <iostream>

using namespace std;

const int N = (100 + 10) * 2;

int a[N];
int pre[N];

int f[N][N];
int g[N][N];

int main()
{
	int n = 0;
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2 * n; i++)
		pre[i] = pre[i - 1] + a[i];
	const int INF = 1000000000;
//	for (int i = 1; i <= n; i++)
//		f[1][i] = a[i];
	for (int i = 2; i <= n; i++)
	{
		for (int l = 1; l + i - 1 <= 2 * n; l++)
		{
			int r = l + i - 1;
			f[i][l] = INF;
			for (int m = 1; m < i; m++)
			{
				f[i][l] = min(f[i][l], f[m][l] + f[i - m][l + m]);
//				cout << f[m][l] + f[i - m][l + m] << "$";
			}
//			cout << f[i][l] << "#";
			f[i][l] += (pre[r] - pre[l - 1]);
//			cout << f[i][l] << " ";
		}
//		cout << endl;
	}
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, f[n][i]);
	}
	cout << ans << endl;
	
	for (int i = 2; i <= n; i++)
	{
		for (int l = 1; l + i - 1 <= 2 * n; l++)
		{
			int r = l + i - 1;
			for (int m = 1; m < i; m++)
			{
				g[i][l] = max(g[i][l], g[m][l] + g[i - m][l + m]);
//				cout << g[m][l] + g[i - m][l + m] << "$";
			}
//			cout << g[i][l] << "#";
			g[i][l] += (pre[r] - pre[l - 1]);
//			cout << g[i][l] << " ";
		}
//		cout << endl;
	}
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, g[n][i]);
	}
	cout << ans << endl;
	
	return 0;
}
