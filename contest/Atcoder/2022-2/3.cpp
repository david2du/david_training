#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main(int argc, char const *argv[])
{
    int n = 0;

    cin >> n >> a[0];
    int ans = a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];

        if (a[i] > a[i - 1])
        {
            ans += (a[i] - a[i - 1]);
        }
    }

    if (n <= 2)
    {
        cout << ans << endl;
    }
    else
    {
        cout << ans - *min_element(a, a + n) << endl;
    }
    // else if (a[0] > a[n - 1])
    // {
    //     cout << ans << endl;
    // }
    // else
    // {
    //     cout << ans - a[0] << endl;
    // }

    return 0;
}