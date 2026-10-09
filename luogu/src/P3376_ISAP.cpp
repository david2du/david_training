#include <bits/stdc++.h> // unknown error.
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
ll num[2 * N];
ll t;

void bfs()
{
    queue<ll> q;
    q.push(t);
    dep[t] = 1;

    while (!q.empty())
    {
        ll now = q.front();
        num[dep[now]]++;
        q.pop();
        for (auto v : e[now])
        {
            auto &ed = edge[v];
            if (!dep[ed.v] && edge[v ^ 1].cap)
            {
                dep[ed.v] = dep[now] + 1;
                q.push(ed.v);
            }
        }
    }
}

ll fst[2 * N];
bool fini;

ll dfs(ll id, ll flow)
{
    if (id == t || !flow)
        return flow;

    ll sum = 0;
    for (ll i = fst[id]; i < e[id].size(); ++i)
    {
        fst[id] = i;
        auto &ed = edge[e[id][i]];
        if ((dep[ed.v] == dep[id] - 1) && (ed.cap > ed.w))
        {
            ll nF = dfs(ed.v, min(ed.cap - ed.w, flow - sum));
            ed.w += nF;
            edge[e[id][i] ^ 1].w -= nF;
            sum += nF;
            if (sum == flow)
                return flow;
            if (fini)
                return sum;
        }
    }
    if (sum < flow) // full
    {
        num[dep[id]]--;
        if (!num[dep[id]])
            fini = true;
        dep[id]++;
        num[dep[id]]++;
    }

    return sum;
}

ll ISAP(ll s, ll n)
{
    bfs();
    ll mxflow = 0;
    while (true)
    {
        ll nowF = dfs(s, INF);
        mxflow += nowF;
        if ((!nowF) || fini)
            break;
        fill(fst, fst + 2 * n + 2, 0);
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
    cout << ISAP(s, n) << endl;

    return 0;
}