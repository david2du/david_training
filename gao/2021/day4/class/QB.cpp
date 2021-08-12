#include <iostream>
#include <map>
#include <math.h>
using namespace std;

int fa[1010];
int sze[1010];

int find(int x)
{
    if (fa[x] == 0)
    {
        return x;
    }

    return fa[x] = find(fa[x]);
}

int main(int argc, char const *argv[])
{
    int T = 0;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n = 0, m = 0;

        cin >> n >> m;

        fill(sze, sze + i, 1);

        for (int i = 0; i < m; i++)
        {
            int a = 0, b = 0;
            cin >> a >> b;
            fa[find(a)] = find(b);
        }

        for (int i = 1; i <= n; i++)
        {
            sze[find(i)]++;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += (int)ceil((double)sze[i] / 10.0);
        }
        fill(fa, fa + n + 1, 0);
        
        cout<< ans << endl;
    }

    return 0;
}