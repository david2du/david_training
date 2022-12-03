#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int a[maxn];
bitset<maxn>b;
 
int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	b[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		sum += x;
		b ^= b << x;
	}
	int ans = 0;
	for (int i = 1; i <= sum; i++) {
		if (b[i])ans++;
	}
	printf("%d\n", ans);
}
