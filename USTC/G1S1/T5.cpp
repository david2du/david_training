#include <stdio.h>
typedef long long ll;
ll prod[30];
ll use[30];
int main()
{
    prod[0] = 1;
    for (ll i = 1; i < 15; ++i)
        prod[i] = prod[i - 1] * i;

    ll n = 0, k = 0;

    scanf("%lld,%lld", &n, &k);
    if (prod[n] && prod[n] <= k)
    {
        for (ll i = n - 1; i >= 0; --i)
            putchar('a' + i);
        return 0;
    }
    for (ll i = n; i > 0; --i)
    {
        ll x = 0;
        if (prod[i - 1])
            x = (k - 1) / prod[i - 1];
        ll cnt = 0;
        ll j = 0;
        // printf("%d", x);
        for (j = 0; j < n && cnt <= x; ++j)
            cnt += !use[j];
        putchar('a' + j - 1);
        use[j - 1] = 1;
        if (prod[i - 1])
            k -= ((k - 1) / prod[i - 1] * prod[i - 1]);
    }

    return 0;
}