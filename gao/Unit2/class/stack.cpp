#include <bits/stdc++.h>
using namespace std;

const int M = 100;
int sta[M], top = 0;

bool is_empty()
{
    return top == 0;
}

bool is_full()
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
    return sta[--top];
}

int main()
{
    return 0;
}