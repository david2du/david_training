#include <iostream>
using namespace std;

int f(int m, int n)
{
    if ((m <= 1) || (n <= 1))
    {
        return 1;
    }

    if (m < n)
    {
        return f(m, m);
    }

    return f(m, n - 1) + f(m - n, n);
}
int main()
{
    int a = 0, m = 0, n = 0;

    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> m >> n;
        cout << f(m, n) << endl;
    }

    return 0;
}