#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int cnt;
    int top;
    bool operator<(const Node &A) const
    {
        return top < A.top;
    }
    bool operator>(const Node &A) const
    {
        return top > A.top;
    }

    Node() {}
    Node(int C, int T)
    {
        cnt = C;
        top = T;
    }
};

vector<Node> v;

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x = 0;
        cin >> x;
        auto pos = lower_bound(v.begin(), v.end(), Node(0, x));
        if (pos != v.end())
        {
            (pos->cnt)++;
            pos->top = x;
        }
        else
            v.push_back(Node(1, x));
    }
    cout << v[0].cnt << endl;

    return 0;
}