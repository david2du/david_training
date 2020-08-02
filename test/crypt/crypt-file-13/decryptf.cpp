#include <bits/stdc++.h>
using namespace std;
int main()
{
	char crypted[1024] = {0}, decrypted[1024] = {0};
	int count = 0;
	ifstream fin("cryptedf.crypt");
	ofstream fout("decryptedf.decrypt");
	while(fin.getline(crypted, sizeof(crypted)))
	{
		while(crypted[count] != 0)
		{
			if ((crypted[count] >= 'a') && (crypted[count] <= 'z'))
			{
				if (crypted[count] >= 'c')
				{
					decrypted[count] = crypted[count] - 13;
				}
				else
				{
					decrypted[count] = crypted[count] - 13 + 26;
				}
			}
			else if ((crypted[count] >= 'A') && (crypted[count] <= 'Z'))
			{
				if (crypted[count] >= 'C')
				{
					decrypted[count] = crypted[count] - 13;
				}
				else
				{
					decrypted[count] = crypted[count] - 13 + 26;
				}
			}
			else
			{
				decrypted[count] = crypted[count];
			}
			count++;
		}
		//cout <<"crypted:"<< crypted <<endl;
		//cout <<"decrypted:"<< decrypted << endl;
		fout << decrypted <<endl;
		count = 0;
		memset(crypted,0,sizeof(crypted));
		memset(decrypted,0,sizeof(decrypted));
	}
	
	return 0;
}
