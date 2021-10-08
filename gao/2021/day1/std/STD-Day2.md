# Day 2

## Class

### B: 拓扑排序

#### 问题 B: 拓扑排序

模版题输入文件: 标准输入  输出文件: 标准输出  
时间限制: 1 Sec 内存限制: 128 MB Special Judge
提交: 216 解决: 157
[[提交](http://www.xmoj.tech/submitpage.php?cid=3755&pid=1&langmask=5)][[状态](http://www.xmoj.tech/problemstatus.php?id=2819)]

题目描述

给定一个 N 个点的有向图，点的编号为 1,2,...,N，请输出拓扑排序的结果。

输入

第一行，两个整数 N（N≤100000）、M（M≤500000），N 表示点的数量，M 表示边的数量。

后续 M 行，每行两个整数 X,Y，表示 X→Y 有一条有向边。

输出

输出一行，N 个空格分开的整数，表示拓扑排序的结果；如果不是 DAG，输出 −1。

样例输入输出

**样例输入 #1**复制

```
5 5
1 2
1 3
2 4
3 4
5 4
```

**样例输出 #1**复制

```
1 2 3 5 4
```

**样例输入 #2**复制

```
3 3
1 2
2 3
3 1
```

#### Answer

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> g[100010];
int cnt=0,deg[100010],pos[100010],vis[100010];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;++i) {
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        deg[y]++;
    }
    queue<int> q;
    for(int i=1;i<=n;++i)
        if(deg[i]==0)
            q.push(i);
    while(!q.empty()) {
        int u=q.front();q.pop();
        pos[++cnt]=u;
        for(int i=0;i<g[u].size();++i) {
            int v=g[u][i];
            deg[v]--;
            if(deg[v]==0) q.push(v);
        }
    }
    if(cnt==n) {
        for(int i=1;i<=n;++i) printf("%d ",pos[i]);
        return 0;
    }
    else printf("-1");
    return 0;
}
```



### C

#### C: [ 2013 普及组 ] 04 - 车站分级

#### Answer

``` cpp
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1010;
int n,m,s,r,degree[MAXN],mapp[MAXN][MAXN],g[MAXN][MAXN],ec[MAXN],ts[MAXN];
int idx,nstack[2][MAXN],top[2];
void init()
{
    static int p[MAXN];
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;++i) {
        scanf("%d",&s);
        memset(p,0,sizeof(p));
        for (int j=1;j<=s;++j) {
            scanf("%d",&ts[j]);
            p[ts[j]]=1;
        }
        for (int j=ts[1];j<=ts[s];++j)
            if (p[j]==0)
                for (int k=1;k<=s;++k)
                    if (mapp[j][ts[k]]==0) {
                        mapp[j][ts[k]]=1;
                        g[j][ec[j]++]=ts[k];
                        ++degree[ts[k]];
                    }
    }
}
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    init();
    s=n; r=0; idx=0;
    for (int i=1;i<=n;++i)
        if (degree[i]==0)
            nstack[0][top[0]++]=i;
    while (s>0) {
        s-=top[idx];
        top[1-idx]=0;
        for (int i=0;i<top[idx];++i)
            for (int j=0;j<ec[nstack[idx][i]];++j)
                if (--degree[g[nstack[idx][i]][j]]==0)
                    nstack[1-idx][top[1-idx]++]=g[nstack[idx][i]][j];
        idx=1-idx;
        ++r;
    }
    printf("%d\n",r);
    return 0;
}
```



### D: 食物链

#### 问题 D: 食物链

输入文件:  标准输入  输出文件: 标准输出  

时间限制: 2 Sec 内存限制: 128 MB
提交: 274 解决: 99
[[提交](http://www.xmoj.tech/submitpage.php?cid=3755&pid=3&langmask=5)][[状态](http://www.xmoj.tech/problemstatus.php?id=2115)]

题目描述

小明在学习生态系统相关的知识，食物链生态系统中一个很重要的知识，A 物种吃 B 物种、B 物种吃 C 物种、C 物种吃 D 物种，这样 A→B→C→D 就构成了一条食物链。更精确的来讲，如果有 N 个物种，以及个物种之间相互捕猎的关系，那么定义 A1→A2→...→Ak 是一条食物链，要求满足：

1）没有任何一个物种会捕食 A1

2）Ai 捕食 Ai+1 (1≤i<k)

3）Ak 不捕食任何其他物种

4）单个物种不构成食物链

比如狼吃狐狸、狐狸吃田鼠、田鼠吃水稻，狼->狐狸->田鼠->水稻构成了一条食物链。老鹰吃田鼠，老鹰吃蛇、蛇吃田鼠，老鹰->田鼠->水稻、老鹰->蛇->田鼠->水稻 分别构成了一条食物链。但是 蛇->田鼠->水稻 不构成一条食物链。

现在小明想让你帮忙计算一下，在一个给定的食物网中，一共有多少条食物链。

输入

第 1 行两个整数 n 和 m，表示一共有 n 个物种，m 种捕食的关系。

第 2 到第 m+1 行，每行两个整数 Ai 和 Bi，表示物种 Ai 捕食物种 Bi。

数据保证输入数据符合生物学特点，且不会有重复的捕猎关系。

保证答案不会爆 int。

输出

一个整数，表示食物网中一共有多少条食物链。

样例输入输出

**样例输入 #1**复制

```
10 16
10 9
10 7
10 6
9 8
8 5
7 9
7 6
6 5
4 8
4 5
4 3
2 5
2 3
1 10
1 4
1 2
```

**样例输出 #1**复制

```
9
```

数据范围

1≤n≤100000，0≤m≤200000。



#### Answer

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,deg[100010],num[100010],ans=0;
vector<int> g[100010];
queue<int> q;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,u,v;i<=m;++i) {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        deg[v]++;
    }
    for(int i=1;i<=n;++i)
        if(deg[i]==0&&g[i].size()==0)
            deg[i]=0x3f3f3f3f;
    for(int i=1;i<=n;++i)
        if(deg[i]==0) {
            q.push(i);
            num[i]=1;
        }
    while(!q.empty()) {
        int u=q.front();q.pop();
        for(int i=0;i<g[u].size();++i) {
            int v=g[u][i];
            deg[v]--;
            num[v]+=num[u];
            if(deg[v]==0) q.push(v);
        }
    }
    for(int i=1;i<=n;++i)
        if(g[i].size()==0)
            ans+=num[i];
    printf("%d",ans);
    return 0;
}
```





