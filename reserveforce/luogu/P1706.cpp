#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> v;
bitset<16> bs;
void fun(int ndep)
{
    if (ndep == n)
    {
        for (int i = 0; i < v.size(); i++)
        {
            printf("%5d", v[i]);
        }
        cout << endl;
        return;
    }

    ndep++;
    for (int i = 1; i <= n; i++)
    {
        if (!bs[i])
        {
            bs[i] = true;
            v.push_back(i);

            fun(ndep);

            bs[i] = false;
            v.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;

    fun(0);

    return 0;
}
