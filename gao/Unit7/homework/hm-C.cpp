#include <bits/stdc++.h>
using namespace std;

bool find(long long n)
{
    while(n % 2 == 0)
    {
        n /= 2;
    }
    while(n % 3 == 0)
    {
        n /= 3;
    }
    while(n % 5 == 0)
    {
        n /= 5;
    }
    while(n % 7 == 0)
    {
        n /= 7;
    }

    return n == 1;
}

int main()
{
    long long n = 0, nu = 0;
    long long i = 0;

    scanf("%d", &n);
    
    while (nu != n)
    {
        ++i;
        if (find(i) == true)
        {
            ++nu;
        }
    }
    printf("%d\n", i);

    return 0;
}