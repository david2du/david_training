#include <bits/stdc++.h>
using namespace std;

int fib(int N)
{
    if (N == 0)
    {
        return 0;
    }
    if (N == 1)
    {
        return 1;
    }
    if (N > 1)
    {
        return fib(N - 1) + fib(N - 2);
    }
     return 0;
     
}

int main()
{
    int n = 0;

    cin >> n;

    cout << fib(n) << endl;

    return 0;
}