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
    return rear == M;
}

int size()
{
    return (rear - front);
}

void enqueue(int x)//设队列不空
{
    q[rear++] = x;
}

int dequeue()//设队列不空
{
    return q[front++];
}

int main()
{
    return 0;
}