#include <iostream>
using namespace std;

int a[3010];
int ans = 0;

bool dfs(int dif, int dep, int n, int g, int f)
{
    if (dep == n)
    {
        return true;
    }

    for (int i = 0; i <= dif; i++)
    {
        if ((a[dep] - i) % g != 0)
        {
            f--;
            if (f < 0)
            {
                f++;
                return false;
            }

            if (dfs(dif, dep + 1, n, g, f))
            {
                return true;
            }
            f++;
        }
        if (dfs(dif, dep + 1, n, g, f))
        {
            return true;
        }
    }

    return false;
}

int solve(int n, int k, int f)
{
    int g = 0;

    for (int i = 0; i < n; i++)
    {
        g += dfs(k, 1, n, i, f);
    }

    return g;
}

int main(int argc, char const *argv[])
{
    int t = 0;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n = 0, k = 0, f = 0;

        solve(n, k, f);
    }

    return 0;
}
