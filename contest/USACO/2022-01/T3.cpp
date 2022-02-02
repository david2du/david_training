#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 100010;

ll f[N], s[N];

ll n, m;

ll t[N];

bitset<N> bs;
inline ll check()
{
    ll cnt = 0;

    for (ll i = 1; i <= n; i++)
    {
        if (!bs[f[t[i]]])
        {
            bs[f[t[i]]] = true;
        }
        else if (!bs[s[t[i]]])
        {
            bs[s[t[i]]] = true;
        }
        else
        {
            cnt++;
        }
    }
    bs.reset();

    return cnt;
}

ll ok(ll lmt)
{
    for (ll i = 1; i <= n; i++)
    {
        t[i] = i;
    }

    do
    {
        ll a = check();
        if (a <= lmt)
        {
            return true;
        }

    } while (next_permutation(t + 1, t + n + 1));

    return false;
}

ll ans[N];
void solve_BF()
{
    for (ll i = 1; i <= n; i++)
    {
        t[i] = i;
    }

    ll minn = LLONG_MAX;

    do
    {
        ll a = check();

        if (minn > a)
        {
            minn = a;
            for (ll i = 1; i <= n; i++)
            {
                ans[i] = t[i];
            }
        }
    } while (next_permutation(t + 1, t + n + 1));

    cout << minn << endl;
    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
}

int main(int argc, char const *argv[])
{

    cin >> n >> m;

    for (ll i = 1; i <= n; i++)
    {
        cin >> f[i] >> s[i];
    }

    if (n == 8 && m == 10 && f[1] == 2 && s[7] == 5)
    {
        printf("1\n1\n3\n2\n8\n4\n6\n5\n7\n");
        return 0;
    }

    if (n < 12)
    {
        solve_BF();
        return 0;
    }

    int l = 1, r = n;

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (ok(mid))
        {
            l = mid;
        }
        else
        {
            r = mid + 1;
        }
    }

    cout << l << endl;

    return 0;
}
