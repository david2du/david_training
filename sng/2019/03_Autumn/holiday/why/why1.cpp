#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool pck[8] = {false}; // pick
    int n = 0;

    cin >> n;

    if (n >= 123)
    {
        n -= 123;
        pck[7] = true;
    }

    int i = 0;
    while (n > 0)
    {
        ++i;

        pck[i] = (n % 2);
        n /= 2;
    }

    for (int i = 0; i < 8; ++i)
    {
        if (pck[i])
        {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}