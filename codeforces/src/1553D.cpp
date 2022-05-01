#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t = 0;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s, t;

        cin >> s >> t;

        if (s.size() < t.size())
        {
            cout << "NO" << endl;
        }
        else if (s.substr(s.size() - t.size(), t.size()) == t)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}