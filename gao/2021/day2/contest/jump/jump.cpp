#include <bits/stdc++.h>
using namespace std;

set<long long> st;

void seive(long long h, long long x, long long y, long long z)
{
    long long a = max(max(x, y), z);
    long long c = min(min(x, y), z);
    long long b = x + y + z - a - c;

    for (long long i = 0; i <= (h / a); i++)
    {
        for (long long j = 0; j <= (h / b); j++)
        {
            if (i * a + j * b + 1 > h)
            {
                break;
            }

            for (long long k = 0; k <= (h / c); k++)
            {
                if (i * a + j * b + k * c + 1 > h)
                {
                    break;
                }

                st.insert(i * a + j * b + k * c + 1);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    long long h = 0;
    long long x = 0, y = 0, z = 0;

    //freopen("jump.in", "r", stdin);
    //freopen("jump.out", "w", stdout);

    cin >> h;
    cin >> x >> y >> z;

    seive(h, x, y, z);
    cout << st.size() << endl;

    return 0;
}