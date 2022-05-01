#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    int m = 0;

    cin >> s >> m;

    string tmp;

    for (int i = s.size(); i > 0; i--)
    {
        int cnt = 0;
        char last = 0;
        multiset<char> st;

        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == last)
            {
                cnt++;
            }
            else
            {
                cnt = 1;
                last = s[j];
            }

            if (cnt >= i)
            {
                st.insert(s[j]);
                s.erase(j - i + 1, i);
                j -= i;
            }
        }
        // cout << endl
        //      << endl
        //      << s << endl
        //      << endl;

        for_each(st.begin(), st.end(), [i, &tmp](char x)
                 {
                    for (int pos = 0; pos < i; pos++)
                    {
                        tmp += x;
                    } });
    }

    int last = 0;
    int cnt = 0;
    string ans;
    for (int j = 0; j < tmp.size(); j++)
    {
        if (tmp[j] == last)
        {
            cnt++;
        }
        else
        {
            cnt = 1;
            last = tmp[j];
        }

        if (cnt <= m)
        {
            ans += tmp[j];
        }
    }

    cout << ans << endl;

    return 0;
}
