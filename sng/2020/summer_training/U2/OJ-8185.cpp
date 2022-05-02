#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    getline(cin, s);
    //cin >> s;

    bool digit = false;
    vector<int> num;
    int cnt = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= '0') && (s[i] <= '9'))
        {
            if (!digit)
            {
                if ((s[i] == '0'))
                {
                    continue;
                }
                num.push_back(s[i] - '0');
                cnt++;
                digit = true;
            }
            else
            {
                num[cnt] *= 10;
                num[cnt] += (s[i] - '0');
            }
        }
        else
        {
            digit = false;
        }
    }
    if (cnt == -1)
    {
        cout << "0" << endl;
    }

    sort(num.begin(), num.end());

    cout << num[0];
    for (int i = 1; i <= cnt; i++)
    {
        cout << "," << num[i];
    }
    cout << endl;

    return 0;
}