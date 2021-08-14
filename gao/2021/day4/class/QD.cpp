#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int fa[100010];
int sze[100010];

map<int, int> id;

int fnd(int x)
{
    if (fa[x] == 0)
    {
        return x;
    }

    return fa[x] = fnd(fa[x]);
}

int main(int argc, char const *argv[])
{
    int n = 0;
    int a = 0, b = 0;

    scanf("%d", &n);

    fill(sze, sze + n + 1, 1);

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);

        if (!id[a])
        {
            id[a] = ++cnt;
        }
        if (!id[b])
        {
            id[b] = ++cnt;
        }

        int an_a = fnd(id[a]), an_b = fnd(id[b]);
        fa[an_a] = an_b;
        sze[an_b] += sze[an_a];
    }

    printf("%d\n", *max_element(sze + 1, sze + cnt + 1));

    return 0;
}