#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int score = 0, count = 0;
	int i = 0 ,max = 0 ,index = 0;
	int math[11] = { 0 };
	
	srand (time(0));
	for (count = 1; count < 11; count++)
	{
		score = rand () % 101;
		math[count] = score;
	}
	index = 1;
	max = math[1];
	for (i = 2; i < 11; i++)
	{
		if (math[i] > max)
		{
			max = math[i];
			index = i;
		}
	}
	cout << "	score : " << max << "	NO." << index << endl << endl;
	
	return 0;
}
