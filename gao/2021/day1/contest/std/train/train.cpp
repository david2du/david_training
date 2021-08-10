#include <bits/stdc++.h>
using namespace std;

struct Train
{
    int a;
    int b;
    int c;

    int num(int time)
    {
        return a - b * time;
    }
};

int f[3010];
vector<Train> train;

int solve(int n, int t)
{
    train.clear();
    fill(f, f + n, 0);

    for (int i = 0; i < n; i++)
    {
        int a = 0, b = 0, c = 0;

        cin >> a >> b >> c;

        train.push_back((Train){a, b, c});
    }

    int ans = 0;
    for (int i = 0; i <= t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (train[j].c <= i)
            {
                f[i] = max(f[i], f[i - train[j].c] + train[j].num(i));
            }
        }
        ans = max(ans, f[i]);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int T = 0;

    freopen("train.in", "r", stdin);
    freopen("train.out", "w", stdout);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int n = 0, t = 0;

        cin >> n >> t;

        cout << solve(n, t) << endl;
    }

    return 0;
}