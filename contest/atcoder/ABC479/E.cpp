#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 200000 + 10;

struct E
{
    ll id;
    ll to;
};
vector<E> e[N];
ll val[N];
ll sz[N];

ll n;

void dfs(ll now, ll fa)
{
    sz[now] = 1;
    for (auto v : e[now])
    {
        if (v.to != fa)
        {
            dfs(v.to, now);
            sz[now] += sz[v.to];
            val[v.to] = v.id;
        }
    }
}

void dfs2(ll now, ll fa)
{
    for (auto v : e[now])
    {
        if (v.to != fa)
        {
            val[v.to] += val[now];
            dfs2(v.to, now);
        }
    }
}

int main()
{
    cin >> n;
    for (ll i = 1; i < n; ++i)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        e[u].push_back((E){i, v});
        e[v].push_back((E){i, u});
    }
    dfs(1, 0);

    for (int i = 2; i <= n; ++i)
    {
        if (sz[i] <= n / 2)
        {
            val[1] += val[i];
            val[i] = -val[i];
        }
    }

    dfs2(1, 0);
    for (int i = 1; i <= n; ++i)
        cout << val[i] << " ";
    cout << endl;

    return 0;
}