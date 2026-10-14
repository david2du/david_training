#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 300000 + 10;
ll l[N], r[N];
ll L[N], R[N];

void init(ll n)
{
    fill(L, L + n + 1, INT_MAX);
    fill(R, R + n + 1, INT_MAX);
    R[2] = r[1];
    for (ll i = 3; i <= n; ++i)
        R[i] = min(R[i - 1], r[i - 1]);
    L[n - 1] = l[n];
    for (ll i = n - 2; i >= 1; --i)
        L[i] = min(L[i + 1], l[i + 1]);
}

int main()
{
    ll n = 0, q = 0;

    cin >> n >> q;
    for (ll i = 2; i <= n; ++i)
        cin >> l[i];
    for (ll i = 1; i <= n - 1; ++i)
        cin >> r[i];
    init(n);
    // for (ll i = 1; i <= n; ++i)
    //     cout << L[i] << " ";
    // cout << endl;
    // for (ll i = 1; i <= n; ++i)
    //     cout << R[i] << " ";
    // cout << endl;
    for (ll i = 0; i < q; ++i)
    {
        ll s = 0, t = 0;
        cin >> s >> t;

        if (s < t)
        {
            cout << min(r[s], l[s] + R[s]) << endl;
        }
        else
        {
            cout << min(l[s], r[s] + L[s]) << endl;
        }
    }

    return 0;
}