#include <bits/stdc++.h>
using namespace std;

struct Color
{
    int index;
    int number;

    bool operator<(const Color &A) const
    {
        return (number != A.number) ? number < A.number : index < A.index;
    }
};

priority_queue<Color> pearls;

int main()
{
    int n = 0, c = 0;

    cin >> n >> c;
    for (int i = 0; i < c; i++)
    {
        int t = 0;
        cin >> t;

        pearls.push((Color){i, t});
    }

    while (!pearls.empty())
    {
        for (int i = 0; i < pearls.size(); i++)
        {
            Color topa = pearls.top();
            pearls.pop();
            Color topb = pearls.top();
            pearls.pop();
            topa.number--;
            topb.number--;
            if (topa.number != 0)
            {
                pearls.push(topa);
            }
            if (topb.number != 0)
            {
                pearls.push(topb);
            }

            printf("%d %d\n", topb.index + 1, topa.index + 1);
        }
    }

    return 0;
}