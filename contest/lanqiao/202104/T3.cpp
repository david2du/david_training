#include <bits/stdc++.h>
using namespace std;

bool ok(int a)
{
    if (a == 2)
    {
        return true;
    }
    if (a < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n = 0;

    cin >> n;

    int sum = 0;
    for (int i = 4; i <= n; i++)
    {
        if (!ok(i))
        {
            sum += i;
        }
    }

    cout << sum << endl;

    return 0;
}