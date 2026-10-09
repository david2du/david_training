#include <bits/stdc++.h>
using namespace std;

const int N = 500000 + 10;
vector<int> e[N];

int cnt;
int dfn[N], low[N];
stack<int> stk;

vector<pair<int, int>> ebc; // edge biconneced component (head, size)
int nxt[N];

inline void pop(int id)
{
    // cout << "pp" << id << endl;
    ebc.push_back(make_pair(stk.top(), 1));
    auto &E = ebc[ebc.size() - 1];
    while (stk.top() != id)
    {
        int now = stk.top();
        stk.pop();
        nxt[now] = stk.top();
        E.second++;
    }
}

void dfs(int id, int fa)
{
    low[id] = dfn[id] = (++cnt);
    stk.push(id);

    int chd = 0;

    for (auto v : e[id])
    {
        if (!dfn[v])
        {
            chd++;
            dfs(v, id);
            low[id] = min(low[id], low[v]);
        }
        else if (v != fa)
            low[id] = min(low[id], dfn[v]);
    }

    if (low[id] == dfn[id])
        pop(id);
}

/**
 * 法一：节点入栈
 */
void tarjan(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if (!dfn[i])
            dfs(i, -1);
    }
    cout << ebc.size() << endl;
    for (auto now : ebc)
    {
        cout << now.second << " ";
        int id = now.first;
        while (id != 0)
        {
            cout << id << " ";
            id = nxt[id];
        }
        cout << endl;
    }
}

int main()
{
    int n = 0, m = 0;

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    tarjan(n);

    return 0;
}