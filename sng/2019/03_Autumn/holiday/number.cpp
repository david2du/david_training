#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    int n = 0;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    for (int i = 0; i < n - 2; i++)
    {
        int a = 0, b = 0;

        a = q.front();
        q.pop();
        b = q.front();
        q.pop();
        q.push(a + b);
    }

    cout << q.front() << ":";
    q.pop();
    cout << q.front() << endl;
    q.pop();

    return 0;
}