#include <bits/stdc++.h>
using namespace std;

int main()
{
    int f[64] = {1, 1};
    int n = 0;

    for (int i = 2; i <= 32; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    while (cin >> n)
    {
        cout << f[n] << endl;
    }
    

    return 0;
}