#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const int N = 10000;
int n, m, blocksize, st[N], b[N];

struct Node
{
    int d[1003]; // d:原数据
    int s[1003]; // s:排序后的数据
    int rev;     // rev:是否翻转
    int delta;   // delta:每个元素都增加
    int same;    // same:每个元素都修改
    ll sum;      // sum:和
    int size;    // size:元素个数
    int nxt;     // nxt:下一块

    void clear()
    {
        sum = 0;
        rev = 0;
        delta = 0;
        same = 0;
        size = 0;
        nxt = -1;
    }
};

Node a[N];
queue<int> q;

int newnode()
{
    int t = q.front();
    q.pop();
    return t;
}

void del(int x)
{
    q.push(x);
    a[x].clear();
}

void init()
{
    for (int i = 1; i < N; i++)
    {
        q.push(i);
    }
    a[0].nxt = -1;
    a[0].size = 0;
}

void find(int &pos, int &now)
{
    for (now = 0; a[now].nxt != -1 && pos > a[now].size; now = a[now].nxt)
    {
        pos -= a[now].size;
    }
}

void push(int now)
{
    if (a[now].rev)
    {
        a[now].rev = 0;
        for (int i = 1; i <= a[now].size / 2; i++)
        {
            swap(a[now].d[i], a[now].d[a[now].size - i + 1]);
        }
    }
    if (a[now].same)
    {
        for (int i = 1; i <= a[now].size; i++)
        {
            a[now].d[i] = a[now].same;
        }
        a[now].sum = a[now].size * a[now].same;
        a[now].same = 0;
    }
    if (a[now].delta)
    {
        for (int i = 1; i <= a[now].size; i++)
        {
            a[now].d[i] += a[now].delta;
        }
        a[now].sum += a[now].size * a[now].delta;
        a[now].delta = 0;
    }
}

void update(int x)
{
    a[x].sum = 0;
    for (int i = 1; i <= a[x].size; i++)
    {
        a[x].s[i] = a[x].d[i];
        a[x].sum += a[x].d[i];
    }
    sort(a[x].s + 1, a[x].s + 1 + a[x].size); //维护顺序
}

void merge(int now) //now+now.nxt ---> now
{
    int t = a[now].nxt;
    push(now);
    push(t);
    for (int i = 1; i <= a[t].size; i++)
    {
        a[now].d[++a[now].size] = a[t].d[i];
    }
    a[now].nxt = a[t].nxt;
    del(t);
    update(now);
}

void maintain(int now) //合并小块
{
    for (; now != -1; now = a[now].nxt)
    {
        if (a[now].nxt != -1 && a[now].size + a[a[now].nxt].size <= blocksize)
        {
            merge(now);
        }
    }
}

void divide(int now, int pos) //分裂 pos分到了下一块
{
    push(now);
    int t = newnode();
    for (int i = pos; i <= a[now].size; i++)
    {
        a[t].d[++a[t].size] = a[now].d[i];
    }
    a[t].nxt = a[now].nxt;
    a[now].nxt = t;
    a[now].size = max(pos - 1, 0);
    update(t);
    update(now);
}

void insert(int pos, int val)
{
    int now;
    pos++;
    find(pos, now);
    divide(now, pos);
    a[now].d[++a[now].size] = val;
    update(now);
    maintain(now);
}

void erase(int pos)
{
    int now;
    find(pos, now);
    push(now);
    for (int i = pos; i < a[now].size; i++)
    {
        a[now].d[i] = a[now].d[i + 1];
    }
    a[now].size--;
    update(now);
    maintain(now);
}

void solve(int l, int r, int &lp, int &rp)
{
    int pos = l;
    find(pos, lp);
    divide(lp, pos);
    pos = r + 1;
    find(pos, rp);
    divide(rp, pos);
    pos = r;
    find(pos, rp);
}

void reverse(int x, int y)
{
    int lp, rp;
    solve(x, y, lp, rp);
    int now = lp, top = 0;
    for (int i = a[lp].nxt; i != a[rp].nxt; i = a[i].nxt)
    {
        st[++top] = i, a[i].rev ^= 1;
    }

    a[st[1]].nxt = a[rp].nxt; //整个区间翻转
    for (int i = top; i > 1; i--)
    {
        a[st[i]].nxt = st[i - 1];
    }
    a[lp].nxt = rp;
    maintain(lp);
}

void move(int x, int y, int z)
{
    int lp, rp, mp, np;
    solve(x, y - z, lp, mp);
    solve(y - z + 1, y, mp, rp);
    np = a[lp].nxt;
    a[lp].nxt = a[mp].nxt;
    a[mp].nxt = a[rp].nxt;
    a[rp].nxt = np;
    maintain(lp);
}

void add(int x, int y, int z)
{
    int lp, rp;
    solve(x, y, lp, rp);
    for (int i = a[lp].nxt; i != a[rp].nxt; i = a[i].nxt)
    {
        a[i].delta += z;
        a[i].sum += a[i].size * z;
    }
    maintain(lp);
}

