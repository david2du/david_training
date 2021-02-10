#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;

int main()
{
    for (int i = 0; i < 26; i++)
    {
        char c = 0;

        cin >> c;
        mp[c] = i;
    }

    string s;
    cin >> s;

    int last = -1, cnt = 0;

    for (unsigned int i = 0; i < s.size(); i++)
    {
        if ((mp[s[i]] <= last) || (last == -1))
        {
            cnt++;
        }

        last = mp[s[i]];
    }

    cout << cnt << endl;

    return 0;
}