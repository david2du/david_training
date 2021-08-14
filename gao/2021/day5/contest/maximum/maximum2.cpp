#include <iostream>
#include <vector>
#include <set>
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

multiset<int> st;

void uni()
{
    multiset<int>::iterator it = st.begin(), it2;

    a.push_back(*(it));
    it++;
    a.push_back(*(it));
    it++;

    for(it2 = st.begin(); it != st.end(); it++, it2++)
    {
        if (*(it) != *(it2))
        {
            a.push_back(*it);
        }
    }

    st.clear();
}

int main(int argc, char const *argv[])
{
    clock_t A = clock();
    int t = 0;

    freopen("maximum.in", "r", stdin);
    freopen("maximum2.out", "w", stdout);

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &n, &c);
        for (int j = 0; j < n; j++)
        {
            int x = 0;

            scanf("%d", &x);
            st.insert(x);
        }
        uni();

        printf("%d\n", solve());
    }

    clock_t B = clock();

    printf("%fs\n", (double)(B - A) / (double)CLOCKS_PER_SEC);

    return 0;
}