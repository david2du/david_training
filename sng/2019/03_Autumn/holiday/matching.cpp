#include <bits/stdc++.h>
using namespace std;

char findLeft(char a)
{
    if (a == ')')
    {
        return '(';
    }
    else if (a == ']')
    {
        return '[';
    }
    else if (a == '}')
    {
        return '{';
    }
    else
    {
        return 0; // NULL
    }
}

int main()
{
    string s;
    stack<char> stk;
    char c[3] = {')', ']', '}'};

    getline(cin, s);

    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] == '(') ||
            (s[i] == '[') ||
            (s[i] == '{'))
        {
            stk.push(s[i]);
        }
        else if ((s[i] == ')') ||
                 (s[i] == ']') ||
                 (s[i] == '}'))
        {
            if (stk.top() == findLeft(s[i]))
            {
                stk.pop();
            }
            else
            {
                cout << "False" << endl;
                return 0;
            }
        }
        else
        {
            continue;
        }
    }

    cout << "True" << endl;

    return 0;
}