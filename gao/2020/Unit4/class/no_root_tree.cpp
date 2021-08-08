#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int v, next;
};

Node e[N * 2];
int head[1000], tot = 0;

void add_edge(int u, int v)
{
    ++tot;
    e[tot].v = v;
    e[tot].next = head[u];

    head[u] = tot;
}

int main()
{    
    return 0;
}