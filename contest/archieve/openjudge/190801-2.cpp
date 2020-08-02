#include <iostream>
#include<string>
using namespace std;
int main()
{
    int num = 0;
    int s[10000] = {0};
    string n[100] ;
    int i = 0, max = 0, a = 0;
    
    cin >> num;
    
    for ( i = 0; i < num; i++)
    {
       cin >> s[i] >> n[i]; 
    }      
    
    max = s[0];
    
    for ( i = 1; i < num; i++)
    {
        if (s[i] > max)
        {
             max = s[i];
             a = i;    
        }         
    }
    
    cout << n[a] << endl;
   
   return 0;
}    
