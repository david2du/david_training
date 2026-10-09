#include <bits/stdc++.h>
using namespace std;

const int N = 20000 + 10;
vector<int> e[N];

int cnt;
int dfn[N], low[N];
vector<int> cut;
int rt;

void tarjan(int id, int fa)
{
    dfn[id] = (++cnt);
    low[id] = dfn[id];

    bool flag = false;
    int chd = 0;

    for (auto v : e[id])
    {
        if (!dfn[v])
        {
            chd++;
            tarjan(v, id);
            low[id] = min(low[id], low[v]);
            if (low[v] >= dfn[id] && id != rt) // 割点要特判根，割边不用
                flag = true;
        }
        else if (v != fa) // 割点可以直接用else,但是仅仅对于割点这一特殊问题正确，因为对于[TR]-id-v-[tr]的情况（TR tr不连通），id显然为一个割点
            low[id] = min(low[id], dfn[v]);
    }
    // cout << id << " " << dfn[id] << " " << low[id] << endl;
    if (id == rt && chd > 1)
        flag = true;

    if (flag)
        cut.push_back(id);
}

int main()
{
    int n = 0, m = 0;

    // freopen("P3388_1.in", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!dfn[i])
        {
            rt = i;
            tarjan(i, -1);
        }
    }
    sort(cut.begin(), cut.end());
    cout << cut.size() << endl;
    for (auto id : cut)
        cout << id << " ";

    return 0;
}