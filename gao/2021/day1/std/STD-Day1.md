

#  Day 1 

## Class

### B: 图的存取

题目描述

一个无向图有 n 个点，m 条边，每条边都有长度 d（d≥0）。

请你计算每一个点的度，以及这个点的所有边的长度和。

输入

输入第一行，空格分开的正整数 n 和 m，点的编号是 1∼n。

然后是 m 行，每行 3 个数 a,b,d，表示 a 和 b 之间有一条边，且其长度为 d。

输出

输出 n 行，每行两个空格分开的整数 d 和 s，分别表示编号为 i 的点的度，以及这个点的所有边的长度和。

样例输入输出

**样例输入 #1**复制

```
6 9
1 2 6
1 3 3
2 3 2
2 4 5
3 4 3
4 5 2
3 5 4
5 6 5
4 6 3
```

**样例输出 #1**复制

```
2 9
3 13
4 12
4 13
3 11
2 8
```

数据范围

对于 60% 的数据，1<n≤1000，0<m≤10000。

对于 100% 的数据，1<n≤10000，0<m≤1000000，0≤d≤10000。

```cpp
//60分代码，使用邻接矩阵
#include<bits/stdc++.h>
using namespace std;
int n,m,g[1010][1010];
int main()
{
    memset(g,-1,sizeof(g));
    scanf("%d%d",&n,&m);
    for (int i=1,u,v,w;i<=m;++i) {
        scanf("%d%d%d",&u,&v,&w);
        g[u][v]=g[v][u]=w;
    }
    for (int i=1,d,s;i<=n;++i) {
        d=s=0;
        for (int j=1;j<=n;++j)
            if (g[i][j]>=0) {
                ++d;
                s+=g[i][j];
            }
        printf("%d %d\n",d,s);
    }
    return 0;
}


//100分代码，使用邻接表
#include<bits/stdc++.h>
using namespace std;
struct Edge { int v,w; };
int n,m;
vector<Edge> g[10010];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1,u,v,w;i<=m;++i) {
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back((Edge){v,w});
        g[v].push_back((Edge){u,w});
    }
    for (int i=1,d,s;i<=n;++i) {
        d=g[i].size(); s=0;
        for (int j=0;j<d;++j)
            s+=g[i][j].w;
        printf("%d %d\n",d,s);
    }
    return 0;
}
```



### C: 边权为0/1的最短路径问题

题目描述

一个无向图有 n 个点，m 条边，每条边都有长度 d（0≤d≤1）。给你起点 s 终点 t，要求输出起点到终点的最短距离。

输入

输入第一行，空格分开的正整数 n 和 m，点的编号是 1∼n。

然后是 m 行，每行 3 个数 a,b,d，表示 a 和 b 之间有一条边，且其长度为 d。

最后一行是两个数 s,t，起点 s，终点 t。(s≠t)

输出

输出一行，s 到 t 的最短路径的长度。如果 s 和 t 不连通，输出 −1。

样例输入输出

**样例输入 #1**复制

```
6 9
1 2 1
1 3 0
2 3 1
2 4 0
3 4 1
4 5 1
3 5 1
5 6 1
4 6 1
1 6
```

**样例输出 #1**复制

```
2
```

数据范围

对于 10% 的数据，1<n≤1000，d=1。

对于 50% 的数据，d=1。

对于 100% 的数据，1<n≤10000，0<m≤200000，0≤d≤1。



```cpp
//100分代码，使用两个队列做BFS
#include<bits/stdc++.h>
using namespace std;
struct Edge { int v,w; };
int n,m,s,t,dist[10010];
vector<Edge> g[10010];
queue<int> q1,q2;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1,u,v,w;i<=m;++i) {
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back((Edge){v,w});
        g[v].push_back((Edge){u,w});
    }
    scanf("%d%d",&s,&t);
    memset(dist,-1,sizeof(dist));
    dist[s]=0;
    q1.push(s);
    while (!(q1.empty()&&q2.empty())) {
        if (q1.empty())
            swap(q1,q2);
        int u=q1.front(); q1.pop();
        if (u==t) break;
        for (int i=0;i<g[u].size();++i) {
            int v=g[u][i].v,w=g[u][i].w;
            if (dist[v]==-1||dist[u]+w<dist[v]) {
                dist[v]=dist[u]+w;
                if (w==0) q1.push(v);
                else q2.push(v);
            }
        }
    }
    printf("%d\n",dist[t]);
    return 0;
}

//50分代码，使用单个队列做BFS
#include<bits/stdc++.h>
using namespace std;
int n,m,s,t,dist[10010];
vector<int> g[10010];
queue<int> q;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1,u,v,w;i<=m;++i) {
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(v);
        g[v].push_back(u);
        assert(w==1);
    }
    scanf("%d%d",&s,&t);
    memset(dist,-1,sizeof(dist));
    dist[s]=0;
    q.push(s);
    while (!q.empty()) {
        int u=q.front(); q.pop();
        if (u==t) break;
        for (int i=0;i<g[u].size();++i) {
            int v=g[u][i];
            if (dist[v]==-1) {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    printf("%d\n",dist[t]);
    return 0;
}
```





### D: 最短路径问题

