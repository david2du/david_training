# Day 2



## 拓扑排序

+ 对于**DAG有向无环图** 排序

+ u到v有路径，u必在v前面
  + 一个节点v，在所有先继都在序列内后，才进入序列
  + 拓扑排序可能不唯一
  
+ **有环图排不了**



---

[Web](http://www.xmoj.tech/problem.php?cid=3755&pid=1)

+ **拓扑排序-正常**  *O（Edge）*

```c++
vector<int> g[MAXN];
int n, m;

int in[MAXN];
int ord[MAXN];
int vis[MAXN];

void init()
{
    cin >> n >> m;
    
    for (int i =0, u, v; i < m; i++)
    {
        cin >> u >> v;
        
        g[u].push_back(v);
        ++in[v];
    }
}

bool toposort()
{
    queue<int> q; // priority_queue<int>
    
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    
    while (!q.empty())
    {
        int k = q.front(); // q.top()
    	q.pop();
        
        ord[++cnt] = k;
        for (int i = 0; i < g[k].size(); i++)
        {
            if (--in[g[k][i]] == 0)
            {
                q.push(g[k][i]);
            }
        }
    }
    
    return cnt == n;
}

...
```


+ **拓扑排序-DFS**

  + 图G使用DFS，每个节点结束后加入链表
  + **定理**

    + 有向图是DAG当且仅当无返祖边
    + 算法得到拓扑排序的逆序

```c++
void dfs(int u)
{
    vis[u] = true;
    for (int i= 0; i< g[u].size(); i++)
    {
        if (!vis[g[u][i]])
        {
            dfs(g[u][i]);
		}
    }
    
    ord[++cnt] = u;
}
```



---

+ DAG 上求**最长路径**
  + *maxdis*(0) = 0

  + ... *(DP)*

+ 关键路径：**最长路径**

```c++
/*
假设节点1为唯一入度为0的节点，节点n为唯一出度为0的节点
*/

struct Edge
{
    int v;
    int w;
};

vetcor<Edge> g[MAXN]; 
int n, m, in[MAXN];
int ve[MAXN], vl[MAXN];

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u = 0, v = 0, w = 0;
        
        cin >> u >> v >> w;
        
        g[u].push_back((Edge){v, w});
        ++in[v];
    }
    
    fill(vl, vl + n + 1, 1e9);
}

bool critical_path()
{
    queue<int> q;
    stack<int> t;
    q.push(1);
    ve[1] = 0;
    int cnt = 1;
    
    while (!q.empty())
    {
        int u = q.front();
    	q.pop();
        
        t.push(u);
        for (int i = 0; i < g[u].size(); i++)
        {
            v = g[u][i].v, w = g[u][i].w;
            ve[v] = max(ve[v], ve[u] + w);
            if (--in[v] == 0)
            {
                q.push(v);
                ++cnt;
            }
        }
    }
    
    if (cnt < n)
    {
        return false;
    }
    
    vl[n] = ve[n];
    
    while(!t.empty()) // reverse
    {
        int u = t.top();
        t.pop();
        for (int i = 0; i < g[u].size(); i++)
        {
            vl[u] = min(vl[u], vl[g[u][i].v] - g[u][i].w);
        }
    }
    
    return true;
}

...
```

  

---

[车站分级](http://www.xmoj.tech/problem.php?cid=3755&pid=2)



## Contest



### T1-Matrix



---



### T3-Jump

f[i]只通过yz到达的楼层

