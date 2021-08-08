#include <bits/stdc++.h>
using namespace std;

struct Pat
{
    string id;
    int age;
    int num;

    bool operator<(const Pat &A) const
    {
        if (age < 60)
        {
            return ((A.age < 60) ? (num < A.num) : false);
        }

        if (A.age < 60)
        {
            return true;
        }

        return ((A.age == age) ? (num < A.num) : (age > A.age));
    }

    bool operator>(const Pat &A) const
    {
        if (age < 60)
        {
            return ((A.age < 60) ? (num > A.num) : true);
        }

        if (A.age < 60)
        {
            return false;
        }

        return ((A.age == age) ? (num > A.num) : (age < A.age));
    }
};

multiset<Pat> ms;

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        int age = 0;

        cin >> s >> age;

        ms.insert((Pat){s, age, i});
    }

    multiset<Pat>::iterator it;
    for (it = ms.begin(); it != ms.end(); it++)
    {
        cout << (*it).id << endl;
    }

    return 0;
}