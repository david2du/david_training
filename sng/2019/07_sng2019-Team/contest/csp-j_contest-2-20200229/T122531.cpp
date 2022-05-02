#include <bits/stdc++.h>
using namespace std;

int a[10010], b[10010];

int main()
{
    int n = 0, ans = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);

    for (int i = 0; i < n; i++)
    {
        ans += abs(a[i] - b[n - i - 1]);
    }

    cout << ans << endl;

    return 0;
}