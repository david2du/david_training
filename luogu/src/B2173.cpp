#include <bits/stdc++.h>
using namespace std;

struct Obj
{
    int w;
    int val;
    Obj() {};
    Obj(int W, int V)
    {
        w = W;
        val = V;
    }
};
vector<Obj> obj;

void split(int w, int val, int c)
{
    int n = 1;

    while (n < c)
    {
        obj.push_back(Obj(w * n, val * n));
        c -= n;
        n <<= 1;
    }
    obj.push_back(Obj(w * c, val * c));
}

int f[1000 + 10];

int main()
{
    int n = 0, v = 0;

    cin >> n >> v;
    for (int i = 0; i < n; ++i)
    {
        int w = 0, val = 0, c = 0;

        cin >> w >> val >> c;
        split(w, val, c);
    }

    for (auto t : obj)
    {
        for (int i = v; i >= t.w; --i)
        {
            f[i] = max(f[i], f[i - t.w] + t.val);
        }
    }
    cout << f[v] << endl;

    return 0;
}