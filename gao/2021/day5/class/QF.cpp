#include <iostream>
#include <math.h>
using namespace std;

typedef long long ll;

ll maxx(ll a, ll b)
{
    return (a > b ? a : b);
}

ll minn(ll a, ll b)
{
    return (a < b ? a : b);
}

ll f[100010];

ll st[32][100010];

ll ask(const ll &lft, const ll &rgt)
{
    const ll LOG = (ll)(log((double)(rgt - lft)) / log((double)(2)));

    return maxx(st[LOG][lft], st[LOG][rgt - (1 << LOG) + 1]);
}

void build(const ll &n)
{
    const ll LOG = (ll)(log((double)(n)) / log((double)(2)));

    for (ll i = 1; i <= LOG; i++)
    {
        for (ll j = 1; j <= (n - (1 << i) + 1); j++)
        {
            st[i][j] = maxx(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int main(int argc, char const *argv[])
{
    ll n = 0, m = 0;

    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> f[i] >> st[0][i];
    }
    build(n);
    /*or (ll i = 0; i < 3; i++)
    {
        for (ll j = 1; j <= 5; j++)
        {
            cout << st[i][j] << " ";
        }
        cout << endl;
    }*/

    ll sumf = f[1];

    ll minnu = INT_MAX;
    ll l = 1, r = 1;

    while ((r <= n) && (l <= n) && (l <= r))
    {
        //printf("%lld, %lld, (%lld, %lld)\n", minnu, sumf, l, r);
        if (sumf >= m)
        {
            minnu = minn(minnu, ask(l, r));

            sumf -= f[l];

            l++;
        }
        else
        {
            r++;
            sumf += f[r];
        }
    }

    cout << minnu << endl;

    return 0;
}