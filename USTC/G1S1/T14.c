#include <stdio.h>

int cnt;
int now;

void print(int n)
{
    cnt++;
    now <<= 1;
    now += n;
    if (cnt == 8)
    {
        printf("%02x", now);

        cnt = 0;
        now = 0;
    }
}

int i2b(int x, int dig)
{
    int num[10];
    int cnt = 0;

    for (int i = 0; i < dig; ++i)
        num[i] = 0;
    while (x)
    {
        num[cnt++] = (x & 1);
        x >>= 1;
    }

    for (int i = dig - 1; i >= 0; --i)
    {
        print(num[i]);
    }
}

void flush()
{
    if (cnt > 0)
    {
        now <<= (8 - cnt);
        printf("%02x", now);
        cnt = 0;
        now = 0;
    }
}

void exch(char c, int cnt)
{
    static int one = 0;
    if (cnt == 1)
    {
        if (!one)
        {
            one = 1;
            i2b(0, 3);
        }
        i2b(c, 8);
        return;
    }
    if (one)
    {
        i2b(0, 3);
        one = 0;
    }

    for (int i = 0; i < (cnt / 8); ++i)
    {
        i2b(7, 3);
        i2b((int)c, 8);
    }
    if (cnt % 8)
    {
        i2b(cnt % 8 - 1, 3);
        i2b((int)c, 8);
    }
}

int main()
{
    freopen("A14s.txt", "r", stdin);
    freopen("A14t.txt", "w", stdout);

    char c = 0, l = 0;
    int cnt = 0;

    while ((c = getchar()) != EOF)
    {
        if (l == c || l == 0)
        {
            cnt++;
            l = c;
        }
        else
        {
            exch(l, cnt);
            cnt = 1;
            l = c;
        }
    }
    exch(l, cnt);
    flush();

    fclose(stdin);
    fclose(stdout);

    return 0;
}