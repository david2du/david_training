#include <iostream>
using namespace std;

typedef long long ll;

bool num[200100];
ll x[200010];

ll mex(ll a, ll b, ll n)
{
    for (ll i = a; i <= b; i++)
    {
        if (x[i] < (n + 1))
        {
            num[x[i]] = true;
            //printf("num[%lld]:true\n", i);
        }
    }

    ll ans = 0;
    for (ll i = 0; i < (n + 1); i++)
    {
        if (!num[i])
        {
            ans = i;
            break;
        }
    }
    //printf("mex(%lld, %lld, %lld):%lld\n", a, b, n, ans);

    fill(num, num + n + 1, false);

    return ans;
}

int main(int argc, char const *argv[])
{
    ll n = 0;

    //freopen("mex.in", "r", stdin);
    //freopen("mex.out", "w", stdout);

    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i; j <= n; j++)
        {
            ans += mex(i, j, (j - i + 1));
        }
    }
    cout << ans << endl;
    
    return 0;
}