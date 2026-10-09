#include <stdio.h>

typedef long double ld;

ld powlf(ld x, int ind)
{
    ld ans = (ld)1;
    for (int i = 0; i < ind; ++i)
        ans *= x;
    return ans;
}

ld nxt(ld k)
{
    ld a = (ld)4 / ((ld)8 * k + (ld)1);
    ld b = (ld)2 / ((ld)8 * k + (ld)4);
    ld c = (ld)1 / ((ld)8 * k + (ld)5);
    ld d = (ld)1 / ((ld)8 * k + (ld)6);

    return powlf((ld)1 / (ld)16, k) * (a - b - c - d);
}

int main()
{
    int n = 0;

    scanf("%d", &n);

    ld ex = 0, ans = 0;
    int k = 0;
    do
    {
        ex = nxt(k);
        ans += ex;
        ++k;
        // printf("%lf\n", (double)ans);
    } while (ex >= powlf((ld)0.1, n));

    // printf("%lf\n", (double)ans);
    ans -= (ld)3;
    printf("pi=3.");
    for (int i = 0; i < n; ++i)
    {
        ans *= (ld)(10);
        printf("%d", (int)(ans));
        ans -= (int)(ans);
    }
    printf("\n");

    return 0;
}