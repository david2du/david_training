#include <bits/stdc++.h>

using namespace std;

typedef __int128 ll;

typedef pair<ll, ll> P;

ll n, m;

vector<ll> fa[100010];
ll chdN[100010];
bitset<100010> nok;
vector<ll> out;

P water[100010];

inline ll gcd(ll a, ll b)
{
	if (b == 0)
	{
		return a;
	}
	
	return gcd(b, a % b);
}

inline void add(P &A, const P &B)
{
	A.first = (A.first * B.second + B.first * A.second);
	A.second *= B.second;
	
	ll g = gcd(A.first, A.second);
	A.first /= g;
	A.second /= g;
}

inline P div(P A, ll B)
{
	A.second *= B;
	
	ll g = gcd(A.first, A.second);
	A.first /= g;
	A.second /= g;
	
	return A;
}

inline void dfs(ll now)
{
	for (ll i = 0; i < fa[now].size(); i++)
	{
//		cout << "	" << i << endl;
		if (nok[fa[now][i]])
		{
			dfs(fa[now][i]);
		}
		add(water[now], div(water[fa[now][i]], chdN[fa[now][i]]));
	}
	nok[now] = false;
}

inline ll read()
{
	ll x = 0, f = 1;
	
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

inline void write(__int128 x)
{
	if(x < 0)
	{
		putchar('-');
		x = -x;
	}
	
	if(x > 9)
	{
		write(x / 10);
	}
	
	putchar(x % 10 + '0');
}

int main(int argc, char const *argv[])
{
	freopen("water4.in", "r", stdin);
	freopen("water.out", "w", stdout);
	
	n = read();
	m = read();
	
	for (ll i = 1; i <= n; i++)
	{
		chdN[i] = read();
		
		if (chdN[i] == 0)
		{
			out.push_back(i);
			continue;
		}
		
		for (ll j = 0; j < chdN[i]; j++)
		{
			ll v = 0;
			
			v = read();
			
			fa[v].push_back(i);
			nok[v] = true;
		}
	}
	
	for (ll i = 1; i <= m; i++)
	{
		nok[i] = false;
		water[i] = make_pair(1LL, 1LL);
	}
	for (ll i = m + 1; i <= n; i++)
	{
		water[i].second = 1;
	}
	
	for (ll i = (m + 1); i <= n; i++)
	{
		if (nok[i])
		{
			dfs(i);
//			for (ll i = 1; i <= n; i++)
//			{
//				cout << water[i].first << " " << water[i].second << endl;
//			}
//			cout << endl;
		}
		
	}
	
	for (ll i = 0; i < out.size(); i++)
	{
		ll g = gcd(water[out[i]].first, water[out[i]].second);
//		cerr << water[out[i]].first << " " << water[out[i]].second << endl;
		
		write(water[out[i]].first / g);
		cout << " ";
		write(water[out[i]].second / g);
		cout << endl;
//		cerr << "!!!" << i << endl;
	}

	return 0;
}

