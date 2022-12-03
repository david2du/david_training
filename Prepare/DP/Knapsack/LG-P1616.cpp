#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 10000;
ll t[M], val[M];
const int T = 10000000 + 10;
ll f[T];

int main()
{
	ll n = 0, m = 0;
	
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> t[i] >> val[i];
	}
	for (ll i = 1; i <= m; ++i)
	{
		for (ll j = t[i]; j <= n; ++j)
			f[j] = max(f[j], f[j - t[i]] + val[i]);
	}
	cout << f[n] << endl;
	
	return 0;
}
