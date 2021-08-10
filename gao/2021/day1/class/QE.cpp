#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int a;
    int b;
    int val;
};

vector<Edge> edge[1010];

void 

int main(int argc, char const *argv[])
{
    int n = 0, m = 0;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0, d = 0;

        cin >> a >> b >> d;

        edge[a].push_back((Edge){a, b, d});
    }

    return 0;
}