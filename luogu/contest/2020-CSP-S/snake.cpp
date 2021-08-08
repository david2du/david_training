#include <bits/stdc++.h>
using namespace std;

map<int, int, less<int> > snk;

void opr()
{
    
}

int main(int argc, char const *argv[])
{
    int t = 0;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        if (i == 0)
        {
            int n = 0;

            cin >> n;
            for (int i = 1; i <= n; i++)
            {
                int a = 0;
                cin >> a;
                snk[i] = a;
            }
            opr();
        }
        else
        {
            int k = 0;

            cin >> k;
            for (int i = 1; i <= k; i++)
            {
                int x = 0, y = 0;
                cin >> x >> y;
                snk[x] = y;
            }
            opr();
        }
    }

    return 0;
}