#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool ok(int a, int b, int c, int systems)
{
    ll n1, n2, n3;

    while (a > 0)
    {
        n1 *= systems;
        n1 += (a % 10);

        a /= 10;
    }
    while (b > 0)
    {
        n2 *= systems;
        n2 += (b % 10);

        b /= 10;
    }
    while (c > 0)
    {
        n3 *= systems;
        n3 += (c % 10);

        c /= 10;
    }

    return ((n1 + n2) == n3);
}

/**
 * find the number system
*/
int findSystem(int a, int b, int c)
{
    int mag = 1000; // magnification

    int l = 2, r = mag;
    int mid = l + (r - l) / 2;

    while (l != r)
    {
        }
}

int main()
{
    int a = 0, b = 0, c = 0;

    cin >> a >> b >> c;

    return 0;
}