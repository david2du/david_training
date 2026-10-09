#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
int a[N];

int main()
{
    int n = 0;
    cin >> n;
    for (int  i = 0; i < n;++i)
    {
        cin >> a[i];
    }
    int mx = 0;
    for (int k = 1; k <= n; ++k)
    {
        mx = max(mx, max(a[k - 1], a[n - k]));
        cout << mx << " ";
    }
    cout << endl;
    // int l = 0, r = n - 1;

    // int ans = 0;
    // for (int k = 1; k <= n; ++k)
    // {
    //     if (a[l] > a[r])
    //     {
    //         cout << a[l] << " ";
    //         l++;
    //     }
    //     else
    //     {
    //         cout << a[r] << " ";
    //         r--;
    //     }
    // }
    // cout << endl;


    return 0;
}