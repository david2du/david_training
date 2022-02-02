#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long M = 998244353LL;

ll powe[1000010];

int main(int argc, char const *argv[])
{
    powe[0] = 1;
    for (ll j = 1; j <= 1000003; j++)
    {
        powe[j] = powe[j - 1] * j;
        powe[j] *= M;
    }

    ll t = 0;

    cin >> t;
    for (ll j = 0; j < t; j++)
    {
        ll n = 0, k = 0;

        cin >> n >> k;

        ll ans = powe[k - 1];

        for (ll i = 0; i < (n - k); i++)
        {
            ans *= (k + 2 * i);

            ans %= M;

            if (i >= 2)
            {
                for (ll k = 2; k <= i; k++)
                {
                    ans += C(k, i);
                    ans %= M;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
