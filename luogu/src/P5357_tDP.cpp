#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
string t;
vector<int> v[N];
struct node
{
	int son[30], fail, cnt, flag;
} a[N];
int n, num, ans, vis[N], vp[N];
void insert(string now, int sp)
{
	int id = 0, l = now.size();
	for (int i = 0; i < l; i++)
		id = a[id].son[now[i] - 97] ? a[id].son[now[i] - 97] : a[id].son[now[i] - 97] = ++num;
	vp[sp] = id;
}
void getfail()
{
	queue<int> q;
	for (int i = 0; i < 26; i++)
		if (a[0].son[i])
			a[a[0].son[i]].fail = 0, q.push(a[0].son[i]);
	while (!q.empty())
	{
		int now = q.front(), f = a[now].fail;
		q.pop();
		for (int i = 0; i < 26; i++)
			if (a[now].son[i])
				a[a[now].son[i]].fail = a[f].son[i], q.push(a[now].son[i]);
			else
				a[now].son[i] = a[f].son[i];
	}
	for (int i = 1; i <= num; i++)
		v[a[i].fail].push_back(i);
}
void query()
{
	int id = 0, l = t.size();
	for (int i = 0; i < l; i++)
		a[id = a[id].son[t[i] - 97]].cnt++;
}
void dfs(int u)
{
	for (auto e : v[u])
		dfs(e), a[u].cnt += a[e].cnt;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t, insert(t, i);
	cin >> t, getfail(), query(), dfs(0);
	for (int i = 1; i <= n; i++)
		cout << a[vp[i]].cnt << '\n';
	return 0;
}