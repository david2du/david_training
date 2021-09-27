#include <iostream>
#include <cmath>

using namespace std;

inline void qrd(long long &x)
{
    char c = 0;

    while (!((c >= '0') && (c <= '9')))
    {
        c = getchar();
    }
    while ((c >= '0') && (c <= '9'))
    {
        x *= 10LL;
        x += (long long)(c - '0');
        c = getchar();
    }
}

long long a[500010];

inline long long min(const long long &a, const long long &b)
{
    return (a < b ? a : b);
}

int main(int argc, char const *argv[])
{
    long long n = 0, m = 0;

    //freopen("subseq.in", "r", stdin);
    //freopen("subseq.out", "w", stdout);

    qrd(n);
    qrd(m);
    for (long long i = 1; i <= n; i++)
    {
        qrd(a[i]);

        a[i] += a[i - 1];
    }

    for (long long i = 1; i <= m; i++)
    {
        long long l = 0, r = 0, p = 0;

        qrd(l);
        qrd(r);
        qrd(p);

        long long ans = LLONG_MAX;
        for (long long j = l; j <= r; j++)
        {
            for (long long k = j; k <= r; k++)
            {
                ans = min(ans, (a[k] - a[j - 1]) % p);
            }
        }
        cout << ans << endl;
    }

    return 0;
}