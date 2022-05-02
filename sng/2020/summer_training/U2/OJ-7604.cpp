#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    string s;
    map<string, int> mp;

    cin >> n;
    cin >> s;
    //getline(cin, s);

    for (int i = 0; i <= (s.size() - n); i++)
    {
        string now;

        now = s[i];
        now += s[i + 1];
        now += s[i + 2];

        mp[now]++;
    } // 枚举每组字符出现个数

    vector<pair<int, string> > v;
    map<string, int>::iterator it = mp.begin();
    for (it = mp.begin(); it != mp.end(); it++)
    {
        v.push_back(make_pair(it->second, it->first));
    }
    sort(v.begin(), v.end(), greater<pair<int, string> >()); // 排序数组，大 -> 小

    const int MAX = v[0].first;
    int num = 0;
    while (v[num + 1].first == MAX)
    {
        num++; // 数组最大值统计
    }

    cout << num + 1 << endl;
    for (int i = 0; i <= num; i++)
    {
        cout << v[i].second << endl;
    }

    return 0;
}