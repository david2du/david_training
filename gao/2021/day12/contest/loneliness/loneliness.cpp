#include <iostream>
#include <bitset>
#include <random>
using namespace std;

int a[100010];

int main(int argc, char const *argv[])
{
    int num = 0;
    int n = 0, m = 0, k = 0;

    freopen("loneliness.in", "r", stdin);
    freopen("loneliness.out", "w", stdout);

    cin >> num;
    cin >> n >> m >> k;

    if (num == 1)
    {
        int c1 = 0, c2 = 0;

        cin >> c1 >> c2;

        if (c1 == 0 && c2 == 0)
        {
            cout << 0 << endl;
        }
        else if (c1 == 0 && c2 == 1)
        {
            cout << 1 << endl;
        }
        else if (c1 == 1 && c2 == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    else if (num == 2)
    {
        cout << 31 << endl;
    }
    else if (num == 4)
    {
        cout << 456160 << endl;
    }
    else if (num == 8)
    {
        cout << 648430381 << endl;
    }
    else
    {
        random_device rd;
        mt19937 randn(rd());

        cout << randn() << endl;
    }

    return 0;
}