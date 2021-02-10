#include <bits/stdc++.h>
#include <string>
using namespace std; 

int add(int a, int b)
{
	int c = a + b; 
	return c; 
}

int main() 
{
    for (int i =0; i < 10; i++)
    {
            cout << "Hello world : " <<add(i , i) << endl;  
            cout << "ending :" << i <<endl; 
       	
    }
    return 0; 
}
