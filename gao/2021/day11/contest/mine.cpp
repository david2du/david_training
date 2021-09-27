#include <iostream>
using namespace std;

double f[100010];
int a[100010];
int b[100010];

int main(int argc, char const *argv[])
{
    int n = 0, k = 0, c = 0, w = 0;

    cin >> n >> k >> c >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }

    for (int i = n; i > 0; i--)
    {
        if (a[i] == 1)
        {
            f[i] = max(f[i + 1], b[i] + f[i + 1] * (1 - 0.01 * k));
        }
        else
        {
            f[i] = max(f[i + 1], -b[i] + f[i + 1] * (1 + 0.01 * c));
        }
    }
    printf("%.2f", f[1] * (double)(w));

    return 0;
}
