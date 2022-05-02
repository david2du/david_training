#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;

    cin >> n;

    int num[n] = {0};
    int b = 100;

    for (int i = 0; i < n; i++)
    {
        num[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
    cout << "b=" << b << endl;

    return 0;
}