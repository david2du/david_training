#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0, i = 0, j = 0;
    int a = 0;
    int sum = 0, diff = 0;

    cin >> n >> i >> j;
    sum = i + j;
    diff = i - j;

    for (a = 1; a <= n; a++)
    {
        cout << "(" << i << "," << a << ")" << " ";
    }
    cout << endl;
    

    for (a = 1; a <= n; a++)
    {
        printf ("(%d,%d) ", a, j);
    }
    cout << endl;

    for (a = 1; a <= n; a++)
    {
        if (a - diff <= n && a - diff > 0)
        {
            printf ("(%d,%d) ", a,  a - diff);
        }
    }
    cout << endl;

    for (a = 1; a <= n; a++)
    {
        if (sum - a <= n && sum - a > 0)
        {
            printf ("(%d,%d) ", sum - a, a);
        }
    }
    cout << endl;

    return 0;
}