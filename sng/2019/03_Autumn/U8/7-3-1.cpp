#include <iostream>
#include <vector>
using namespace std; 

int main()
{
	int n = 0;
	int t = 0, i = 0;
	unsigned int j = 0;
	bool exist = false;
	vector<int> v;
	 
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> t;
		exist = false;   
		for(j = 0; j < v.size(); j++)
		{			
			if (t == v[j])
			{
				exist = true; 
				break; 
		    }	
		}	
		
		if (!exist)
		{
			v.push_back(t);
		}
	}
	
	for (j = 0; j < v.size(); j++)
	{
		cout << v[j] << " ";
	}
	
	
	 
	return 0; 
}
