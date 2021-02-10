#include <bits/stdc++.h>
using namespace std;

int flower[128];

bool ok(const int &start, const int &end)
{
    const int NUM = (end - start + 1);
    int sum = 0, ave = 0;
    for (int i = start; i <= end; i++)
    {
        sum += flower[i];
    }
    ave = sum / NUM;

    if ((ave * NUM) != sum)
    {
        return false;
    }

    for (int i = start; i <= end; i++)
    {
        if (flower[i] == ave)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> flower[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ans += (ok(i, j));
        }
    }

    cout << ans << endl;

    return 0;
}