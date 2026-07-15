#include <bits/stdc++.h>
using namespace std;

/**
 * Palindromic Automaton
 */

struct Node
{
    int fa;
    int fail;
    int len;
    int chd[26];
    int fn; // fail counts
    Node()
    {
        fa = 0;
        fail = 0;
        len = 0;
        fn = 0;
        memset(chd, 0, sizeof(chd));
    }
    Node(const int L, const int FA, const int F, const int FN = 0)
    {
        fa = FA;
        fail = F;
        len = L;
        fn = FN;
        memset(chd, 0, sizeof(chd));
    }
};

deque<char> s;
vector<Node> tr;
int last[2];

/**
 * 0: even pal
 * 1: odd pal
 */
void init()
{
    tr.push_back(Node(0, -1, 1));
    tr.push_back(Node(-1, -1, 1));
    last[0] = 1;
    last[1] = 1;
}

inline int c2i(char c)
{
    return c - 'a';
}

inline int getFail(int pos, bool back)
{
    if (back)
    {
        while (((int)s.size() - tr[pos].len - 2 < 0) || s[s.size() - tr[pos].len - 2] != s.back())
            pos = tr[pos].fail;
    }
    else
    {
        while ((int)tr[pos].len + 1 >= s.size() || s[tr[pos].len + 1] != s.back())
            pos = tr[pos].fail;
    }

    return pos;
}

/**
 * @param c
 * @param back true: push back, false: push front
 */
int push(char c, bool back)
{
    if (back)
        s.push_back(c);
    else
        s.push_front(c);
    int fa = getFail(last[back], back);
    int now = tr[fa].chd[c2i(c)];
    if (!now)
    {
        now = tr.size();
        int fl = tr[getFail(tr[fa].fail, back)].chd[c2i(c)]; // fl
        tr.push_back(Node(tr[fa].len + 2, fa, fl, tr[fl].fn + 1));
        tr[fa].chd[c2i(c)] = now;
    }
    if (s.size() == tr[now].len)
        last[!back] = now;
    last[back] = now;

    // return tr[now].len; // 最长回文
    return now; // 当前节点
}

int main()
{
    init();
    string str;
    cin >> str;
    int la = 0;
    for (int i = 0; i < str.size(); i++)
        printf("%d ", (la = tr[push((c2i(str[i]) + la) % 26 + 'a', true)].fn));

    return 0;
}