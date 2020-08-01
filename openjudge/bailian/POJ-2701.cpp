#include <iostream>
using namespace std;

int main()
{
    unsigned long long sum = 0;
    int n = 0;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        bool find = true;

        if (i % 7 == 0)
        {
            find = false;
        }
        int a = i;
        while (a != 0)
        {
            if (a % 10 == 7)
            {
                find = false;
                break;
            }
            a /= 10;
        }
        if (find)
        {
            sum += i * i;
        }
    }

    cout << sum << endl;

    return 0;
}