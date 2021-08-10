#include <bits/stdc++.h>
using namespace std;

long long a[1000010];

void change(long long x, long long y)
{
    a[x] = y;
}

long long sum(long long x, long long y, long long n)
{
    long long ans = 0;

    for (long long i = 1; i <= n; i++)
    {
        ans += ((a[i] + x) & y);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    long long n = 0, q = 0;

    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);

    cin >> n >> q;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (long long i = 0; i < q; i++)
    {
        long long x = 0, y = 0, z = 0;

        cin >> x >> y >> z;

        if (x == 1)
        {
            change(y, z);
        }
        else
        {
            cout << sum(y, z, n) << endl;
        }
    }

    return 0;
}