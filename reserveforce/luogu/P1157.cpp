#include <bits/stdc++.h>
using namespace std;

int n, k;

vector<int> v;
bitset<16> bs;
void fun(int ndep, int now)
{
    if (ndep == k)
    {
        for (int i = 0; i < v.size(); i++)
        {
            printf("%3d", v[i]);
        }
        cout << endl;
        return;
    }

    ndep++;
    for (int i = now + 1; i <= n; i++)
    {
        if (!bs[i])
        {
            bs[i] = true;
            v.push_back(i);

            fun(ndep, i);

            bs[i] = false;
            v.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> k;

    fun(0, 0);

    return 0;
}
