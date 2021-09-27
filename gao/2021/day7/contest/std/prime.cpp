#include <iostream>
using namespace std;

long long qmul(long long a, long long b, long long p)
{
    long long ans = 0;
    while (b)
    {
        if (b & 1)
            ans += a, ans %= p;
        a += a, a %= p, b >>= 1;
    }
    return ans;
}
long long qpow(long long a, long long b, long long p)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = qmul(ans, a, p);
        a = qmul(a, a, p), b >>= 1;
    }
    return ans;
}
bool miller_rabin(long long n, long long k)
{
    long long t = n - 1;
    long long s = 0;
    while (t % 2 == 0)
        t /= 2, s++;
    for (long long i = 0; i < k; ++i)
    {
        long long a = 0;

        a = rand() % (n - 3) + 2;
        long long temp = qpow(a, t, n);
        if (temp % n == 1 || temp % n == n - 1)
            continue;
        long long flag = 0;
        for (long long j = 1; j < s; ++j)
        {
            temp = qmul(temp, temp, n);
            if (temp % n == n - 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;
        return 0;
    }
    return 1;
}
bool isPrime(long long n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    long long k = 32;
    return miller_rabin(n, k);
}

const long long N = 500010;
long long n, prime;
bitset<N> vis;

long long Era_sieve(long long n)
{
    long long cnt = 0;
    for (long long i = 2; i < n; ++i)
    {
        if (!vis[i])
            prime = i;
        for (long long j = 2; j * i < n; ++j)
            vis[j * i] = 1;
    }
    return prime;
}

int main(int argc, char const *argv[])
{
    long long n = 0;

    cin >> n;

    /*if (n <= N)
    {
        cout << Era_sieve(n - 1LL) << endl;
    }*/
    //else
    //{
        long long i = 1;

        while (!isPrime(n - i))
        {
            i++;
        }

        cout << n - i << endl;
    //}

    return 0;
}