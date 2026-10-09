#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main()
{
    int a = 0, b = 0, c = 0;

    scanf("%d,%d,%d", &a, &b, &c);
    if ((a + b > c) && (b + c > a) && (c + a > b))
    {
        int mx = max(a, max(b, c));
        int mn = min(a, min(b, c));
        int md = (a + b + c - mx - mn);
        if (mx * mx == (md * md + mn * mn))
        {
            printf("right triangle");
        }
        else if ((a == b) && (b == c))
        {
            printf("equilateral triangle\n");
        }
        else if ((a == b) || (b == c) || (c == a))
        {
            printf("isosceles triangle\n");
        }
        else
        {
            printf("normal triangle\n");
        }
    }
    else
    {
        printf("NOT triangle\n");
    }

    return 0;
}