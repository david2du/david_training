#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Pair
{
    int a;
    int b;
    int c;
} f[3][10000 + 10];

int better(const struct Pair *A, const struct Pair *B)
{
    if ((abs(A->a) + abs(A->b) + abs(A->c)) != abs(B->a) + abs(B->b) + abs(B->c))
    {
        return (abs(A->a) + abs(A->b) + abs(A->c)) < abs(B->a) + abs(B->b) + abs(B->c);
    }
    return (max(0, A->a) + max(0, A->b) + max(0, A->c)) < (max(0, B->a) + max(0, B->b) + max(0, B->c));
}

#define INF 1000000

int main()
{
    int a = 0, b = 0, c = 0;
    int na = 0, nb = 0, nc = 0;
    int ma = 0, mb = 0, mc = 0;
    int E = 0;

    scanf("%d,%d,%d", &a, &b, &c);
    scanf("%d,%d,%d", &na, &nb, &nc);
    scanf("%d,%d,%d", &ma, &mb, &mc);
    scanf("%d", &E);

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 1; j <= E; ++j)
        {
            f[i][j].a = INF;
            f[i][j].b = INF;
            f[i][j].c = INF;
        }
        f[i][0].a = 0;
        f[i][0].a = 0;
        f[i][0].a = 0;
    }

    int r = 0;
    for (int j = 1; j * a <= E; ++j)
    {
        f[r][j].a = j;
    }
    r = 1;

    for (int j = 1; j <= E; ++j)
    {
        for (int i = -mb; i <= na; ++i)
        {
            if ((j - i * b) > E || )
            if (better(&f[r - 1][j + i * b], &f[r][j]))
        }

        f[r][j] =
    }

    return 0;
}