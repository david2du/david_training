#include <bits/stdc++.h>
using namespace std;

struct Cross
{
    int a;
    int b;
};

int x[1000010];

Cross cross[1000010];
int cn[1000010];

void build(int n)
{

}

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }

    build(n);

    return 0;
}