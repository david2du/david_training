#include <bits/stdc++.h>
using namespace std;

int mp[128][128];

const int DX[4] = {0, 0, -1, 1}, DY[4] = {-1, 1, 0, 0};

int n, m;

void dfs(int x, int y, int ndep)
{
    if (ndep == n)
    {
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + DX[i], ny = y + DY[i];

        if (((nx >= 0) && (nx < m)) && ((ny >= 0) && (ny < m)))
        {
            if (mp[nx][ny] == 1)
            {
                continue;
            }
            mp[nx][ny] = 2;

            // cout << "dep: " << ndep << endl;
            // for (int i = 0; i < m; i++)
            // {
            //     for (int j = 0; j < m; j++)
            //     {
            //         // ans += (mp[i][j] == 2);
            //         cout << mp[i][j];
            //     }
            //     cout << endl;
            // }
            // cout << endl;

            dfs(nx, ny, ndep + 1);
        }
    }
}

vector<pair<int, int>> coi;

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c = 0;

            cin >> c;

            switch (c)
            {
            case 'P':
                mp[i][j] = 0;
                break;

            case 'O':
                mp[i][j] = 1;
                /* code */
                break;

            case 'X':
                mp[i][j] = 2;
                coi.push_back(make_pair(i, j));
                /* code */
                break;

            default:
                break;
            }
        }
    }

    for (int i = 0; i < coi.size(); i++)
    {
        dfs(coi[i].first, coi[i].second, 0);
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += (mp[i][j] == 2);
            // cout << mp[i][j];
        }
        // cout << endl;
    }

    cout << ans << endl;

    return 0;
}
