#include <iostream>
using namespace std;

int a[64];
int f[64][1010];

int main(int argc, char const *argv[])
{
    int n = 0, v = 0;

    cin >> n >> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (a[i] <= j)
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + a[i]);
            }
            else
            {
                f[i][j] = f[i - 1][j];
            }
        }
    }

    cout << v - f[n][v] << endl;

    return 0;
}