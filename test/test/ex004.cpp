#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    string init;
    vector<char> dele;
    int num = 0;
    bool y = false;
    
    getline(cin, init);
    
    for (int i = 0; i < init.size(); i++)
    {
        if (init[i] == ' ')
        {
            num++;
        }
        else
        {
            num = 0;
        }
        
        if (num > 1)
        {
            continue;
        }
        
        dele.push_back(init[i]);
    }
    
    for (int i = 0; i < dele.size(); i++)
    {
        cout << dele[i];
    }
    
    cout << endl;
    
    return 0; 
}