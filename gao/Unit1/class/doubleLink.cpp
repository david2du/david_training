#include <bits/stdc++.h>
using namespace std;

const int MAXN = 128;

struct S
{
    int val;
    int pre;
    int nxt;
}s[MAXN];

int head, tot;

void insert(int p, int v)
{
    ++tot;
    s[tot].val = v;
    s[tot].nxt = s[p].nxt;
    s[p].nxt = tot;
    s[s[tot].nxt].pre = tot;
    s[tot].pre = p;
}

void del(int p)
{
    s[p].nxt = s[s[p].nxt].nxt;
    if (s[p].nxt == 0)
    {
        s[s[p].nxt].pre = p;
    }
}

int main()
{
    return 0;
}