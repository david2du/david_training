#include <iostream>
using namespace std;

long long a[1000010];

int main(int argc, char const *argv[])
{
    long long n = 0;

    // freopen("mars.in", "r", stdin);
    // freopen("mars.out", "w", stdout);

    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long ans = 0;
    for (long long i = 0; i <= n; i++)
    {
        for (long long j = i + 1; j < n; j++)
        {
            ans += (a[i] ^ a[j]);
        }
    }

    cout <<ans << endl;

    return 0;
}