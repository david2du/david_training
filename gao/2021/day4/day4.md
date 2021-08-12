# Day4



## 并查集



+ 如何查找根节点

  ```c++
  int find(int t)
  {
      if (father[t] == t)
      {
          return t;
      }
  
      return find(father[t]);
  }
  ```

  

+ 如何合并两树

  ```c++
  father[find(y)]=find(x);
  ```

  

+ 路径压缩

  + 链式树并查集效率慢

  ```c++
  int find(int t)
  {
      if (father[t] == t)
      {
          return t;
      }
  
      return father[t] = find(father[t]);
  }
  ```

  + m次查询：O(m *a*(m)) = O(1)

---

[宴席](http://www.xmoj.tech/problem.php?cid=3763&pid=1)

维护size

一个大小为*x*的并查集，要[x/10]桌



## 树状数组

+ 完成两种操作

  + 更新单个元素
  + 对子段求和

+ *c[i] = SIGMA{j=i - 2 ^ k + 1, i}a[i]*,k为二进制下零的个数

  + 2 ^ k = LOW_BIT(*x*)=x and (x xor (x - 1))=x & (-x), **LOWBIT(X)为X二进制末位1的位置**

  ```c++
  int lowbit(int x)
  {
      return x & (-x);
  }
  ```

  

+ 更改一个a, 可能会修改很多Ci

  ```c++
  void add(int x, int d)
  {
      while(x <= n)
      {
          c[x] += t;
          x += lowbit(x); // 提升一层
      }
  }
  ```

+ 计算子段和

  ```c++
  int sum(int x)
  {
      int v = 0;
      while(x > 0)
      {
          v += c[x];
          x -= lowbit(x);
      }
    
      return v;
  }
  ```

  

+ **下标一定不能从零开始!!!**



## 线段树

+ 完成两种操作
  + 更新单个元素
  + 对子段求最值

+ 平衡二叉树
  + 深度不超过*log(N)*
+ 构建

```c++
int n;
int val[MAXN << 2];
int lazy[MAXN << 2];
int init_val[MAXN];

void push_up()
{
  
}

void update_one(int rt, int l, int idx, int add)
{
  if (l == r)
  {
    val[rt] += add;
    return;
  }
  int mid = (l + r) / 2;
  if (idx <= mid)
  {
      update_one(rt * 2, l, mid, idx, add);
  }
  else
  {
      update_one(rt * 2 + 1, mid + 1, r, idx, add);
  }
  push_up(rt);
}

void push_down()
{
  if (lazy[rt] != 0)
  {
    lazy[rt* 2] += lazy[rt];
    lazy[rt* 2 + 1] += lazy[rt];
  }
}

int query(int rt, int l, int r, int ql, int qr)
{
    if (ql > r || qr < l)
    {
        return 0;
    }
    if (ql <= l && qr >= r)
    {
        return val[rt];
    }
    push_down(rt);

    int mid = (l + r) / 2;

    return min(query(rt * 2, l, mid, ql, qr), query(rt * 2 + 1, mid + 1, r, ql, qr));
}

void update(int rt, int l, int r, int ul, int ur, int add)
{
    if (ul > r || ul < l)
    {
      return;
    }
    if (ul <= l || ur >= r)
    {
      val[rt] += add;
      lazy[rt] += add;
    }
    push_down(rt);
  
    int mid = (l + r) / 2;
  
    update(rt * 2, l, mid, ul, ur, add);
    update(rt * 2 + 1, mid + 1, r, ul, ur, add);
  
    push_up(rt);
}
```

+ 求和

```c++
int n;
int val[MAXN << 2];
int lazy[MAXN << 2];
int init_val[MAXN];
```

