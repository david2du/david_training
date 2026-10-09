#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge
{
    ll u;
    ll v;
    ll cap;
    ll w;
};

const ll INF = (1LL << 40);

const ll N = 200 + 10;
vector<Edge> edge;
vector<ll> e[N];

ll dep[2 * N];
ll t;

bool bfs(ll s)
{
    queue<ll> q;
    q.push(s);
    dep[s] = 1;

    while (!q.empty())
    {
        ll now = q.front();
        q.pop();
        for (auto v : e[now])
        {
            auto &ed = edge[v];
            if (!dep[ed.v] && ed.cap > ed.w)
            {
                dep[ed.v] = dep[now] + 1;
                q.push(ed.v);
                if (ed.v == t)
                    return true;
            }
        }
    }

    return false;
}

ll fst[2 * N]; // arc optim
bool full[2 * N];

ll dfs(ll id, ll flow)
{
    if (full[id])
        return 0;
    if (id == t || !flow)
        return flow;
    ll curF = 0;
    bool flag = true;
    for (ll i = fst[id]; i < e[id].size(); ++i)
    {
        fst[id] = i;
        auto &ed = edge[e[id][i]];
        if (!full[ed.v] && dep[ed.v] == dep[id] + 1)
        {
            ll nxtF = dfs(ed.v, min(flow - curF, ed.cap - ed.w));
            curF += nxtF;
            ed.w += nxtF;
            edge[e[id][i] ^ 1].w -= nxtF;
            if (curF == flow)
                return flow;
        }
    }
    if (curF < flow)
        full[id] = true;

    return curF;
}

ll Dinic(ll s, ll n)
{
    ll mxflow = 0;
    while (bfs(s))
    {
        mxflow += dfs(s, INF);

        fill(dep, dep + 2 * n + 2, 0);
        fill(fst, fst + 2 * n + 2, 0);
        fill(full, full + 2 * n + 2, false);
    }

    return mxflow;
}

inline void addE(ll u, ll v, ll w)
{
    e[u].push_back(edge.size());
    edge.push_back({u, v, w, 0});
}

int main()
{
    ll n = 0, m = 0, s = 0;

    cin >> n >> m >> s >> t;
    for (ll i = 0; i < m; ++i)
    {
        ll u = 0, v = 0, w = 0;
        cin >> u >> v >> w;
        addE(u, v, w);
        addE(v, u, 0);
    }
    cout << Dinic(s, n) << endl;

    return 0;
}