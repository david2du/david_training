#include <iostream>
#include <stack>

using namespace std;

const int N = 3000010;

int h[N];
int ans[N];

int main()
{
    int n = 0;

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    stack<int> stk;
    for (int i = n - 1; i >= 0; --i)
    {
        while (!stk.empty() && h[stk.top()] <= h[i])
            stk.pop();
        if (stk.empty())
            ans[i] = 0;
        else
            ans[i] = stk.top() + 1;
        stk.push(i);
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";

    return 0;
}