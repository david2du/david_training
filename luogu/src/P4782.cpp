#include <bits/stdc++.h>
using namespace std;

const int N = 2000010;

vector<int> e[N];

int dfn[N], low[N];
int cnt;
int scc[N];
int sccN;

int stat[N]; // scc status
vector<int> mem[N];
bool inS[N];

stack<int> stk;

void dfs(int id)
{
    stk.push(id);
    dfn[id] = low[id] = (++cnt);
    inS[id] = true;

    for (auto v : e[id])
    {
        if (!dfn[v])
        {
            dfs(v);
            low[id] = min(low[id], low[v]);
        }
        else if (inS[v])
        {
            low[id] = min(low[id], dfn[v]);
        }
    }

    if (low[id] == dfn[id])
    {
        sccN++;
        while (stk.top() != id)
        {
            scc[stk.top()] = sccN;
            mem[sccN].push_back(stk.top());
            inS[stk.top()] = false;
            stk.pop();
            
        }
        scc[stk.top()] = sccN;
        mem[sccN].push_back(stk.top());
        inS[stk.top()] = false;
        stk.pop();
    }
}

int main()
{
    int n = 0, m = 0;

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u = 0, a = 0, v = 0, b = 0;
        cin >> u >> a >> v >> b;
        e[u + (a ^ 1) * n].push_back(v + b * n);
        e[v + (b ^ 1) * n].push_back(u + a * n);
    }
    for (int i = 1; i <= (2 * n); ++i)
    {
        if (!dfn[i])
            dfs(i);
    }
    bool flag = false;
    for (int i = 1; i <= n; ++i)
    {
        if (scc[i] == scc[n + i])
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << "POSSIBLE" << endl;
        for (int i = 1; i <= n; ++i)
        {
            if (scc[i] < scc[i + n])
            {
                cout << "0 ";
            }
            else
                cout << "1 ";
        }
        // for (int i = 1; i <= sccN; ++i)
        // {
        //     if (!stat[i])
        //         stat[i] = 2;
        //     int nxt = (stat[i] == 2 ? 1 : 2);
        //     for (auto v : mem[i])
        //     {
        //         stat[scc[getpr(v)]] = nxt;
        //     }
        // }
        // for (int i = 1; i <= n; ++i)
        // {
        //     if (stat[i] == 2)
        //         cout << "0 ";
        //     else
        //         cout << "1 ";
        // }
        // cout << endl;
    }

    return 0;
}