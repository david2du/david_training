#include <bits/stdc++.h>
using namespace std;

const int MAX = 7 * 11 * 17;

int ok(int n)
{
    if (((n - 1) % 7 == 0) && (n % 11 == 0) && ((n + 1) % 17 == 0))
    {
        return 1;
    }
    else if (((n - 1) % 17 == 0) && (n % 11 == 0) && ((n + 1) % 7 == 0))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int i = 1;

    while(ok(i) == 0)
    {
        i++;
    }

    int flag = ok(i);

    printf("%d, %d, %d\n", i - 1, i, i + 1);
    printf("status: %d\n\n", flag);
    if (flag == 1)
    {
        printf("%d\n", i - 1);
        printf("%d\n", i);
        printf("%d\n", i + 1);

        if (((i - 1) % 7 == 0) && (i % 11 == 0) && ((i + 1) % 17 == 0))
        {
            printf("Checked.\n");
            return 0;
        }
        else
        {
            printf("ERROR.\n");
        }
        
    }
    if (flag == 1)
    {
        printf("%d - 17 = %d\n", i - 1, (i - 1) - 7);
        printf("%d - 11 = %d\n", i, i - 7);
        printf("%d - 7 = %d\n", i + 1, (i + 1) - 7);

        if (((i - 1) % 17 == 0) && (i % 11 == 0) && ((i + 1) % 7 == 0))
        {
            printf("Checked.\n");
            return 0;
        }
        else
        {
            printf("ERROR.\n");
        }
        
    }

    return 0;
}