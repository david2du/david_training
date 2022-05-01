#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;

    int n = 0;

    cin >> n >> s;

    string tmp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'C' || s[i] == 'B')
        {
            tmp += s[i];
        }
        else
        {
            tmp += "BB";
        }
    }

    string ans;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == 'C')
        {
            ans += tmp[i];
        }
        else
        {
            if ((i + 1) < tmp.size())
            {
                if (tmp[i + 1] == 'B')
                {
                    ans += 'A';
                    i++;
                }
                else
                {
                    ans += 'B';
                }
            }
            else
            {
                ans += 'B';
            }
        }
    }

    cout << ans << endl;

    return 0;
}
