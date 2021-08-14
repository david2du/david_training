#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("maximum.in", "w", stdout);

    cout << 6 << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << 1e4 << " " << rand() % 3 + 1 << endl;
        for (int j = 0; j < (1e4); j++)
        {
            int a = rand() % (1 << 10) + 1;
            cout << a << endl;
        }
    }

    return 0;
}