#include <bits/stdc++.h>
using namespace std;

vector<int> m;
list<int> lst;

int main(int argc, char const *argv[])
{
    int n = 0;

    while (cin >> n)
    {
        for (int i = 0; i < (n - 1); i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << ' ';
            }
            cout << 'V';
            for (int j = 0; j < 2 * (n - i - 1) - 1; j++)
            {
                cout << ' ';
            }
            cout << 'V' << endl;
        }
        for (int j = 0; j < (n - 1); j++)
        {
            cout << ' ';
        }
        cout << 'V' << endl;
    }

    return 0;
}
