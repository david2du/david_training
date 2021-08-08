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
    for (int i = 0; i < 128; i++)
    {
        if (ok(i))
        {
            cout << i << endl;
        }
    }

    return 0;
}