#include <bits/stdc++.h>
using namespace std;

bool fun(int a, int b)
{
    if ((a / b >= 2) || (a == b))
    {
        return true;
    }

    return !fun(b, a - b);
}

int main()
{
    int a = 0, b = 0;

    while ((cin >> a >> b) && ((a != 0) || (b != 0)))
    {
        if (a < b)
        {
            swap(a, b);
        }
        if (fun(a, b))
        {
            cout << "win" << endl;
        }
        else
        {
            cout << "lose" << endl;
        }
    }

    return 0;
}