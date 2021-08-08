#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 100000;
long long sta[MAXN];
long long top;

bool empty()
{
    return top == 0; 
}

bool full()
{
    return top == MAXN;
}

long long topn()
{
    if (empty() == true)
    {
        return -1;
    }
    return sta[top - 1];
}

long long size()
{
    return top;
}

void push(long long n)
{
    sta[top++] = n;
}

long long pop()
{
    if (empty() == true)
    {
        return -1;
    }

    return sta[--top];
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

                push(pushn);
            }
        }
        if (str.compare("Pop") == 0)
        {
            long long popn = 0;
            long long pn = 0;

            cin >> popn;

            for (j = 0; j < popn; j++)
            {
                pn = pop();

                cout << pn << " ";

                if (pn == -1)
                {
                    break;
                }
            }
            cout << endl;         
        }
        if (str.compare("Top") == 0)
        {
            cout << topn() << endl;
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