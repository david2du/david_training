#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;
int a[N], b[N], c[N];

void solve()
{
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i <= n; ++i)
        c[i] = b[i] - a[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        // ans += abs(c[i] - c[i - 1]);
        if (c[i] - c[i - 1] != 0)
            ans++;
    }
    cout << ans << endl;
    fill(c, c + n + 2, 0);
}

int main()
{
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        solve();
    }


    return 0;
}