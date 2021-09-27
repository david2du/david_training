#include <iostream>
using namespace std;

struct P
{
    int h;
    int x1;
    int x2;
};

int a[100010];
P p[1024];

bool cmp(const P &A, const P &B)
{
    return A.h < B.h;
}

int main(int argc, char const *argv[])
{
    int n = 0;

    //freopen("platform.in", "r", stdin);
    //freopen("platform.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].h >> p[i].x1 >> p[i].x2;
        p[i].x2--;
    }
    sort(p, p + n, cmp);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += ((p[i].h - a[p[i].x1]) + (p[i].h - a[p[i].x2]));
        fill(a + p[i].x1, a + p[i].x2 + 1, p[i].h);
    }

    cout << ans << endl;

    return 0;
}