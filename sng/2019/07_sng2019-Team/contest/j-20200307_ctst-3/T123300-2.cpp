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

        do
        {
            sum += m / k * k;
            m = m / k + m % k;
        } while (m / k != 0);
        sum += m;

        printf("%lld\n", sum);
    }

    return 0;
}