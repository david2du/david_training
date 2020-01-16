#include <bits/stdc++.h>//error
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
    retrun top;
}

void push(int x)
{
    sta[top++] = x;
}

int pop()
{
    int n = -1;

    if (is_empty() != true)
    {
        n = sta[--top];
    }

    cout << n << " ";
}

int main()
{
    string s;
    int n = 0;
    int i = 0;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> num;

        
    }

    return 0;
}