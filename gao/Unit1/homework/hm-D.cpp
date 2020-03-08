#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    int nxt;
};

const int N = 310;
Node link[N];
int front = 1;

void del(int countN)
{
    int pos = front;
    int count = 0;

    while (pos != 0)
    {
        ++count;

        if ((count + 1) % countN == 0)
        {
            link[pos].nxt = link[link[pos].nxt].nxt;
            count++;
        }

        if (link[pos].nxt == pos)
        {
            link[pos].nxt = 0;
            front = pos;
        }

        pos = link[pos].nxt;
    }
}

void build(int linkN)
{
    for (int i = front; i <= linkN; ++i)
    {
        link[i].val = i;
        link[i].nxt = (i + 1);
    }

    link[linkN].nxt = 1;
}

void reset(int linkN)
{
    for (int i = front; i <= linkN; ++i)
    {
        link[i].nxt = 0;
        link[i].val = 0;
    }

    front = 1;
}

int main()
{
    int linkN = -1, countN = -1;

    while ((linkN != 0) && (linkN != 0))
    {
        cin >> linkN >> countN;

        reset(linkN);

        if ((linkN == 0) && (linkN == 0))
        {
            break;
        }

        build(linkN);
        del(countN);
        cout << front << endl;
    }

    return 0;
}