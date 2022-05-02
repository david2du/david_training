#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 0;
    int count;

    cin >> num;

    while(num != 1)
    {
        if (num % 2 == 0)
        {
            num /= 2;
        }
        else
        {
            num -= 1;
        }
        count++;
    }

    cout << count << endl;

    return 0;
}