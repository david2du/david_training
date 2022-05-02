#include <bits/stdc++.h>
using namespace std;

void opr(int n)
{
    bool first = true;
    int i = 1;

    while (n > 1)
    {
        i++;
        if (n % i != 0)
        {
            continue;
        }

        int cnt = 0;
        while (n % i == 0)
        {
            n /= i;
            cnt++;
        }

        if (!first)
        {
            printf("*");
        }
        else
        {
            first = false;
        }

        if (cnt > 1)
        {
            printf("%d^%d", i, cnt);
        }
        else
        {
            printf("%d", i);
        }
    }
}

int main()
{
    int n = 0;

    cin >> n;

    opr(n);

    return 0;
}