#include <bits/stdc++.h>
using namespace std;

struct S
{
    int val;
    int nxt;
};

const int MAXN = 200000;
S s[MAXN];
int head, tot;
int num; 

void buildLink()
{
    int i = 0;
    
    for (i = 0; i < num; i++)
    {
        cin >> s[i].val;
        tot++;

        if (i > 0)
        {
            s[i - 1].nxt = (tot - 1);
        }
    }

    s[num - 1].nxt = -1;
}

void del(int n)
{
    int p = head, pre = -1;

    do
    {
        if (s[p].val == n)
        {
            if (pre != -1)
            {
                s[pre].nxt = s[p].nxt;
            }
            else
            {
                head = s[p].nxt;
            }
        }
        else
        {
            pre = p;
        }
        p = s[p].nxt;
    }
    while (p != -1);
}

void print()
{
    int p = head;

    if (head == -1)
    {
        cout << endl;
        return;
    }

    do
    {
        cout << s[p].val << " ";
        p = s[p].nxt;
    } while (p != -1);

    cout << endl;
}

int main()
{
    int deln = 0;

    cin >> num;
    buildLink();
    cin >> deln;

    del(deln);
    print();

    return 0;
}