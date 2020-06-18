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
            web[idx].back = t;
            web[t].front = idx;
            idx = t;
            v = true;
        }
        else if (c == 'b')
        {
            if (t > 1)
            {
                cout << web[web[idx].front].name << endl;
                idx = web[idx].front;
                v = false;
            }
        }
        else if (c == 'f')
        {
            if ((!v) && (web[idx].back != 0))
            {
                v = false;
                cout << web[web[idx].back].name << endl;
                idx = web[idx].back;
            }
            else
            {
                cout << "?" << endl;
            }
        }
    }

    return 0;
}