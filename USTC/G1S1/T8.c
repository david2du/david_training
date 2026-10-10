#include <stdio.h>

#define N 100000
int vst[N + 10];

int main()
{
    int n = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int x = 0;
        scanf("%d", &x);

        if (1 <= x && x <= n)
            vst[x] = 1;
    }
    int pos = 1;
    for (pos = 1; pos <= n; ++pos)
    {
        if (!vst[pos])
            break;
    }
    printf("%d\n", pos);

    return 0;
}