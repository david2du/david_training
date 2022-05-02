#include <iostream>
#include <cstdio>  
#include <algorithm>
using namespace std;

bool b2s(int a , int b)
{
    return a > b; 
    
}

bool s2b( int a, int b)
{
    return a < b; 
}

int main()
{
    int a[] = {3,2,4, 5,1};

    sort(a,a + 5, b2s);
    for (int i = 0; i < 5; i ++)
    {
        cout << a[i] <<endl; 
    }

    sort(a,a + 5, s2b);
    for (int i = 0; i < 5; i ++)
    {
        cout << a[i] <<endl; 
    }
}
