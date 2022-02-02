#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> e[100010];
bitset<100010> vst;

set<ll> st[100010];
ll timer;

ll n;
ll nst;

inline void dfs(ll now)
{
    if (now == n)
    {
        nst = timer;
    }

    st[timer].insert(now);
    vst[now] = true;

    for (ll i = 0; i < e[now].size(); i++)
    {
        if (!vst[e[now][i]])
        {
            dfs(e[now][i]);
        }
    }
}

inline ll power(ll a)
{
    return a * a;
}

inline ll add_road(ll a, ll b)
{
    ll ans = LLONG_MAX;

    if (st[a].size() > st[b].size())
    {
        swap(a, b);
    }
    for (auto it = st[a].begin(); it != st[a].end(); it++)
    {
        auto fnd = st[b].lower_bound(*it);

        if (fnd == st[b].end())
        {
            ans = min(ans, power((*st[b].rbegin()) - (*it)));
            break;
        }
        if (fnd == st[b].begin())
        {
            ans = min(ans, power((*fnd) - (*it)));
            continue;
        }
        ans = min(ans, power((*fnd) - (*it)));
        ans = min(ans, power((*(fnd--)) - (*it)));
    }

    return ans;
}

inline ll add_troad(ll a, ll b, ll c)
{
    return add_road(a, c) + add_road(b, c);
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

    nst = n;
    for (ll i = 1; i <= n; i++)
    {
        if (!vst[i])
        {
            dfs(i);
            timer++;
        }
    }

    if (nst == 0)
    {
        return 0;
    }

    ll ans = add_road(0, nst);
    // cout << ans << endl;

    for (ll i = 1; i < timer; i++)
    {
        if (i == nst)
            continue;
        ans = min(ans, add_troad(0, nst, i));
        // cout << ans << endl;
    }
    // cout << endl;

    for (ll i = 1; i <= n; i++)
    {
        e[i].clear();
    }
    for (ll i = 0; i < timer; i++)
    {
        st[i].clear();
    }
    timer = 0;
    vst.reset();

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
