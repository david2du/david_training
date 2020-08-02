#include <bits/stdc++.h>
using namespace std;
int main()
{
	char info[1024] = {0}, crypted[1024] = {0};
	int count = 0; 
	ifstream fin("init-crypt.info");
	ofstream fout("cryptedf.crypt");
	while(fin.getline(info, sizeof(info)))
	{
		while(info[count] != 0)
		{
			if ((info[count] >= 'a') && (info[count] <= 'z'))
			{
				if (info[count] <= 'x')
				{
					crypted[count] = info[count] + 2;
				}
				else
				{
					crypted[count] = info[count] + 2 - 26;
				}
			}
			else if ((info[count] >= 'A') && (info[count] <= 'Z'))
			{
				if (info[count] <= 'X')
				{
					crypted[count] = info[count] + 2;
				}
				else
				{
					crypted[count] = info[count] + 2 - 26;
				}
			}
			else
			{
				crypted[count] = info[count];
			}
			count++;
		}
		//cout <<"init:"<<info <<endl;
		//cout <<"crypted:"<< crypted << endl;
		fout << crypted<<endl;
		count = 0;
		memset(info,0,sizeof(info));
		memset(crypted,0,sizeof(crypted));
	}
	
	return 0;
}
