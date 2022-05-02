#include <bits/stdc++.h>
using namespace std;

int f[1024];
int num[1024];

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    f[0] = 1;
    for (int i = 1; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (num[i] > num[j])
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        //printf("f[%d]: %d\n", i, f[i]);
    }

    cout << *max_element(f, f + n) << endl;

    return 0;
}