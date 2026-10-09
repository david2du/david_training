#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int p[N];
void solve()
{
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
    }

    int r = n + 1;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i] != i)
        {
            if (p[p[i]] != i || p[i] > r)
            {
                cout << "NO" << endl;
                return;
            }
            r = p[i];
        }
    }
    cout << "YES" << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}