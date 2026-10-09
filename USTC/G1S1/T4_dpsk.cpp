#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    double e = 1.0;
    for (int i = 0; i < n; ++i)
        e /= 10.0;
    double pi = 0.0;
    double power = 1.0;
    double term;
    int k = 0;

    do {
        double a = 4.0 / (8.0 * k + 1.0);
        double b = 2.0 / (8.0 * k + 4.0);
        double c = 1.0 / (8.0 * k + 5.0);
        double d = 1.0 / (8.0 * k + 6.0);

        term = power * (a - b - c - d);
        pi += term;

        power /= 16.0;
        ++k;
    } while (term >= e);

    printf("pi=%.*lf\n", n, pi);
    return 0;
}