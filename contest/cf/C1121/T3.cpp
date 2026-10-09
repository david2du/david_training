#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;
typedef long long ll;
ll a[N];

const ll MOD = 998244353;
vector<ll> prod;

void solve()
{
    int n = 0;
    cin >> n;
    if (n > prod.size())
    {
        for (int i = prod.size(); i < n; ++i)
            prod.push_back(prod.back() * i);
    }
    
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    sort(a, a + n);
    ll ans = 1, sum = 0;
    for (int i = n - 1; i > 0; --i)
    {
        sum += a[i];
        sum %= MOD;
        ans *= (sum - (a[i - 1] * (n - i)) % MOD + MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}

int main()
{
    int t = 0;

    cin >> t;
    prod.push_back(1);
    for (int i = 0; i < t; ++i)
    {
        solve();
    }


    return 0;
}