#include <bits/stdc++.h>
using namespace std;

int neib[10010];
long long sum[10010];

int main(int argc, char const *argv[])
{
    int n = 0, m = 0;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0, d = 0;

        cin >> a >> b >> d;

        neib[a]++;
        sum[a] += (long long)(d);
        neib[b]++;
        sum[b] += (long long)(d);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << neib[i] << " " << sum[i] << endl;
    }

    return 0;
}