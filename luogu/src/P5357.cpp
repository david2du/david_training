#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
string t[N];
int id[N];
int cnt[N];
string s;

struct Node
{
    int chd[26];
    int fail;
    bool end;
    int cnt;
    int ans;
    int fin;

    Node()
    {
        memset(chd, 0, sizeof(chd));
        fail = 0;
        end = false;
        cnt = 0;
        fin = 0;
        ans = 0;
    }
};

vector<Node> tr;

inline void add(string s, int c)
{
    int now = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (!tr[now].chd[s[i] - 'a'])
        {
            tr[now].chd[s[i] - 'a'] = tr.size();
            tr.push_back(Node());
        }
        now = tr[now].chd[s[i] - 'a'];
    }
    tr[now].end = true;
    id[c] = now;
}

inline void buildFail()
{
    queue<int> q;
    int lst[26];

    for (int i = 0; i < 26; ++i)
    {
        if (tr[0].chd[i])
            q.push(tr[0].chd[i]);
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < 26; ++i)
        {
            if (tr[now].chd[i])
            {
                if (tr[tr[tr[now].fail].chd[i]].end)
                    tr[tr[now].chd[i]].fin = tr[tr[now].fail].chd[i];
                else
                    tr[tr[now].chd[i]].fin = tr[tr[tr[now].fail].chd[i]].fin;
                tr[tr[now].chd[i]].fail = tr[tr[now].fail].chd[i];
                q.push(tr[now].chd[i]);
            }
            else
                tr[now].chd[i] = tr[tr[now].fail].chd[i]; // virtual node，代替了反复while的fail跳跃，更快，有类似kmp地回溯功能
        }
    }
}

vector<int> vst;

void match(const string &s)
{
    int now = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        int c = s[i] - 'a';
        now = tr[now].chd[c];
        if (!tr[now].cnt)
            vst.push_back(now);
        tr[now].cnt++;
    }
    for (int i = 0; i < vst.size(); ++i)
    {
        int tmp = vst[i];
        int val = tr[tmp].cnt;
        while (tmp)
        {
            tr[tmp].ans += val;
            tmp = tr[tmp].fin;
        }
    }
}

int main()
{
    tr.push_back(Node());
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i];
        add(t[i], i);
    }
    buildFail();
    cin >> s;
    match(s);
    for (int i = 0; i < n; ++i)
        cout << tr[id[i]].ans << endl;

    return 0;
}