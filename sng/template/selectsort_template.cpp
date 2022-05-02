#include <bits/stdc++.h>
using namespace std;

bool cmp_less(int a , int b)
{
    return a < b;
}

bool cmp_less_equal(int a , int b)
{
    return a <= b;
}

bool cmp_greater(int a , int b)
{
    return a > b;
}

bool cmp_greater_equal(int a , int b)
{
    return a <= b;
}

bool cmp_equal(int a , int b)
{
    return a == b;
}

bool cmp_not_equal_to(int a , int b)
{
    return a != b;
}

void select_sort(int n[], int size,  bool (* cmp)(int a , int b))
{
    int i = 0, j = 0;
    int cmpn = 0, cmpn_index = 0;

    for (i = 0; i < (size - 1); i++)
    {
        cmpn = n[i];
        cmpn_index = i;
        for (j = (i + 1); j < size; j++)
        {
            if (cmp(n[j], cmpn))
            {
                cmpn = n[j];
                cmpn_index = j;
            }
        }
        if (cmpn != n[i])
        {
            swap(n[i], n[cmpn_index]);
        }
    }
}

int main()
{
    int n[/*length*/] = {0};
    int i = 0;

    for (i = 0; i < /*length*/; i++)
    {
        cin >> n[i];
    }

    select_sort(n, /*length*/, /*cmp*/);
    select_sort(n, /*length*/, /*cmp*/);

    return 0;
}