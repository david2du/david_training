#include <bits/stdc++.h>
using namespace std;

int n;

int cow[32];
int hei[32];
bool vst[32];

long long cnt;

int cowmin[32];

void fun(int step, int now)
{
    if (step == n - 1)
    {
        cnt++;
        return;
    }

    step++;
    vst[now] = true;

    if (n - cowmin[step] + 1 < (n - step + 1))
    {
        return;
    }

    for (int i = cowmin[step]; i < n; i++)
    {
        if (!vst[i])
        {
            fun(step, i);
        }
    }
    vst[now] = false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cow[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> hei[i];
    }
    sort(cow, cow + n);
    sort(hei, hei + n);

    for (int i = 0; i < n; i++)
    {
        cowmin[i] = lower_bound(hei, hei + n, cow[i]) - hei;
    }

    for (int i = cowmin[0]; i < n; i++)
    {
        fun(0, i);
    }

    cout << cnt << endl;

    return 0;
}