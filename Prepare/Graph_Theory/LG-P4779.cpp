#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 100000 + 10;
const int M = 200000 + 10;

struct Edge
{
	int dest;
	int val;
} e[M];
int hd[N], nxt[M];
int nE;

inline int addEdge(int u, int v, int w)
{
	nE++;
	e[nE] = (Edge){v, w};
	nxt[nE] = hd[u];
	hd[u] = nE;
}

struct Node
{
	int id;
	int dst;
	
	inline bool operator<(const Node &A) const
	{
		return dst < A.dst;
	}
	inline bool operator>(const Node &A) const
	{
		return dst > A.dst;
	}
};

int dst[N];
bool vst[N];

void dijkstra(int n, int s)
{
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	memset(dst, 0x3f, (n + 1) * sizeof(int));
	
	pq.push((Node){s, 0});
	dst[s] = 0;
	
	while(!pq.empty())
	{
		int now = pq.top().id;
		pq.pop();
		if (vst[now])
			continue;
		vst[now] = true;
		
		for (int id = hd[now]; id; id = nxt[id])
		{
			if (dst[e[id].dest] > dst[now] + e[id].val)
			{
				dst[e[id].dest] = dst[now] + e[id].val;
				pq.push((Node){e[id].dest, dst[e[id].dest]});
			}
		}
	}
}

int main()
{
	int n = 0, m = 0, s = 0;
	
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		int u = 0, v = 0, w = 0;
		
		cin >> u >> v >> w;
		addEdge(u, v, w);
	}
	
	dijkstra(n, s);
	for (int i = 1; i <= n; i++)
		cout << dst[i] << " \n"[i == n];
	
	return 0;
}
