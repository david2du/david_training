#include <iostream>
#include <queue>
#include <vector>
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

bool vst[256];
int d[100010];
vector<Edge> edge[100010];

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

    // freopen("journey.in", "r", stdin);
    // freopen("journey.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int t = 0;

            cin >> t;

            if (i != j)
            {
                edge[i].push_back((Edge){i, j, t});
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int c = 0, x = 0, y = 0;

        cin >> c >> x >> y;

        if (c == 1)
        {
            vector<Edge>::iterator it;
            for (it = edge[x].begin(); it != edge[x].end(); it++)
            {
                if ((*it).b == y)
                {
                    break;
                }
            }

            if (it != edge[x].end())
            {
                edge[x].erase(it);
            }
        }
        else
        {
            fill(d, d + n + 1, INT_MAX);
            cout << Dij(x, y) << endl;
            fill(vst, vst + n + 1, false);
        }
    }

    return 0;
}