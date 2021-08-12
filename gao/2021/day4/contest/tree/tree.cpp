#include <iostream>
#include <queue>
using namespace std;

vector<long long> edge[100010];
priority_queue<long long, vector<long long>, greater<long long> > ring;
bool vst[1000010];

bool tryNode(long long x, long long now, long long fa)
{
    if (vst[now])
    {
        return false;
        ring.push(now);
    }

    for (long long i = 0; i < edge[now].size(); i++)
    {
        if (edge[now][i] != fa && (edge[now][i] != x))
        {
            if (tryNode(x, edge[now][i], now))
            {
                ring.push(now);
                return false;
            }
        }
    }

    return true;
}

vector<long long> good;

void normal(long long m, long long n)
{
    for (long long i = 1; i <= n; i++)
    {
        if (edge[i].size() == (m - n + 1))
        {
            if (tryNode(i, 1, -1))
            {
                good.push_back(i);
            }
        }
    }

    cout << good.size() << endl;
    for (long long i = 0; i < good.size(); i++)
    {
        cout << good[i] << " ";
    }
    cout << endl;
}

void minus1(long long n)
{
    vector<long long> one;

    for (long long i = 1; i <= n; i++)
    {
        if (edge[i].size() == 1)
        {
            one.push_back(i);
        }
    }

    if (one.size() == 2)
    {
        cout << 2 << endl
             << one[0] << " " << one[1] << endl;
    }
    else
    {
        cout << n - 1 << endl;
        for (long long i = 0; i < one.size(); i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

bool findring(long long now, long long fa)
{
    if (vst[now])
    {
        return true;
        ring.push(now);
    }

    for (long long i = 0; i < edge[now].size(); i++)
    {
        if (edge[now][i] != fa)
        {
            if (findring(edge[now][i], now))
            {
                ring.push(now);
                return true;
            }
        }
    }

    return false;
}

void equal_solve(long long n)
{
    for (long long i = 1; i <= n; i++)
    {
        if (edge[i].size() != 2)
        {
            findring(i, -1);
            for (long long i = 0; i < ring.size(); i++)
            {
                if (edge[ring.top()].size() == 2)
                {
                    cout << ring.top() << endl;
                }
                ring.pop();
            }
            return;
        }
    }

    cout << n << endl;
    for (long long i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    long long n = 0, m = 0;

    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    cin >> n >> m;
    for (long long i = 0; i < m; i++)
    {
        long long a = 0, b = 0;

        cin >> a >> b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    if (m == n - 1)
    {
        minus1(n);
    }
    else if (m == n)
    {
        equal_solve(n);
    }
    else
    {
        normal(m, n);
    }

    return 0;
}