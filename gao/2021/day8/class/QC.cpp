#include <iostream>
using namespace std;

int v[128];
int t[128];
int f[128][1024];

int main(int argc, char const *argv[])
{
    int n = 0, vil = 0;

    cin >> vil >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> t[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= vil; j++)
        {
            if (v[i] <= j)
            {
                f[i][j] = max(f[i - 1][j - v[i]] + t[i], f[i - 1][j]);
            }
            else
            {
                f[i][j] = f[i - 1][j];
            }
        }
    }

    cout << f[n][vil] << endl;

    return 0;
}