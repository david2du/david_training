#include <bits/stdc++.h>
using namespace std;

int num[1024] = {0};

int main()
{
    int N = 0, i = 0, n = 0;
    int m = 0;

    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> n;
        num[n]++;
    }

    for (i = 0; i <= 1024; i++)
    {
        if (num[i] > 0)
        {
            m++;
        }
    }


    cout << m << endl;
    for (i = 0; i <= 1024; i++)
    {
        if (num[i] > 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}