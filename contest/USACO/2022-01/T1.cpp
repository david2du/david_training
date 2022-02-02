#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll LMT = 52;

void dfs(ll ndep, ll com)
{
    if (ndep > LMT)
    {
        return;
    }

    dfs(ndep + 1, 1);

    if (com != 2)
    {
        dfs(ndep + 1, 3);
    }
    if (com != 3)
    {
        dfs(ndep + 1, 2);
    }
}

int main(int argc, char const *argv[])
{
    clock_t A = clock();
    dfs(0, 0);
    
    clock_t B = clock();

    cout << (double)(B - A) / (double)(CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
