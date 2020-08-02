#include <iostream>
using namespace std;

 int a[1000001] = {0}, n, ans = -1;

void swap(int &a, int &b)
{
    int c = 0;
    c = a;
    a = b;
    b = c;
}

int FindKth(int left, int right, int n)
{
    int tmp = 0, value = 0, i = 0, j = 0;
    if (left == right)
    {
        return 0;
    }
    tmp = rand() % (right - left) + left;
    swap(a[tmp], a[left]);
    value = a[left];
    i = right;
    j = right;
    while (i < j)
    {
        while ((i < j) && (a[j] < value))
        {
            j--;
        }
        while ((i < j) && (a[j] > value))
        {
            i++;
        }
        if (i < j)
        {
            a[j] = a[i];
            j--;
        }
        else
        {
            break;
        }

        if (i < n)
        {
            return FindKth(i + 1, right, n);
        }
        if (i > n)
        {
            return FindKth(left, i - 1, n);
        }
        return i;
    }
}

int main()
{
    int i = 0;
    int m = 10000;
    for (i = 1; i <= m; i++)
    {
        cin >> a[i];
        cin >> n;
    }
    ans = FindKth(1, m, n);
    cout << a[ans] << endl;

    return 0;
}