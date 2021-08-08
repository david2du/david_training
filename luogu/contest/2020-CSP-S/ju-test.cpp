#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll q = 0;

    for (int i = -4713; i < 1582; i++)
    {
        if (i == 0)
        {
            continue;
        }

        q += 365;
        if ((i < 0 && (i - 1) % 4) || ((i > 0) && i % 4))
        {
            q += 1;
        }
    }

    cout << q + 276 << endl;

    q = 0;

    
    
    return 0;
}