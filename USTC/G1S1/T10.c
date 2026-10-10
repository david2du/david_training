#include <stdio.h>
#include <math.h>

#define EPS 1e-5

const int MX[6] = {59, 69, 79, 89, 99, 100};
const int MN[6] = {0, 60, 70, 80, 90, 100};

static inline int f(int x)
{
    if (x == 5)
        return 1;
    if (x == 0)
        return 60;
    return 10;
}

int possible[600];

int main()
{
    double x = 0;

    scanf("%lf", &x);
    x *= 5.0;

    if (fabs(x - floor(x)) > EPS || x < -EPS || x > (25.0 + EPS))
    {
        printf("Impossible\n");
        return 0;
    }
    int n = round(x);
    int cnt = 0;

    int mn = 100000, mx = 0;
    for (int a = 0; a <= 5; a++)
        for (int b = 0; b <= 5; b++)
            for (int c = 0; c <= 5; c++)
                for (int d = 0; d <= 5; d++)
                    for (int e = 0; e <= 5; e++)
                        if (a + b + c + d + e == n)
                        {
                            // cnt += f(a) * f(b) * f(c) * f(d) * f(e);
                            int x = MN[a] + MN[b] + MN[c] + MN[d] + MN[e];
                            int y = MX[a] + MX[b] + MX[c] + MX[d] + MX[e];
                            mn = (mn > x) ? x : mn;
                            mx = (mx < y) ? y : mx;

                            for (int s = x; s <= y; s++)
                                possible[s] = 1;
                        }
    for (int i = 0; i <= 500; ++i)
    {
        cnt += possible[i];
    }
    printf("MinAve:%.1lf MaxAve:%.1lf PossibleAve:%d\n", (double)mn / 5.0, (double)mx / 5.0, cnt);

    return 0;
}