```c++
#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
template <typename T> void read(T &t) {
    t=0; char ch=getchar(); int f=1;
    while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
    do {(t*=10)+=ch-'0'; ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m,s,t;
int g1[1010][1010];
void floyd()
{
    memset(g1,INF,sizeof(g1));
    for (int i=1;i<=n;++i) g1[i][i]=0;
    for (int i=0;i<m;++i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g1[u][v]=min(g1[u][v],w);
        g1[v][u]=min(g1[v][u],w);
    }
    scanf("%d%d",&s,&t);
    for (int k=1;k<=n;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                if (g1[i][j]>g1[i][k]+g1[k][j])
                    g1[i][j]=g1[i][k]+g1[k][j];
    printf("%d\n",g1[s][t]==INF?-1:g1[s][t]);
}
const int MAXN=10010;
struct Edge { int to,w; };
int vis[MAXN],dist[MAXN];
vector<Edge> g2[MAXN];
void dijkstra1()
{
    for (int i=1;i<=n;++i) {
        int u=-1,dx=INF;
        for (int j=1;j<=n;++j)
            if (!vis[j]&&dist[j]<dx)
                dx=dist[u=j];
        if (u==-1) break;
        vis[u]=1;
        for (int j=0;j<g2[u].size();++j) {
            int v=g2[u][j].to,w=g2[u][j].w;
            if (!vis[v]&&dist[u]+w<dist[v])
                dist[v]=dist[u]+w;
        }
    }
}
struct A {
    int u,d;
    bool operator < (const A& a) const {
        return d>a.d;
    }
};
priority_queue<A> pq;
void dijkstra2()
{
    pq.push((A){s,0});
    while (!pq.empty()) {
        int u=pq.top().u; pq.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=0;i<g2[u].size();++i) {
            int v=g2[u][i].to,w=g2[u][i].w;
            if (!vis[v]&&dist[u]+w<dist[v]) {
                dist[v]=dist[u]+w;
                pq.push((A){v,dist[v]});
            }
        }
    }
}
void dijkstra()
{
    for (int i=0;i<m;++i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g2[u].push_back((Edge){v,w});
        g2[v].push_back((Edge){u,w});
    }
    scanf("%d%d",&s,&t);
    fill(dist+1,dist+n+1,INF);
    dist[s]=0;
    if (n<=1000) dijkstra1();
    else dijkstra2();
    printf("%d\n",dist[t]==INF?-1:dist[t]);
}
int main()
{
    scanf("%d%d",&n,&m);
    if (n<=100) floyd();
    else dijkstra();
    return 0;
}
```





```c++
#include <iostream>
#include <cstring>
using namespace std;
int n,m,s,t,v[1010],map[1010][1010];
int main()
{
    int x,y,d;
    memset(map,0x2f,sizeof(map));
    cin>>n>>m;
    for (int i=0;i<m;++i) {
        cin>>x>>y>>d;
        map[x-1][y-1]=map[y-1][x-1]=d;
    }
    cin>>s>>t;
    for (int k=0;k<n;++k)
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                if (map[i][j]>map[i][k]+map[k][j])
                    map[i][j]=map[i][k]+map[k][j];
    cout<<(map[s-1][t-1]==0x2f2f2f2f?-1:map[s-1][t-1]);
    return 0;
}
```

```C++
#include <iostream>
#include <cstring>
using namespace std;
int n,m,s,t,map[1010][1010],v[1010],d[1010];
int main()
{
    int x,y,dd;
    memset(map,0x2f,sizeof(map));
    cin>>n>>m;
    for (int i=0;i<m;++i) {
        cin>>x>>y>>dd;
        map[x-1][y-1]=map[y-1][x-1]=dd;
    }
    cin>>s>>t;
    --s,--t;
    for (int i=0;i<n;++i) map[i][i]=0;
    for (int i=0;i<n;++i) d[i]=map[s][i];
    v[s]=1;
    for (int i=1;i<n;++i) {
        x=-1;
        for (int j=0;j<n;++j)
            if (!v[j]&&d[j]<0x2f2f2f2f)
                if (x==-1||d[j]<d[x])
                    x=j;
        if (x==-1) break;
        v[x]=1;
        for (int j=1;j<=n;++j)
            if (!v[j]&&d[x]+map[x][j]<d[j])
                d[j]=d[x]+map[x][j];
    }
    cout<<(d[t]==0x2f2f2f2f?-1:d[t]);
    return 0;
}


```

```C++
#include<bits/stdc++.h>
using namespace std;
int n,m,s,t,vis[10010],d[10010];
struct E { int v,w; };
vector<E> g[10010];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,x,y,z;i<=m;++i) {
        scanf("%d%d%d",&x,&y,&z);
        g[x].push_back((E){y,z});
        g[y].push_back((E){x,z});
    }
    scanf("%d%d",&s,&t);
    memset(d,0x3f3f3f3f,sizeof(d));
    d[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u=q.front();q.pop();
        vis[u]=0;
        for (int i=0;i<g[u].size();++i) {
            int v=g[u][i].v,w=g[u][i].w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                if (!vis[v]) vis[v]=1,q.push(v);
            }
        }
    }
    if(d[t]<0x3f3f3f3f) printf("%d\n",d[t]);
    else printf("-1\n");
    return 0;
}
```

### E: 带负权的最短路径问题

  题目描述

一个图有 n 个点，m 条有向边，每条边都有长度 d。给你起点 s 终点 t，要求输出起点到终点的最短距离。

输入

输入第一行，空格分开的正整数 n 和 m，点的编号是 1∼n。

然后是 m 行，每行 3 个数 a,b,d，表示 a 到 b 有一条边，且其长度为 d。

最后一行是两个数 s,t，起点 s，终点 t。(s≠t)

输出

输出一行，s 到 t 的最短路径的长度。如果 s 和 t 不连通，或者最短路径长度为 −∞，输出 −1。

样例输入输出

**样例输入 #1**复制

```
6 9
1 2 5
1 3 3
2 3 10
2 4 -2
3 4 1
4 5 2
3 5 4
5 6 5
4 6 3
1 6
```

**样例输出 #1**复制

```
6
```

**样例输入 #2**复制

```
6 9
1 2 5
1 3 3
2 3 -10
2 4 -2
3 4 1
4 5 2
3 5 4
5 6 5
4 6 3
1 6
```

**样例输出 #2**复制

```
-1
```

提示

对于 80% 的数据，不存在负环。

对于 100% 的数据，1<n≤1000，−1000≤d≤1000。

