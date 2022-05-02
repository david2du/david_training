#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, s1, s2;

    getline(cin, s, ',');
    getline(cin, s1, ',');
    getline(cin, s2);

    unsigned long long a = s.find(s1);
    unsigned long long b = s.rfind(s2);

    if ((a == string::npos) || (b == string::npos) || (b < (a + s1.size())))
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (b - (a + s1.size())) << endl;
    }

    return 0;
}