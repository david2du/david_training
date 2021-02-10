#include <bits/stdc++.h>
using namespace std;

/**
 * Even is Bigger than Odd.
*/
void ebo(int even, int odd)
{
    if (even == odd)
    {
        cout << odd * 2 << endl;
    }
    else
    {
        cout << odd * 2 + 1 << endl;
    }
}

int main()
{
    int n = 0;

    cin >> n;

    int even = 0, odd = 0;

    for (int i = 0; i < n; i++)
    {
        int a = 0;

        cin >> a;

        if (a % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    if (even >= odd)
    {
        ebo(even, odd);
        return 0;
    }

    while (even < odd)
    {
        odd -= 2;
        even += 1;
    }

    ebo(even, odd);

    return 0;
}