### E: CPU

####  Question 

题目描述

小明最近沉迷于学习计算机原理，他自己做了一个CPU集群的模型。这个CPU集群非常强大，可以在瞬间执行完任意一条指令，而且还是并发的，可以并行任意多个核心同时执行指令。由于这个CPU太快了，为了安全起见，有些指令不能同时执行，指令间必须要有一个安全间隔时间。

现在有 N 条要执行的指令，小明想请你帮忙计算一下每条指令的最早执行时间，以及为了不影响所有指令最快完成的最晚执行时间。

输入

第一行，两个整数 N 和 M，表示 N 条指令（编号为 1−N）和 M 个指令间的先后依赖关系。（N≤1000，M≤10000）

接下来 M 行，每行三个整数 x、y、z，表示编号为 x 的指令至少要提前编号为 y 的指令 z 秒执行。（1≤x,y≤N，1≤z≤1000）

输出

第一行，一个整数，表示所有指令执行完毕的最短时间。

后续 N 行，每行两个整数 a、b，分别表示第 i 条指令的最早执行时间和为了不影响所有指令最快完成的最晚执行时间。

所有时间的单位都是秒。

样例输入输出

**样例输入 #1**复制

```
4 4
1 2 5
1 3 10
2 4 5
3 4 4
```

**样例输出 #1**复制

```
14
0 0
5 9
10 10
14 14
```

