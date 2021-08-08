#include <bits/stdc++.h>
using namespace std;

vector<int> edge[110];
bool vst[110];

int dfs(int begin, int end, int step)
{
    if (begin == end)
    {
        return step;
    }

    step++;
    vst[begin] = true;

    for (int i = 0; i < edge[begin].size(); i++)
    {
        int chd = edge[begin][i];

        if (!vst[chd])
        {
            int t = dfs(chd, end, step);
            if (t)
            {
                return t;
            }
        }
    }

    vst[begin] = false;

    return -1;
}

int main()
{
    int n = 0, x = 0, y = 0;
    cin >> n >> x >> y;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            bool a = false;

            cin >> a;

            if (a)
            {
                edge[i].push_back(j);
            }
        }
    }

    cout << dfs(x, y, 0) - 1 << endl;

    return 0;
}