#include <stdio.h>

#define N 10010

int not_prime[N];
int prime[N];
int cnt;

void euler_seive(int n)
{
    not_prime[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (!not_prime[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt; ++j)
        {
            if (i * prime[j] > n)
                break;
            not_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    int n = 0;

    scanf("%d", &n);
    euler_seive(n);
    for (int i = 0; i < cnt; ++i)
    {
        if (prime[i] > n / 2)
            break;
        if (!not_prime[n - prime[i]])
        {
            printf("%d=%d+%d\n", n, prime[i], n - prime[i]);
        }
    }

    return 0;
}