```C++
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3F3F3F3F;
int n,m,g[1010][1010],s,t,ans;
int main()
{
    memset(g,INF,sizeof(g));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=c;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if (g[i][k]<INF&&g[k][j]<INF)             
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    cin>>s>>t;
    ans=g[s][t];
    if (ans==INF) ans=-1;
    for (int i=1;i<=n;++i)
        if (g[i][i]<0&&g[s][i]<INF&&g[i][t]<INF)
            ans=-1;
    cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN=10010;
const int MAXE=100010;
const int INF=0x3f3f3f3f;
struct Edge { int u,v,w; } e[MAXE];
int n,m,s,t,d[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    memset(d,INF,sizeof(d));
    for (int i=0;i<m;++i)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    scanf("%d%d",&s,&t);
    d[s]=0;
    int tt;
    for (tt=0;tt<n;++tt) {
        bool f=true;
        for (int i=0;i<m;++i)
            if (d[e[i].u]<INF&&d[e[i].u]+e[i].w<d[e[i].v]) {
                d[e[i].v]=d[e[i].u]+e[i].w;
                f=false;
            }
        if (f) break;
    }
    if (tt==n||d[t]==INF) cout<<-1<<endl;
    else cout<<d[t]<<endl;
    return 0;
}
```



### F: [ 2017 普及组 ] 03 - 棋盘

```c++
#include <bits/stdc++.h>
using namespace std;
const int W=0,Y=2,R=1;
int m,n,g[110][110],ans[110][110][3];
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
void dfs(int x,int y,int c,int v)
{
    if (ans[x][y][c]<=v) return;
    ans[x][y][c]=v;
    if (x==m&&y==m) return;
    for (int i=0;i<4;++i) {
        int x2=x+dx[i],y2=y+dy[i];
        if (1<=x2&&x2<=m&&1<=y2&&y2<=m) {
            if (g[x][y]!=W) {
                if (g[x2][y2]!=W) dfs(x2,y2,g[x2][y2],v+(c!=g[x2][y2]));
                else {
                    dfs(x2,y2,c,v+2+(g[x][y]!=c));  //贪心优化
                    // dfs(x2,y2,R,v+2+(g[x][y]!=R));
                    // dfs(x2,y2,Y,v+2+(g[x][y]!=Y));
                }
            } else if (g[x2][y2]!=W) dfs(x2,y2,g[x2][y2],v+(c!=g[x2][y2]));
        }
    }
}
int main()
{
    freopen("chess.in","r",stdin); freopen("chess.out","w",stdout);
    memset(ans,0x3f,sizeof(ans));
    cin>>m>>n;
    for (int i=1,x,y,c;i<=n;++i) {
        cin>>x>>y>>c;
        g[x][y]=c+1;
    }
    dfs(1,1,g[1][1],0);
    int ans2=min(ans[m][m][R],ans[m][m][Y]);
    if (ans2==0x3f3f3f3f) ans2=-1;
    cout<<ans2<<endl;
    return 0;
}
```







### G: [ 2014 提高组 ] Day 2 - 02 寻找道路

```cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
 
int tot,total,n,m,ss,tt,l[500050],r[500050],pre[500050],last[10050],other[500050];
int que[10050],d[10050];
bool judge[10050],vis[10050],point[10050];
 
void add(int u,int v) {
    pre[++tot]=last[u];
    last[u]=tot;
    other[tot]=v;
}
 
void bfs(int x) {
    int h=0,t=1;
    que[1]=x;
    vis[x]=1;
    point[x]=1;
    total++;
    while (h<t) {
        int cur=que[++h];
        for (int p=last[cur]; p; p=pre[p]) {
            int q=other[p];
            if (!vis[q]) {
                vis[q]=1;
                que[++t]=q;
                total++;
                point[q]=1;
            }
        }
    }
}
 
void spfa(int x) {
    int h=0,t=1;
    que[1]=x;
    memset(d,127,sizeof d);
    d[x]=0;
    while (h<t) {
        int cur=que[++h];
        vis[cur]=0;
        for (int p=last[cur]; p; p=pre[p]) {
            int q=other[p];
            if (!point[q]) continue; 
            if (judge[q]) continue;
            if (d[q]>d[cur]+1) {
                d[q]=d[cur]+1;
                if (!vis[q]) {
                    vis[q]=1;
                    que[++t]=q;
                }
            }
        }
    }
}
 
int main() {
     
    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; i++) scanf("%d%d",&l[i],&r[i]);
    scanf("%d%d",&ss,&tt);
    for (int i=1; i<=m; i++) add(r[i],l[i]);
    bfs(tt);
    if (!point[ss]) {
        printf("%d",-1);
        return 0;         
    }
    for (int i=1; i<=n; i++) {
        if (point[i]) continue;
        for (int p=last[i]; p; p=pre[p]) {
            int q=other[p];
            judge[q]=1;
        }
    }
    memset(que,0,sizeof que);
    memset(vis,0,sizeof vis);
    memset(last,0,sizeof last);
    tot=0;
    for (int i=1; i<=m; i++) add(l[i],r[i]);
    spfa(ss);
    printf("%d",d[tt]);
    return 0;
}
```

### H: 有轨电车

题目描述

小明所在的城市还运营着有轨电车网络，这个网络是由轨道和交叉点构成的。在每一个交叉点，有一个开关指向其中一条向外的铁轨。当电车进入交叉点后，只能向开关所指向的那个方向前进。如果司机想要去另外一个方向，那么就需要人工改变这个开关。当司机从交叉点 A 开车到交叉点 B 的时候，他想要选择一条人工改变开关次数最少的路线。

请你编一个程序，计算从交叉点 A 开车到交叉点 B，最少需要人工改变开关的次数。

输入

第一行，空格分开的三个整数 N、A、B（2≤N≤100，1≤A,B≤N），N 是交叉点的数量，所有交叉点用 1−N 来进行编号。

