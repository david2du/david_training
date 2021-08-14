#include <iostream>
using namespace std;

typedef long long ll;

ll step(ll x)
{
    ll ans = 0;
    for (ll i = 1; i <= x; i++)
    {
        ans *= x;
        ans %= (1e9 + 7);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    freopen("relative.in", "r", stdin);
    freopen("relative.out", "w", stdout);

    long long n = 0;

    cin >> n;
    cout << step(n)<< endl;

    return 0;
}