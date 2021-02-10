#include <bits/stdc++.h>
using namespace std;

int num[10];

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> num[i];
    }

    sort(num, num + 10);

    double ave = 0.0;

    for (int i = 1; i < 9; i++)
    {
        ave += (double)num[i];
    }

    cout << ave / 8.0 << endl;

    return 0;
}