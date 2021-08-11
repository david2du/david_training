#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
using namespace std;

struct Edge
{
    long long node;
    long long len;
};

vector<Edge> edge[100010];
long long in[100010];

long long prtme[100010]; // process time
long long lte[100010];

long long critical_path(long long n)
{
    queue<long long> q;

    for (long long i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            q.push(i);
            prtme[i] = 0;
        }
    }

    long long ans = 0;

    stack<long long> t;

    while (!q.empty())
    {
        long long now = q.front();
        q.pop();

        t.push(now);

        for (long long i = 0; i < edge[now].size(); i++)
        {
            long long v = edge[now][i].node, l = edge[now][i].len;
            prtme[v] = max(prtme[v], prtme[now] + l);
            ans = max(ans, prtme[v]);

            if (!(--in[v]))
            {
                q.push(v);
            }
        }
    }

    fill(lte, lte + n + 1, LLONG_MAX);
    lte[t.top()] = prtme[t.top()];

    while (!t.empty()) // reverse
    {
        long long u = t.top();
        t.pop();
        for (long long i = 0; i < edge[u].size(); i++)
        {
            lte[u] = min(lte[u], lte[edge[u][i].node] - edge[u][i].len);
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    long long n = 0, m = 0;

    cin >> n >> m;
    for (long long i = 0; i < m; i++)
    {
        long long x = 0, y = 0, z = 0;

        cin >> x >> y >> z;

        edge[x].push_back((Edge){y, z});
        in[y]++;
    }

    cout << critical_path(n) << endl;
    for (long long i = 1; i <= n; i++)
    {
        cout << prtme[i] << " " << lte[i] << endl;
    }

    return 0;
}