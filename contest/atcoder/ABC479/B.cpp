#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    string s;

    cin >> n >> s;
    int cnt = 0;
    int mx = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'R')
        {
            cnt++;
        }
        else
        {
            mx = max(mx, cnt);
            cnt = 0;
        }
    }
    mx = max(mx, cnt);
    cout << mx << endl;

    return 0;
}