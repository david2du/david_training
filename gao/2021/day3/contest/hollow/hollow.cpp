#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> edge[200010];

int vst[200010];

int findt(int now, int fa, int findn)
{
    if (now == findn)
    {
        return (vst[now]++);
    }

    for (int i = 0; i < edge[now].size(); i++)
    {
        if (edge[now][i] != fa)
        {
            int n = findt(edge[now][i], now, findn);
            if (n != -1)
            {
                return n + (vst[now]++);
            }
        }
    }

    return -1;
}

int findt2(int now, int fa, int findn, int last_step)
{
    if (now == findn)
    {
        return last_step + 1;
    }

    for (int i = 0; i < edge[now].size(); i++)
    {
        if (edge[now][i] != fa)
        {
            int n = findt2(edge[now][i], now, findn, last_step + 1);

            if (n != -1)
            {
                return n;
            }
        }
    }

    return -1;
}

int N_N(int a, int b, int c)
{
    findt(b, -1, a);
    return findt(b, -1, c);
}

int Y_U(int a, int b, int c)
{
    if ((a - b) >= 0 && ((c - b) >= 0))
    {
        return ((a > c ? (c - b + 1) : (a - b + 1)));
    }
    else if ((a - b) <= 0 && ((c - b) <= 0))
    {
        return ((a > c ? (b - a + 1) : (b - c + 1)));
    }
    return 1;
}

int N_Y(int a, int b, int c)
{
    return findt2(b, -1, a, 0);
}

int main(int argc, char const *argv[])
{
    clock_t A = clock();
    int n = 0, q = 0, num = 0;

    freopen("4.in", "r", stdin);
    freopen("hollow.out", "w", stdout);

    cin >> n >> q >> num;
    for (int i = 0; i < (n - 1); i++)
    {
        int a = 0, b = 0;

        cin >> a >> b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 0; i < q; i++)
    {
        int a = 0, b = 0, c = 0;

        cin >> a >> b >> c;

        if (num <= 10 || num == 20)
        {
            cout << N_N(a, b, c) << endl;
            /*for (int i = 1; i <= n; i++)
            {
                cout << vst[i] << " ";
            }
            cout << endl;*/
            fill(vst, vst + n + 1, 0);
        }
        else if (num <= 18 && num >= 11)
        {
            cout << Y_U(a, b, c) << endl;
        }
        else
        {
            cout << N_Y(a, b, c) << endl;
        }
    }

    clock_t B = clock();

    cout << (double)(B - A) / (double)(CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}