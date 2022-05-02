#include <bits/stdc++.h>
using namespace std;

void opr(string s)
{
    vector<bool> ok;
    stack<int> stk;

    for (unsigned int i = 0; i < s.size(); i++)
    {
        ok.push_back(true);
        if (s[i] == '(')
        {
            ok[i] = false;
            stk.push(i);
        }
        else if (s[i] == ')')
        {
            if (!stk.empty())
            {
                ok[stk.top()] = true;
                stk.pop();
            }
            else
            {
                ok[i] = false;
            }
        }
        else
        {
            continue;
        }
    }

    for (unsigned int i = 0; i < ok.size(); i++)
    {
        if (ok[i])
        {
            cout << " ";
        }
        else
        {
            if (s[i] == '(')
            {
                cout << "$";
            }
            else
            {
                cout << "?";
            }
        }
    }

    cout << endl;
}

int main()
{
    string s;

    while (getline(cin, s))
    {
        cout << s << endl;
        opr(s);
    }

    return 0;
}