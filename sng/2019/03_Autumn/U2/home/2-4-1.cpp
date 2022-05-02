#include <bits/stdc++.h>
using namespace std;
int main()
{
    string sen;
    string modifiedw;
    string modifyw;
    string::size_type a = 0;

    getline(cin, sen);
    getline(cin, modifiedw);
    getline(cin, modifyw);

    a = sen.find(modifiedw);
    if (a != string::npos)
    {
        sen.replace(a, modifiedw.size(), modifyw);
    }
    else
    {
        cout << modifiedw << ", NOT FOUND" << endl << endl;
    }

    cout << sen << endl;

    return 0;
}