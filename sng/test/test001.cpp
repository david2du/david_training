#include <iostream>
using namespace std; 

int main() 
{
    int a = 10; 
    int b = a ++ ; 
    cout << b << ' ' << a <<endl;

    int c = ++a;
    cout << c << ' ' << a <<endl;

    int n1[3] = {9,8,7};
    c = 0;
    int n2[3] = {0,1,2};

    n1[c++] = n2[0];
    cout << n1 << endl << c << endl << endl;
    n1[++c] = n2[1];
    cout << n1 << endl << c << endl << endl;

    return 0; 
}