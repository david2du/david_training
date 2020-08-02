#include <bits/stdc++.h>
using namespace std;

bool num(int n)
{
    int sum = 1;

    for (int i = 2; i <= (int)sqrt(n); ++i)
    {
        if ((n % i == 0) && (i != n))
        {
            sum += (i + n / i);
        }
    }

    return (sum == n);
}

int main()
{
    int n = 0;
    int sum = 0;

    cin >> n;

    for (int i = 2; i < n; ++i)
    {
        if (num(i))
        {
            ++sum;
            cout << i << endl;
        }
    }

    cout << "*" << sum << endl;

    return 0;
}