#include <bits/stdc++.h>
using namespace std;

int fun(int n)
{
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        //cout << "Hello  world" << endl << endl;
        sum += i;
    }

    return sum;
}

int main()
{
    
    cout << "sum :" << fun(10) << endl;

    return 0;
}