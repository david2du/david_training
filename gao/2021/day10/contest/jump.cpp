#include <iostream>
using namespace std;

int x[760][760];
int f[760][760];

const int MOD = 1e9 + 7;

void solve(int n, int m)
{
    f[0][0] = 1;
    for (int i = 1; i < (n - 1); i++)
    {
        for (int j = 1; j < (m - 1); j++)
        {
            if (x[i][j] != x[0][0])
            {
                f[i][j] = f[0][0];
            }
        }
    }

    f[n - 1][m - 1] = (x[0][0] != x[n - 1][m - 1]);
    for (int i = 1; i < (n - 1); i++)
    {
        for (int j = 1; j < (m - 1); j++)
        {
            for (int k = i + 1; k < (n - 1); k++)
            {
                for (int l = j + 1; l < (m - 1); l++)
                {
                    if (x[k][l] != x[i][j])
                    {
                        f[k][l] += f[i][j];
                        f[k][l] = (f[k][l] >= MOD ? f[k][l] - MOD : f[k][l]);
                    }
                }
            }
        }
    }

    for (int i = 1; i < (n - 1); i++)
    {
        for (int j = 1; j < (m - 1); j++)
        {
            if (x[i][j] != x[n - 1][m - 1])
            {
                f[n - 1][m - 1] += f[i][j];
                f[n - 1][m - 1] %= MOD;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 0, m = 0, k = 0;

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x[i][j];
        }
    }

    solve(n, m);

    cout << f[n - 1][m - 1] << endl;

    return 0;
}
