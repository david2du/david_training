#include <bits/stdc++.h>
using namespace std;

int a[5010], b[5010];

int main(int argc, char const *argv[])
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);

    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            flag = false;
        }
    }

    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    

    return 0;
}
