#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0;
	string s;
	string word[11] = 
		{
		 "strawberry",
		 "banana", 
		 "orange",
		 "watermelon",
		 "pear",
		 "manago",
		 "grape",
		 "peach",
		 "apple",
		 "pineapple",
		 "cherry"
		};
	string chinese[11] = 
		{
			"��ݮ",
			"�㽶",
			"����",
			"����",
			"����",
			"â��",
			"����",
			"����",
			"ƻ��",
			"����",
			"ӣ��"			
		};
	
	srand(time(0));
	n = rand() % 11;
	
	cout << chinese[n] << endl;
	cin >> s;
	
	if (s == word[n])
	{
		cout << "Right!" << endl;
	}
	else
	{
		cout << "Error!" << endl;
	}
		
	//for (int i = 0; i < 11; i++)
	//{
	//	cout << chinese[i] <<endl;
	//}
	
	return 0;
}
