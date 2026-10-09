#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2100000 + 10;
ll a[N];

void solve()
{
    int n = 0, m = 0;

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    priority_queue<ll> pq;
    ll sum = 0;
    for (int i = 1; i < m; ++i)
    {
        pq.push(a[i]);
        sum += a[i];
    }
    ll mx = (ll)m * a[m] - sum;
    for (int i = m + 1; i <= n; ++i)
    {
        if (!pq.empty() && a[i - 1] < pq.top())
        {
            sum -= pq.top();
            pq.pop();
            sum += a[i - 1];
            pq.push(a[i - 1]);
        }
        mx = max(mx, m * a[i] - sum);
    }
    cout << mx << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}