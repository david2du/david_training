## [NOI](http://noi.openjudge.cn/)**/4.6算法之贪心**


- [题目](http://noi.openjudge.cn/ch0406/)
- [排名](http://noi.openjudge.cn/ch0406/ranking/)
- [状态](http://noi.openjudge.cn/ch0406/status/)
- [提问](http://noi.openjudge.cn/ch0406/clarify/)

## 2407: Bookshelf

- [View](http://noi.openjudge.cn/ch0406/2407/)
- [Submit](http://noi.openjudge.cn/ch0406/2407/submit/)
- [Statistics](http://noi.openjudge.cn/ch0406/2407/statistics/)
- [Clarify](http://noi.openjudge.cn/ch0406/clarify/2407/)

- **Total Time Limit**

  **20000** *ms*

- **Single Test Time Limit**

  **1000** *ms*

- **Memory Limit**

  **65536** *KB*

### Description

- Farmer John recently bought a bookshelf for cow library, but the shelf is getting filled up quite quickly, and now the only available space is at the top.  Each of the N cows (1 <= N <= 20,000) has some height of H_i (1 <= H_i <= 10,000) and a total height summed across all N cows of S. The bookshelf has a height of B (1 <= B <= S < 2,000,000,007).  To reach the top of the bookshelf taller than the tallest cow, one or more of the cows can stand on top of each other in a stack, so that their total height is the sum of each of their individual heights. This total height must be no less than the height of the bookshelf. Since more cows than necessary in the stack can be dangerous, your job is to find the set of cows that produces a stack of the smallest number of cows possible such that the stack can reach the bookshelf.


- **Input**

   Line 1: Two space-separated integers: N and B  * Lines 2..N+1: Line i+1 contains a single integer: H_i


- **Output**

  Line 1: A single integer representing the size of the smallest set of cows that can reach the bookshelf.

### Sample Input & Output

- **Sample Input**

```
6 40
6
18
11
13
19
11
```

- **Sample Output**

```
3
```

- **Hint**

  *INPUT DETAILS:  Six cows; bookshelf height 40. Cow heights fall in the range 6..19.  OUTPUT DETAILS:  One way to reach 40 with 3 cows is 18+11+13; many others exist*

### Source

  **USACO December 2007 Bronze**





### Chinese Version
___

#### 2407:书架

- [查看](http://noi.openjudge.cn/ch0406/2407/)
- [提交](http://noi.openjudge.cn/ch0406/2407/submit/)
- [统计](http://noi.openjudge.cn/ch0406/2407/statistics/)
- [提问](http://noi.openjudge.cn/ch0406/clarify/2407/)

- **总时间限制**

  **20000** *ms*

- **单个测试点时间限制**

  **1000** *ms*

- **内存限制**

  **65536** *KB*

#### 描述

- John最近买了一个书架用来存放奶牛养殖书籍，但书架很快被存满了，只剩最顶层有空余。 John共有N头奶牛(1 ≤ N ≤ 20,000)，每头奶牛有自己的高度Hi(1 ≤ Hi ≤ 10,000)，N头奶牛的总高度为S。书架高度为B(1 ≤ B ≤ S < 2,000,000,007). 为了到达书架顶层，奶牛可以踩着其他奶牛的背，像叠罗汉一样，直到他们的总高度不低于书架高度。当然若奶牛越多则危险性越大。为了帮助John到达书架顶层，找出使用奶牛数目最少的解决方案吧。 

- 输入

  第1行：空格隔开的整数N和B 第2~N+1行：第i+1行为整数Hi

- 输出

  能达到书架高度所使用奶牛的最少数目

#### 样例输入输出
- **样例输入**

```
6 40
6
18
11
13
19
11
```

- **样例输出**

```
3
```





## 2390: Pearl Pairing

- [View](http://noi.openjudge.cn/ch0406/2390/)
- [Submit](http://noi.openjudge.cn/ch0406/2390/submit/)
- [Statistics](http://noi.openjudge.cn/ch0406/2390/statistics/)
- [Clarify](http://noi.openjudge.cn/ch0406/clarify/2390/)

- **Total Time Limit**

  **10000** *ms*

- **Single Test Time Limit**

  **1000** *ms*

- **Memory Limit**

  **65536** *KB*

### Description

- At Bessie's recent birthday party, she received N (2 <= N <= 100,000; N%2 == 0) pearls, each painted one of C different colors (1 <= C <= N).  Upon observing that the number of pearls N is always even, her creative juices flowed and she decided to pair the pearls so that each pair of pearls has two different colors.  Knowing that such a set of pairings is always possible for the supplied testcases, help Bessie perform such a pairing. If there are multiple ways of creating a pairing, any solution suffices.

- Input

  - Line 1: Two space-separated integers: N and C
  - Lines 2..C + 1: Line i+1 tells the count of pearls with color i: C_i

- Output

  Lines 1..N/2: Line i contains two integers a_i and b_i indicating that Bessie can pair two pearls with respective colors a_i and b_i.

### Sample Input & Output

- Sample Input

```
8 3
2
2
4
```

- Sample Output

```
1 3
1 3
2 3
3 2
```

- Hint

  *INPUT DETAILS:  There are 8 pearls and 3 different colors. Two pearls have color I; two have color II; four have color III.  OUTPUT DETAILS:  Bessie pairs each pearl of color III with one of color I and II.*

### Source

  **USACO March 2008 Gold**





## 3527:胡

- [查看](http://noi.openjudge.cn/ch0406/3527/)
- [提交](http://noi.openjudge.cn/ch0406/3527/submit/)
- [统计](http://noi.openjudge.cn/ch0406/3527/statistics/)
- [提问](http://noi.openjudge.cn/ch0406/clarify/3527/)

- **总时间限制**

  **1000** *ms*

- **内存限制**

  **65536** *KB*

### 描述

- 对于一个元素为数字1-9的集合A（每个数字的数量不超过4个，集合中元素的数量不超过14个），判断其是否满足如下规则： 　　集合A可以分割为若干个由3个数字组成的集合Bo...Bn和一个由2个数字组成的集合C。其中Bo...Bn需要满足每个集合中的数字均相等或者依次递增一（例如5 5 5以及4 5 6均满足条件）；C中的两个数字相等
- 显然，当集合中的元素个数等于3n+2（n=0，1..4）时才有可能满足上述条件，我们将元素个数不为3n+2的集合称为“相公”的集合，满足上述条件的集合称为能够“胡”的集合，否则则是“不胡”的集合
___

- 输入

  　　​	输入的每一行包括一组测试数据，测试数据的开头为0表示测试结束；每一组数据由若干个1-9的数字组成，数字之间用空格隔开

- 输出

    ​	每一行输出对应一行输入的结果，对于“相公”的集合输出“XIANGGONG”；对于满足“胡”的集合，输出“HU”；否则输出“BUHU”

### 样例输入输出

- 样例输入

```
1 2
4 4
1 1 1 2 3 4 5 6 7 8 9 9 9
1 1 1 2 3 4 5 6 7 8 9 9 9 9
0
```

- 样例输出

```
BUHU HU XIANGGONG HU
```