#include <iostream>
#include <utility>
using namespace std;

long long bit[32]; // BIT: one

int main(int argc, char const *argv[])
{
    long long n = 0;
    // freopen("mars.in", "r", stdin);
    // freopen("mars.out", "w", stdout);
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        long long a = 0;

        cin >> a;

        long long cnt = 0;
        while (a != 0)
        {
            if (a & 1)
            {
                bit[cnt]++;
            }

            a >>= 1;
            cnt++;
        }
    }

    long long ans = 0;
    for (long long i = 0; i < 32; i++)
    {
        ans += (bit[i] * (n - bit[i]) * (1LL << i));
    }

    cout << ans << endl;

    return 0;
}
