#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char c[10] = {0};
    int n[10] = {0};

    scanf("%c-%c%c%c-%c%c%c%c%c-%c", &c[0], &c[1], &c[2], &c[3], &c[4], &c[5], &c[6], &c[7], &c[8], &c[9]);

    for (int i = 0; i < 10; i++)
    {
        if (c[i] == 'X')
        {
            n[i] = 10;
            continue;
        }
        n[i] = c[i] - '0';
    }

    int lstN = 0;

    for (int i = 0; i < 9; i++)
    {
        lstN += (n[i] * (i + 1));
    }
    lstN %= 11;

    if (lstN == n[9])
    {
        printf("Right\n");
    }
    else
    {
        printf("%d-%d%d%d-%d%d%d%d%d-", n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8]);
        if (lstN == 10)
        {
            printf("X\n");
        }
        else
        {
            printf("%d\n", lstN);
        }
    }

    return 0;
}