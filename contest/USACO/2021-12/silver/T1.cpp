#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, ll> grs;
priority_queue<ll> tas;

int main(int argc, char const *argv[])
{
    ll n = 0, m = 0, k = 0;

    cin >> k >> m >> n;
    
    for (ll i = 0; i < k; i++)
    {
        ll a = 0, b = 0;

        cin >> a >> b;

        grs[a] = b;
    }

    for (ll i = 0; i < m; i++)
    {
        ll f = 0;

        cin >> f;

        if (grs.find(f) != grs.end())
        {
            grs.erase(f);
        }
    }

    for (auto it = grs.begin(); it != grs.end(); it++)
    {
        tas.push(it->second);
    }

    ll ans = 0;
    ll cnt = 0;
    while (!tas.empty() && cnt < n)
    {
        ans += tas.top();
        tas.pop();
        cnt++;
    }
    
    cout << ans << endl;
    
    return 0;
}
