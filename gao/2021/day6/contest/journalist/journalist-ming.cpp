#include <iostream>
#include <queue>
using namespace std;
 
struct Edge
{
    int to;
    int value;
    int next;
};
 
const int EDGE_MAX = 400010, NODE_MAX = 200010;
 
int bl[NODE_MAX];
 
Edge edge[EDGE_MAX];
int hd[NODE_MAX], nEdge;
 
int n, p, m;
 
void add(int from, int to, int value)
{
    edge[++nEdge] = (Edge){to, value, hd[from]};
    hd[from] = nEdge;
}
 
const int INF = 1e9; // infinity
 
int dst[NODE_MAX];     // distance
int cnt[NODE_MAX];     // count
bool in_que[NODE_MAX]; // in the queue
 
struct Bl
{
    int node;
    int bl;
 
    bool operator>(const Bl &A) const
    {
        return (A.node == node ? bl > A.bl : node > A.node);
    }
 
    bool operator<(const Bl &A) const
    {
        return (A.node == node ? bl < A.bl : node < A.node);
    }
};
 
Bl rdb[NODE_MAX];
 
bool SPFA(int start_Node)
{
    fill(dst, dst + n, INF);
 
    priority_queue<Bl, vector<Bl>, greater<Bl> > q;
 
    q.push((Bl){start_Node, bl[start_Node]});
    dst[start_Node] = 0;
    in_que[start_Node] = true;
    cnt[start_Node] = 1;
    rdb[start_Node]=(Bl){start_Node, bl[start_Node]};
 
    while (!q.empty())
    {
        int now = q.top().node;
        q.pop();
        in_que[now] = false;
 
        for (int i = hd[now]; i; i = edge[i].next)
        {
            int node = edge[i].to;
            int val = edge[i].value;
 
            if (dst[node] > (dst[now] + val))
            {
                rdb[node] = (Bl){now, bl[i]};
                dst[node] = dst[now] + val;
                cnt[node] = cnt[now] + 1;
 
                if (in_que[node])
                {
                    continue;
                }
                in_que[node] = true;
                q.push((Bl){node, bl[node]});
            }
 
            if (cnt[node] > n)
            {
                return true;
            }
        }
    }
 
    return false;
}
 
int A[NODE_MAX];
 
int main()
{
    freopen("journalist.in", "r", stdin);
    freopen("journalist.out", "w", stdout);
 
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> bl[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0, val = 0;
 
        cin >> a >> b >> val;
        add(a, b, val);
        add(b, a, val);
    }
 
    SPFA(1);
 
    int cnt = 0;
    for (int i = n; i != 1; i = rdb[i].node)
    {
        A[cnt++] = bl[i];
    }
    A[cnt++] = bl[1];
 
    cout << dst[n] << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
 
    return 0;
}