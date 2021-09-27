#include <iostream>
#include <queue>
using namespace std;

struct Edge
{
    long long to;
    long long value;
    long long next;
};

const long long EDGE_MAX = 100000, NODE_MAX = 110;

Edge edge[EDGE_MAX];
long long hd[NODE_MAX], nEdge;

long long n, p, m;

void add(long long from, long long to, long long value)
{
    edge[++nEdge] = (Edge){to, value, hd[from]};
    hd[from] = nEdge;
}

const long long INF = 1e9; // infinity

long long dst[NODE_MAX];     // distance
long long cnt[NODE_MAX];     // count
bool in_que[NODE_MAX]; // in the queue

bool SPFA(long long start_Node, long long addn)
{
    fill(dst, dst + n, INF);

    queue<long long> q;

    q.push(start_Node);
    dst[start_Node] = 0;
    in_que[start_Node] = true;
    cnt[start_Node] = 1;

    while (!q.empty())
    {
        long long now = q.front();
        q.pop();
        in_que[now] = false;

        for (long long i = hd[now]; i; i = edge[i].next)
        {
            long long node = edge[i].to;
            long long val = edge[i].value;

            if ((dst[node] + addn) > (dst[now] + val + addn))
            {
                dst[node] = dst[now] + val + addn;
                cnt[node] = cnt[now] + 1;

                if (in_que[node])
                {
                    continue;
                }
                in_que[node] = true;
                q.push(node);
            }

            if (cnt[node] > n)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    long long t = 0;

    cin >> t;
    for (long long i = 0; i < n; i++)
    {
        cin >> n >> m;

        long long minn = INT_MAX, maxn = INT_MIN;
        for (long long i = 0; i < m; i++)
        {
            long long a = 0, b = 0, val = 0;

            cin >> a >> b >> val;
            add(a, b, val);
            minn = min(minn, val);
            maxn = max(maxn, val);
        }

        long long ans = INT_MAX;
        long long last = INT_MAX;
        for (long long i = minn; i <= maxn; i++)
        {
            SPFA(1, -i);
            if (dst[n] < 0)
            {
                continue;
            }
            if (ans > last)
            {
                break;
            }

            last = ans;
            nEdge = 0;
            for (long long i = 1; i <= n; i++)
            {
                hd[i] = 0;
                cnt[i] = 0;
                in_que[i] = false;
            }
            for (long long i = 1; i <= m; i++)
            {
                edge[i].next = 0;
                edge[i].to = 0;
                edge[i].value = 0;
            }
        }

        cout << ans << endl;
    }

    return 0;
}