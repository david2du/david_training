#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int N = 64;
ull dp[N];

int main()
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < 32; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int n = 0;
    
    while(cin >> n)
    {
        cout << dp[n] << endl;
    }

    return 0;
}