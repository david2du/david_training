#include <bits/stdc++.h>
using namespace std;

struct Web
{
    string name;
    int front;
    int back;
};

Web web[50010];

int main()
{
    int m = 0, t = 0;
    char c = 0;
    int idx = 0;
    bool v = true;

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> c;

        if (c == 'v')
        {
            cin >> web[++t].name;
            cout << web[t].name << endl;
            web[t].front = idx;
            web[t].back = web[idx].back;
            web[idx].back = t;
            idx = t;
            v = true;
        }
        else if ((c == 'b') && (web[idx].front != 0))
        {
            if (t > 1)
            {
                cout << web[web[idx].front].name << endl;
                idx = web[idx].front;
                v = false;
            }
            else
            {
                cout << "?" << endl;
            }
        }
        else if (c == 'f')
        {
            if ((!v) && (web[idx].back != 0))
            {
                cout << web[web[idx].back].name << endl;
                idx = web[idx].back;
                v = false;
            }
            else
            {
                cout << "?" << endl;
            }
        }
        else
        {
            continue;
        }
    }

    return 0;
}