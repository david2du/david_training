#include <bits/stdc++.h>
using namespace std;

struct Node
{
    vector<int> to;
    int len;
    int deg;
    int time;
    Node()
    {
        len = 0;
        deg = 0;
        time = 0;
    }
};

const int N = 10000 + 10;
Node node[N];

int ans;

inline void bfs(int n)
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        // printf("%d %d\n", i, node[i].len);
        if (!node[i].deg)
        {
            node[i].time = node[i].len;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (auto i : node[now].to)
        {
            node[i].deg--;
            node[i].time = max(node[i].time, node[i].len + node[now].time);
            ans = max(ans, node[i].time);
            if (!node[i].deg)
                q.push(i);
        }
    }
}

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x = 0;
        cin >> x;
        cin >> node[x].len;
        int t = 0;
        do
        {
            cin >> t;
            if (t)
            {
                node[x].to.push_back(t);
                node[t].deg++;
            }
        } while (t);
    }

    bfs(n);
    cout << ans << endl;

    return 0;
}