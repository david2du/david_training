//循环队列
#include <bits/stdc++.h>
using namespace std;

const int M = 1024;
int qu[M];
int front, rear;

bool empty()
{
    return (front == rear);
}

bool full()
{
    return ((rear + 1) % M == front);
}

int size()
{
    return ((rear - front + M) % M);
}

void enqueue(int x)//设队列不空
{
    q[rear++] = x;
    rear %= M;
}

int dequeue()//设队列不空
{
    int ans = q[front++];
    front %= M;

    return q[front++];
}

int main()
{
    return 0;
}