#include <bits/stdc++.h>
using namespace std;

long long tree[1000010];

long long n, m;
long long sum;

bool ok(long long h)
{
    long long idx = upper_bound(tree, tree + n, h) - tree;

    long long s = 0;

    if (idx < (n / 2))
    {
        for (long long i = 0; i < idx; i++)
        {
            s += tree[i];
        }
        return ((sum - s) >= m);
    }
    else
    {
        for (long long i = idx; i < n; i++)
        {
            s += (tree[i] - h);
        }
        return (s >= m);
    }
    
}

int main()
{
    long long maxn = 0;

    cin >> n >> m;
    for (long long i = 0; i < n; i++)
    {
        cin >> tree[i];
        maxn = max(maxn, tree[i]);

        sum += tree[i];
    }
    sort(tree, tree + n);

    long long l = 0, r = maxn;
    long long mid = 0;

    long long ans = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;

        if (ok(mid))
        {
            ans = l;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}