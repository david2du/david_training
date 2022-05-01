#include <bits/stdc++.h>
using namespace std;

const int N = 50010;

bitset<N> bs[N];
// set<int> prb[N];

bitset<N> ta, tb;

bool cheat1(int a, int b)
{
    ta.reset();
    tb.reset();

    ta |= bs[a];
    tb |= bs[b];

    ta &= tb;

    if (ta.none() || ta == bs[a] || ta == bs[b])
    {
        return false;
    }
    return true;
}

const int M = 500010;
set<int> prb[M];

bool cheat2(int a, int b)
{
    if (prb[a].size() > prb[b].size())
    {
        swap(a, b);
    }

    int com = 0;
    for (auto it = prb[a].begin(); it != prb[a].end(); it++)
    {
        com += (prb[b].find(*it) != prb[b].end());
    }

    if (com == 0)
    {
        return false;
    }
    if (com == prb[a].size())
    {
        return false;
    }
    return true;
}

void solve()
{
    int n = 0;

    cin >> n;
    // int maxn = 0;

    if (n <= 1000)
    {
        for (int i = 1; i <= n; i++)
        {
            int a = 0;

            cin >> a;

            for (int j = 0; j < a; j++)
            {
                int t = 0;

                cin >> t;
                prb[i].insert(t);
                bs[i][t] = true;

                // maxn = max(maxn, t);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (cheat1(i, j))
                {
                    cout << "YES" << endl
                         << i << " " << j << endl;
                    return;
                }
            }
            bs[i].reset();
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            int a = 0;

            cin >> a;
            for (int j = 0; j < a; j++)
            {
                int t = 0;

                cin >> t;
                prb[i].insert(t);

                // maxn = max(maxn, t);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (cheat2(i, j))
                {
                    cout << "YES" << endl
                         << i << " " << j << endl;
                    return;
                }
            }
            prb[i].clear();
        }
    }

    cout << "NO" << endl;
}

int main(int argc, char const *argv[])
{
    freopen("discuss.in", "r", stdin);
    freopen("discuss.out", "w", stdout);

    int t = 0;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
