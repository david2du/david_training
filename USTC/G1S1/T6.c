#include <stdio.h>
#include <stdbool.h>

const int MD[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int y = 0, m = 0, d = 0;

    scanf("%d,%d,%d", &y, &m, &d);

    bool leap = false;
    if ((y % 4 == 0) && ((y % 400 == 0) || (y % 100 != 0)))
        leap = true;
    if (m > 12 || m < 1 || d < 1 ||
        (leap && m == 2 && d > 29) || (!leap && m == 2 && d > 28) ||
        (m != 2 && d > MD[m]))
    {
        printf("Invalid\n");
        return 0;
    }
    int ly = (y - 1600 + 3) / 4 - (y - 1600 + 99) / 100 + (y - 1600 + 399) / 400;
    int day = 5 + ly + (y - 1600);

    for (int i = 1; i < m; ++i)
        day += MD[i];
    if (leap && (m > 2))
        day++;
    day += d;
    printf("%d\n", (day % 7 == 0 ? 7 : day % 7));

    return 0;
}