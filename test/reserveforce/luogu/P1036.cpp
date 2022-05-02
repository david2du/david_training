#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/**
 * @brief Miller Rabin Prime Number Checking Method
 *
 */
namespace MR_PCM
{
    ll qmul(ll a, ll b, ll p)
    {
        ll ans = 0;

        while (b)
        {
            if (b & 1)
            {
                ans += a;
                ans %= p;
            }

            a += a;
            a %= p;
            b >>= 1;
        }

        return ans;
    }

    ll qpow(ll a, ll b, ll p)
    {
        ll ans = 1;

        while (b)
        {
            if (b & 1)
            {
                ans = qmul(ans, a, p);
            }

            a = qmul(a, a, p);
            b >>= 1;
        }

        return ans;
    }

    bool miller_rabin(ll n, ll k)
    {
        ll t = n - 1;
        ll s = 0;

        while (t % 2 == 0)
        {
            t /= 2;
            s++;
        }

        for (ll i = 0; i < k; ++i)
        {
            ll a = 0;

            while (!(a >= 2 && a <= n - 2))
            {
                a = rand() % n;
            }

            ll temp = qpow(a, t, n);
            if (temp % n == 1 || temp % n == n - 1)
            {
                continue;
            }

            ll flag = 0;

            for (ll j = 1; j < s; ++j)
            {
                temp = qmul(temp, temp, n);
                if (temp % n == n - 1)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                continue;
            }

            return false;
        }

        return true;
    }

    bool isPrime(ll n)
    {
        if (n == 1)
        {
            return 0;
        }
        if (n == 2)
        {
            return 1;
        }
        if (n % 2 == 0)
        {
            return 0;
        }

        const ll ROUND = 10;

        return miller_rabin(n, ROUND);
    }
} // namespace MR_PCM

ll n, k;

bitset<32> bs;
ll num[32];
ll sum, cnt;

void fun(ll ndep, ll now)
{
    if (ndep == k)
    {
        if (MR_PCM::isPrime(sum))
        {
            cnt++;
        }

        return;
    }

    ndep++;
    for (ll i = now + 1; i < n; i++)
    {
        if (!bs[i])
        {
            bs[i] = true;
            sum += num[i];

            fun(ndep, i);

            bs[i] = false;
            sum -= num[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    fun(0, -1);
    cout << cnt << endl;

    return 0;
}