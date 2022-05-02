#include <bits/stdc++.h>
using namespace std;

struct People
{
    string name;
    int score;
};

bool cmp(People A, People B)
{
    return A.score > B.score;
}

int main()
{
    int n = 0, m = 0;
    vector<People> v;

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string name;
        int score;

        cin >> name >> score;

        v.push_back((People){name, score});
    }
    sort(v.begin(), v.end(), cmp);

    int score = v[(int)((m - 1) * 1.5)].score;
    int num = 0;

    while (v[m].score >= score)
    {
        ++m;
        ++num;
    }

    cout << score << " " << m << endl;

    for (int i = 0; i < m; i++)
    {
        cout << v[i].name << " " << v[i].score << endl;
    }

    return 0;
}