#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int a[10] = {0};
    int b[10] = {0};
    int na = 0, nb = 0;

    for (int i = 0; i < 10; i++)
    {
        int n = 0;
        cin >> n;

        if (n % 2 == 1)
        {
            a[na++] = n;
        }
        else
        {
            b[nb++] = n;
        }
    }

    sort(a, a + na, cmp);
    sort(b, b + nb);

    for (int i = 0; i < na; i++)
    {
        cout << a[i] << " ";
    }
    for (int i = 0; i < nb; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}