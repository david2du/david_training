#include <bits/stdc++.h>
using namespace std;

// Kosaraju

const int N = 10000 + 10;
int val[N];
int clr[N];
vector<int> e[N], re[N];
bitset<N> vst;
vector<int> seq;

void dfs1(int id)
{
    vst[id] = true;
    for (auto v : e[id])
    {
        if (!vst[v])
            dfs1(v);
    }
    seq.push_back(id);
}

void dfs2(int id, int c)
{
    clr[id] = c;
    for (auto v : re[id])
    {
        if (!clr[v])
            dfs2(v, c);
    }
}

int kosaraju(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if (!vst[i])
            dfs1(i);
    }

    int c = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (!clr[seq[i]])
            dfs2(seq[i], ++c);
    }

    return c;
}

set<int> eCon[N]; // concentrated
int valCon[N];    // concentrated
int deg[N];
int ans[N];

inline int topo(int n, int c)
{
    for (int i = 1; i <= n; ++i)
    {
        cout << i << " " << clr[i] << val[i] << endl;
        valCon[clr[i]] += val[i];
        for (auto v : e[i])
        {
            if (clr[i] != clr[v])
            {
                if (eCon[clr[i]].find(clr[v]) == eCon[clr[i]].end())
                    deg[clr[v]]++;
                eCon[clr[i]].insert(clr[v]);
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= c; ++i)
    {
        if (!deg[i])
        {
            ans[i] = valCon[i];
            q.push(i);
        }
    }

    int mx = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        mx = max(mx, ans[now]);

        for (auto v : eCon[now])
        {
            ans[v] = max(ans[v], valCon[v] + ans[now]);
            deg[v]--;
            if (!deg[v])
                q.push(v);
        }
    }

    return mx;
}

int main()
{
    int n = 0, m = 0;

    freopen("P3387_2.in", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> val[i];
    for (int i = 0; i < m; ++i)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        e[u].push_back(v);
        re[v].push_back(u);
    }
    cout << topo(n, kosaraju(n)) << endl;

    return 0;
}