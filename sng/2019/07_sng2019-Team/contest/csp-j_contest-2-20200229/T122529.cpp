#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long k = 0;
    long long i = 0, sum = 0, ans = 0;

    cin >> k;

    while (sum < k)
    {
        i++;
        sum += i;
    }

    ans = i - (sum - k);
    if (k == sum)
    {
        ans = i;
    }

    cout << ans << endl;

    return 0;
}