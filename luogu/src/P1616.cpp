#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 10000 + 10, T = 10000000 + 10;
ll c[M], v[M];
ll f[T];

int main()
{
    ll t = 0, m = 0;

    cin >> t >> m;
    for (ll i = 0; i < m; ++i)
    {
        cin >> c[i] >> v[i];
    }
    for (ll i = 0; i < m; ++i)
    {
        for (ll j = c[i]; j <= t; ++j)
            f[j] = max(f[j], f[j - c[i]] + v[i]);
    }
    cout << f[t] << endl;

    return 0;
}