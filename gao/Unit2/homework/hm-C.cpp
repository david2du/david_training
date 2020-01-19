#include <bits/stdc++.h>
using namespace std;

const int M = 1000000;
long long sta[M], top = 0;

bool isEmpty()
{
    return top == 0;
}

bool isFull()
{
    return top == M;
}

int size()
{
    return top;
}

void push(int x)
{
    sta[top++] = x;
}

void pop()
{
    if (isEmpty() == true)
    {
        cout << "error" << endl;
        return;
    }

    cout << sta[--top] << endl;
}

string s[100];
int num[100];

void getNum()
{
    int n = 0;
    int i = 0;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> s[i];
        if (s[i].compare("PUSH") == 0)
        {
            cin >> num[i];
        }
    }

    for (i = 0; i < n; i++)
    {
        if (s[i].compare("PUSH") == 0)
        {
            push(num[i]);
        }

        if (s[i].compare("POP") == 0)
        {
            pop();
        }
    }
}

void print()
{
    int i = 0;

    if (isEmpty() == true)
    {
        cout << "empty" << endl;
    }

    for (i = (top - 1); i >= 0; i--)
    {
        cout << sta[i] << " ";
    }

    cout << endl;
}

int main()
{
    getNum();
    print();

    return 0;
}