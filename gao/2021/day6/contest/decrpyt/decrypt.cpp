#include <iostream>
#include <string>
using namespace std;

struct Id
{
    int x;
    int y;
};

string s[1010][1010];

Id id[1010][1010];

int A[1010], B[1010];

int main(int argc, char const *argv[])
{
    //time_t a = clock();
    int n = 0, m = 0, q = 0;

    freopen("decrypt.in", "r", stdin);
    freopen("decrypt.out", "w", stdout);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
            id[i][j] = (Id){i, j};
        }
    }

    for (int i = 0; i < q; i++)
    {
        int x = 0, y = 0, x2 = 0, y2 = 0, l = 0, c = 0;

        cin >> x >> y >> x2 >> y2 >> l >> c;

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < c; j++)
            {
                swap(id[x + i][y + j], id[x2 + i][y2 + j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << s[id[i][j].x][id[i][j].y] << " ";
        }
        cout << endl;
    }

    //time_t b = clock();

    //cout << (double)(b - a) / (double)(CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
