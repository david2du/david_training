#include <bits/stdc++.h>

using namespace std;

int ans[1024];

int main(int argc, char const *argv[])
{
    int n = 0, m = 0;

    freopen("kingdom.in", "r", stdin);
    freopen("kingdom.out", "w", stdout);

    cin >> n >> m;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int a = 0;
            cin >> a;

            ans[i] += (a * 2 - 1);
        }
    }

    int r = 0;
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        cin >> a;

        if ((a * 2 - 1) * ans[i] > 0)
        {
            r++;
        }
    }

    cout << r << endl;

    return 0;
}
