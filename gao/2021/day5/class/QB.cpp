#include <iostream>
using namespace std;

struct Range
{
    int node;

    int l;
    int r;

    int mid()
    {
        return (l + r) / 2;
    }
};

const int MAXN = 100010;

int st[MAXN];

/**
 * Left Child
*/
int lc(int node)
{
    return node * 2;
}

/**
 * Right Child
*/
int rc(int node)
{
    return node * 2 + 1;
}

void push_up(int node)
{
    st[node] = st[lc(node)] + st[rc(node)];
}

void build(Range rt, int initN)
{
    if (rt.l == rt.r)
    {
        st[rt.node] = initN;
        return;
    }

    int mid = (rt.l + rt.r) / 2;

    build((Range){lc(rt.node), rt.l, mid}, initN);
    build((Range){lc(rt.node), mid + 1, rt.r}, initN);

    push_up(rt.node);
}

bool lazy[MAXN];

void push_down(int node)
{
    if (lazy[node])
    {
        st[lc(node)] = 0;
        st[rc(node)] = 0;
        lazy[lc(node)] = true;
        lazy[rc(node)] = true;
    }
}

void update(Range rt, int l, int r)
{
    if ((l > rt.r) || (r < rt.l))
    {
        return;
    }
    if ((l <= rt.l) && (r >= rt.r))
    {
        st[rt.node] = 0;
        lazy[rt.node] = true;
    }

    int mid = rt.mid();

    push_down(rt.node);

    update((Range){lc(rt.node), rt.l, mid}, l, r);
    update((Range){rc(rt.node), mid + 1, rt.r}, l, r);

    push_up(rt.node);
}

int query(Range rt, int l, int r)
{
    if ((l > rt.r) || (r < rt.l))
    {
        return 0;
    }
    if ((l <= rt.l) && (r >= rt.r))
    {
        return st[rt.node];
    }

    push_down(rt.node);

    int mid = rt.mid();

    return (query((Range){lc(rt.node), rt.l, mid}, l, r) +
            query((Range){rc(rt.node), mid + 1, rt.r}, l, r));
}

int main(int argc, char const *argv[])
{
    int l = 0, m = 0, q = 0;

    cin >> l;

    build((Range){0, 0, l}, 1);

    for (int i = 0; i < l; i++)
    {
    }

    return 0;
}