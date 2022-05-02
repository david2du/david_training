#include <bits/stdc++.h>
using namespace std;

struct Thing
{
    int weight;
    int value;
    double value_per_weight;
    Thing(int w, int v)
    {
        weight = w;
        value = v;
        value_per_weight = (double)value / (double)weight;
    }

    bool operator>(const Thing &A) const
    {
        return value_per_weight > A.value_per_weight;
    }
};

int main()
{
    int k = 0;

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int w = 0, s = 0;
        multiset<Thing, greater<Thing> > ms;

        cin >> w >> s;
        for (int i = 0; i < s; i++)
        {
            int n = 0, v = 0;
            cin >> n >> v;
            ms.insert( Thing(n, v));
        }

        double sum = 0.0;
        multiset<Thing, greater<Thing> >::iterator it;

        /*int cnt = 0;
        cout << "ms" << endl;
        for (it = ms.begin(); it != ms.end(); it++, cnt++)
        {
            printf("No. %d, VPW: %.2f, weight: %d, value: %d\n", cnt, it->value_per_weight, it->weight, it->value);
        }
        cout << endl;*/

        for (it = ms.begin(); it != ms.end(); it++)
        {
            if (w >= (it->weight))
            {
                sum += (double)(it->value);
                w -= (it->weight);
                //printf("Choose: ALL, left_weight: %d, sum: %.2f\n", w, sum);
            }
            else
            {
                sum += (double)((it->value_per_weight) * w);
                //printf("Choose: %dKG, left_weight: 0, sum: %.2f\n", w, sum);
                break;
            }
        }

        printf("%.2f\n", sum);
    }

    return 0;
}