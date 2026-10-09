#include <stdio.h>

int main()
{
    typedef unsigned long ul;
    ul n = 0, m = 0;

    scanf("%ld,%ld", &n, &m);
    ul now = 1, ans = 0;
    ul ovf = 0;
    for (ul i = 1; i <= n; ++i)
    {
        now = (now * i);
        ans += now;
        if (ans >= m)
        {
            printf("overflow at %ld!\n", i);
            ovf = 1;
            break;
        }
    }
    if (!ovf)
    {
        printf("%ld\n", ans);
    }

    return 0;
}