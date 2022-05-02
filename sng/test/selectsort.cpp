#include <bits/stdc++.h>
using namespace std;

bool cmp_stb(int a , int b) // small to big
{
    return a < b;
}
bool cmp_bts(int a , int b) // big to small
{
    return a > b;
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
    int n[10] = {0};
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        cin >> n[i];
    }

    select_sort(n, 10, cmp_stb);
    for (i = 0; i < 10; i++)
        cout << n[i] << endl;

    cout << "bts" << endl;
    select_sort(n, 10, cmp_bts);
    for (i = 0; i < 10; i++)
        cout << n[i] << endl;

    return 0;
}