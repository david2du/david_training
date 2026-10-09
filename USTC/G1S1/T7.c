#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MX 40000

struct Pair
{
    int a;
    int b;
    int c;
} f[3][2 * MX + 10];

#define max(a, b) (a > b ? a : b)

int better(const struct Pair *A, const struct Pair *B)
{
    if ((abs(A->a) + abs(A->b) + abs(A->c)) != abs(B->a) + abs(B->b) + abs(B->c))
    {
        return (abs(A->a) + abs(A->b) + abs(A->c)) < (abs(B->a) + abs(B->b) + abs(B->c));
    }
    return (max(0, A->a) + max(0, A->b) + max(0, A->c)) < (max(0, B->a) + max(0, B->b) + max(0, B->c));
}

#define F(a, b) f[a][b + MX]
#define INF 1000000

void print(int cnt, int cash)
{
    if (cnt > 0)
        printf("Buyer pays %d bills of %d yuan.\n", cnt, cash);
    else if (cnt < 0)
        printf("Seller changed %d bills of %d yuan.\n", -cnt, cash);
}

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
        for (int j = -MX; j <= MX; ++j)
        {
            F(i, j).a = INF;
            F(i, j).b = INF;
            F(i, j).c = INF;
        }
    }

    int r = 0;
    for (int j = -ma; j <= na; ++j)
    {
        F(r, j * a).a = j;
    }
    r = 1;

    for (int j = -MX; j <= MX; ++j)
    {
        for (int i = -mb; i <= nb; ++i)
        {
            if ((j - i * b) > MX || (j - i * b < (-MX)))
                continue;
            F(r - 1, j - i * b).b = i;
            if (better(&F(r - 1, j - i * b), &F(r, j)))
            {
                F(r, j) = F(r - 1, j - i * b);
            }
            F(r - 1, j - i * b).b = INF;
        }
    }

    r = 2;
    for (int j = -MX; j <= MX; ++j)
    {
        for (int i = -mc; i <= nc; ++i)
        {
            if ((j - i * c) > MX || (j - i * c < (-MX)))
                continue;
            F(r - 1, j - i * c).c = i;
            if (better(&F(r - 1, j - i * c), &F(r, j)))
            {
                F(r, j) = F(r - 1, j - i * c);
            }
            F(r - 1, j - i * c).c = INF;
        }
    }
    struct Pair e = F(2, E);

    if (e.a != INF && e.b != INF && e.c != INF)
    {
        print(e.a, a);
        print(e.b, b);
        print(e.c, c);
    }
    else
    {
        printf("Cannot buy.\n");
    }

    return 0;
}