#include <iostream>
#include <algorithm>
using namespace std;

bool s2b(int a, int b)
{
    return a < b;
}

bool b2s(int a, int b)
{
    return a > b;
}

int main()
{
    int n[10] = {0}, a = 0;
    string compare;

    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> n[i];
    }
    cin >> compare;

    if (compare == "bts")
    {
        sort(n, n + a, b2s);
    }
    else
    {
        sort(n, n + a, s2b);
    }
    
    for (int i = 0; i < a; i++)
    {
        cout << n[i];
    }

    return 0;
}