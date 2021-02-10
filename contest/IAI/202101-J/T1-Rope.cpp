#include <bits/stdc++.h>
using namespace std;

int rope1[100010];
int rope2[100010];
int n;

int doRope2();

int ok(bool rp1)
{
    int i = 0;
    bool flag = false;

    for (i = 0; i < n; i++)
    {
        if (rope1[i] != rope2[i])
        {
            flag = true;
            break;
        }
    }

    if (!flag)
    {
        return -1;
    }

    if (rp1)
    {
        int fd = find(rope1, rope1 + n, rope2[i]) - rope1;
        int dis
    }
    else
    {
        int fd = find(rope2, rope2 + n, rope1[i]) - rope2;
    }

    return -2;
}

int doRope1()
{
    int cnt = ok(true);

    if (cnt == -1)
    {
        return 0;
    }

    return min(doRope1(), doRope2()) + 1;
}

int doRope2()
{
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> rope1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> rope2[i];
    }

    return 0;
}