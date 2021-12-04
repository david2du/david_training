#include <bits/stdc++.h>
using namespace std;

multiset<double> stu1;
multiset<double, greater<double>> stu2;

double stu[16];

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        cin >> stu[i];
    }
    for (int i = 0; i < 10; i++)
    {
        int a = 0;

        cin >> a;

        if (a == 1)
        {
            stu1.insert(stu[i]);
        }
        else
        {
            stu2.insert(stu[i]);
        }
    }

    for (auto it = stu1.begin(); it != stu1.end(); it++)
    {
        printf("%.2f ", *it);
    }
    for (auto it = stu2.begin(); it != stu2.end(); it++)
    {
        printf("%.2f ", *it);
    }
    cout << endl;

    return 0;
}
