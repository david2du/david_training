#include <bits/stdc++.h>
using namespace std;

int q[2][1000010], front[2], rear[2];
int n, k, p;

void push(int w, int x)
{
    q[w][rear[w]++] = x;

    if (rear[w] == 100000)
    {
        rear[w] = 0;
    }
}

int pop(int w)
{
    int ret = q[w][front[w]++];

    if (front[w] == 100000)
    {
        front[w] = 0;
    }

    return ret;
}

int main()
{
    scanf("%d%d%d", &n, &k, &p);

    for (int i = 1; i <= k; i++)
    {
        push(0, i);
    }

    for (int i = 1; i <= k / n; i++)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x = pop(0);

            if (j == n)
            {
                push(1, x);
            }

            for (int s = 1; s <= p; s++)
            {
                push(0, pop(0));
            }
        }
    }

    sort(q[1] + front[1], q[1] + rear[1]);

    for (int i = front[1]; i < rear[1]; i++)
    {
        printf("%d\n", q[1][i]);
    }

    return 0;
}