#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll w[8], v[8];

ll fun(ll idx, ll lastw, ll use)
{
    if ((lastw + (w[idx] * use) > 15) || (idx >= 5))
    {
        return 0;
    }

    return (v[idx] * use) + max(fun(idx + 1, lastw + (w[idx] * use), 0), fun(idx + 1, lastw + (w[idx] * use), 1));
}

int main()
{
    for (ll i = 0; i < 5; i++)
    {
        cin >> w[i];
    }
    for (ll i = 0; i < 5; i++)
    {
        cin >> v[i];
    }

    cout << max(fun(0, 0, 0), fun(0, 0, 1)) << endl;

    return 0;
}