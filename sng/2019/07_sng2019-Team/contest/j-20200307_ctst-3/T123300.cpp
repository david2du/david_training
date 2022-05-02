#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long m = 0, k = 0;

    while (1)
    {
        long long sum = 0;

        scanf("%lld%lld", &m, &k);

        if ((m == 0) && (k == 0))
        {
            break;
        }

        while(m / k != 0)
        {
            sum = k;
            m -= (k - 1);
        }
        sum += m;

        printf("%d\n", sum);
    }

    return 0;
}