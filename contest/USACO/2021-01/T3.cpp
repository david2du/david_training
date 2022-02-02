#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll cow[32];
ll hei[32];
ll forb;

int main()
{
    ll n = 0;

    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> cow[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> hei[i];
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (cow[i] > hei[j])
            {
                forb++;
            }
        }
    }

    ld ans = 1.0;
    for (ll i = 1; i <= n; i++)
    {
        ans *= (ld)i;
    }

    if (forb != 0)
    {
        ans /= (ld)n;
        ans *= (ld)(n - 1);
        //ans = ceill(ans);
        for (ll i = 1; i < forb; i++)
        {
            ans /= (ld)(n - 1);
            ans *= (ld)(n - 2);
            //ans = ceill(ans);
        }
        ans = ceill(ans);
    }

    cout << ans << endl;

    return 0;
}