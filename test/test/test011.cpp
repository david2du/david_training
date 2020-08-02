#include <bits/stdc++.h>
using namespace std;


struct A
{
    int a;
    char c;
};


struct B
{
    char c;
    int a;
};

//typedef unsigned long long   ull;

int main()
{
    cout << "char:" << sizeof(char) << endl;
    cout << "int:" << sizeof(int) << endl;
    cout << "bool:"<< sizeof(bool) << endl;
    cout <<"short:" << sizeof(short) <<endl; 
    cout <<"long:" << sizeof(long) << endl;
    cout <<"long long:" << sizeof(long long) <<endl; 
    cout <<"float:" << sizeof(float) << endl; 
    cout <<"double:" << sizeof(double) << endl; 
        
    cout <<"A:" << sizeof(A)<<endl; 
    cout <<"B:" << sizeof(B) <<endl;

    unsigned long long n = ULLONG_MAX;
    printf("%llu\n", n);
    printf("%llo\n%llx\n", n, n);
    printf("%llu\n", 0xffffffffffffffff);

    return 0;
}