#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string s;
    string s1;
    string s2;
    string::size_type a = 0;
    string::size_type b = 0;

    getline(cin, s, ',');
    getline(cin, s1, ',');
    getline(cin, s2);

    a = s.find(s1);
    b = s.rfind(s2);

    if (((a + s1.size()) >= b) || (a == string::npos) || (b == string::npos))
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << b - a - s1.size() << endl;
    }

    return 0;
}