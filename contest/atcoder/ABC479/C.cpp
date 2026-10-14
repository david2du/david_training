#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 30;

ll a[N], b[N];
ll f[N];

ll n, w;
ll mx;

void dfs(ll v, ll id, ll val)
{
    if (id == n)
    {
        mx = max(mx, val);
        return;
    }
    if (v + b[id] <= w)
        dfs(v + b[id], id + 1, val + a[id]);
    dfs(v, id + 1, val);
}

int main()
{
    cin >> n >> w;
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
    }

    dfs(0, 0, 0);
    cout << mx << endl;

    return 0;
}