接着 N 行，包含空格分开的整数序列。第一个数字 Ki (0≤Ki≤N−1) 表示从第 i 个交叉点出去的铁轨的总数。接下来的 Ki 个数字，表示和第 i 个交叉点直接相连的交叉点，其中的第一个数字表示第 i 个交叉点的开关一开始指向的交叉点。

输出



输出一行，一个整数，表示从 A 到 B 需要人工改变开关的最少次数。如果 A 到 B 没有路线可以走，输出 −1。

样例输入输出

**样例输入 #1**复制

```
3 2 1
2 2 3
2 3 1
2 1 2
```

**样例输出 #1**复制

```
0
```



```cpp
//交叉点建图，直接指向的w=0，需要手工的w=1
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 110;
const int INF = 100000000;
int n,s,e; //点的个数，起点，终点   
int w[MAXN][MAXN]; //w[i][j]表示是否连通 0默认 1需手动调节 INF不连通
bool vis[MAXN]; //标记是否使用
int dist[MAXN]; //dist[i]表示从起点到点i的距离
void dijkstra()
{
    memset(vis,false,sizeof(vis)); //清除所有的点
    for(int i=1;i<=n;i++) dist[i]=w[s][i];
    dist[s]=0;
    vis[s]=true; //标记起点
        
    for(int i=1;i<n;i++) { //循环n-1次
        int x=0,m=INF;
        for(int y=1;y<=n;y++) //在所有未标号的节点中，选出dist值的最小点x
            if(!vis[y]&&dist[y]<m)
                m=dist[x=y];
        if (x==0) break;
        vis[x]=true; //给节点x标记
        for(int y=1;y<=n;y++) //更新 松弛操作
            if (!vis[y])
                dist[y]=min(dist[y],dist[x]+w[x][y]);
    }
    if(dist[e]==INF) printf("-1\n");
    else printf("%d\n", dist[e]);
}
int main()
{
    scanf("%d%d%d",&n,&s,&e);
    for(int i=1;i<=n;i++) {
        dist[i]=INF;
        for(int j=1;j<=n;j++) w[i][j]=(i==j?0:INF);
    }
    int path,y;
    for(int i=1;i<=n;i++) {
        scanf("%d",&path);
        for(int j=1;j<=path;j++) {
            scanf("%d",&y);
            w[i][y]=(j==1?0:1); //需手动调节
        }
    }
    dijkstra();
    return 0;
}
```



### I:  畅通工程

题目描述

某省调查乡村交通状况，得到的统计表中列出了任意两村庄间的距离。省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可），并要求铺设的公路总长度为最小。请计算最小的公路总长度。

输入

第1行给出村庄数目 N (N≤100)。

随后的 N∗(N−1)/2 行对应村庄间的距离，每行三个正整数 ui,vi,wi，分别是两个村庄的编号，以及此两村庄间的距离。

为简单起见，村庄从 1 到 N 编号。

1≤ui,vi≤N，wi≤10000

输出

最小的公路总长度。

样例输入输出

**样例输入 #1**复制

```
3
1 2 1
1 3 2
2 3 4
```

**样例输出 #1**复制

```
3
```

**样例输入 #2**复制

```
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
```

**样例输出 #2**复制

```
5
```

```cpp
#include <bits/stdc++.h>
using namespace std;
const int MAXN=110;
const int INF=0x7f7f7f7f;
int n,m,mapp[MAXN][MAXN],dist[MAXN],vis[MAXN],weight;
void prim()
{
    int mini=1,w;
    memset(dist,INF,sizeof(dist));
    memset(vis,0,sizeof(vis));
    vis[1]=true;
    dist[1]=weight=0;
    for (int i=1;i<n;++i) {
        for (int j=1;j<=n;++j)
            if (!vis[j]&&mapp[mini][j]<dist[j])
                dist[j]=mapp[mini][j];
        mini=0, w=INF;
        for (int j=1;j<=n;++j)
            if (!vis[j]&&dist[j]<w)
                w=dist[mini=j];
        vis[mini]=true;
        weight+=w;
    }
}
int main()
{
    scanf("%d",&n);
    memset(mapp,INF,sizeof(mapp));
    m=n*(n-1)/2;
    for (int i=1;i<=m;++i) {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        mapp[x][y]=mapp[y][x]=z;
    }
    prim();
    cout<<weight<<endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
const int MAXN=110,MAXE=5010;
const int INF=0x7f7f7f7f;
struct Edge{
    int from,to,w;
    bool operator < (const Edge& edge) const {
        return w<edge.w;
    }
};
Edge edges[MAXE],mstEdges[MAXE];
int n,ec,mstec,id[MAXN],weight;
int find(int p){
    if(id[p]==p) return p;
    return id[p]=find(id[p]);
}
void kruscal(){
    mstec=weight=0;
    sort(edges,edges+ec);
    for(int i=1;i<=n;++i) id[i]=i;
    for(int i=0;i<ec;++i){
        int p=find(edges[i].from);
        int q=find(edges[i].to);
        if(p==q) continue;
        mstEdges[mstec++]=edges[i];
        weight+=edges[i].w;
        id[p]=q;
        if(mstec==n-1) break;
    }
}
int main(){
    scanf("%d",&n);
    ec=n*(n-1)/2;
    for(int i=0,u,v,w;i<ec;++i)
        scanf("%d %d %d",&edges[i].from,&edges[i].to,&edges[i].w);
    kruscal();
    cout<<weight<<endl;
    return 0;
}
```





### J :  继续畅通工程

题目描述

省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。现得到城镇道路统计表，表中列出了任意两城镇间修建道路的费用，以及该道路是否已经修通的状态。现请你编写程序，计算出全省畅通需要的最低成本。

输入

第1行给出村庄数目N（1<N<100）；

随后的 N∗(N−1)/2 行对应村庄间道路的成本及修建状态，每行给 4 个正整数，分别是两个村庄的编号（从 1 编号到 N），此两村庄间道路的成本，以及修建状态：1 表示已建，0 表示未建。

