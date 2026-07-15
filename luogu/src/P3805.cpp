#include <bits/stdc++.h>
using namespace std;

string prep(const string &s1)
{
    string s2;

    s2.push_back('@');
    s2.push_back('#');
    for (int i = 0; i < s1.size(); ++i)
    {
        s2.push_back(s1[i]);
        s2.push_back('#');
    }
    s2.push_back('$');

    return s2;
}

const int N = 11000010;

int l[N * 2];

int manacher(const string &s)
{
    int r_max = 0, pos = 0;
    int mx = 0;
    for (int i = 1; i < s.size(); ++i)
    {
        if (r_max > i)
            l[i] = min(l[2 * pos - i], r_max - i + 1);
        else
            l[i] = 1;
        while (s[i + l[i]] == s[i - l[i]])
            ++l[i];
        mx = max(mx, l[i]);
        if ((i + l[i] - 1) > r_max)
        {
            r_max = i + l[i] - 1;
            pos = i;
        }
    }

    return mx - 1;
}

int main()
{
    string s;
    cin >> s;
    cout << manacher(prep(s)) << endl;

    return 0;
}