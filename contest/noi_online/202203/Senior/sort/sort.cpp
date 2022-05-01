#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 200010;

ll f[6][N];

ll m, n;

ll fun(ll i, ll j)
{
    ll maxn = 0, minn = LLONG_MAX;
    
    for (ll k = 1; k <= m; k++)
    {
        maxn = max(maxn, f[k][i] + f[k][j]);
        maxn = min(minn, f[k][i] + f[k][j]);
    }

    return maxn + minn;
}

int main(int argc, char const *argv[])
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    cin >> m >> n;
    for (ll i = 1; i <= m; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> f[i][j];
        }
    }

    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            sum += fun(i, j);
        }
    }

    cout << sum << endl;

    return 0;
}