输出

输出全省畅通需要的最低成本。

样例输入输出

**样例输入 #1**复制

```
3
1 2 1 0
1 3 2 0
2 3 4 0
```

**样例输出 #1**复制

```
3
```

**样例输入 #2**复制

```
3
1 2 1 0
1 3 2 0
2 3 4 1
```

**样例输出 #2**复制

```
1
```

**样例输入 #3**复制

```
3
1 2 1 0
1 3 2 1
2 3 4 1
```

**样例输出 #3**复制

```
0
```



```cpp
#include <bits/stdc++.h>
using namespace std;
const int MAXN=110;
const int MAXE=10000;
const int INF=0x7f7f7f7f;
struct Edge {
    int from,to,w,used;
    bool operator < (const Edge& edge) const {
        return w<edge.w;
    }
};
Edge edges[MAXE],mstEdges[MAXE];
int n,ec,mstec,id[MAXN],sz[MAXN],weight;
int find(int p)
{
    while (id[p]!=p) {
        id[p]=id[id[p]];
        p=id[p];
    }
    return p;
}
void uni(int i,bool calWeight)
{
    int p=find(edges[i].from);
    int q=find(edges[i].to);
    if (p==q) return;
    mstEdges[mstec++]=edges[i];
    if (calWeight) weight+=edges[i].w;
    if (sz[p]<sz[q]) {
        id[p]=q;
        sz[q]+=sz[p];
    } else {
        id[q]=p;
        sz[p]+=sz[q];
    }
}
void kruskal()
{
    mstec=weight=0;
    sort(edges,edges+ec);
    for (int i=1;i<=n;++i) {
        id[i]=i;
        sz[i]=1;
    }
    for (int i=0;i<ec;++i)
        if (edges[i].used)
            uni(i,false);
    for (int i=0;i<ec;++i)
        if (!edges[i].used)
            uni(i,true);
}
int main()
{
    scanf("%d",&n);
    ec=n*(n-1)/2;
    for (int i=0;i<ec;++i)
        scanf("%d %d %d %d",&edges[i].from,&edges[i].to,
            &edges[i].w,&edges[i].used);
    kruskal();
    cout<<weight<<endl;
    return 0;
}
```



###   K: 高速公路

题目描述

凌云市是一个风景优美的山区城市，气候宜人，景色秀美，非常适合度假。可是，凌云市没有公共交通，所以游客在不同县之间游玩时交通很成问题。市政府已经意识到这个问题，打算在各个县之间修建高速公路，能够让游客通过自己的方式到达任何一个县城。

凌云市的各个县分别用1−N来进行编号，每条高速公路连接其中的两个县。高速公路在两个县之间走直接路程，任意两条高速公路如果相遇都可以自由交错通行。高速公路都是双向的。司机如果想从一条高速公路转到另一条高速公路，只能在这两条高速公路都连接的县完成，不能在两条高速公路途中相遇的地方切换路线。

凌云市政府希望找到一个建设方案，使得所有高速公路里最长的那条高速公路的长度最短，同时保证任意两个县都可以通过高速公路到达。

输入

第一行是一个整数T（T≤10），表示有多少个测试数据。

每一个测试数据的第一行是一个整数 N （3≤N≤500），表示一共有多少个县。接下来的 N 行，每行 N 个整数。第 i 行的第 j 个整数 di,j 表示第 i 个县到第 j 个县的距离（di,j≤1000）。

输出

每一个测试数据，输出一行，包含一个整数，表示能够满足要求的高速公路网中长度最长的高速公路的长度。

样例输入输出

**样例输入 #1**复制

```
1
3
0 990 692
990 0 179
692 179 0
```

**样例输出 #1**复制

```
692
```

```cpp
#include <bits/stdc++.h>
using namespace std;
const int INF=0x7f7f7f7f;
const int MAXN=510;
int m[MAXN][MAXN];
int n,dist[MAXN],vis[MAXN],ans;
void prim()
{
    int mini=1,w;
    memset(vis,0,sizeof(vis));
    memset(dist,INF,sizeof(dist));
    vis[1]=true;
    dist[1]=ans=0;
    for (int i=1;i<n;++i) {
        for (int j=1;j<=n;++j)
            if (!vis[j]&&m[mini][j]<dist[j])
                dist[j]=m[mini][j];
        mini=0, w=INF;
        for (int j=1;j<=n;++j)
            if (!vis[j]&&dist[j]<w)
                w=dist[mini=j];
        vis[mini]=true;
        ans=max(ans,w);
    }
}
int main()
{
    int cc;
    cin>>cc;
    while (cc--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                scanf("%d",&m[i][j]);
        prim();
        cout<<ans<<endl;
    }
    return 0;
}
```

### L: 通讯网络

题目描述

某草原地区有 n 个部落 ( 1≤n≤500 )，每个部落的坐标用一对整数 (x,y) 表示，其中 0≤x,y≤10000。为了加强联系，决定在部落之间建立通讯网络。通讯工具可以是无线电收发机，也可以是卫星设备。所有的部落都拥有一部无线电收发机，且所有的无线电收发机型号相同。但卫星设备数量有限，只能给 一部分部落配备卫星设备。

不同型号的无线电收发机有一个不同的参数 d，两个部落之间的距离如果不超过 d 就可以用该型号的无线电收发机直接通讯，d 值越大的型号价格越贵。拥有卫星设备的两个部落无论相距多远都可以直接通讯。

现在有 k 台 (0≤k≤100) 卫星设备，请你编一个程序，计算出应该如何分配这 k 台卫星设备，才能使所拥有的无线电收发机的 d 值最小，并保证每两个部落之间都可以直接或间接地通讯。 

输入

第 1 行是空格分开的两个整数 n 和 k。

第 2 到 n+1 行，每行空格分开的两个整数 x 和 y，表示第 1 个村庄到第 n 个村庄的坐标。

输出

