#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, v[N], fa[N];

bool p0(int x, int y)
{
    int f = fa[x];

    while(f)
    {
        if (f == y)
        {
            return true;
        }

        f = fa[f];
    }

    return false;
}

int p(int x, int y)
{
    if (p0(x, y) == true)
    {
        return y;
    }
    if (p0(y, x) == true)
    {
        return x;
    }

    return -1;
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &v[i], &fa[i]);
    }

    int k = 0, x = 0, y = 0;

    scanf("%d", &k);

    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d", x, y);

        cout << p(x, y) << endl;
    }

    return 0;
}