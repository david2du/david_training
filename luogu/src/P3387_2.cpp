#include <bits/stdc++.h>
using namespace std;

// Tarjan

const int N = 10000 + 10;

vector<int> e[N];
int val[N];

int clr[N];
int dfn[N];
int low[N];
stack<int> stk;

int C;
int cnt;

void dfs(int id)
{
    // cout << "vst" << id << endl;
    stk.push(id);
    dfn[id] = ++cnt;
    low[id] = dfn[id];
    for (auto v : e[id])
    {
        // if (id == 4)
        // {
        //     cout <<"v4- " << v << endl;
        // }
        if (!dfn[v])
        {
            dfs(v);
            low[id] = min(low[id], low[v]);
        }
        else if (!clr[v])
            low[id] = min(low[id], dfn[v]);
        else
            ;
    }

    // printf("id%d\t%d\t%d\t%d\n", id, low[id], dfn[id], clr[id]);
    if (low[id] == dfn[id])
    {
        C++;
        // if (id == 1)
        // {
        //     while (!stk.empty())
        //     {
        //         cout << "pop1-" << stk.top() << endl;
        //         stk.pop();
        //     }
        // }
        // while (!stk.empty() && (low[stk.top()] == dfn[id]))
        while(true)
        {
            // cout << "pop" << stk.top() << endl;
            int t = stk.top();
            clr[t] = C;
            stk.pop();
            if (t == id)
                break;
        }
        // cout << ";sd" << endl;
    }
}

int tarjan(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if (!dfn[i])
            dfs(i);
    }
    return C;
}

set<int> eCon[N]; // concentrated
int valCon[N];    // concentrated
int deg[N];
int ans[N];

inline int topo(int n, int c)
{
    for (int i = 1; i <= n; ++i)
    {
        // cout << low[i] << endl;
        // cout << i << " " << clr[i] << val[i] << endl;
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
    }
    cout << topo(n, tarjan(n)) << endl;

    return 0;
}