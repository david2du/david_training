#include <iostream>
using namespace std;
int main()
{
    int x = 0, p = 0, m = 0, i = 0, result = 0;

    cin >> x >> m >> p ;

    result = 1;
    while (p > 0)
    {
        if (p % 2 == 1)
        {
            result = result * x % m;
        }
        p /= 2;
        x = x * x % m;
    }
    cout << result << endl;

    return 0;
}
