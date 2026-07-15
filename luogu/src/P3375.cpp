#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
string s1, s2;
int nxt[N]; // 0~(i - 1) prefix

void init() // calculate next
{
    /*
    for (int i = 1; i < s2.size(); i++)
    {
        int lst = i;
        while (s2[nxt[lst]] != s2[i] && nxt[lst])
            lst = nxt[lst];
        if (s2[nxt[lst]] == s2[i])
            nxt[i + 1] = nxt[lst] + 1;
        else
            nxt[i + 1] = 0;
    }
    */
    for (int i = 1; i < s2.size(); i++)
    {
        int lst = nxt[i];
        while (s2[lst] != s2[i] && lst)
            lst = nxt[lst];
        if (s2[lst] == s2[i])
            nxt[i + 1] = lst + 1;
        else
            nxt[i + 1] = 0;
    }
    
}

void match()
{
    int pos2 = 0;
    for (int i = 0; i < s1.size(); ++i)
    {
        while (pos2 && ((s1[i] != s2[pos2]) || (pos2 >= s2.size())))
            pos2 = nxt[pos2];
        if (s1[i] == s2[pos2])
            pos2++;
        if (pos2 == s2.size())
            cout << i + 2 - s2.size() << endl;
    }
}

int main()
{
    cin >> s1 >> s2;
    init();
    match();
    for (int i = 1; i <= s2.size(); ++i)
        cout << nxt[i] << " ";

    return 0;
}