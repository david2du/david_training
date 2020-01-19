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
    return top == MAXN;
}

int size()
{
    return top;
}

void push(int n)
{
    sta[top++] = n;
}

int pop()
{
    return sta[--top];
}

void get_sta()
{
    getline(cin, s);
}

void print()
{
    int a = 0, b = 0;
    int i = 0;

    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            push(i);
        }
        else
        {
            a = pop();

            cout << a << " " << i << endl;
        }
    }
}

int main()
{
    get_sta();
    print();

    return 0;
}