#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int node;
    int black;
    int dist;

    bool operator<(const Node &A) const
    {
        return (black == A.black) ? black < A.black : dist < A.dist;
    }

    bool operator>(const Node &A) const
    {
        return (black == A.black) ? black > A.black : dist > A.dist;
    }
};

struct Edge
{
    int a;
    int b;
    int val;
};

vector<Edge> edge[200010];

int blk[200010];
int dst[200010];
int fa[200010];
bool vst[200010];

int Dij(int s, int t)
{
    priority_queue<Node, vector<Node>, greater<Node> > pq;

    pq.push((Node){s, blk[s], 0});
    dst[s] = 0;

    while (!pq.empty())
    {
        Node u = pq.top();
        pq.pop();

        if (vst[u])
        {
            continue;
        }

        vst[Node] = true;

        for (int i = 0; i < edge[u].size(); i++)
        {
            int v = edge[u][i].b, di = edge[u][i].val;

            if (!vst[v] && dst[v] > (dst[u] + di))
            {
                dst[v] = dst[u] + di;
                fa[v] = u;
                //printf("d[%d], %d->%d\n", v, d[v] - di, d[v]);

                pq.push((Node){v, blk[v], dst[v]});
            }
        }
    }

    return (dst[t] == INT_MAX ? -1 : dst[t]);
}

int A[200010];

int main()
{
    int n = 0, m = 0;
    
    freopen("journalist.in", "r", stdin);
    freopen("journalist.out", "w", stdout);

    cin >> n >> m;
    cerr << n << m;
    for (int i = 0; i < n; i++)
    {
        cin >> blk[i];
    }
    cerr << n << endl;
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0, val = 0;

        cin >> a >> b >> val;
        edge[a].push_back((Edge){a, b, val});
    }
    cerr << n << endl;

    Dij(1, n);

    cerr << n << endl;
    int cnt = 0;
    for (int i = n; i != 1; i = fa[i])
    {
        cerr << n << endl;
        A[cnt++] = blk[i];
    }
    A[cnt++] = blk[1];

    cout << dst[n] << endl;
    for (int i = cnt; i >= 0; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}