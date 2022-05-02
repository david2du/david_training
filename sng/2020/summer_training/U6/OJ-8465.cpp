#include <bits/stdc++.h>
using namespace std;

const int MAX = 128;
bool vst[MAX][MAX];
int tr, tc; // total row, total column
int total;

const int DR[8] ={ -2, -1, 1, 2, 2, 1, -1, -2 };
const int DC[8] ={ 1, 2, 2, 1, -1, -2, -2, -1 };

int ans = 0;
void dfs(int r, int c, int last_step)
{
    //printf("Row: %d, Col: %d, visited, step: %d\n", r, c, last_step + 1);
    //vst[r][c] = true;
    if (last_step == total)
    {
        //printf("Succeed. Ruturn. ans: %d\n\n\n\n\n", ans + 1);
        ans++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        int nr = r + DR[i], nc = c + DC[i];

        if ((nr >= 0) && (nr < tr) && (nc >= 0) && (nc < tc) && (!vst[nr][nc]))
        {
            vst[r][c] = true;
            dfs(nr, nc, last_step + 1);
            vst[r][c] = false;
        }
    }

    //printf("\nReturn. Row: %d, Col: %d\n", r, c);
}

int main()
{
    int sr = 0, sc = 0; // start row, start column
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tr >> tc >> sr >> sc;
        total = tr * tc;

        dfs(sr, sc, 1);
        cout << ans << endl;
        ans = 0;
    }

    return 0;
}