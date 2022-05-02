#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string s;
    int idx;

    bool operator<(const Node &A) const
    {
        if (s != A.s)
        {
            return s < A.s;
        }
        return idx < A.idx;
    }
};

bool cmp(const pair<Node, int> &A, const pair<Node, int> &B)
{
    if (A.second != B.second)
    {
        return A.second > B.second;
    }
    return A.first < B.first;
}

int main()
{
    int n = 0;
    string s;
    map<Node, int> mp;

    cin >> n;
    cin >> s;
    //getline(cin, s);

    for (int i = 0; i <= (s.size() - n); i++)
    {
        string now;

        now = s[i];
        now += s[i + 1];
        now += s[i + 2];

        mp[(Node){now, i}]++;
    }

    vector<pair<int, Node> > v;
    map<Node, int>::iterator it = mp.begin();
    for (it = mp.begin(); it != mp.end(); it++)
    {
        v.push_back(make_pair(it->second, it->first));
    }
    sort(v.begin(), v.end(), cmp /*greater<pair<int, Node> >()*/);

    const int MAX = v[0].first;
    int num = 0;
    while (v[num + 1].first == MAX)
    {
        num++;
    }

    cout << num + 1 << endl;
    for (int i = 0; i <= num; i++)
    {
        cout << v[i].second.s << endl;
    }

    return 0;
}