void same(int x, int y, int z)
{
    int lp, rp;
    solve(x, y, lp, rp);
    for (int i = a[lp].nxt; i != a[rp].nxt; i = a[i].nxt)
    {
        a[i].delta = 0;
        a[i].same = z;
        a[i].sum = a[i].size * z;
    }
    maintain(lp);
}

ll sum(int x, int y)
{
    int lp, rp;
    solve(x, y, lp, rp);
    ll ans = 0;
    for (int i = a[lp].nxt; i != a[rp].nxt; i = a[i].nxt)
    {
        ans += a[i].sum;
    }
    maintain(lp);
    return ans;
}

int range(int x, int y)
{
    int lp, rp;
    solve(x, y, lp, rp);
    int mn = INF, mx = -INF;
    for (int i = a[lp].nxt; i != a[rp].nxt; i = a[i].nxt)
        if (a[i].size)
        {
            if (a[i].same)
            {
                mn = min(mn, a[i].same + a[i].delta); //可能没有push
                mx = max(mx, a[i].same + a[i].delta);
            }
            else
            {
                mn = min(mn, a[i].s[1] + a[i].delta);
                mx = max(mx, a[i].s[a[i].size] + a[i].delta);
            }
        }
    maintain(lp);
    return mx - mn;
}

int near(int x, int y, int z)
{
    int lp, rp;
    solve(x, y, lp, rp);
    int ans = INF;
    for (int i = a[lp].nxt; i != a[rp].nxt; i = a[i].nxt)
    {
        if (a[i].same)
        {
            ans = min(ans, abs(a[i].same + a[i].delta - z));
        }
        else
        {
            int x = lower_bound(a[i].s + 1, a[i].s + a[i].size + 1, z - a[i].delta) - a[i].s;
            if (x != a[i].size + 1)
            {
                ans = min(ans, abs(a[i].s[x] + a[i].delta - z));
            }
            if (x != 1)
            {
                x--, ans = min(ans, abs(a[i].s[x] + a[i].delta - z));
            }
        }
    }
    maintain(lp);
    return ans;
}

int min_k(int x, int y, int z)
{
    int lp, rp;
    solve(x, y, lp, rp);
    int L = 0, R = INF, ans;
    while (L < R)
    {
        int M = ((L + R) >> 1) + 1;
        int sum = 1; //排名
        for (int i = a[lp].nxt; i != a[rp].nxt; i = a[i].nxt)
        {
            if (a[i].same)
            {
                if (a[i].same + a[i].delta < M)
                    sum += a[i].size;
            }
            else
            {
                int x = upper_bound(a[i].s + 1, a[i].s + a[i].size + 1, M - a[i].delta - 1) - a[i].s;
                sum += max(x - 1, 0);
            }
        }
        if (sum <= z)
        {
            L = M;
        }
        else
        {
            R = M - 1;
        }
    }
    maintain(lp);
    return L;
}

int ask_xiao(int x, int y, int z)
{
    int lp, rp;
    solve(x, y, lp, rp);
    int ans = 0;
    for (int i = a[lp].nxt; i != a[rp].nxt; i = a[i].nxt)
    {
        if (a[i].same)
        {
            if (a[i].same + a[i].delta < z)
                ans += a[i].size;
        }
        else
        {
            int x = upper_bound(a[i].s + 1, a[i].s + a[i].size + 1, z - a[i].delta - 1) - a[i].s;
            ans += max(x - 1, 0);
        }
    }
    maintain(lp);
    return ans;
}

int main()
{
    scanf("%d", &n);
    int opt, x, y, z;
    blocksize = sqrt(n);
    init();
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        insert(i - 1, x); //从0开始
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &opt);
        switch (opt)
        {
        case 1: // 在x后插入val
            scanf("%d%d", &x, &y);
            insert(x, y);
            break;

        case 2: // 删除第x个数
            scanf("%d", &x);
            erase(x);
            break;

        case 3: // 翻转第x个到第y个数
            scanf("%d%d", &x, &y);
            reverse(x, y);
            break;

        case 4: // 向右移动第x个到第y个
            scanf("%d%d%d", &x, &y, &z);
            move(x, y, z);
            break;

        case 5: // 第x个到第y个数加val
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
            break;

        case 6: // 第x个到第y个数改为val
            scanf("%d%d%d", &x, &y, &z);
            same(x, y, z);
            break;

        case 7: // 回答第x个到第y个数的和
            scanf("%d%d", &x, &y);
            printf("%lld\n", sum(x, y));
            break;

        case 8: // 回答第x个到第y个数最大值与最小值的差
            scanf("%d%d", &x, &y);
            printf("%d\n", range(x, y));
            break;

        case 9: // 回答第x个到第y个数与val的差的绝对值的最小值
            scanf("%d%d%d", &x, &y, &z);
            printf("%d\n", near(x, y, z));
            break;

        case 10: // 回答第x个到第y个数中第k小的数
            scanf("%d%d%d", &x, &y, &z);
            printf("%d\n", min_k(x, y, z));
            break;

        case 11: // 回答第x个到第y个数比val小的数的个数
            scanf("%d%d%d", &x, &y, &z);
            printf("%d\n", ask_xiao(x, y, z));
            break;

        default:
            break;
        }
    }

    return 0;
}