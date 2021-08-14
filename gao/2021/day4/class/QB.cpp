#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;

int fa[1001];
int sze[1001];

int fnd(int x)
{
    if (fa[x] == 0)
        return x;

    return fa[x] = fnd(fa[x]);
}

int main(int argc, char const *argv[])
{
    int T = 0;
    int n = 0, m = 0;
    int a = 0, b = 0;
    int ans = 0;

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d%d", &n, &m);

        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            fa[fnd(a)] = fnd(b);
        }

        for (int i = 1; i <= n; i++)
            sze[fnd(i)]++;

        ans = 0;
        for (int i = 1; i <= n; i++)
            ans += (int)ceil((double)sze[i] / 10.0);

        fill(fa, fa + n + 1, 0);
        fill(sze, sze + n + 1, 0);

        printf("%d\n", ans);
    }

    return 0;
}