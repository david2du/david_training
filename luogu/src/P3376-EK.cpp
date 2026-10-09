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

const ll N = 200 + 10;
vector<Edge> edge;
vector<ll> e[N];

ll orig[N];
ll flow[N];

ll EK(ll s, ll t, ll n)
{
    ll mxflow = 0;
    while (true)
    {
        fill(flow, flow + n + 1, 0);
        fill(orig, orig + n + 1, 0);
        queue<ll> q;
        q.push(s);
        flow[s] = INT_MAX;

        while (!q.empty())
        {
            ll now = q.front();
            q.pop();
            for (auto v : e[now])
            {
                auto &ed = edge[v];
                if (!flow[ed.v] && ed.w < ed.cap)
                {
                    orig[ed.v] = v;
                    flow[ed.v] = min(flow[now], ed.cap - ed.w);
                    q.push(ed.v);
                    if (ed.v == t)
                        break;
                }
            }
            if (flow[t])
                break;
        }
        if (!flow[t])
            break;
        for (ll i = t; i != s; i = edge[orig[i]].u)
        {
            edge[orig[i]].w += flow[t];
            edge[orig[i] ^ 1].w -= flow[t];
        }
        mxflow += flow[t];
    }

    return mxflow;
}

inline void addE(ll u, ll v, ll w)
{
    e[u].push_back(edge.size());
    edge.push_back({u, v, w});
}

int main()
{
    ll n = 0, m = 0, s = 0, t = 0;

    cin >> n >> m >> s >> t;
    for (ll i = 0; i < m; ++i)
    {
        ll u = 0, v = 0, w = 0;
        cin >> u >> v >> w;
        addE(u, v, w);
        addE(v, u, 0);
    }
    cout << EK(s, t, n) << endl;

    return 0;
}