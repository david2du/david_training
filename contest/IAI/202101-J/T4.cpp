#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll ans = 0;
    int n = 0;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int rev = 0;
        int cnt = 0;
        int t = i;

        while (t != 0)
        {
            rev *= 10;
            rev += (t % 10);

            t /= 10;
            cnt++;
        }

        ans += rev;
        ans += ((long long)i * (long long)pow(10, cnt));
    }

    cout << ans << endl;

    return 0;
}