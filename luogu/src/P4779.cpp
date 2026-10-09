#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
struct Edge
{
    int v;
    int w;
    Edge() {};
    Edge(int V, int W)
    {
        v = V;
        w = W;
    }
};

vector<Edge> e[N];

struct Node
{
    int u;
    int dst;
    inline bool operator<(const Node &A) const
    {
        return dst < A.dst;
    }
    inline bool operator>(const Node &A) const
    {
        return dst > A.dst;
    }
};

int dst[N];
bool vst[N];

void dij(int ori)
{
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dst[ori] = 0;
    pq.push({ori, 0});

    while (!pq.empty())
    {
        int now = pq.top().u;
        pq.pop();
        if (vst[now])
            continue;
        vst[now] = true;
        for (auto v : e[now])
        {
            if (dst[v.v] > dst[now] + v.w)
            {
                dst[v.v] = dst[now] + v.w;
                pq.push({v.v, dst[v.v]});
            }
        }
    }
}

int main()
{
    int n = 0, m = 0, s = 0;

    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i)
    {
        int u = 0, v = 0, w = 0;
        cin >> u >> v >> w;
        e[u].push_back(Edge(v, w));
    }
    fill(dst, dst + n + 1, INT_MAX);
    dij(s);
    for (int i = 1; i <= n; ++i)
        cout << dst[i] << " ";
    cout << endl;

    return 0;
}