#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    int id;
    int l;
    int r;

    Node()
    {
        id = 0;
        l = 0;
        r = 0;
    }
    Node(int I, int L, int R)
    {
        id = I;
        l = L;
        r = R;
    }
};

// vector<Node> tr;
string s;
Node tr[1010];

// int build(int id)
// {
//     tr.push_back(Node(tr.size(), -1, -1));
//     auto &now = tr[tr.size() - 1];
//     if (s[id] == '0')
//         return id + 1;
//     if (s[id] == '1')
//     {
//         now.l = tr.size();
//         return build(id + 1);
//     }
//     else if (s[id] == '2')
//     {
//         now.r = tr.size();
//         return build(id + 1);
//     }
//     else
//     {
//         now.l = tr.size();
//         int t = build(id + 1);
//         now.r = tr.size();
//         return build(t);
//     }
// }

void build()
{
    stack<pair<int, int>> stk;

    stk.push(make_pair(0, s[0] - '0'));
    for (int i = 1; i < s.size(); i++)
    {
        tr[i].id = i;
        tr[i].l = -1;
        tr[i].r = -1;
        auto fa = stk.top();
        stk.pop();

        if (fa.second == 1)
            tr[fa.first].l = i;
        else if (fa.second == 2)
            tr[fa.first].r = i;
        else // 3
        {
            tr[fa.first].l = i;
            fa.second--;
            stk.push(fa);
        }
        if (s[i] != '0')
            stk.push(make_pair(i, s[i] - '0'));
    }

}

int main()
{
    cin >> s;
    build();
    // for (int i = 0; i < s.size(); i++)
    // {
    //     printf("%d %d %d\n", i, tr[i].l, tr[i].r);
    // }


    return 0;
}