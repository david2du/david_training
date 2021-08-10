#include <bits/stdc++.h>
using namespace std;

struct Fish
{
    long long x;
    long long y;
};

Fish fish[30010];

void xm(long long l, long long r, long long d)
{
    for (long long i = l; i <= r; i++)
    {
        fish[i].x += d;
    }
}

void ym(long long l, long long r, long long d)
{
    for (long long i = l; i <= r; i++)
    {
        fish[i].y += d;
    }
}

long long x1, x2, y, y2;

long long ask(long long l, long long r)
{
    long long ans = 0;

    for (long long i = l; i <= r; i++)
    {
        ans += (((fish[i].x >= x1) && (fish[i].x <= x2)) && ((fish[i].y >= y) && (fish[i].y <= y2)));
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    long long t = 0;

    freopen("fish.in", "r", stdin);
    freopen("fish.out", "w", stdout);

    cin >> t;
    for (long long i = 0; i < t; i++)
    {
        long long n = 0;

        cin >> n >> x1 >> y >> x2 >> y2;

        for (long long j = 1; j <= n; j++)
        {
            cin >> fish[j].x >> fish[j].y;
        }

        long long m = 0;

        cin >> m;
        for (long long j = 0; j < m; j++)
        {
            long long a = 0, b = 0, c = 0;

            cin >> a >> b >> c;
            if (a == 3)
            {
                cout << ask(b, c) << endl;
            }
            else
            {
                long long d = 0;
                cin >> d;

                if (a == 1)
                {
                    xm(b, c, d);
                }
                else
                {
                    ym(b, c, d);
                }
            }
        }
    }

    return 0;
}