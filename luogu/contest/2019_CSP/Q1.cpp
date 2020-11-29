#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a = 0;
    long long b = 0, c = 0;

    cin >> a >> b >> c;

    unsigned long long s1 =(unsigned long long) a * a, s2 = (unsigned long long)b * c;

    if (s1 > s2)
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }
    

    return 0;
}