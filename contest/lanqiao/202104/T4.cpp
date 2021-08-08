#include <bits/stdc++.h>
using namespace std;

long long getsum(long long n)
{
    long long sum = 0;

    for (long long i = 1; i <= n; i++)
    {
        sum += i;
    }

    return sum;
}

long long n;
//bool used[64];

long long meth(long long num, long long last_sum, long long now)
{
    if (num == 1)
    {
        return (last_sum == now);
    }
    if (last_sum < now)
    {
        return 0;
    }

    //used[now] = true;
    last_sum -= now;

    long long ans = 0;
    for (long long i = now + 1; i <= n; i++)
    {
        if (last_sum < i)
        {
            break;
        }
        //if (!used[i])
        //{
            ans += meth(num - 1, last_sum, i);
        //}
    }
    //used[now] = false;

    return ans;
}

int main()
{
    long long m = 0;

    cin >> n >> m;
    long long sum = getsum(n);
    long long get = (sum - m) / 2;

    long long ans = 0;
    for (long long i = 1; i <= (long long)(sqrt(2 * get)) + 2; i++)
    {
        for (long long j = 1; j <= n; j++)
        {
            ans += meth(i, get, j);
        }
    }

    cout << ans << endl;

    return 0;
}