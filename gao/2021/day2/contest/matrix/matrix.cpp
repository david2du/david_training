#include <bits/stdc++.h>
using namespace std;

long long l[100010], t[100010];

const long long MOD = 1e9 + 7;

long long zero(long long n, long long b)
{
    long long ans = t[n - 1];

    for (long long i = 2; i <= n; i++)
    {
        ans *= b;
        ans %= MOD;
    }

    return ans;
}

long long lastcol[1000010];
long long solve(long long n, long long a, long long b)
{
    for (long long i = 0; i < n; i++)
    {
        lastcol[i] = t[i];
    }

    for (long long i = 1; i < n; i++)
    {
        lastcol[0] = l[i];
        for (long long j = 1; j < n; j++)
        {
            long long t1 = (a * lastcol[j - 1]) % MOD;
            long long t2 = (b * lastcol[j]) % MOD;

            lastcol[j] = (t1 + t2) % MOD;
        }
    }

    return lastcol[n - 1];
}

int main(int argc, char const *argv[])
{
    long long n = 0, a = 0, b = 0;

    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);


    cin >> n >> a >> b;
    for (long long i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    if (a == 0)
    {
        cout << zero(n, b) << endl;
    }
    else
    {
        cout << solve(n, a, b) << endl;
    }

    return 0;
}