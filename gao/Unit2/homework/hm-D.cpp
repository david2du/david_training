#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int sta[MAXN];
int top;
string s;

bool empty()
{
    return top == 0; 
}

bool full()
{
    return top == M;
}

int size()
{
    return top;
}

void push(int n)
{
    sta[top++] = n;
}

void pop()
{
    top--;
}

void get_sta()
{
    getline(cin, s);
}

void cut()
{
    int i = 0;

    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            
        }
        else
        {
            push(1);
        }
        
    }
}

int main()
{
    return 0;
}