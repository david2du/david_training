#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u;
    int v;
    int w;
    inline bool operator<(const Edge &A) const
    {
        return w < A.w;
    }
    inline bool operator>(const Edge &A) const
    {
        return w > A.w;
    }
};

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

const int N = 5000 + 10;
int root[N];

inline int findRoot(int x)
{
    if (root[x] == x)
        return x;
    return root[x] = findRoot(root[x]);
}

int kruskal(int n)
{
    int cnt = 0;
    int ans = 0;

    for (int i = 1; i <= n; ++i)
        root[i] = i;
    while (!pq.empty() && (cnt < (n - 1)))
    {
        auto now = pq.top();
        pq.pop();
        int ru = findRoot(now.u), rv = findRoot(now.v);

        if (ru != rv)
        {
            root[ru] = rv;
            cnt++;
            ans += now.w;
        }
    }
    if (cnt == n - 1)
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
        pq.push({x, y, z});
    }
    int ans = kruskal(n);
    if (ans)
        cout << ans << endl;
    else
        cout << "orz" << endl;

    return 0;
}