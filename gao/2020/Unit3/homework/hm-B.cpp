#include <bits/stdc++.h>
using namespace std;

const int M = 100000;
long long q[M];
long long front, rear;

bool empty()
{
    return (front == rear);
}

bool full()
{
    return rear == M;
}

long long frontn()
{
    if (empty() == true)
    {
        return -1;
    }

    return q[front];
}

long long size()
{
    return (rear - front);
}

void enqueue(long long x)
{
    q[rear++] = x;
}

long long dequeue()
{
    if (empty() == true)
    {
        return -1;
    }

    return q[front++];
}

void opr()
{
    string str;
    long long k = 0;
    long long i = 0, j = 0;

    cin >> k;

    for (i = 0; i < k; i++)
    {
        cin >> str;

        if (str.compare("Push") == 0)
        {
            long long nu = 0;
            long long pushn = 0;

            cin >> nu;

            for (j = 0; j < nu; j++)
            {
                cin >> pushn;

                enqueue(pushn);
            }
        }
        if (str.compare("Pop") == 0)
        {
            long long popn = 0;
            long long pn = 0;

            cin >> popn;

            for (j = 0; j < popn; j++)
            {
                pn = dequeue();

                cout << pn << " ";

                if (pn == -1)
                {
                    break;
                }
            }
            cout << endl;         
        }
        if (str.compare("Front") == 0)
        {
            cout << frontn() << endl;
        }

        if (str.compare("Size") == 0)
        {
            cout << size();
            cout << endl;
        }
    }
}

int main()
{
    opr();

    return 0;
}