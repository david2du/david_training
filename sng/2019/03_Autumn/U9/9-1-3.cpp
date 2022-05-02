#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int mid = 0, next = 0;
    int i = 0;
    
    getline(cin, str);

    mid = str.size() / 2 - 1;
    next = mid + 1;
    if (str.size() % 2 == 1)
    {
        next++;
    }

    char stk[1024] = {0};
    int top = 0;

    for (i = 0; i <= mid; i++)
    {
        stk[++top] = str[i];
    }

    for (i = next; i < str.size(); i++)
    {
        if (str[i] == stk[top])
        {
           top--;
        }
        else
        {
            break;
        }
    }

    if (top == 0)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    

    return 0;
}