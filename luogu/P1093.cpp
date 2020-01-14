#include <bits/stdc++.h>
using namespace std;

struct Stu
{
    int ch;
    int ma;
    int en;
    int sum;
    int stuNum;
};

bool cmp(Stu a, Stu b)
{
    return (a.sum > b.sum) ||
           ((a.sum == b.sum) && (a.ch > b.ch)) ||
           ((a.sum == b.sum) && (a.ch == b.ch) && (a.stuNum < b.stuNum));
}

int main()
{
    Stu stu[300];
    int n = 0;
    int i = 0;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        stu[i].stuNum = i + 1;
        cin >> stu[i].ch >> stu[i].ma >> stu[i].en;
        stu[i].sum = stu[i].ch + stu[i].ma + stu[i].en;
    }

    sort(stu, stu + n, cmp);
    for (i = 0; i < 5; i++)
    {
        cout << stu[i].stuNum << " " << stu[i].sum << endl;
    }

    return 0;
}