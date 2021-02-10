#include <bits/stdc++.h>
using namespace std;

long long f[64] = {1, 1, 1, 1, 2, 3};

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 6; i < n; i++)
    {
        f[i] = (f[i - 6] + f[i - 5] + f[i - 4] + f[i - 3]);
    }

    cout << f[n - 1] << endl;

    return 0;
}