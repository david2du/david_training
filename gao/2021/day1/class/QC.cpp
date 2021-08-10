#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int node;
    int val;
};

vector<Edge> edge[10010];
int val[10010];
bool vst[10010];

int bfs(int s, int t, int n)
{
    deque<int> dq;

    fill(val, val +n +1, INT_MAX);

    dq.push_back(s);
    vst[s] = true;
    val[s] = 0;

    while (!dq.empty())
    {
        int now = dq.front();
        dq.pop_front();

        for (int i = 0; i < edge[now].size(); i++)
        {
            int nx = edge[now][i].node;
            val[nx] = min(val[nx], val[now] + edge[now][i].val);

            //printf("vst: %d\n", nx);

            if (!vst[nx])
            {
                vst[nx] = true;
                if (edge[now][i].val == 1)
                {
                    dq.push_back(nx);
                    //printf("backpush, %d", nx);
                }
                else
                {
                    dq.push_front(nx);
                    //printf("frontpush, %d", nx);
                }
            }
        }
    }

    return (val[t] == INT_MAX ? -1 : val[t]);
}

int main(int argc, char const *argv[])
{
    int n = 0, m = 0;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0, d = 0;

        cin >> a >> b >> d;

        edge[a].push_back((Edge){b, d});
        edge[b].push_back((Edge){a, d});
    }

    int s = 0, t = 0;

    cin >> s >> t;
    cout << bfs(s, t, n) << endl;

    return 0;
}