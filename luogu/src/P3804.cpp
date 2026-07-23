#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int len;
    int link;
    int chd[26];

    int cnt;  // 出现次数
    int lChd; // link child后缀链接树中的孩子数

    Node()
    {
        len = 0;
        link = -1;
        memset(chd, 0, sizeof(chd));

        cnt = 1;
        lChd = 0;
    }
    Node(int L)
    {
        len = L;
        link = -1;
        memset(chd, 0, sizeof(chd));

        cnt = 1;
        lChd = 0;
    }
};

vector<Node> tr;
int last; // last visited

void init()
{
    tr.push_back(Node());
}

inline void add(char ch)
{
    int now = tr.size();
    tr.push_back(Node(tr[last].len + 1));
    int c = ch - 'a';

    int p = last;
    int ans = 0;
    while (p != -1 && !tr[p].chd[c]) // 对于0节点也跑一下
    {
        tr[p].chd[c] = now;
        p = tr[p].link;
    }
    if (p == -1)
        tr[now].link = 0;
    else
    {
        int q = tr[p].chd[c];
        if (tr[q].len != tr[p].len + 1) // now的链接父节点q恰好有来自p主干其他分支的边，要分裂
        {
            int q2 = tr.size();
            tr.push_back(Node(tr[p].len + 1)); // 新节点，连上原来连在q并且再主干上的所有节点
            memcpy(tr[q2].chd, tr[q].chd, sizeof(tr[q].chd));
            tr[now].link = q2;
            while (p != -1 && tr[p].chd[c] == q)
            {
                tr[p].chd[c] = q2;
                p = tr[p].link;
            }
            tr[q2].link = tr[q].link;
            tr[q].link = q2;
            tr[q2].lChd++;
            tr[q2].cnt = 0;
        }
        else
            tr[now].link = q;
    }
    tr[tr[now].link].lChd++;
    last = now;
}

typedef long long ll;

ll solve()
{
    ll ans = 0LL;
    queue<int> q;
    for (int i = 1; i < tr.size(); i++)
    {
        if (!tr[i].lChd)
            q.push(i);
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (!now)
            break;
        if (tr[now].cnt > 1)
            ans = max(ans, (ll)(tr[now].cnt) * (ll)(tr[now].len))/*, printf("%lld %lld %lld\n", (ll)(tr[now].cnt),  (ll)(tr[now].len), ans)*/;
        int fa = tr[now].link;
        tr[fa].cnt += tr[now].cnt;
        tr[fa].lChd--;
        if (!tr[fa].lChd)
            q.push(fa);
    }
    return ans;
}

int main()
{
    // freopen("P3804_2.in", "r", stdin);
    string s;
    cin >> s;
    // cout << s.size() << endl;
    init();
    for (auto c : s)
        add(c);
    cout << solve() << endl;

    return 0;
}