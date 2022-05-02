#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> ms;
    ms.insert(1); 
    ms.insert(2);

    multiset<int>::iterator it; 
    for(it = ms.begin(); it != ms.end(); it++)
    {
        cout << * it <<endl; 
    }

    return 0;
}