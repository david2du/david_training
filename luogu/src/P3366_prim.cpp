#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int v;
    int w;
};

const int N = 5000 + 10;
vector<Edge> e[N];

struct Node
{
    int x;
    int dis;
    inline bool operator<(const Node &A) const
    {
        return dis < A.dis;
    }
    inline bool operator>(const Node &A) const
    {
        return dis > A.dis;
    }
};

bool inTr[N];

int prim(int n)
{
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({1, 0});
    int cnt = 0;
    int ans = 0;
    
    while (!pq.empty())
    {
        auto now = pq.top();
        pq.pop();
        if (inTr[now.x])
            continue;
        inTr[now.x] = true;
        cnt++;
        ans += now.dis;
        for (auto v : e[now.x])
        {
            if (!inTr[v.v])
                pq.push({v.v, v.w});
        }
    }
    
    if (cnt == n)
        return ans;
    return 0;
}

int main()
{
    int n = 0, m = 0;

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x = 0, y = 0, z = 0;
        cin >> x >> y >> z;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }
    int ans = prim(n);
    if (ans)
        cout << ans << endl;
    else
        cout << "orz" << endl;

    return 0;
}