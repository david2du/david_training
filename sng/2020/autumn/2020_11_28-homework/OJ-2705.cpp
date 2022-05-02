#include <bits/stdc++.h>
using namespace std;

void opr(const string &s)
{
    vector<char> v; // output
    stack<int> stk; // save the index of the left-parenthesis

    for (unsigned int i = 0; i < s.size(); i++)
    {
        v.push_back(' ');
        if (s[i] == '(')
        {
            stk.push(i);
        }
        else if (s[i] == ')')
        {
            if (!stk.empty())
            {
                stk.pop();
            }
            else
            {
                v[i] = '?';
            }
        }
        else
        {
            continue;
        }
    }

    while (!stk.empty())
    {
        v[stk.top()] = '$';
        stk.pop();
    }

    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << endl;
}

int main()
{
    string s;

    while (cin >> s)
    {
        cout << s << endl;
        opr(s);
    }

    return 0;
}