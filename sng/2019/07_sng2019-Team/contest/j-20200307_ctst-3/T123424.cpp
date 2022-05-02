#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> stk;
    int n = 0, num = 0;
    bool flag = false;

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        char c = 0;
        scanf("%c", &c);
        stk.push(c);
    }

    while (1)
    {
        while ((!stk.empty()) && (stk.top() != 'B'))
        {
            stk.pop();
        }
        if (stk.size() == 0)
        {
            break;
        }
        stk.pop();
        stk.push('R');
        while (stk.size() < n)
        {
            stk.push('B');
        }

        num++;
    }
    printf("%d", num);

    return 0;
}