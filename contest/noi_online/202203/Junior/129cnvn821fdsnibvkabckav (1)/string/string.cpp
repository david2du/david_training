#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ans;
string s, t;
string r;

inline void dfs(ll pos)
{
    if (pos >= s.size())
    {
        ans += (r == t);
        return;
    }

    if (s[pos] == '-')
    {
        auto a = r[0];

        r = r.substr(1);
        dfs(pos + 1);
        r = a + r;

        a = r[r.size() - 1];
        r.pop_back();
        dfs(pos + 1);
        r.push_back(a);
    }
    else
    {
        r.push_back(s[pos]);
        dfs(pos + 1);
        r.pop_back();
    }
}

void solve()
{
    int n = 0, m = 0;

    cin >> n >> m >> s >> t;

    dfs(0);

    cout << ans << endl;
    ans = 0;
}

int main(int argc, char const *argv[])
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int T = 0;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
    }

    return 0;
}