输出一行，最小的 d 值，保留 2 位小数。

样例输入输出

**样例输入 #1**复制

```
3 1
10 10
10 0
30 0
```

**样例输出 #1**复制

```
20.00
```

样例说明 #1

![img](http://www.xmoj.tech/upload/image/20171208/20171208000801_78181.png)

这三个部落如上图所示，|AB|=10，|BC|=20，|AC|=10∗5。

如果只有 0 个或者 1 个卫星设备，则满足条件的最小的 d=20，因为 A 和 B、B 和 C 用无线电通讯，A 和 C 可以通过 B 中转。

如果有 2 个卫星设备，则满足条件的 d=10，因为 A 和 B 之间用无线电通讯，A 和 C 之间用卫星通讯。

如果有 3 个卫星设备，则满足条件的 d=0，因为两两之间都可以用卫星通讯。

**样例输入 #2**复制

```
3 2
10 10
10 0
30 0
```

**样例输出 #2**复制

```
10.00
```

**样例输入 #3**复制

```
3 3
10 10
10 0
30 0
```

**样例输出 #3**复制

```
0.00
```

```cpp
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
typedef pair<int,int> Point;
Point ptr[MAXN];
struct Edge {
    int u,v;
    double w;
    bool operator < (const Edge& e) const {
        return w<e.w;
    }
} edges[MAXN*MAXN];
int n,k,m,p[MAXN],ans;
#define isqr(x) ((x)*(x))
#define distance(a,b) (sqrt(isqr(a.first-b.first)+isqr(a.second-b.second)))
int find(int x) {
    return p[x]==x?x:p[x]=find(p[x]);
}
bool merge(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x==y) return false;
    p[x]=y;
    return true;
}
double kruskal(){
    for(int i=1;i<=n;i++) p[i]=i;
    int num=0;
    for(int i=0;i<m;i++)
        if(merge(edges[i].u,edges[i].v))
            if (++num==n-k)
                return edges[i].w;
    return -1; //Impossible
}
int main()
{
    cin>>n>>k;
    if (k==0) k=1;
    if (k>=n) {
        cout<<"0.00"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++) cin>>ptr[i].first>>ptr[i].second;
    m=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++) {
            edges[m].u=i;
            edges[m].v=j;
            edges[m++].w=distance(ptr[i],ptr[j]);
        }
    sort(edges,edges+m);
    cout<<setprecision(2)<<fixed<<kruskal()<<endl;
    return 0;
}
```

## Contest

###  A:  训练

#### 问题 A: 训练

输入文件: train.in  输出文件: train.out  时间限制: 1 Sec 内存限制: 256 MB
提交: 155 解决: 21
[[提交](http://www.xmoj.tech/submitpage.php?cid=3752&pid=0&langmask=5)][[状态](http://www.xmoj.tech/problemstatus.php?id=4713)]

题目描述

马上要出征奥运了，小明决定再和 n 个人训练以提高经验值。但由于时间有限，最多只能训练 t 分钟，所以他可以选择一部分人来训练，每个人的训练价值由一个三元组 (a,b,c) 组成，表示如果小明在第 x 分钟和这个人训练，他需要训练 c 分钟，会得到 a−b∗(x+c) 的经验值。

小明想知道他最多可以得到多少经验值。

输入

第一行一个正整数 T，表示数据组数。

对于每组数据，第一行为两个正整数 n 和 t，表示跟和小明训练的人数和小明的训练时间。

接下来 n 行，每行三个正整数 ai,bi,ci，表示每个人的训练价值，含义见题面。

输出

每组数据输出一行，一个整数表示小明最多能得到多少经验值。

样例输入输出

**样例输入 #1**复制

```
1
4 10
110 5 9
30 2 1
80 4 8
50 3 2
```

**样例输出 #1**复制

```
88
```

样例说明 #1

第 0 分钟和第二个人 (30 2 1) 训练，得到经验值 28；再和第一个人 (110 5 9) 训练，得到经验值 60。

数据范围

20% 的数据：n≤10

50% 的数据：n≤18

100% 的数据：1≤n≤1000,ai≤106,1≤ci≤t,1≤t≤3000

保证 n≥200 时 T≤5，其他情况 T≤10。

保证每个人贡献的经验值到训练结束都不会变成负数。

#### Method 

首先，假如我们已经确定了要跟哪些人训练，按什么顺序训练最好？

假设已经确定了要训练的 m 个人，某一个方案中训练的顺序是 x1,x2,...,xm， 那么对于任意的相邻两项 xi,xi+1，考虑交换这两项的顺序，是否会变得更优。交换相邻两项，只会对这两个人的贡献有影响，对其余的人 不会产生影响。

如果不交换这两项，损失的贡献是 cxi×bxi+1+K，如果交换这两项，损失的贡献是 cxi+1×bxi+K（K是一个常数）所以只需要判断是否 cxi×bxi+1≤cxi+1×bxi。如果此不等式不成立，那么应该交换这两项。对上式移项得 bxi+1cxi+1>bxicxi。所以对于一个确定的训练集合，训练的最优顺序只与每个人的 bici 有关，按这个比值排序从大到小训练。

于是，我们先对所有的人按照这个比值进行排序，接下来只要按照排好的顺序选择与哪些人训练就可以了。

这相当于一个简单的“背包问题”，使用动态规划来解决。fi 表示恰好用了 i 分钟的最高经验值。状态转移方程为 fi=max1≤j<ifi−cj+aj−i×bj。

最终答案是 max0≤i≤tfi。

#### Answer

```cpp
#include <bits/stdc++.h>
using namespace std;
#define maxn 3009
struct node{int a,b,c;} q[maxn];
bool cmp(const node& x,const node &y) { return x.b*y.c>x.c*y.b; }
int n,t,f[maxn],ans;
int main()
{
    freopen("train.in","r",stdin);
    freopen("train.out","w",stdout);
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&t);
        for (int i=1;i<=n;++i) scanf("%d%d%d",&q[i].a,&q[i].b,&q[i].c);
        sort(q+1,q+n+1,cmp);
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;++i)
            for (int j=t;j>=q[i].c;--j)
                f[j]=max(f[j],f[j-q[i].c]+q[i].a-j*q[i].b);
        ans=0;
        for (int i=0;i<=t;++i) ans=max(ans,f[i]);
        printf("%d\n", ans);
    }
    return 0;
}
```



### B:  鱼

#### 问题 B: 鱼

输入文件: fish.in  输出文件: fish.out  时间限制: 5 Sec 内存限制: 256 MB
提交: 145 解决: 11
[[提交](http://www.xmoj.tech/submitpage.php?cid=3752&pid=1&langmask=5)][[状态](http://www.xmoj.tech/problemstatus.php?id=4714)]

题目描述

小明最喜欢钓鱼，可以一下午在池塘边也没钓到几条鱼，于是他打算改成捕鱼。

池塘可以看成一 个二维平面，渔网可以看成一个与坐标轴平行的矩形。池塘里的一条鱼可以看成一个点，可以不停地在水中游动。有的时候会有鱼游进渔网，有的时候也会有鱼游出渔网。所以小明想知道什么时候收网可以抓住最多的鱼。

池塘里一共有 n 条鱼，小明给每条鱼一个标号，分别是 1 到 n。鱼的游动可以概括为两个动作：

1 l r d ：表示标号在 [l,r] 区间内的鱼向 x 轴正方向游动了 d 个单位长度。

2 l r d ：表示标号在 [l,r] 区间内的鱼向 y 轴正方向游动了 d 个单位长度。

在某些时刻小明会想知道现在有多少条他关心的鱼在渔网内（边界上的也算）。

输入

第一行包含一个整数 T，表示测试数据组数。

对于每组测试数据：

第一行包含一个整数 n 表示鱼的总数。

第二行包含四个整数 x1,y1,x2,y2，表示渔网的左下角坐标和右上角坐标。

接下来 n 行每行两个整数 xi,yi，表示标号为 i 的鱼初始时刻的坐标。

接下来一行包含一个整数 m，表示后面的事件数目。

接下来的 m 行每行为以下三种类型的一种：

1 l r d ：表示标号在 [l,r] 这个区间内的鱼向 x 轴正方向游动了 d 个单位长度。

2 l r d ：表示标号在 [l,r] 这个区间内的鱼向 y 轴正方向游动了 d 个单位长度。

3 l r ：表示询问现在标号在 [l,r] 这个区间内的鱼有多少在渔网内。

输出

对于每组数据的每个询问，输出一个整数表示对应的答案。

样例输入输出

**样例输入 #1**复制

```
1
5
1 1 5 5
1 1
2 2
3 3
4 4
5 5
3
3 1 5
1 2 4 2 
3 1 5
```

**样例输出 #1**复制

```
5
4
```

样例说明 #1

对于 30% 的数据：1≤n,m≤1000

对于 100% 的数据：1≤T≤10,1≤n,m≤30000,1≤l≤r≤n,1≤d≤109,x1≤x2,y1≤y2。

保证任意时刻所有涉及的坐标值在 [−109,109] 范围内。

#### Method

题目关键在于在 x 轴和 y 轴上，鱼的坐标变化都是单调的，因为 d 是正值。

我们把在一个 矩形内部有多少个点的询问拆分成四个在某个点的左下角有多少个点的询问，然后用一棵线段树维护鱼的 x 坐标，一棵线段树维护鱼的 y 坐标。对于移动操作，在对应的线段树上进行区间更新，更新完成后询问该区间内的最大值，若最大值超过了我们关心的值，那么这个点就可以删掉了，删除的方法可以通过在对应的线段树上把值设为 −∞，同时继续询问直到最大值不大于我们关心的值为止。那么我们就可以实时维护当前在我们关心的点左下角的点有哪些了，这可以再借助于一个树状数组。这样子作四遍我们就能得到最终的答案了。

由于 每一次的过程中每个点只会被删除一次，所以复杂度是 O((n+q)×log⁡n))。

#### Answer

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m,xx1,xx2,yy1,yy2,sum[4][410000],X[4],Y[4],x[410000],y[410000],ans[4];
ll maX[4][410000],maY[4][410000],addX[4][410000],addY[4][410000];
#define lson rt<<1
#define rson rt<<1|1
void update(int t,int rt) {
    sum[t][rt]=sum[t][lson]+sum[t][rson];
    maX[t][rt]=max(maX[t][lson]+addX[t][lson],maX[t][rson]+addX[t][rson]);
    maY[t][rt]=max(maY[t][lson]+addY[t][lson],maY[t][rson]+addY[t][rson]);
}
void mkt(int t,int rt,int l,int r) {
    addX[t][rt]=addY[t][rt]=0;
    if (l==r) {
        if (x[l]<=X[t]&&y[l]<=Y[t]) {
            sum[t][rt]=1;
            maX[t][rt]=x[l];
            maY[t][rt]=y[l];
        } else {
            sum[t][rt]=0;
            maX[t][rt]=-1e18;
            maY[t][rt]=-1e18;
        }
        return;
    }
    int mid=(l+r)>>1;
    mkt(t,lson,l,mid);
    mkt(t,rson,mid+1,r);
    update(t,rt);
}
void modifyX(int t,int rt,int l,int r,int ul,int ur,int d) {
    if (ul>r||ur<l) return;
    if (ul<=l&&r<=ur) { addX[t][rt]+=d; return; }
    int mid=(l+r)>>1;
    modifyX(t,lson,l,mid,ul,ur,d);
    modifyX(t,rson,mid+1,r,ul,ur,d);
    update(t,rt);
}
void modifyY(int t,int rt,int l,int r,int ul,int ur,int d) {
    if (ul>r||ur<l) return;
    if (ul<=l&&r<=ur) { addY[t][rt]+=d; return; }
    int mid=(l+r)>>1;
    modifyY(t,lson,l,mid,ul,ur,d);
    modifyY(t,rson,mid+1,r,ul,ur,d);
    update(t,rt);
}
int query(int t,int rt,int l,int r,int ql,int qr) {
    if (ql>r||qr<l) return 0;
    if (ql<=l&&r<=qr) return sum[t][rt];
    int mid=(l+r)>>1;
    return query(t,lson,l,mid,ql,qr)+query(t,rson,mid+1,r,ql,qr);
}
void adjust(int t,int rt,int l,int r,ll ssx,ll ssy) {
    if (maX[t][rt]+addX[t][rt]+ssx<=X[t]&&maY[t][rt]+addY[t][rt]+ssy<=Y[t])
        return;
    if (l==r) {
        sum[t][rt]=0;
        maX[t][rt]=-1e18;
        maY[t][rt]=-1e18;
    } else {
        int mid=(l+r)>>1;
        adjust(t,lson,l,mid,ssx+addX[t][rt],ssy+addY[t][rt]);
        adjust(t,rson,mid+1,r,ssx+addX[t][rt],ssy+addY[t][rt]);
        update(t,rt);
    }
}
int main() {
    freopen("fish.in","r",stdin);
    freopen("fish.out","w",stdout);
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d%d%d",&n,&xx1,&yy1,&xx2,&yy2);
        X[0]=xx2;   Y[0]=yy2;
        X[1]=xx1-1; Y[1]=yy2;
        X[2]=xx2;   Y[2]=yy1-1;
        X[3]=xx1-1; Y[3]=yy1-1;
        for (int i=1;i<=n;++i)
            scanf("%d%d",&x[i],&y[i]);
        for (int i=0;i<4;++i)
            mkt(i,1,1,n);
        scanf("%d",&m);
        for (int i=1,t,l,r,d;i<=m;++i) {
            scanf("%d%d%d",&t,&l,&r);
            if (t<=2) scanf("%d",&d);
            if (t==1) {
                for (int i=0;i<4;++i)
                    modifyX(i,1,1,n,l,r,d),adjust(i,1,1,n,0,0);
            }
            if (t==2) {
                for (int i=0;i<4;++i)
                    modifyY(i,1,1,n,l,r,d),adjust(i,1,1,n,0,0);
            }
            if (t==3) {
                for (int i=0;i<4;++i)
                    ans[i]=query(i,1,1,n,l,r);
                printf("%d\n",ans[0]-ans[1]-ans[2]+ans[3]);
            }
        }
    }
    return 0;
}
```

### C: 计树

#### 问题 C: 计树

输入文件: tree.in  输出文件: tree.out  时间限制: 1 Sec 内存限制: 128 MB
提交: 195 解决: 20
[[提交](http://www.xmoj.tech/submitpage.php?cid=3752&pid=2&langmask=5)][[状态](http://www.xmoj.tech/problemstatus.php?id=4715)]

题目描述

一个有 n 个结点的树，设它的结点分别为 v1,v2,…,vn，已知第 i 个结点 vi 的度数为 di，问满足这样的条件的不同的树有多少棵。

输入

第一行一个正整数 n，表示树有 n 个结点。

第二行有 n 个数，第 i 个数表示 di，即树的第 i 个结点的度数。

输出

输出一个整数，表示满足条件的树有多少棵。

样例输入输出

**样例输入 #1**复制

```
4
2 1 2 1
```

**样例输出 #1**复制

```
2
```

数据范围

对于 50% 的数据：n≤10

对于 100% 的数据：n≤150，0≤di<n，保证答案 ≤1017。



#### Method

此题需要用到 Purfer 序列的性质（下文中的性质 3），可以使用组合数乘法直接计算。



Purfer 序列是一个元素值域均为 [1,n] 的，n−2 个整数构成的序列。其可以与一个 n 阶完全图的生成树一一对应，形成双射。凯莱定理即由此而来。



构造方法：

**树构造 Purfer**

每次选择编号最小的叶子节点，删去，然后把它的父节点的编号加入到序列后面，最后只剩下两个节点时算法停止。

从上述构造 Prufer 序列的过程可以看出 Prufer 序列具有以下两个性质：

1、在构造完 Prufer 序列后原树中会剩下两个节点，其中一个一定是编号最大的点 n。

2、每个节点在序列中出现的次数是其度数减 1，因此没有出现的就是叶节点。

**Purfer 构造树**

每次我们选择一个编号最小的度数为 1 的节点，与当前枚举到的 Prufer 序列的点连接，然后同时减掉两个点的度数。重复 n−2 次后就只剩下两个度数为 1 的节点，其中一个是 n，把它们连接起来即可。



Purfer 序列有如下 3 条**性质**：

1、Purfer 序列与带编号无根树形成双射。

2、度数为 di 的点会在 Prufer 中出现 di−1 次。

3、对于给定度数 d1,d2,...,dn 的一颗无根树，共有 (n−2)!∏i=1n(di−1)! 种情况。

性质 3 的证明：利用组合数学知识，序列一共有 n−2 个位置，挑出 di−1 个给一个点，然后减去已被占有的位置，继续此操作直到所有位置都填上数。

####  Answer

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=156;
int n;
ll d[N],C[N][N],sum,ans=1;
void init(int n) {
    for (int i=0;i<=n;++i) {
        C[i][0]=C[i][i]=1;
        for (int j=1;j<=i;++j)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
}
int main() {
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    init(n);
    for (int i=1;i<=n;++i)
        scanf("%lld",&d[i]),sum+=d[i]-1;
    if (n==1) ans=d[1]==0;
    else if (sum!=n-2) ans=0;
    else {
        for (int i=1;i<=n;++i) {
            if (d[i]==0) { ans=0; break; }
            ans*=C[sum][d[i]-1],sum-=d[i]-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
```

