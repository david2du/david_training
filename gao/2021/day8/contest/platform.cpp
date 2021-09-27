#include <iostream>
#include <algorithm>
using namespace std;

struct Board
{
    long long h;
    long long x1;
    long long x2;

    bool operator<(const Board &A) const
    {
        if (A.h != h)
        {
            return h < A.h;
        }
        if (x1 != A.x1)
        {
            return x1 < A.x1;
        }
        return x2 < A.x2;
    }

    bool operator>(const Board &A) const
    {
        if (A.h != h)
        {
            return h > A.h;
        }
        if (x1 != A.x1)
        {
            return x1 > A.x1;
        }
        return x2 > A.x2;
    }
};

Board b[1010];

long long s[100010];

int main(int argc, char const *argv[])
{
    long long n = 0;

    //freopen("platform.in", "r", stdin);
    //freopen("platform.out", "w", stdout);

    cin >> n;
    long long minn = INT_MAX, maxn = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> b[i].h >> b[i].x1 >> b[i].x2;
        --b[i].x2;
    }

    sort(b, b + n);

    long long ans = 0;
    for (long long i = n - 1; i >= 0; i--)
    {
        for (long long j = b[i].x1; j <= b[i].x2; j++)
        {
            ans -= s[j];
            s[j] = b[i].h;
            ans += s[j];
        }
    }

    cout << ans << endl;

    return 0;
}