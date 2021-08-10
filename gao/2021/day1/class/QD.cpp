#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int a;
    int b;
    int val;
};

struct Node
{
    int node;
    int dist;

    bool operator>(const Node &A) const
    {
        return dist > A.dist;
    }

    bool operator<(const Node &A) const
    {
        return dist < A.dist;
    }
};

bool vst[10010];
int d[10010];
vector<Edge> edge[10010];

int Dij(int s, int t)
{
    priority_queue<Node, vector<Node>, greater<Node> > pq;

    pq.push((Node){s, 0});
    d[s] = 0;

    while (!pq.empty())
    {
        int u = pq.top().node;
        pq.pop();

        if (vst[u])
        {
            continue;
        }

        vst[u] = true;

        for (int i = 0; i < edge[u].size(); i++)
        {
            int v = edge[u][i].b, di = edge[u][i].val;

            if (!vst[v] && d[v] > (d[u] + di))
            {
                d[v] = d[u] + di;
                //printf("d[%d], %d->%d\n", v, d[v] - di, d[v]);

                pq.push((Node){v, d[v]});
            }
        }
    }

    return (d[t] == INT_MAX ? -1 : d[t]);
}

int main(int argc, char const *argv[])
{
    int n = 0, m = 0;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0, d = 0;

        cin >> a >> b >> d;

        edge[a].push_back((Edge){a, b, d});
        edge[b].push_back((Edge){b, a, d});
    }

    int s = 0, t = 0;

    cin >> s >> t;

    fill(d, d + n + 1, INT_MAX);
    cout << Dij(s, t) << endl;

    return 0;
}