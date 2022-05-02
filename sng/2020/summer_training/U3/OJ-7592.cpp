#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 0, b = 0;

    cin >> a >> b;

    if (b > a)
    {
        swap(a, b);
    }
    while ((a % b != 0) && (b % a != 0))
    {
        a %= b;
        swap(a, b);
    }

    cout << min(a, b) << endl;

    return 0;
}