#include <iostream>
#include <vector>
using namespace std;

vector<int> e[10010];
string va;

inline bool dfs(const string &s, register int nowdep, register int idx, register int fa)
{
    if (nowdep == s.size() - 1)
    {
        return true;
    }

    for (register int i = 0; i < e[idx].size(); i++)
    {
        if ((e[idx][i] != fa) && (va[e[idx][i] - 1] == s[nowdep + 1]))
        {
            if (dfs(s, nowdep + 1, e[idx][i], idx))
            {
                return true;
            }
        }
    }

    return false;
}

inline bool solve(const string &s, register int n)
{
    for (register int i = 1; i <= n; i++)
    {
        if (va[i - 1] == s[0])
        {
            if (s.size() == 1)
            {
                return true;
            }
            if (dfs(s, 0, i, -1))
            {
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    register int t = 0;

    cin >> t;
    for (register int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        register int n = 0;

        cin >> n;
        for (register int i = 0; i < (n - 1); i++)
        {
            register int u = 0, v = 0;

            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        cin >> va;

        string s;

        cin >> s;

        if (solve(s, n))
        {
            cout << "Find" << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }

        for (register int i = 1; i <= n; i++)
        {
            e[i].clear();
        }
        va.clear();
    }

    return 0;
}