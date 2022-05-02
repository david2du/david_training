#include <bits/stdc++.h>
using namespace std;

/*
answer: C. 80
*/

int opr(int num)
{
    return (num % 10) * 100 + (num / 10 % 10) * 10 + (num / 100);
}

int main()
{
    int ans = 0;

    for (int i = 100; i < 1000; ++i)
    {
        if (opr(i) - i == 99)
        {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}