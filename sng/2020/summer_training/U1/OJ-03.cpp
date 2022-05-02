#include <bits/stdc++.h>
using namespace std;

struct Stu
{
    string name;
    int score;
};

bool cmp(const Stu &A, const Stu &B)
{
    if (A.score != B.score)
    {
        return (A.score > B.score);
    }
    else
    {
        return (A.name < B.name);
    }
}

int main()
{
    int n = 0;
    vector<Stu> stu;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string a;
        int b = 0;
        cin >> a >> b;

        stu.push_back((Stu){a, b});
    }

    sort(stu.begin(), stu.end(), cmp);

    for (int i = 0; i < n; ++i)
    {
        cout << stu[i].name << " " << stu[i].score << endl;
    }

    return 0;
}