#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;

    scanf("%d", &n);

    int maxn = 0;
    for (int a = 0; a <= n; ++a)
    {
        for (int b = 0; b <= n; ++b)
        {
            if ((a + b) % 2 == 0)
            {
                for (int c = 0; c <= n; ++c)
                {
                    if (((b + c) % 3 == 0) && ((a + b + c) % 5 == 0))
                    {
                        maxn = max((a + b + c), maxn);
                    }
                }
            }
        }
    }

    printf("%d", maxn);

    return 0;
}