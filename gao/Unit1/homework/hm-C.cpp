#include <bits/stdc++.h>
using namespace std;

struct Stu
{
    string inf;
    int nxt;
    int pre;
};

Stu stu[100000];
int head, rear;
int tot;

void getInf()
{
    string s;

    while(s.compare("end") != 0)
    {
        getline(cin, s);

        if (s.compare("end") == 0)
        {
            break;
        }
        stu[tot].inf = s;

        tot++;
    }
}

void buildLink()
{
    int i = 0;

    getInf();

    stu[0].pre = -1;
    for (i = 0; i < tot; i++)
    {
        stu[i].pre = i - 1;

        if (i > 0)
        {
            stu[stu[i].pre].nxt = i;
        }
    }

    rear = tot - 1;
    stu[rear].nxt = -1;
}

void print()
{
    int i = rear;

    do
    {
        cout << stu[i].inf << endl;
        i = stu[i].pre;
    }
    while (stu[i].pre != -1);

    cout << stu[head].inf << endl;  
}

int main()
{
    buildLink();
    print();
    
    return 0;
}