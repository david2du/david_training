#include <bits/stdc++.h>
using namespace std;

int main()
{
    string num;
    unsigned int i = 0, j = 0;
    int n = 0, r = 0;
    bool f = false;

    getline(cin, num);

    for (i = 2; i < 10; i++)
    {
        n = 0;
        r = 0;
        for (j = 0; j < num.size(); j++)
        {
            n += num[j] - '0';
            r = n % i;
            n = r * 10;
        }
        if (r == 0)
        {
            cout << i << " ";
            f = true;
        }
    }
    if (f == false)
    {
        cout << "none";
    }
    cout << endl;

    return 0;
}