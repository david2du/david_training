#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace miller_rabin
{
    typedef long long ll;

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

            bool flag = false;
            for (ll j = 1; j < s; ++j)
            {
                temp = qmul(temp, temp, n);
                if (temp % n == n - 1)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                return false;
            }
        }

        return true;
    }

    bool isPrime(ll n, ll rnd = 10)
    {
        if (n == 1)
        {
            return false;
        }
        if (n == 2)
        {
            return true;
        }
        if (n % 2 == 0)
        {
            return false;
        }

        return miller_rabin(n, rnd);
    }
} // namespace miller_rabin

map<ll, ll> m1, m2;

const ll N = 5000000;
vector<ll> prime;
bitset<N> nvis;

ll Euler_sieve(const int n = N)
{
    ll cnt = 0;

    for (ll i = 2; i <= n; ++i)
    {
        if (!nvis[i])
        {
            prime.push_back(i);
        }
        for (ll j = 1; j <= cnt && prime[j] * i <= n; ++j)
        {
            nvis[prime[j] * i] = true;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    return cnt;
}

inline void sep(ll x, map<ll, ll> &mp)
{
    if (x == 1)
    {
        mp[1] = 1;
        return;
    }

    ll pos = 0;
    for (ll pos = 0; pos < prime.size() && (prime[pos] * prime[pos]) <= x; pos++)
    {
        while (!(x % prime[pos]))
        {
            mp[prime[pos]]++;
            x /= prime[pos];
        }
    }
    if (pos < prime.size())
    {
        if (x > 1)
        {
            mp[x]++;
        }
        return;
    }

    bool changed = true;
    for (ll i = prime[prime.size() - 1] + 1; i * i <= x; i++)
    {
        // if (changed)
        // {
        //     if (miller_rabin::isPrime(x, 4))
        //     {
        //         break;
        //     }
        // }
        changed = false;
        if (!(x % i))
        {
            changed = true;
        }
        while (!(x % i))
        {
            mp[i]++;
            x /= i;
        }
    }
    if (x > 1)
    {
        mp[x]++;
    }
}

inline void solve()
{
    ll x = 0, z = 0;

    cin >> x >> z;

    z /= x;

    if (x == 1)
    {
        cout << z << endl;
        return;
    }
    if (z == 1)
    {
        cout << 1 << endl;
        return;
    }

    sep(x, m1);
    sep(z, m2);

    ll y = 1;
    for (auto it = m2.begin(); it != m2.end(); it++)
    {
        ll num = (it->first), cnt = (it->second);
        auto fd = m1.find(num);

        if (fd != m1.end())
        {
            if (cnt <= ((fd->second) * 2))
            {
                if (cnt % 2)
                {
                    cout << -1 << endl;
                    return;
                }
                else
                {
                    cnt /= 2;
                }
            }
            else
            {
                cnt -= fd->second;
            }
        }

        y *= pow(num, cnt);
    }

    cout << y << endl;

    m1.clear();
    m2.clear();
}

int main(int argc, char const *argv[])
{
    clock_t A = clock();
    freopen("math4.in", "r", stdin);
    freopen("math.out", "w", stdout);

    ll t = 0;
    cin >> t;

    // Euler_sieve(100000);
    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    clock_t B = clock();

    cerr << (double)(B - A) / (double)(CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
