#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

vector<ll> e[100010];
bitset<100010> vst;

inline bool dfs(ll now)
{
    if (now == n)
    {
        return true;
    }

    vst[now] = true;

    for (ll i = 0; i < e[now].size(); i++)
    {
        if (!vst[e[now][i]])
        {
            if (dfs(e[now][i]))
            {
                return true;
            }
        }
    }

    return false;
}

inline ll solve()
{
    // cout << endl << endl;
    ll m = 0;

    cin >> n >> m;

    for (ll i = 0; i < m; i++)
    {
        int a = 0, b = 0;

        cin >> a >> b;

        e[a].push_back(b);
        e[b].push_back(a);
    }

    if (dfs(1))
    {
        return 0;
    }
    vst.reset();

    ll ans = LLONG_MAX;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            // if (i == j)
            // {
            //     continue;
            // }
            e[i].push_back(j);
            e[j].push_back(i);

            if (dfs(1))
            {
                // printf("%lld, %lld, true\n", i, j);
                ans = min(ans, (i - j) * (i - j));
            }
            // else
            // {
            //     printf("%lld, %lld, false\n", i, j);
            // }
            e[i].pop_back();
            e[j].pop_back();
            vst.reset();
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            for (ll k = 1; k <= n; k++)
            {
                for (ll l = 1; l <= n; l++)
                {
                    e[i].push_back(j);
                    e[j].push_back(i);
                    e[k].push_back(l);
                    e[l].push_back(k);

                    if (dfs(1))
                    {
                        ans = min(ans, (i - j) * (i - j) + (k - l) * (k - l));
                    }

                    e[i].pop_back();
                    e[j].pop_back();
                    e[k].pop_back();
                    e[l].pop_back();

                    vst.reset();
                }
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        e[i].clear();
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    ll t = 0;

    cin >> t;

    for (ll i = 0; i < t; i++)
    {
        cout << solve() << endl;
    }

    return 0;
}
