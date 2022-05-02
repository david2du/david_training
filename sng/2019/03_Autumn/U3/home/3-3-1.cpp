#include <bits/stdc++.h>//18min 46s
using namespace std;

int road[10001] = {0};
int mp[100][2] = {0};

int main()
{
    int l = 0, m = 0;
    int n = 0;
    int i = 0, j = 0;

    cin >> l >> m;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cin >> mp[i][j];
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = mp[i][0]; j <= mp[i][1]; j++)
        {
            road[j] = -1;
        }
    }

    for (i = 0; i < (l + 1); i++)
    {
        if (road[i] == 0)
        {
            n++;
        }
    }

    cout << n << endl;

    return 0;
}