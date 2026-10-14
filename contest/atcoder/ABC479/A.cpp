#include <bits/stdc++.h>

using namespace std;

int a[110];

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = 0;
    for (int i = 1; (2 * i - 1) <= n; ++i)
        ans += a[2 * i - 1];
    cout << ans << endl;

    return 0;
}