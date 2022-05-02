#include <bits/stdc++.h>
using namespace std;

/*
	  1
	 2 3
	4 5 6
*/

int ans[16];
int total;

void print()
{
	printf("(%d)\n", ++total);
	printf("   %d\n", ans[1]);
	printf("  %d %d\n", ans[2], ans[3]);
	printf(" %d %d %d\n\n", ans[4], ans[5], ans[6]);
}

bool vst[16];

void dfs(int step)
{
	if (step > 6)
	{
		if ((ans[1] + ans[2] + ans[4] == ans[4] + ans[5] + ans[6]) &&
		        (ans[4] + ans[5] + ans[6] == ans[1] + ans[3] + ans[6]))
		{
			print();
			return;
		}
	}

	for (int i = 1; i <= 6; i++)
	{
		if (!vst[i])
		{
			vst[i] = true;
			ans[step] = i;
			dfs(step + 1);
			vst[i] = false;
		}
	}
}

int main()
{
	dfs(1);
	printf("total: %d\n", total);

	return 0;
}
