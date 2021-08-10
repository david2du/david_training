#include <bits/stdc++.h>
using namespace std;

vector<int> edge[100010];
int in[100010];

vector<int> topo;

bool topo_sort(int n)
{
    priority_queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int now = q.top();
        q.pop();
        topo.push_back(now);

        for (int i = 0; i < edge[now].size(); i++)
        {
            if (!(--in[edge[now][i]]))
            {
                q.push(edge[now][i]);
            }
        }
    }

    return topo.size() == n;
}

int main(int argc, char const *argv[])
{
    int n = 0, m = 0;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x = 0, y = 0;

        cin >> x >> y;

        edge[x].push_back(y);
        in[y]++;
    }

    if (!topo_sort(n))
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 0; i < topo.size(); i++)
        {
            cout << topo[i] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}