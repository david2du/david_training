#include <bits/stdc++.h>
using namespace std;

/**
 * dynamic list
 * @date 2026.7.7
 */

struct Node
{
    int val;
    Node *nxt;
    Node *prev;
};

void init(Node *now, int n)
{
    Node *head = now;
    for (int i = 0; i < (n - 1); i++, now = now->nxt)
    {
        now->nxt = new Node;
        (now->nxt)->prev = now;
        now->val = i + 1;
    }
    head->prev = now;
    now->nxt = head;
    now->val = n;
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

    Node *now = new Node;
    init(now, n);
    // for (int i = 0; i < 2 * n; i ++, now = now->nxt)
    //     cout << now ->val << endl;
    int cnt = 0;
    while ((now->nxt) != now)
    {
        if (cnt == (m - 1))
        {
            Node *prev = now->prev;
            (now->prev)->nxt = now->nxt;
            (now->nxt)->prev = now->prev;
            cout << (now->val) << " ";
            delete now;
            now = prev->nxt;
        }
        else
            now = now->nxt;
        cnt++;
        cnt %= m;
    }
    cout << now->val << endl;

    return 0;
}