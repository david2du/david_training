#include <bits/stdc++.h>
using namespace std;

inline void solve()
{
    int n = 0, k = 0;
    string s;
    cin >> n >> k  >> s;
    int cnt  = 0;
    for (int i = 0; i < (n / k); ++i)
    {
        bool flag = true;
        for (int j = 0; j < k; ++j)
        {
            if (s[i * k + j] == '0')
                flag = false;
        }
        cnt += flag;
    }
    cout << cnt << endl;
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