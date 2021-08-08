#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int h[MAXN], hn;

void build()
{
    scanf("%d", &hn);

    for (int i = 0; i < hn; ++i)
    {
        scanf("%d", &h[i]);
    }
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    build();

    sort(h, h + hn, cmp);

    for (int i = 0; i < hn; i++)
    {
        printf("%d\n", h[i]);
    }

    return 0;
}