#### Answer

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,deg[100010],num[100010],ans=0;
vector<int> g[100010];
queue<int> q;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,u,v;i<=m;++i) {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        deg[v]++;
    }
    for(int i=1;i<=n;++i)
        if(deg[i]==0&&g[i].size()==0)
            deg[i]=0x3f3f3f3f;
    for(int i=1;i<=n;++i)
        if(deg[i]==0) {
            q.push(i);
            num[i]=1;
        }
    while(!q.empty()) {
        int u=q.front();q.pop();
        for(int i=0;i<g[u].size();++i) {
            int v=g[u][i];
            deg[v]--;
            num[v]+=num[u];
            if(deg[v]==0) q.push(v);
        }
    }
    for(int i=1;i<=n;++i)
        if(g[i].size()==0)
            ans+=num[i];
    printf("%d",ans);
    return 0;
}
```



### F: 排次序

#### Question

题目描述

排序算法是根据元素的大小来排次序的算法，次序可以用小于号（<）表示。例如，ABCD 是排好序的，表示 A<B、B<C、C<D。如果已经知道部分元素的次序关系，是否可以将这些元素进行完整的排序呢？

输入

输入是由多个 Case 组成，Case 数不超过 20。

每个 Case 的第一行是空格分开的两个整数 n、m，其中 n（2≤n≤26）表示要排序的元素的数量，要排序的元素是大写字母（即 A−Z），m（m≤106）表示已知的元素大小关系的数量。

后续的 m 行，每行都是 A<B 的形式，表示第一个元素的次序小于第二个元素。

n=m=0表示整个输入结束。

输出

每个 Case 输出一行，是以下三种情况之一：

1、如果通过前 x 个关系已经可以完全确定元素的次序，输出：

Sorted sequence determined after *x* relations: *yyyyyy*.

*yyyyyy* 表示按照从小到大排序的元素。

2、如果无法确定元素的次序，输出：

Sorted sequence cannot be determined.

3、如果通过前 x 个关系发现冲突，输出：

Inconsistency found after *x* relations.

其中，1 和 3 两种情况，按照先发生的优先的原则输出。

样例输入输出

**样例输入 #1**复制

```
4 6
A<B
A<C
B<C
C<D
B<D
A<B
3 2
A<B
B<A
26 1
A<Z
0 0
```

**样例输出 #1**复制

```
Sorted sequence determined after 4 relations: ABCD.
Inconsistency found after 2 relations.
Sor
```

#### Answer

```cpp
#include<cstdio>
#include<cstring>
char alp[27];
int edge[27][27],in[27];
int TopoSort(int n) 
{
    int t=0,tmp[27],flag=1;
    for(int i=1;i<=n;i++)
        tmp[i]=in[i];
    for(int i=1;i<=n;i++){
        int in0=0,loc;//查找入度为零的顶点个数
        for(int j=1;j<=n;j++){
            if(tmp[j]==0){
                in0++; 
                loc=j; 
            }
        }
        if(in0==0) return 0;//有环,那么后面的就不用再判断了 
        if(in0>1) flag=-1;//不确定,但不能直接return -1;因为后面的字母中还可能形成环而return 0; 
        alp[t++]='A'+loc-1;//入度为零的字母入队
        tmp[loc]=-1;
        for(int k=1;k<=n;k++)
            if(edge[loc][k]==1) 
                tmp[k]--;
    }
    return flag;
}
//flag=1:有序 flag=-1:不确定
int main()
{
    int m,n,x,y;  
    char str[5];
    while(scanf("%d%d",&n,&m),n|m){
        memset(edge,0,sizeof(edge));
        memset(in,0,sizeof(in));
        bool sign=0;
        for(int i=1;i<=m;i++){
            scanf("%s",str);
            if(sign) continue; //一旦得出结果,对后续的输入不做处理,但是不能break,因为还得继续输入 
            x=str[0]-'A'+1;
            y=str[2]-'A'+1;
            if(edge[x][y]) continue;
            edge[x][y]=1;
            in[y]++;
            int flag=TopoSort(n);
            if(flag==0){//有环
                printf("Inconsistency found after %d relations.\n",i);
                sign=1;
            }
            if(flag==1){//有序
                printf("Sorted sequence determined after %d relations: ",i);
                for(int j=0;j<n;j++)
                    printf("%c",alp[j]);
                printf(".\n");
                sign=1;
            }//当sign=1时表明已得出结果
        }
        if(!sign) //不确定
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
```



### G: 海选

#### Question

题目描述

知名导演小明到艺校来选拔电影的男主角，一共有 N 个候选人报名参加。学校把这些学生按照身高从高到低进行编号，身高最高的编号为 1，身高最矮的编号为 N。由于各种原因，有些学生必须要在另外一些学生之后才能参加面试。我们把 A 学生必须在 B 学生之前参加面试记为 <A,B>。

片中的男主角需要身高，所以小明倾向于选用身高较高的学生，学校也会尽量让身高较高的学生参加面试。具体来说就是：在满足所有限制的前提下，1 号学生尽量优先安排面试；在满足所有限制的前提下，1 号同学尽量优先安排面试的前提下，2 号同学尽量优先安排面试；在满足所有限制的前提下，1 号同学尽量优先安排面试的前提下，2 号同学尽量优先安排面试的前提下，3 号同学尽量优先安排面试；以此类推。

例1：共 4 位学生，两条限制 <3,1>、<4,1>，那么面试顺序是 3,4,1,2。先考虑 1，因为 3、4 都必须在 1 前面，另外 3 要优先于 4，所以这三个同学的面试顺序是 3,4,1；接下来考虑 2，最终确定是 3,4,1,2。

例2：共 5 位学生，两条限制 <5,2>、<4,3>，那么面试顺序是 1,5,2,4,3。首先面试 1 是不违背限制的；接下来考虑 2 时有 <5,2> 的限制，所以接下来的面试顺序是 5,2；接下来考虑 3 时有 <4,3> 的限制，所以接下来的面试顺序是 4,3；最终的顺序是 1,5,2,4,3。

现在你需要求出这个最优的面试顺序。无解输出“Impossible!” （不含引号） 

输入

第一行一个整数 T，表示数据组数，接下来是 T 组数据。

每组数据，第一行两个正整数 N、M，分别表示学生人数和限制的条目数。

接下来 M 行，每行两个正整数 x、y，表示 x 号学生必须要在 y 号学生之前参加面试。（注意，可能存在完全相同的限制）

输出

每组数据输出一行，N 个整数，表示面试的顺序，或者 “Impossible!” 表示无解（不含引号）。

样例输入输出

**样例输入 #1**复制

```
3
5 2
4 3
5 2
5 4
5 4
5 3
4 2
3 2
3 3
1 2
2 3
3 1
```

**样例输出 #1**复制

```
1 5 2 4 3
1 5 3 4 2
Impossible!
```

数据范围

100% 的数据满足 N≤100000，M≤100000，

#### Answer

```cpp
#include <bits/stdc++.h>
using namespace std;
int t,m,n,in[100010],tp[100010];
vector <int> p[100010];
priority_queue < int,vector<int>,less<int> > q;
int main () {
    cin >> t;
    for (int i=1;i<=t;i++) {
        cin >> n >> m;
        for (int j=1;j<=100000;j++) {
            p[j].clear();
        }
        memset (in,0,sizeof(in));
        memset (tp,0,sizeof(tp));
        for (int j=1;j<=m;j++) {
            int x,y;
            cin >> x >> y;
            p[y].push_back(x);
            in[x]++;
        }
        for (int j=1;j<=n;j++) {
            if (in[j]==0) {
                q.push(j);
            }
        }
        int cnt=0;
        while (!q.empty()) {
            int a=q.top();
            q.pop();
            cnt++;
            tp[cnt]=a;
            for (int j=0;j<p[a].size();j++) {
                if (--in[p[a][j]]==0) {
                    q.push(p[a][j]);
                }
            }
        }
        if (cnt!=n) {
            cout << "Impossible!";
        } else {
            for (int j=cnt;j>=1;j--) {
                cout << tp[j] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
```



### H:神经网络

#### Question

题目描述

人工神经网络（Artificial Neural Network）是一种新兴的具有自我学习能力的计算系统，在模式识别、函数逼近及贷款风险评估等诸多领域有广泛的应用。对神经网络的研究一直是当今的热门方向，兰兰同学在自学了一本神经网络的入门书籍后，提出了一个简化模型，他希望你能帮助他用程序检验这个神经网络模型的实用性。

在兰兰的模型中，神经网络就是一张有向图，图中的节点称为神经元，而且两个神经元之间至多有一条边相连，下图是一个神经元的例子：

![img](http://www.xmoj.tech/upload/image/20181123/20181123233849_42621.png)

​               神经元〔编号为 i）

图中，X1—X3是信息输入渠道，Y1－Y2是信息输出渠道，Ci 表示神经元目前的状态，Ui 是阈值，可视为神经元的一个内在参数。

神经元按一定的顺序排列，构成整个神经网络。在兰兰的模型之中，神经网络中的神经无分为几层；称为输入层、输出层，和若干个中间层。每层神经元只向下一层的神经元输出信息，只从上一层神经元接受信息。下图是一个简单的三层神经网络的例子。

![img](http://www.xmoj.tech/upload/image/20181123/20181123233923_77304.png)

兰兰规定，Ci 服从公式（1<=i<=n，其中 n 是网络中所有神经元的数目）：

![img](http://www.xmoj.tech/upload/image/20181123/20181123233951_54717.png)

公式中的Wj,i（可能为负值）表示连接 j 号神经元和 i 号神经元的边的权值。当 Ci 大于 0 时，该神经元处于兴奋状态，否则就处于平静状态。当神经元处于兴奋状态时，下一秒它会向其他神经元传送信号，信号的强度为 Ci。

如此．在输入层神经元被激发之后，整个网络系统就在信息传输的推动下进行运作。现在，给定一个神经网络，及当前输入层神经元的状态（Ci），要求你的程序运算出最后网络输出层的状态。

输入

第一行是两个整数 n（1≤n≤200）和 p。

接下来 n 行，每行两个整数，第 i＋1 行是神经元 i 最初状态和其阈值（Ui），非输入层的神经元开始时状态必然为0。

再下面 p 行，每行由两个整数 i，j 及一个整数 Wi,j，表示连接神经元 i、j 的边权值为 Wi,j。

输出

包含若干行，每行有两个整数，分别对应一个神经元的编号，及其最后的状态，两个整数间以空格分隔。仅输出最后状态大于零的输出层神经元状态，并且按照编号由小到大顺序输出！

若输出层的神经元最后状态均为 0，则输出 NULL。

样例输入输出

**样例输入 #1**复制

```
5 6
1 0
1 0
0 1
0 1
0 1
1 3 1
1 4 1
1 5 1
2 3 1
2 4 1
2 5 1
```

#### Answer

```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,maxm=maxn*2+10;
int n,m,In[maxn],Out[maxn],U[maxn],num[maxn],ans;
int tot,Head[maxn],Next[maxm],To[maxm],W[maxm];
queue<int> Q;
void add(int u,int v,int w)
{
    Next[++tot]=Head[u]; To[tot]=v; W[tot]=w; Head[u]=tot;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d%d",&num[i],&U[i]);
    for (int i=1,u,v,w;i<=m;++i) {
        scanf("%d%d%d",&u,&v,&w);
        ++In[v];
        ++Out[u];
        add(u,v,w);
    }
    for (int i=1;i<=n;++i)
        if (In[i]==0&&num[i]>0)
            Q.push(i);
        else if (In[i]!=0)
            num[i]-=U[i];
    while (!Q.empty()) {
        int now=Q.front(); Q.pop();
        if (num[now]<=0) continue;
        for (int i=Head[now];i;i=Next[i]) {
            int v=To[i],w=W[i];
            num[v]+=num[now]*w; 
            if (In[v]==0) continue;
            if (--In[v]==0)
                Q.push(v);
        }
          
    }
    int s=0;
    for (int i=1;i<=n;++i)
        if (Out[i]==0&&num[i]>0)
            printf("%d %d\n",i,num[i]),s+=1;
    if (s==0) printf("NULL\n");
    return 0;
}
```



### I: 飞行计划-1

#### Question

题目描述

小明去参观了下海市国际机场的调度中心，发现调度中心每天非常忙碌，需要为很多架飞机安排起飞的时间。机场只有一根跑道，有 N 架飞机需要安排起飞，飞机的编号分别是 1,2,...,N，安排起飞顺序后，每一架飞机有一个起飞序号。复杂的是，这 N 架飞机的起飞安排都很多的限制条件，限制条件有两种类型：

1、每一架飞机的起飞序号必须不能超过 Xi

2、A 飞机必须比 B 飞机早起飞

现在小明想知道，在这两类限制条件下，每架飞机在所有可能方案中的最小起飞序号是多少。

输入

第 1 行，两个整数 N 和 M，N 表示飞机数量，M 表示第二类限制条件的数量。

第 2 行，N 个正整数 X1,X2,...,XN，表示第 i 架飞机的起飞序列不能超过 Xi。

接下来 M 行，每行两个整数 A 和 B，表示 A 飞机必须在 B 飞机之前起飞。

输出

第二行，N 个整数 T1,T2,...,TN，Ti 表示第 i 架飞机在所有可能方案中的最小起飞序号。

样例输入输出

**样例输入 #1**复制

```
5 5
4 5 2 5 4
3 1
3 4
5 1
3 2
1 2
```

**样例输出 #1**复制

```
3 4 1 2 1
```

样例说明 #1

所有满足要求的起飞序列是：

3 4 5 1 2，5 3 1 2 4，3 5 1 2 4，5 3 1 4 2，3 5 1 4 2，5 3 4 1 2，3 5 4 1 2

对于第 

1

 架飞机，由于有 

(5,1)

、

(3,1)

 两个限制，最小的起飞序号为 

3

。其他飞机类似。

数据范围

30% 的数据，N≤10；

60% 的数据，N≤500；

100% 的数据，N≤2000，M≤10000，至少存在一个可行的起飞方案。

```cpp

```

#### Answer

```cpp
# include <bits/stdc++.h>
using namespace std;
const int N=2005;
int dee[N], d[N], ans[N], t[N];
vector<int> g[N];
struct cmp {
    bool operator() (int a,int b) {
        return t[a]>t[b];
    }
};
priority_queue<int, vector<int>, cmp> q;
int main ()
{
    int n, m, u, v, num;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",t+i), t[i]=n-t[i];
    for (int i=1;i<=m;++i)
        scanf("%d%d",&u,&v), g[v].push_back(u), ++dee[u];
    for (int i=1;i<=n;++i) {
        num=0;
        memcpy(d,dee,sizeof(d));
        for (int j=1;j<=n;++j)
            if (d[j]==0&&j!=i) q.push(j);
        while (!q.empty()) {
            u=q.top(); q.pop();
            if (t[u]>num) break;
            ++num;
            for (int j=0;j<g[u].size();++j) {
                --d[v=g[u][j]];
                if (d[v]==0&&v!=i) q.push(v);
            }
        }
        ans[i]=n-num;
        while (!q.empty()) q.pop();
    }
    for (int i=1;i<=n;++i) printf("%d%c",ans[i],i<n?' ':'\n');
    return 0;
}
```



## Contest

### A: Matrix

#### Question

题目描述

给定两个长度为 n 的整数序列 l 和 t，分别作为 n×n 矩阵 F 的第一列和第一行，并且保证 l1=t1。同时矩阵中的任意其他元素 Fi,j 由以下递推给定：

Fi,j=a⋅Fi,j−1+b⋅Fi−1,j

给定系数 a,b，要求计算 Fn,n 模 109+7 的值。

输入

第一行包含三个整数 n,a,b。

第二行包含 n 个整数 li。

第三行包含 n 个整数 ti。

输出

共一行包含一个整数，表示 Fn,n 模 109+7 的值。

样例输入输出

**样例输入 #1**复制

```
4 3 5
4 1 7 3
4 7 4 8
```

**样例输出 #1**复制

```
59716
```

数据范围

对于 40% 的数据，n,a,b,li,ti≤5000。

对于另外 20% 的数据，a=0。

对于 100% 的数据，n,a,b,li,ti≤100000。

#### Method

算法一：暴力，时间复杂度 O(N2)。

算法二：a=0 时，不同列的元素之间没有任何的影响，每一个元素只会将自己的值乘以 b 之后转移给同一列的下一个元素，所以答案为 tn⋅bn−1，时间复杂度 O(log⁡N)。

算法三：扩展算法二，考虑贡献法。

每个 ti 对答案的贡献可以拆分为矩阵中从这个点到达右下角的所有路径，每次向右则乘以 a，向下则乘以 b，最后计算总和得到 C2n−i−2n−2⋅an−i⋅bn−1。

li 同理，可以得到每个 li 的贡献是 C2n−i−2n−2⋅an−1⋅bn−i。

时间复杂度 O(Nlog⁡N)。

#### Answer

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int MAXN= 100005;
ll n,a,b,l[MAXN],t[MAXN],ans;
ll C[MAXN*2],pa[MAXN],pb[MAXN];
ll ksm(ll x,int y)
{
    ll ret=1;
    while (y) {
        if (y&1) ret=ret*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ret;
}
int main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    scanf("%lld%lld%lld",&n,&a,&b);
    for (int i=1;i<=n;++i) scanf("%lld",&l[i]);
    for (int i=1;i<=n;++i) scanf("%lld",&t[i]);
    C[0]=1;
    for (int i=1;i<=n;++i) C[i]=C[i-1]*ksm(i,MOD-2)%MOD*(i+n-2)%MOD;
    pa[0]=pb[0]=1;
    for (int i=1;i<=n;++i) pa[i]=pa[i-1]*a%MOD;
    for (int i=1;i<=n;++i) pb[i]=pb[i-1]*b%MOD;
    for (int i=2;i<=n;++i) {
        ans+=t[i]*pb[n-1]%MOD*pa[n-i]%MOD*C[n-i]%MOD;
        ans%=MOD;
    }
    for (int i=2;i<=n;++i) {
        ans+=l[i]*pb[n-i]%MOD*pa[n-1]%MOD*C[n-i]%MOD;
        ans%=MOD;
    }
    printf("%lld\n",ans);
    return 0;
}
```



### B: Binary

#### Question

题目描述

给定一个长度为 n 的整数数列 a 和 q 次操作：

修改操作：1 x y，表示将 ax 的值修改为 y；

询问操作：2 x y，表示询问 ∑i=1n(ai+x) and y 的值。其中 and 表示二进制按位与操作。

输入

第一行包含两个整数 n,q。

第二行包含 n 个整数 ai。

之后 q 行每行包含三个整数 opt,x,y 表示一个询问，形式如题目描述。

输出

对于每一个询问操作，输出一行包含一个整数，表示该询问操作的答案。

样例输入输出

**样例输入 #1**复制

```
6 6
8 9 1 13 9 3
1 4 5
2 6 9
1 3 7
2 7 7
1 6 1
2 11 13
```

**样例输出 #1**复制

```
45
19
21
```

数据范围

对于 40% 的数据，n,q≤5000。

对于另外 20% 的数据，所有询问操作满足 x=0。

对于 100% 的数据，n,q≤100000，0≤ai,x,y<220。

#### Method

算法一：暴力，时间复杂度 O(nq)。

算法二：x=0 即对原数列进行位运算并求和，而位运算操作对于每一个二进制位是独立的，即只需要知道原数列中第 i 个二进制位中 1 出现的次数，而不需要知道具体的每个元素。

将每一个询问按照二进制位拆分后，如果第 i 位是 1，则将答案增加 fi⋅2i−1。

时间复杂度 O(nlog⁡n)

算法三：继续算法二的思路，将询问中的 y 按照二进制位拆分。x and 2i−1 的结果是随着 x 循环出现的。2i−1 个 0 和 2i−1 个 2i−1 轮流出现。

所以将所有的数对 2i 取模后建树状数组，并询问模在 [−x+2i−1,−x+2i−1] 区间中的个数，再和算法二一样处理。

时间复杂度 O(nlog2⁡n)。

#### Answer

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010;
int n,q;
ll s;
int a[N],f[21][(1<<20)+10];
void add(int k,int x,int v) {
    for (int i=x;i<=(1<<k);i+=i&(-i)) f[k][i]+=v;
}
int sum(int k,int x) {
    int ret=0;
    for (int i=x;i;i-=i&(-i)) ret+=f[k][i];
    return ret;
}
int main() {
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1;i<=n;++i)
        for (int k=1;k<=20;++k)
            add(k,a[i]%(1<<k)+1,1);
    for (int i=1,op,x,y;i<=q;++i) {
        scanf("%d%d%d",&op,&x,&y);
        if (op==1) {
            for (int k=1;k<=20;++k) {
                add(k,a[x]%(1<<k)+1,-1);
                add(k,y%(1<<k)+1,1);
            }
            a[x]=y;
        } else {
            s=0;
            for (int k=1,l,r;k<=20;++k) {
                if (y&(1<<(k-1))) {
                    r=((1<<20)-x)%(1<<k);
                    l=(r+(1<<(k-1)))%(1<<k);
                    s+=(ll)(sum(k,r)-sum(k,l)+n*(l>r))<<(k-1);
                }
            }
            printf("%lld\n",s);
        }
    }
}
```





### C

#### Question

题目描述

小明的家是一幢 h 层的摩天大楼，为了方便访客，物业将其中的一个电梯改造成了跳楼机。

经过改造，跳楼机可以采用以下四种方式移动：

\1. 向上移动 x 层；

\2. 向上移动 y 层；

\3. 向上移动 z 层；

\4. 回到第一层。

一个月黑风高的大中午，小红来到了小明的家，现在她在第一层，碰巧跳楼机也在第一层。小红想知道，她可以乘坐跳楼机前往的楼层数。

输入

第一行一个整数 h，表示摩天大楼的层数。

第二行三个正整数，分别表示题目中的 x,y,z。

输出

一行一个整数，表示小红可以到达的楼层数。

样例输入输出

**样例输入 #1**复制

```
15
4 7 9
```

**样例输出 #1**复制

```
9
```

样例说明 #1

可以到达的楼层有：1,5,8,9,10,12,13,14,15。

数据范围

对于 20% 的数据，1≤h,x,y,z≤100；

对于 40% 的数据，1≤h,x,y,z≤105；

对于 100% 的数据，1≤h≤1018，1≤x,y,z≤105。

#### Method

算法一：

BFS，期望得分 20 分。



算法二：

状态过多，考虑减少状态。

记 di=c 表示在满足 cmodx=i 的前提下，仅通过第二和第三个操作可以到达的最小楼层 c。

最后的答案是：∑i=0x−1(⌊h−dix⌋+1)。

考虑如何计算 di。显然有如下两种转移：

d(i+y)modx=di+y

d(i+z)modx=di+z

不难发现，这是一个最短路模型，可以用 SPFA 或堆优化的 Dijkstra 解决。

#### Answer

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> plli;
 
const int N = 110000;
struct Edge { int u,v,w,nxt;
    // int from, to, len, nxt;
} E[N<<1];
int head[N],vis[N];
priority_queue<plli> q;
ll h,ans,d[N];
int x,y,z,tot;
 
inline void addEdge(int u,int v,int w) {
    E[++tot]=(Edge){u,v,w,head[u]};
    head[u]=tot;
}
void Dijkstra() {
    memset(d,0x3f,sizeof(d));
    d[1%x]=1;
    q.push(make_pair(-d[1%x],1%x));
    while(!q.empty()) {
        plli now=q.top(); q.pop();
        if (vis[now.second]) continue;
        int u=now.second; vis[u]=1;
        for(int i=head[u],v,w;i;i=E[i].nxt) {
            v=E[i].v,w=E[i].w;
            if (!vis[v]&&d[u]+w<=h&&d[u]+w<d[v]) {
                d[v]=d[u]+w;
                q.push(make_pair(-d[v],v));
            }
        }
    }
}
int main() {
    freopen("jump.in", "r", stdin);
    freopen("jump.out", "w", stdout);
    scanf("%lld%d%d%d",&h,&x,&y,&z);
    for (int i=0;i<x;++i) {
        addEdge(i,(i+y)%x,y);
        addEdge(i,(i+z)%x,z);
    }
    Dijkstra();
    for (int i=0;i<x;++i)
        if (d[i] <= h)
            ans+=(h-d[i])/x+1;
    printf("%lld\n", ans);
    return 0;
}
```



