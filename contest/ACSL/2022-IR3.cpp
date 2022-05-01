/**
 * @file 2022-IR3.cpp
 * @author David Chenyue Du (david2du@hotmail.com)
 * @brief The CPP file of the ACSL competition 2022(Intermediate Round 3)
 * @version 0.1
 * @date 2022-03-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f[64];
ll pas[64][64];

int main(int argc, char const *argv[])
{
    ll n = 0;

    cin >> n;

    f[0] = 1;
    f[1] = 1;

    ll cnt = 1;
    while (f[cnt] < n)
    {
        cnt++;
        f[cnt] = f[cnt - 1] + f[cnt - 2];
        // cout << f[cnt] << endl;
    }

    pas[0][0] = 1;
    // cout << pas[0][0] << endl;
    for (ll i = 1; i <= cnt; i++)
    {
        pas[i][0] = 1;
        pas[i][i] = 1;
        // cout << pas[i][0] << " ";
        for (ll j = 1; j < i; j++)
        {
            pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
            // cout << pas[i][j] << " ";
        }
        // cout << pas[i][i] << endl;
    }

    ll maxn = 0;
    ll odd = 0, even = 0;
    for (ll i = cnt, pos = 0; pos <= i; pos++, i--)
    {
        if (pas[i][pos] % 2)
        {
            odd++;
        }
        else
        {
            even++;
        }

        maxn = max(maxn, pas[i][pos]);
    }

    cout << odd << " " << even << " " << maxn << endl;

    return 0;
}
