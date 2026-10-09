#include <bits/stdc++.h>
using namespace std;

struct Obj
{
    int w;
    int val;
    int c;
    Obj() {};
    Obj(int W, int V, int C)
    {
        w = W;
        val = V;
        c = C;
    }
};
vector<Obj> obj;

int f[1000 + 10];

int main()
{
    int n = 0, v = 0;

    cin >> n >> v;
    for (int i = 0; i < n; ++i)
    {
        int w = 0, val = 0, c = 0;

        cin >> w >> val >> c;
        obj.push_back(Obj(w, val, c));
    }

    return 0;
}