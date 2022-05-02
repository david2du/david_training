#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1)
    {
        int m = 0, k = 0, sum = 0;

        scanf("%d%d", &m, &k);

        if ((m == 0) && (k == 0))
        {
            break;
        }

        while (m >= k)
        {
            sum += k;
            m -= (k - 1);
        }
        sum += m;

        printf("%d\n", sum);
    }

    return 0;
}