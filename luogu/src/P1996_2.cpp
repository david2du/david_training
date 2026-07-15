#include <bits/stdc++.h>
using namespace std;

/**
 * static list realized by array
 * @date 2026.7.7
 */

struct Node
{
    int val;
    Node *nxt;
    Node *prev;
};

Node lst[110];

void init(int n)
{
    for (int i = 1; i < n; i++)
    {
        lst[i].nxt = &lst[i + 1];
        lst[i].prev = &lst[i - 1];
        lst[i].val = i + 1;
    }
    lst[0].prev = &lst[n - 1];
    lst[0].nxt = &lst[1];
    lst[0].val = 1;
    lst[n - 1].nxt = &lst[0];
}

int main()
{
    int n = 0, m = 0;

    cin >> n >> m;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    init(n);
    Node *now = lst;
    int cnt = 0;
    while ((now->nxt) != now)
    {
        if (cnt == (m - 1))
        {
            (now->prev)->nxt = now->nxt;
            (now->nxt)->prev = now->prev;
            cout << (now->val) << " ";
        }
        cnt++;
        cnt %= m;
        now = now->nxt;
    }
    cout << now->val << endl;

    return 0;
}