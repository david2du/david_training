#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
vector<int> e[N];
vector<int> ct[N];

typedef long long ll;

ll n;
int cnt;
int dfn[N], low[N];

ll sz[N];
ll ans[N];

void dfs(int id)
{
    ll as = 0; // answer
    ll cs = 1; // cut size
    int chd = 0;
    bool flag = false;
    sz[id] = 1;

    low[id] = dfn[id] = ++cnt;
    for (auto v : e[id])
    {
        if (!dfn[v])
        {
            chd++;
            dfs(v);
            sz[id] += sz[v];
            low[id] = min(low[id], low[v]);
            if (low[v] >= dfn[id])
            {
                as += (sz[v] * cs);
                cs += sz[v];
            }

        }
        else
            low[id] = min(low[id], dfn[v]);
    }
    ans[id] = as + (ll)(n - cs) * cs;
}

int main()
{
    int m = 0;

    // freopen("P3469_4.in", "r", stdin);
    // freopen("P3469_4.ans", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1);
    for (int i = 1; i <= n; ++i)
        cout << ans[i] * 2 << endl;

    return 0;
}