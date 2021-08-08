#include <bits/stdc++.h>
using namespace std;

const int MAXN = 128;

struct S
{
    int val;
    int nxt;
}s[MAXN];

int head, tot;

void insert(int p, int v)
{
    ++tot;
    s[tot].val = v;
    s[tot].nxt = s[p].nxt;
    s[p].nxt = tot;
}

void del(int p)
{
    s[p].nxt = s[s[p].nxt].nxt;
}

int get_pos(int k)
{
    int p = head;

    for (int i = 1; i < k; ++i)
    {
        p = s[p].nxt;
    }

    return p;
}

int main()
{
    int p = head;

    while(p)
    {
        printf("%d", s[p].val);
        p = s[p].nxt;
    }

    return 0;
}