#include <bits/stdc++.h>
using namespace std; 

struct Test
{
    int a;
    int b;
};

struct Test2
{
    int a;
    Test b;
};

void tsting(Test2 A)
{

}

void tsting(Test A)
{

}

int main() 
{
    int a = 10; 
    for(int i = 0; i < 10; i++)
    {
        cout << a + i <<endl;
    }

    tsting({1,{2, 3}});

    return 0;
}