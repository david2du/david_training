#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int pqn = 0, ans = 0;

int main()
{
    cin >> pqn;

    for (int i = 0; i < pqn; ++i)
    {
        int n = 0;
        cin >> n;
        pq.push(n);
    }

    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        ans += (a + b);
        pq.push(a + b);
    }

    cout << ans << endl;

    return 0;
}