#include <iostream>
using namespace std;

struct Edge
{
    int na; // node a
    int nb; // node b

    int value; // value of the edge
};

Edge e[200010];
int id[100010];
int n, m;

int root(int index)
{
    return (id[index] == index) ? index : id[index] = root(id[index]);
}

bool cmp(const Edge &A, const Edge &B)
{
    return A.value > B.value;
}

int kruskal()
{
    sort(e, e + m, cmp);

    int ans = 0;
    int side = 0;
    for (int i = 0; ((i < m) && (side < (n - 1))); i++)
    {
        int ra = root(e[i].na);
        int rb = root(e[i].nb);

        if (ra == rb)
            continue;
        ans += e[i].value;
        cout << i << endl;
        side++;

        id[ra] = rb;
    }

    return ans;
}

int main()
{
    int t = 0;

    //freopen("pipe.in", "r", stdin);
    //freopen("pipe.out", "w", stdout);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            id[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> e[i].na >> e[i].nb >> e[i].value;
        }
        cout << kruskal() << endl;
        fill (e, e +m + 1, (Edge){0, 0, 0});
    }

    return 0;
}