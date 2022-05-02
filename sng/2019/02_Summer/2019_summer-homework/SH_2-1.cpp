#include <bits/stdc++.h>
using namespace std;
vector<int> split(int n)
{
    vector<int> sn;
    int i = 0;

    while(n != 0)
    {
        i = n % 10;
        sn.push_back(i);
        n = (n - i) / 10;
    }

    return sn; 
}

bool judge(int n, int k)
{
    int num[10] = {0};
    bool j = false;
    vector<int> a;
    unsigned int i = 0;
    int jn = 0;

    a = split(n);

    for (i = 0; i < a.size(); i++)
    {
        if(a[i] <= k)
        {
            num[a[i]]++;
        }
    }

    for (i = 0; i < 10; i++)
    {
        if (num[i] > 0)
        {
            jn++;
        }
    }
    if (jn == (k + 1))
    {
        j = true;
    }

    return j;
}

int main()
{
    int n = 0, k = 0, m = 0;
    bool f = false;

    scanf("%d,%d", &n, &k);

    for (m = 1; m < 30001; m++)
    {
        if (judge(n * m, k) == true)
        {
            f = true;
            break;
        }
    }

    if (f == true)
    {
        cout << m << endl;
    }
    else
    {
        cout << "No find!" << endl;
    }
    

    return 0;
}