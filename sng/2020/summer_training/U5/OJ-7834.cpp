#include <bits/stdc++.h>
using namespace std;

int fun(int a, int b)
{
    if (b > a)
    {
        swap(a, b);
    }
    while ((a % b != 0) && (b % a != 0))
    {
        a %= b;
        swap(a, b);
    }

    return min(a, b);
}

int num[16];
bool vst[16];

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num, num + n);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vst[i])
        {
            vst[i] = true;
            for (int j = (n - 1); j > i; j--)
            {
                if ((fun(num[i], num[j]) == 1) && (!vst[j]))
                {
                    num[i] *= num[j];
                    vst[j] = true;
                }
            }
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}