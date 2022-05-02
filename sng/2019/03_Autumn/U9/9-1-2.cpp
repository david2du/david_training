#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;

    getline(cin, s1);
    
    s2 = s1;
    reverse(s2.begin(), s2.end());
    
    if (s1.compare(s2.c_str()) == 0)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}