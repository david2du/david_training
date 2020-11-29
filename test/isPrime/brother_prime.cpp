#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_prime(ll n)
{
    if (n < 2)
    {
        return false;
    }

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

bool is_brother(ll n)
{
    if ((is_prime(n)) && (is_prime(n + 2)))
    {
        return true;
    }
    return false;
}

int main()
{
    ll ra = 0, rb = 0;

    cin >> ra >> rb;

    if ((ra < 0) || (rb < 0))
    {
        cout << "INPUT ERROR." << endl;
        return 0;
    }

    ll cnt = 0;
    for (ll i = ra; i < rb; i++)
    {
        if (is_brother(i))
        {
            printf("No.%lld (%lld, %lld)\n", ++cnt, i, i + 2);
        }
    }

    printf("\nTOT: %lld BP(Brother-Primes)", cnt);

    return 0;
}