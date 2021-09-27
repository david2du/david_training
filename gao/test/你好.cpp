#include <cstdio>
//#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int fa[100010];
int id[100010];

int fnd(int x)
{
    if (fa[x] == x)
    {
        return x;
    }

    return fa[x] = fnd(fa[x]);
}

int main(int argc, char const *argv[])
{
    int m = 0;
    int a = 0, b = 0;
    int ans = 0;

    for (int i = 0; i <= 100000; i++)
    {
        fa[i] = i;
    }

    int cnt = 0;
    while (1)
    {
        scanf("%d%d", &a, &b);
        if (a == 0 && b == 0)
        {
            break;
        }

        if (!id[a])
        {
            id[a] = ++cnt;
        }
        if (!id[b])
        {
            id[b] = ++cnt;
        }

        int an_a = fnd(id[a]), an_b = fnd(id[b]);
        if (fa[an_a] == an_b)
        {
            printf("No\n");
            return 0;
        }
        fa[an_a] = an_b;
    }
    int last = -1;
    int cn = 0;

    for (int i = 1; i <= cnt; i++)
    {
        int x = fnd(i);
        //printf("%d, %d\n", i, x);
        if (x != last)
        {
            last = x;
            cn++;
        }
        if (cn > 1)
        {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");

    return 0;
}