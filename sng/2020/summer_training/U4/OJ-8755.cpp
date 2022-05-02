#include <bits/stdc++.h>
using namespace std;

const int WEIGHT[6] = {1, 2, 3, 5, 10, 20};
int num[6];
int ans[6];
set<int> s;

void dfs(int step, int last_sum)
{
    if (step == 6)
    {
        int sum = 0;
        for (int i = 0; i < 6; i++)
        {
            sum += ans[i];
        }

        s.insert(sum);

        return;
    }

    for (int i = 0; i <= num[step]; i++)
    {
        last_sum += (i * WEIGHT[step]);
        ans[step] = last_sum;
        dfs(step + 1, last_sum);
        last_sum -= (i * WEIGHT[step]);
    }
}

int main()
{
    for (int i = 0; i < 6; i++)
    {
        cin >> num[i];
    }

    dfs(0, 0);

    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }

    printf("Total=%d", s.size() - 1);

    return 0;
}