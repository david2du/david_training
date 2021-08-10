#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int node;
    int len;
};

vector<Edge> edge[100010];
int in[100010];

int prtme[100010]; // process time
int lte[100010];

int critical_path(int n)
{
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            q.push(i);
            prtme[i] = 0;
        }
    }

    int ans = 0;

    stack<int> t;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        t.push(now);

        for (int i = 0; i < edge[now].size(); i++)
        {
            int v = edge[now][i].node, l = edge[now][i].len;
            prtme[v] = max(prtme[v], prtme[now] + l);
            ans = max(ans, prtme[v]);

            if (!(--in[v]))
            {
                q.push(v);
            }
        }
    }

    fill(lte, lte + n + 1, INT_MAX);
    lte[t.top()] = prtme[t.top()];

    while(!t.empty()) // reverse
    {
        int u = t.top();
        t.pop();
        for (int i = 0; i < edge[u].size(); i++)
        {
            lte[u] = min(lte[u], lte[edge[u][i].node] - edge[u][i].len);
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 0, m = 0;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x = 0, y = 0, z = 0;

        cin >> x >> y >> z;

        edge[x].push_back((Edge){y, z});
        in[y]++;
    }

    cout << critical_path(n) << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << prtme[i] << " " << lte[i] << endl;
    }

    return 0;
}