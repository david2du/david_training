#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int v[N], w[N], m[N];
int f[2][40010];

int main()
{
    int n = 0, W = 0;

    cin >> n >> W;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i] >> w[i] >> m[i];
    }
    int now = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int y = 0; y < w[i]; ++y)
        {
            int M = (W - y) / w[i];
            deque<int> dq;
            for (int x = 0; x <= M; ++x)
            {
                while (!dq.empty() && dq.front() < x - m[i])
                    dq.pop_front();
                while (!dq.empty() && (f[now ^ 1][dq.back() * w[i] + y] - v[i] * (dq.back())) <=
                                          (f[now ^ 1][x * w[i] + y] - v[i] * x))
                    dq.pop_back();
                dq.push_back(x);
                f[now][x * w[i] + y] = f[now ^ 1][dq.front() * w[i] + y] - v[i] * dq.front() + v[i] * x;
            }
        }
        now ^= 1;
    }
    cout << f[now ^ 1][W] << endl;

    return 0;
}