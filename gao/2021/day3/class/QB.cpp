#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> edge[10010];

int dfn[10010];
int low[10010];
stack<int> sta;
int idx;
bool instack[10010];
int scc_cnt;
vector<int> scc[10010];

void tarjan(int u)
{
    dfn[u] = low[u] = ++idx;
    instack[u] = true;
    sta.push(u);

    for (int i = 0; i < edge[u].size(); i++) // dfs
    {
        int v = edge[u][i];
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (instack[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u])
    {
        ++scc_cnt;
        int v = 0;
        do
        {
            v = sta.top();
            sta.pop();
            instack[v] = false;
            scc[scc_cnt].push_back(v);
        } while (v != u);
    }
}

void solve(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 0, m = 0;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0;
        cin >> a >> b;

        edge[a].push_back(b);
    }

    solve(n);

    return 0;
}