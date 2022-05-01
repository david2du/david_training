#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

const ll N = 5010;

vector<ll> e[N];  // Graph
vector<ll> re[N]; // reversed Graph

deque<ll> seq;
bitset<N> vst1;

inline void dfs1(ll u)
{
    vst1[u] = true;
    for (auto x : e[u])
    {
        if (!vst1[x])
        {
            dfs1(x);
        }
    }

    seq.push_front(u);
}

set<ll> scc[N];
bitset<N> vst2;

ll cnt;

inline void dfs2(ll u)
{
    scc[cnt].insert(u);
    vst2[u] = true;

    for (auto x : re[u])
    {
        if (!vst2[x])
        {
            dfs2(x);
        }
    }
}

ll SLS_id; // Supreme Large SCC ID

void kosaraju()
{
    for (ll i = 1; i <= n; i++)
    {
        if (!vst1[i])
        {
            dfs1(i);
        }
    }

    for (auto x : seq)
    {
        if (!vst2[x])
        {
            dfs2(x);
            cnt++;
        }
    }

    SLS_id = 0;
    auto maxn = scc[0].size();
    for (ll i = 1; i < cnt; i++)
    {
        if (maxn < scc[i].size())
        {
            maxn = scc[i].size();
            SLS_id = i;
        }
    }
}

void input()
{
    cin >> n >> m;

    for (ll i = 0; i < m; i++)
    {
        ll a = 0, b = 0, t = 0;

        cin >> a >> b >> t;

        if (t == 1)
        {
            e[a].push_back(b);
            re[b].push_back(a);
        }
        else
        {
            e[a].push_back(b);
            e[b].push_back(a);

            re[a].push_back(b);
            re[b].push_back(a);
        }
    }
}

void output()
{
    cout << scc[SLS_id].size() << endl;
    for (auto x : scc[SLS_id])
    {
        cout << x << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    input();
    kosaraju();
    output();

    return 0;
}