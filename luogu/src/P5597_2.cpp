#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

struct Node
{
    int l;
    int r;
    Node()
    {
        l = 0;
        r = 0;
    }
    Node(int L, int R)
    {
        l = L;
        r = R;
    }
} tr[N];
int n;

void input() // 递归建树
{
    int c = getchar() - '0';
    int now = ++n;
    if (c & 1)
    {
        tr[now].l = n + 1;
        input();
    }
    if (c & 2)
    {
        tr[now].r = n + 1;
        input();
    }
}

Node tr2[N];
int dep[N];
int cnt;

int pos1; // 原树目标点
int pos2; // 并树目标点

/**
 * @brief 建立子树并集，并树每到达目标点，就回到根节点，并树动作与原树同步
 * @param u 原树编号
 * @param v 并树编号
 */
void dfs2(int u, int v)
{
    if (u == pos1)
        pos2 = v;
    if (v == pos2)
        v = 1;
    if (tr[u].l)
    {
        if (!tr2[v].l)
            tr2[v].l = ++cnt;
        dfs2(tr[u].l, tr2[v].l);
    }
    if (tr[u].r)
    {
        if (!tr2[v].r)
            tr2[v].r = ++cnt;
        dfs2(tr[u].r, tr2[v].r);
    }
}

int ans;

/**
 * @brief 遍历每一个目标点，计算深度
 * @param id 编号
 * @param dep 深度
 */
void dfs1(int id, int dep)
{
    if (id != 1)
    {
        pos1 = id;
        pos2 = 0;
        cnt = 1;
        fill(tr2, tr2 + n, Node(0, 0));
        dfs2(1, 1);
        ans = min(ans, (cnt * 2 - 2 - dep));
    }
    if (tr[id].l)
        dfs1(tr[id].l, dep + 1);
    if (tr[id].r)
        dfs1(tr[id].r, dep + 1);
}

int main()
{
    ans = INT_MAX;
    input();
    dfs1(1, 0);
    cout << ans << endl;

    return 0;
}