#include <bits/stdc++.h>
using namespace std;

struct Color
{
    int index;
    int number;

    bool operator<(const Color &A) const
    {
        return number < A.number;
    }
};

priority_queue<Color> color;

int main()
{
    int n = 0, c = 0;



    cin >> n >> c;
    for (int i = 0; i < c; i++)
    {
        int t = 0;
        cin >> t;

        color.push((Color){i, t});
    }
    
    while(!color.empty())
    {
        Color topa = color.top();
        color.pop();
        Color topb = color.top();
        color.pop();
        topa.number -= topb.number;
        for (int i = 0; i < topb.number; i++)
        {
            printf("%d %d\n", topa.index + 1, topb.index + 1);
        }

        if (topa.number != 0)
        {
            color.push(topa);
        }
    }

    return 0;
}