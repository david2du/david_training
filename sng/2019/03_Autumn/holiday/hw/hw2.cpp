#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 0;
    
    for (i = 1; i < 100; ++i)
    {
        if ((i * 1000 + 999) % 23 == 0)
        {
            break;
        }
    }

    cout << i * 1000 + 999 << endl;

    return 0;
}