#include <bits/stdc++.h>
using namespace std;

string s;
int now[32];
bool vst[32];

void print()
{
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[now[i]];
    }
    cout << endl;
}

int cnt = 0;

void fun(int n)
{
    vst[n] = true;
    now[cnt++] = n;

    if (cnt == s.size())
    {
        print();
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (!vst[i])
        {
            fun(i);

            cnt--;
            vst[i] = false;
            now[cnt] = -1;
        }
    }

    return;
}

int main()
{
    cin >> s;

    fill(now, now + s.size(), -1);

    for (int i = 0; i < s.size(); i++)
    {
        fun(i);
        vst[i] = false;
        now[i] = -1;
        cnt = 0;
    }

    return 0;
}