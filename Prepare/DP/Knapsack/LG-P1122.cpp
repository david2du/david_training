#include <bits/stdc++.h>

using namespace std;

const int N = 16000 + 10;
int bty[N];

int e[N * 2];
int hd[N];
int nxt[N * 2];

int nE;

int f[N];

inline void dfs(int now, int fa = 0)
{
	f[now] = bty[now];
	for (int i = hd[now]; i; i = nxt[i])
	{
		if (e[i] != fa)	
		{
			dfs(e[i], now);
			f[now] += max(0, f[e[i]]);
		}
	}
}

inline void addEdge(int a, int b)
{
	nE++;
	e[nE] = b;
	nxt[nE] = hd[a];
	hd[a] = nE;
}

int main()
{
	int n = 0;
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> bty[i];
	for (int i = 0; i < (n - 1); ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		addEdge(a, b);
		addEdge(b, a);
	}
	
	dfs(1);
	
	cout << *max_element(f + 1, f + n + 1) << endl;
	
	return 0;
}
