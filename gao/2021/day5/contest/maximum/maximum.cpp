#include <iostream>
#include <vector>
using namespace std;

int n = 0, c = 0;

vector<int> a;

int opr(int x, int y)
{
    if (c == 1)
    {
        return x & y;
    }
    else if (c == 2)
    {
        return x ^ y;
    }
    else
    {
        return x | y;
    }
}

int solve()
{
    int maxn = 0;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            maxn = max(maxn, opr(a[i], a[j]));
            //printf("i:%d, j:%d, opr:%d, maxn: %d\n", i, j, opr(a[i], a[j]), maxn);
        }
    }
    a.clear();

    return maxn;
}

int main(int argc, char const *argv[])
{
    clock_t A = clock();
    int t = 0;

    freopen("maximum.in", "r", stdin);
    freopen("maximum.out", "w", stdout);

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &n, &c);
        for (int j = 0; j < n; j++)
        {
            int x = 0;

            scanf("%d", &x);
            a.push_back(x);
        }

        cout << solve() << endl;
    }

    clock_t B = clock();

    printf("%fs\n", (double)(B - A) / (double)CLOCKS_PER_SEC);

    return 0;
}