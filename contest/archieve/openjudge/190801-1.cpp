#include <iostream>
using namespace std;
int main()
{
    int n = 0, x = 0;
    int a[10000]  ={0};
    int i = 0;
    bool f = false;
    
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        cin >> a[i];
    }     
    cin >> x;
    
    for (i = 0; i < n; i++)
    {   
        if (a[i] == x)
        {
            f = true;
            break;  
        }        
        
    }    
    
    if (f == false)
    {
        cout << "-1" << endl;     
    }      
    
    else
    {
        cout << i + 1 << endl;
    }   
    
    return 0;
}    
