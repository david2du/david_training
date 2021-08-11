# Day 3



## Class



### 强连通

+ 任意两点之间有u->v,v->u
+ 强连通分量 *(SCC)*：有向图的极大强连通子图
  + SCC之间交集为空
  + **将SCC缩为一个点，图变为DAG**
  + 从任意一点可遍历SCC
+ DFS树*（搜索树）*：**DFS过程中，添加为探索的新边**
  + 返祖边（后向边）
  + 前向边
  + 横叉边：连接两个子树的边
+ Tarjan

```c++
const int MAXN = 10000;
int n;

stack<int> sta;
bool inStack[MAXN];
int dfn[MAXN];
int low[MAXN]; // 能追溯到的最早节点
int idx = 0; // 引索号
vector<int> g[MAXN];
int scc_cnt = 0;
int in_scc[MAXN]; // 节点所在的SCC编号
vector<int> scc[MAXN]; // 每个SCC包含的节点

void tarjan(int u)
{
  	dfn[u] = low[u] = ++idx;
    instack[u] = true;
    sta.push(u);
  
    for (int i = 0; i < g[u].size(); i++) // dfs
    {
				int v = g[u][i];
      if (!dfn[v])
      {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      }
      else if (instack[v])
      {
        low[u] = min(low[u], dfn[v]);
      }
    }
  
    if (dfn[u] == low[u])
    {
        ++scc_cnt;
        int v = 0;
        do
        {
            v = sta.top();
            sta.pop();
            instack[v] = false;
            scc[scc_cnt].push_back(v);
            in_scc[v] = scc_cnt;
        } while(v != u);
    }
}

void solve()
{
  	for (int i = 1;i <= n; i++)
    {
      	if (!dfn[i])
          	tarjan(i);
    }
}

...
```

---

[学校网络](http://www.xmoj.tech/problem.php?cid=3759&pid=2)

<!--缩点-->

```c++
...

for (int i = 1; i<= n; i++)
{
    for (int j = 0; j < e[i].size(); j++)
    {
        // i -> g[i][j]
        if (in_scc[i] != in_scc[g[i][j]])
        {
          ++out[in_scc[i]];
          ++in_scc[g[i][j]];
        }
    }
}
```

---

[大队长](http://www.xmoj.tech/problem.php?cid=3759&pid=1)



### 割点

+ Tarjan
  + low

```c++
int ap[MAXN];
void ap_tarjan()
{
    int children = 0;

    dfn[u] = low[u] = ++idx;

    for ()//NOT FINISHED
}
```



### 割边 & 桥

+ Tarjan
  + low[i]：从i出发只经过树边或至多一条非树边



### Tarjan



​					*min{low[u],low[v]}* | **(u,v)为树边**

***Low[u]=*** 	

​					*min{low[u],**dfn**[v]}*｜**(u,v)非树边 **



## Contest