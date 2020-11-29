#ifndef _ISP_   1
#define _ISP_   1

bool is_prime(long long n)
{
    if (n < 2)
    {
        return false;
    }

    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

#endif