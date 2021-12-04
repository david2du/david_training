#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f[64];

int main(int argc, char const *argv[])
{
    ll n = 0;

    cin >> n;

    f[1] = 1LL;
    f[2] = 2LL;
    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    cout << f[n] << endl;

    return 0;
}
