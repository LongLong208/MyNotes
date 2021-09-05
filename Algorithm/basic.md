<head>
<style>
*{
    font-family:consolas;
}
html body h2{
    color:#a4f3d1;
    text-align:center;
}
html body h3{
    color:#e06666;
}
html body h4{
    color:pink;
}
html body h5{
    color:#e4e79b;
}
html body code {
    color: #83ee73;
}
.short {
    width:60%;
    background-color:rgba(0,0,0,0);
    border-bottom:4px dotted #515151;
}
.code-output {
    background-color: #323232;
    padding: .8em;
    margin: 1em 0px;
}
.code-hr {
    margin:3em 0px .5em 0px;
}
</style>
</head>


```cpp {cmd="run" id="sf" hide}
//sf
```

<font style="font-size:30px; font-weight:bold;">算法</font>



[TOC]

---

<br>

### 模板



```markdown

___
## 大分类
<hr class=short>

### 小分类（具体问题）

#### 方法或内容分类


分隔符：
大分类之间的间隔使用：

<br>

___

小分类之间分隔使用： 

<br>
<hr class=short>

最小的间隔：

<br>
<hr width=20%>

```

**示例：**

<div style="padding:2% 5% 2% 5%; background-color:#323232">


<!-- ********************************************************************************* -->
<!-- ********************************************************************************! -->
<!-- ********************************************************************************? -->
<!-- *****************************************************************************todo -->

---
## 三角形
<hr class=short>


### 三角形的周长

周长公式： $C = a + b + c$

<br><hr class=short>

### 三角形的面积

#### 公式1

$S=\frac{d \times h}{2} $

<br><br>

#### 公式2

$S=\sqrt{p(p-a)(p-b)(p-c)},~ p = \frac{a+b+c}{2}$

<br>
<br>
<br>



<!-- *****************************************************************************todo -->
<!-- ********************************************************************************? -->
<!-- ********************************************************************************! -->
<!-- ********************************************************************************* -->

---

</div>

<br>
<br>
<br>

---
## 一些笔记
<hr class=short>

### 面试问题

https://leetcode-cn.com/leetbook/read/top-interview-questions/xmted6/

```mermaid
graph LR;
T{问题类型}

A(操作系统)
T --- A
A --- 内存管理
A --- 线程处理
A --- 文件系统
A --- 网络

B(编程)
T --- B
B --- 语言
B --- 递归,继承,类型

C(算法)
T --- C
C --- 时间复杂度
C --- 搜索
C --- 排序
C --- 图

D(数据结构)
T --- D
D --- 数组
D --- 堆,队列,栈
D --- 树,图
D --- 集
D --- 哈希,映射

E(数学)
T --- E
E --- 概率
E --- 平方
E --- 阶乘
E --- 整除

T ---- F(系统设计)

```

<br><br><hr class=short>

### 算法与数据结构

https://leetcode-cn.com/leetbook/read/top-interview-questions/xmted6/

#### 算法

1. 排序算法：快排、归并、计数
2. 搜索算法：回溯、递归、剪枝技巧
3. 图论：最短路、最小生成树、网络流建模
4. 动态规划：背包问题、最长子序列、计数问题
5. 技巧：分治、倍增、二分、贪心

#### 数据结构

1. 数组与链表：单/双向链表、跳舞链
2. 栈与队列
3. 树与图：最近公共祖先、并查集
4. 哈希表
5. 堆：大/小根堆、可并堆
6. 字符串：字典树、后缀树

<br>
<br>
<br>

---

## 数论
算法中，数论常见的问题都是关于质数
<hr class=short>

### 质数

#### 质数的判断

对某个数 $n$ 是不是质数的判断：

遍历 $1 < x \le \sqrt{n}$ ， 若有 `n % x==0`，则不是质数

遍历前可先判断： $n$ 是不是 `大于 2 的偶数`

若满足此条件则必不为质数

<br>
<br>

#### 分解质因数

任何一个大于 1 的正整数 $n$，如果 $n$ 不是质数，那么 $n$ 可以唯一地分解成有限个质数的乘积

<br>
<br>

#### 最大公约数 gcd

求两数 $a,b$ 的最大公约数算法

##### 更相减损术

核心：`gcd(a, b) = gcd(b, a - b)`

```cpp {cmd=run continue=sf}
int gcd(int a, int b)
{
    if(a == b)  // 递归出口
        return a;
    if(a != b && a % 2 == 0 && b % 2 == 0)
    {
        // a b 都是偶数，用 2 约分
        while(a % 2 == 0) a /= 2;
        while(b % 2 == 0) b /= 2;
        return gcd(a, b);
    }
    if(a < b)
        return gcd(a, b - a);
    return gcd(b, a-b);
}
```
```cpp {cmd=run continue hide}
//entry
int a,b;
input >> a >> b;
if(input)
    output << gcd(a, b);
//test
```
```cpp {cmd=run continue}
63 98
260 104
```

<br>
<br>

##### 辗转相除法（欧几里得算法）

核心：`gcd(a, b) = gcd(b, a mod b)`

```cpp {cmd=run continue=sf}
int gcd(int a, int b)
{
    if(a < b)
        return gcd(b, a);
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}
```
```cpp {cmd=run continue hide}
//entry
int a,b;
input >> a >> b;
if(input)
    output << gcd(a, b);
//test
```
```cpp {cmd=run continue}
63 98
260 104
```

<br><br>

##### 裴蜀定理

表述：若 $\gcd (a, b) = c$, 那么对于任意整数对 $(x, y)$, $ax+by$ 一定是 $c$ 的倍数

特别的， 一定存在整数对 $x, y$, 使得 $ax+by=c$

推论：$a, b$ 互质 $\Leftrightarrow$ 存在整数对 $(x, y)$，使得 $ax+by=1$ 


<br>
<br>
<br>

---

## 数学几何

<br><hr class=short>

### 平面几何

#### 直线

##### 直线方程

一般式：$Ax+By+C=0$

斜截式：$y=kx+b$

截距式：$\frac{x}{a}+\frac{y}{b} = 1$

点斜式：$y-y_0=k(x-x_0)$

两点式：$\frac{x~-~x2}{x1-x2} = \frac{y~-~y2}{y1-y2}$

<br><br>

##### 点到直线的距离

点 $(x_0, y_0)$ 到直线 $Ax+By+C=0$ 的距离

公式： $d=\frac{|Ax_0+By_0+C|}{\sqrt{A^2+B^2}}$

<br><br>

#### 矩形

##### 矩形重叠问题

以 $[x1, y1, x2, y2]$ 的形式给出两个矩形 $rec1$, $rec2$ ，其中矩形的两边分别平行于 $x$ 轴和 $y$ 轴， $[x1, y1]$ 表示矩形左下角的点坐标， $[x2, y2]$ 表示矩形右上角坐标

问题：输入 $ax1, ay1, ax2, ay2, bx1, by1, bx2, by2$ ， 返回两个矩形是否重叠

思路：两个矩形重叠时，他们的 x 和 y 坐标范围有重叠

关键代码： 

```cpp 
ax1 < bx2 && bx1 < ax2 && ay1 < by2 && by1 < ay2
```

<br><br>

##### 矩形重叠面积

矩形表示方式同上

问题：输入 $ax1, ay1, ax2, ay2, bx1, by1, bx2, by2$ ， 返回两个矩形的重叠面积

关键代码：

```cpp
(min(ax2, bx2) - max(ax1, bx1)) * (min(ay2, by2) - max(ay1, by1))
```

<br><br>

#### 圆

##### 圆的方程

$(x-a)^2+(y-b)^2=r^2$

其中： 圆心坐标：$[a, b]$，半径：$r$


<br>
<br>
<br>

---
## 随机算法
<hr class=short>

### 权重随机算法

输入数组 `name` 和正整数数组 `w` ，其中每个元素 `w[i]` 表示选择到 `name[i]` 的权重，那么调用随机选择函数时，选择到 `i` 的概率为 $w[i]~/~sum(w)$

请你设计一个算法，实现这个随机选择函数

方法：前缀和 + 二分查找

思路：构造 `w` 数组的前缀和数组 `s`，随机生成一个索引 `x`，返回数组 `s` 中第一个大于等于 `x` 的元素的下标

表格解析：

|     w[i]     |   1   |   1   |   2   |   3   |
| :----------: | :---: | :---: | :---: | :---: |
|     s[i]     |   1   |   2   |   4   |   7   |
| 随机索引 `x` |   1   |   2   |  3 4  | 5 6 7 |

解释：如 x = 5,6,7 时，匹配到的是 w 中权重为 3 的下标，而且刚好 x 的取值有 3 个，满足的权重为 3 的要求


代码：
```cpp {cmd=run continue=sf}
class RandomSelect {
        vector<int> pre;
public:
    RandomSelect(vector<int>& w) {
        srand(time(0));
        pre.resize(w.size() + 1);
        pre[0] = 0;
        for (int i = 1; i < pre.size(); ++i) {
            pre[i] = pre[i - 1] + w[i - 1];
        }
    }
    
    int pickIndex() {
        int ran = rand() % pre[pre.size() - 1] + 1;
        int l = 1, r = pre.size() - 1, m = (l + r) / 2;
        int index = pre.size() - 1;
        while(l <= r) {
            if (pre[m] >= ran) {
                r = m - 1;
                index = m;
            } else {
                l = m + 1;
            }
            m = (l + r) / 2;
        }

        return index - 1;
    }
};
```
```cpp {cmd=run continue hide}
//entry
vector<int> w;
vector<string> name;
input >> w >> name;
if(input)
{
    RandomSelect rs(w);
    vector<vector<string>> res;
    for (int i = 0; i < 5; ++i) {
        vector<string> temp;
        for (int j = 0; j < 10; ++j) {
            temp.push_back(name[rs.pickIndex()]);
        }
        res.push_back(temp);
    }
    cout << res;
}
//test
```
```cpp {cmd=run continue}
//模拟一下某游戏抽卡
[40,50,8,2][白,紫,橙,彩]
```



<br>
<br>
<br>

---
## 位运算
<hr class=short>

### N进制转十进制

$ 720.5_{(8)} = ~ ? $

<div align=center>

$720.5_{(8)} = 7×8^{2}+2×8^{1}+0×8^{0}+5×8^{−1} = 464.625$

</div>

<br><br>


### 十进制转N进制

#### 整数转换

$ 50_{(10)} = ~ ? _{(2)} $


<div align=center>

$ 50 \div 2 = 25 ~余~ 0  $
$ 25 \div 2 = 12 ~余~ 1  $
$ 12 \div 2 = 6 ~余~ 0  $
$ 6 \div 2 = 3 ~余~ 0 $
$ 3 \div 2 = 1 ~余~ 1 $
$ 1 \div 2 = 0 ~余~ 1 $

</div>

余数反向遍历： 1 1 0 0 1 0， 因此 $50_{(10)} = 110010_{(2)}$

<br><br>

#### 小数转换

$
0.6875_{(10)} = ~ ? _{(2)}
$

<div align=center>

$ 0.6875×2=1.375 ~整数部分~ 1  $
$ 0.375×2=0.75 ~整数部分~ 0 $
$ 0.75×2=1.5 ~整数部分~ 1 $
$ 0.5×2=1 ~整数部分~ 1 $

</div>


整数部分正序遍历： 1 0 1 1，因此 $0.6875_{(10)} = 0.1011_{(2)}$

<br><hr class=short>

### 位运算的性质

幂等律： | &（幂等于它本身）
交换律： | & ^
结合律： | & ^

分配律： | 对 &，| 对 &，& 对 ^（类比 乘法对加法）
德摩根率： $\sim(a~\&~b) = ~\sim a~ | ~ \sim b, ~ ~ ~\sim(a~|~b) = ~\sim a~ \& ~ \sim b$
取反性质： $-1 =~ \sim 0,~ ~ ~-a = ~\sim (a-1)$

与运算性质： $a ~\&~ 0 = a,~ ~ ~a~\&~(-1)=a,~ ~ ~a~\&~(\sim a)=0$
或运算性质： $a~|~0=a,~ ~ ~a~|~(\sim a)=-1$
异或运算性质： $a ~\^{} ~ 0 = a,~ ~ ~a ~\^{} ~ (-1) = \sim a,~ ~ ~a~\^{}~a=0$

**其他性质：**

- $a ~\&~ (a−1)$ 可将 $a$ 的二进制表示中最后一个1 变成 0
- $a~\&~(-a)$ 结果为 只保留 $a$ 二进制中最后一个 1 ，其他全 0 （ $a ~\&~ (\sim(a-1))$ 等价）
- 让 $[a, b]$ 区间的所有数按位与，结果是如下形式的二进制字符串
  - 前面是：a 和 b 的公共前缀；后面补 0

<br><hr class=short>

### 格雷编码

> 格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
> 
> 给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。即使有多个不同答案，你也只需要返回其中一种。
> 
> 格雷编码序列必须以 0 开头。

2位的格雷编码如：

<p align="center">00 - 0<br>01 - 1<br>11 - 3<br>10 - 2</p>

思路：
1. 初始数组为 [0]
1. 反向遍历 n（位数）次数组，在每个数组元素的最前面添加一个 1，并插入数组尾部

示例：

1. [ 0 ]
2. [ 0, <font color="red" >1</font> ]
3. [ 00, 01, <font color="red">11</font>, <font color="red">10</font> ]
4. [ 000, 001, 011, 010, <font color="red">110</font>, <font color="red">111</font>, <font color="red">101</font>, <font color="red">100</font> ] 

代码

```cpp {cmd="run" continue="sf"}
vector<int> grayCode(int n) {
    vector<int> ans;
    ans.push_back(0);
    for(int i = 0; i < n; ++i){
        for(int j = ans.size() - 1; j >= 0; --j){
            ans.push_back(ans[j] | 1 << i);
        }
    }
    return ans;
}
```
```cpp {cmd="run" continue hide}

};
Solution so;
//entry
int n;
input >> n;
if(n)
    cout<<so.grayCode(n);
//test
```
```cpp {cmd="run" continue}
3
4
5
```

<br><hr class=short>

### 状态压缩

状态压缩，顾名思义就是将多个值的状态压缩成一个数字。
具体而言，如果有 $n$ 个值，每个值有 2 种可能的状态，则状态总数有 $2^n$ 个，可以用一个 $n$ 位二进制数记录全部 $n$ 个状态的取值。





<br>
<br>
<br>

---
## 图
<hr class=short>

### 并查集

#### 一些定义：
父结点：顶点的直接父亲结点。（自己也可以是自己的父结点）
根结点：没有父节点的结点。（由于自己可以是自己的父结点，所以自己也可以是自己的根结点）

<br>

#### 并查集基本思想：
将一系列元素按照他们的关系合并到一系列集合中，并选取一个代表元素（父节点或根节点）。若查询两个元素间有无关系，则只需要返回他们各自的代表元素并比较，就能知道他们是否有关系（是否在同一个集合中）

<br>

#### 并查集编程思想：
例：
```mermaid
graph TD;
0 --- 1
1 --- 3
0 --- 2
4 --- 8
5 --- 6
5 --- 7
9
```
查询上图中 $(0, 3)$ $(1, 5)$ $(7,8)$ 的连通性

解法：

1. 生成并查集数组 $root[10]$
  初始化： `root[i] = i` 
  将 `root[i]` 设为 `i` 的父结点，无父结点就设为 `i` 本身

| 元素  |   0   |   0   |   0   |   1   |   4   |   5   |   5   |   5   |   4   |   9   |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 下标  |   0   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |

2. 查询 $0$ 和 $3$ 的根节点 （find 函数）
  `find(i)`: 
  - 当 `root[i] == i` 时，返回 `i` （ `i` 是根节点）
  - 当 `root[i] != i` 时，返回 `find(root[i])` （ `i` 不是根节点）

3. 若新增连接 $(4, 7)$ ，`root` 如何变化？ （union 函数）
  `union(i, j)`: `k = find(i); root[k] = j;`

<br>

#### 普通并查集两种实现方法

##### QuickFind 的并查集

`root` 数组存放每个结点的根结点
特点：

- `find` : $O(1)$ ，直接返回的就是根结点
- `union` : $O(n)$ ，需要将的其中一个的集合全部的根结点更新


实现：
```cpp {cmd=run}
//class
class UnionFind_Test {
  vector<int> root;

public:
  UnionFind_Test(int size){
      root.resize(size);
      for(int i = 0; i < root.size(); ++i)
          root[i] = i;
  }
  int find(int x){
      return root[x];
  }
  void union_(int x, int y){
      int rootY = find(y);
      if (find(x) != rootY)
          for(auto& i : root)
              if(i == rootY)
                  i = rootY;
  }
};
```

| QuickFind  | 构造函数 |  find  | union  |
| :--------: | :------: | :----: | :----: |
| 时间复杂度 |  $O(n)$  | $O(1)$ | $O(n)$ |

<br>

##### QuickUnion 的并查集

`root` 数组存放每个结点的父结点
特点：

- `find` : $O(h)$ ，$h$ 为并查集形成的树的高度，需要寻找才能返回根结点
- `union` : $O(1)$ ~ $O(n)$，时间复杂度取决于 `find` 函数 ，只需要将的其中一个结点的父结点更新


实现：

```cpp {cmd=run}
//class
class UnionFind_Test {
    vector<int> root;

public:
    UnionFind_Test(int size){
        root.resize(size);
        for(int i = 0; i < root.size(); ++i)
            root[i] = i;
    }
    int find(int x){
        while (x != root[x])
            x = root[x];
        return x;
    }
    void union_(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
            root[rootY] = rootX;
    }
};
```

| QuickUnion | 构造函数 |  find  | union  |
| :--------: | :------: | :----: | :----: |
| 时间复杂度 |  $O(n)$  | $O(d)$ | $O(d)$ |

$d$ 为并查集中结点所在的树的平均深度

<br>

#### 按秩合并的 QuickUnion
`find` 函数不变
`union` 函数：低树往高树合并（谁高谁做根结点）

实现：

```cpp {cmd=run}
//class
class UnionFind_Test{
    vector<int> root;
    vector<int> rank;   // rank 数组储存每个结点所在的高度

public:
    UnionFind_Test(int size) {
        root.resize(size);
        rank.resize(size);
        for(int i = 0; i < root.size(); ++i) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) {
        while (x != root[x])
            x = root[x];
        return x;
    }
    void union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }
};
```

| 按秩合并的QuickUnion | 构造函数 |    find     |    union    |
| :------------------: | :------: | :---------: | :---------: |
|      时间复杂度      |  $O(n)$  | $O(\log n)$ | $O(\log n)$ |

<br>

#### 路径压缩的 QuickUnion
调用 `find` 函数后，将该查找路径上的所有结点的父结点，都改为根结点

路径压缩本质是 执行 `find()` 的过程将下图左图，转化为右图

```mermaid
graph TB;
subgraph  After
    g[0] --- h[1]
    g --- i[2]
    g --- j[3]
    g --- k[4]
    g --- l[5]
end
subgraph  Before
    a[0] --- b[1] --- c[2]
    a --- d[3]
    d --- e[4]
    d --- f[5]
end
```

实现：
```cpp {cmd=run}
//class
class UnionFind_Test {
    vector<int> root;

public:
    UnionFind_Test(int size) {
        root.resize(size);
        for(int i = 0; i < root.size(); ++i)
            root[i] = i;
    }
    int find(int x) {
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    void union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
            root[rootY] = rootX;
    }
};
```

| 路径压缩的QuickUnion | 构造函数 |    find     |    union    |
| :------------------: | :------: | :---------: | :---------: |
|      时间复杂度      |  $O(n)$  | $O(\log n)$ | $O(\log n)$ |

<br>

#### 基于路径压缩的按秩合并优化的并查集

`find()` 路径优化
`union()` 按秩合并

实现：
```cpp {cmd=run}
//class
class UnionFind_Test {
public:
    vector<int> root;
    vector<int> rank;

    UnionFind_Test(int size) {
        root.resize(size);
        rank.resize(size);
        for(int i = 0; i < root.size(); ++i){
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) {
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    void union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }
};
```

```cpp {cmd=run continue modify_source}
//use
UnionFind_Test uf(10);
uf.union_(0,1);
uf.union_(0,2);
uf.union_(1,3);

uf.union_(4,5);
uf.union_(5,6);

uf.union_(2,4);

// output
cout << "```mermaid \n" << "graph TD; \n";
for (int i = 0; i < uf.root.size(); ++i) {
    if(uf.root[i] != i)
        cout << uf.root[i] << " --- " << i << endl;
    else
        cout << i << endl;
}
cout << "``` \n";
```

<!-- code_chunk_output -->

```mermaid 
graph TD; 
0
0 --- 1
0 --- 2
0 --- 3
0 --- 4
4 --- 5
4 --- 6
7
8
9
``` 


<!-- /code_chunk_output -->


<br><br><hr class=short>

### 深度优先搜索

方法：使用栈

输入：

    一维数组 V ，V[i] 表示顶点 i
    二维数组 E ，E[i][j] 表示点 i 和点 j 之间是否相连（或相连的权值）

输出：深度优先搜索遍历序列

代码

```cpp {cmd=run continue=sf}
string DepthFirstSearch(vector<string>& V, vector<vector<int>>& E) {
    vector<bool> visit(V.size(), false);
    stack<int> S;
    stringstream res("");
    S.push(0);
    while (!S.empty()) {
        int i = S.top();
        S.pop();
        if(visit[i]) continue;
        res << V[i] <<' ';
        visit[i] = true;
        for (int j = 0; j < E[i].size(); ++j) {
            if (E[i][j]) {
                S.push(j);
            }
        }
    }
    return res.str();
}
```
```cpp {cmd=run continue hide}
//entry
vector<string> V;
vector<vector<int>> E; 

input >> V >> E;
if(input){
    output << DepthFirstSearch(V, E);
}
//test
```
```cpp {cmd=run continue}
[A,B,C,D,E,F]
[
    [1,1,1,1,0,0],
    [1,1,0,0,1,1],
    [1,0,1,0,1,0],
    [1,0,0,1,1,0],
    [0,1,1,1,1,1],
    [0,1,0,0,1,1]
]
```

<br><br><hr class=short>

### 广度优先搜索

方法：使用队列（跟dfs代码几乎一样，就是栈换成了队列）

输入：

    一维数组 V ，V[i] 表示顶点 i
    二维数组 E ，E[i][j] 表示点 i 和点 j 之间是否相连（或相连的权值）

输出：广度优先搜索遍历序列

代码

```cpp {cmd=run continue=sf}
string BreathFirstSearch(vector<string>& V, vector<vector<int>>& E) {
    vector<bool> visit(V.size(), false);
    queue<int> Q;
    stringstream res("");
    Q.push(0);
    while (!Q.empty()) {
        int i = Q.front();
        Q.pop();
        if(visit[i]) continue;
        res << V[i] <<' ';
        visit[i] = true;
        for (int j = 0; j < E[i].size(); ++j) {
            if (E[i][j]) {
                Q.push(j);
            }
        }
    }
    return res.str();
}
```
```cpp {cmd=run continue hide}
//entry
vector<string> V;
vector<vector<int>> E; 

input >> V >> E;
if(input){
    output << BreathFirstSearch(V, E);
}
//test
```
```cpp {cmd=run continue}
[A,B,C,D,E,F]
[
    [1,1,1,1,0,0],
    [1,1,0,0,1,1],
    [1,0,1,0,1,0],
    [1,0,0,1,1,0],
    [0,1,1,1,1,1],
    [0,1,0,0,1,1]
]
```

<br><br><hr class=short>

### 所有路径

求图中两点的所有路径，且每个结点只能经过一次

输入：

    一维数组 V，V[i] 表示顶点 i
    二维数组 E，E[i][j] 表示点 i 和点 j 之间是否相连（或相连的权值）
    顶点 a, b

输出：

    数组 O，存放了 a->b 的所有路径

代码

深度优先搜索所有路径

```cpp {cmd=run continue=sf}
vector<vector<string>> dfsPath(vector<string>& V, vector<vector<int>>& E, int a, int b) {
    vector<bool> visit(V.size(), false);
    stack<vector<int>> S;
    vector<vector<string>> res;
    vector<int> start{a};
    S.push(start);

    while (!S.empty()) {
        vector<int> cur = S.top();
        S.pop();
        int i = cur.back();

        /* 判断是否到达终点 */
        if (i == b) {
            vector<string> temp;
            for(int j = 0; j < cur.size(); ++j) {
                temp.push_back(V[cur[j]]);
            }
            res.push_back(temp);
            continue;
        }

        /* 获取下一结点，并将路径入栈 */
        for(int j = 0; j < E[i].size(); ++j) {
            if(E[i][j] && i != j) {

                /* 判断是否已访问 */
                bool visit = false;
                for(int k = 0; k < cur.size(); ++k) {
                    if(j == cur[k])
                        visit = true;
                }
                if(visit) continue;

                /* 结点 j 加入路径 */
                vector<int> temp = cur;
                temp.push_back(j);
                S.push(temp);
            }
        }
    }

    return res;
}
```
```cpp {cmd=run continue hide}
//entry
vector<string> V;
vector<vector<int>> E; 
int a, b;

input >> V >> E >> a >> b;
if(input){
    output << dfsPath(V, E, a, b);
}
//test
```
```cpp {cmd=run continue}
[A,B,C,D,E,F]
[
    [1,1,1,1,0,0],
    [1,1,0,0,1,1],
    [1,0,1,0,1,0],
    [1,0,0,1,1,0],
    [0,1,1,1,1,1],
    [0,1,0,0,1,1]
]
0 1
```

<br><br>

广度优先搜索所有路径

```cpp {cmd=run continue=sf}
vector<vector<string>> dfsPath(vector<string>& V, vector<vector<int>>& E, int a, int b) {
    vector<bool> visit(V.size(), false);
    queue<vector<int>> S;
    vector<vector<string>> res;
    vector<int> start{a};
    S.push(start);

    while (!S.empty()) {
        vector<int> cur = S.front();
        S.pop();
        int i = cur.back();

        /* 判断是否到达终点 */
        if (i == b) {
            vector<string> temp;
            for(int j = 0; j < cur.size(); ++j) {
                temp.push_back(V[cur[j]]);
            }
            res.push_back(temp);
            continue;
        }

        /* 获取下一结点，并将路径入栈 */
        for(int j = 0; j < E[i].size(); ++j) {
            if(E[i][j] && i != j) {

                /* 判断是否已访问 */
                bool visit = false;
                for(int k = 0; k < cur.size(); ++k) {
                    if(j == cur[k])
                        visit = true;
                }
                if(visit) continue;

                /* 结点 j 加入路径 */
                vector<int> temp = cur;
                temp.push_back(j);
                S.push(temp);
            }
        }
    }

    return res;
}
```
```cpp {cmd=run continue hide}
//entry
vector<string> V;
vector<vector<int>> E; 
int a, b;

input >> V >> E >> a >> b;
if(input){
    output << dfsPath(V, E, a, b);
}
//test
```
```cpp {cmd=run continue}
[A,B,C,D,E,F]
[
    [1,1,1,1,0,0],
    [1,1,0,0,1,1],
    [1,0,1,0,1,0],
    [1,0,0,1,1,0],
    [0,1,1,1,1,1],
    [0,1,0,0,1,1]
]
0 1
```

<br><br><hr class=short>

### 最小生成树

`最小生成树` 是指带权无向图中，生成的总权重最小的，具有所有顶点的连通子图

#### 切分定理

> 切分：指将图切成两个部分
> 
> 横切边：如果一条边的两个顶点属于切分的两个部分，则为横切边
> 
> 切分定理：在连通带权无向图中，给定任意的切分，如果有一条横切边的权值严格小于所有其他横切边，则这条边必然属于图的最小生成树的一条边

<br>

#### Kruskal 算法

Kruskal 算法适合简单图

方法：

1. 将所有边从小到大排序（使用最小堆，每次选取堆顶元素即可）
2. 将小边依次加入最小生成树中，形成环则跳过（使用并查集查询两点是否已在同一颗树中）
3. 直到选择 `n - 1` 条边为止


代码思路：

需要使用：堆，并查集
1. 将所有边插入堆中
2. 取出堆顶的边 `(p1,p2)`，在并查集中判断 `p1` 和 `p2` 是否已连接，若是，则丢弃重取
3. 若 `p1` `p2` 未连接，则边 `(p1,p2)` 为最终结果生成树的其中一条边，在并查集中连接 `p1` `p2`
4. 循环 23. 直到选出了 `n-1` 条边


```cpp {cmd=run continue=sf}
/* 边 */
template<class CostType>
class Edge{
public:
    int p1;
    int p2;
    CostType cost;

    Edge(int point1, int point2, CostType c):p1(point1), p2(point2), cost(c){}
};

/* 堆使用的比较函数 */
auto com = [](Edge<double> e1, Edge<double> e2)->bool{return e1.cost < e2.cost;};


/* Kruskal 算法 */
template<class Type>
Graph<Type, 0, 1> Kruskal(Graph<Type, 0, 1>& graph) {
    Heap<Edge<double>, decltype(com)> edges(com);

    /* 初始化堆，将所有边插入到堆中 */
    for (int i = 0; i < graph.edge.size(); ++i) {
        for (int j = i + 1; j < graph.edge[i].size(); ++j) {
            if(graph.edge[i][j] > 0){
                edges.push(Edge<double>(i, j, graph.edge[i][j]));
            }
        }
    }

    /* 初始化并查集 */
    UnionFind uf(graph.vertex.size());
    int n = graph.vertex.size() - 1;

    /* 结果图的邻接矩阵 */
    vector<vector<double>> edgeRes(graph.vertex.size(), vector<double>(graph.vertex.size(), 0));

    /* 开始选边 */
    for(int i = 0; i < n; ++i) {
        /* 取出最小堆顶的边 */
        Edge<double> e = edges.top();
        edges.pop();
        /* 在并查集中查询这条边的两点是否已经在同一个生成树 */
        if(!uf.connected(e.p1, e.p2)){
            /* 不是则连接，并将权值赋给结果邻接矩阵 */
            uf.unite(e.p1, e.p2);
            edgeRes[e.p1][e.p2] = edgeRes[e.p2][e.p1] = e.cost;
        }
        /* 已在同一邻接矩阵，则需要多找一条边 */
        else
            ++n;
    }

    /* 生成结果图 */
    Graph<Type, 0, 1> res(graph.vertex, edgeRes);
    return res;
}
```
```cpp {cmd=run continue hide}
//entry
modify_source = true;
Graph<string, 0, 1> g;
input >> g;
if(input) {
    output << "原图：\n" << g << "最小生成树：\n" << Kruskal(g);
}
//test
```
```cpp {cmd=run continue modify_source}
[A,B,C,D,E]
[
    [0,0.5,0,0,1],
    [0.5,0,4,3,1.5],
    [0,4,0,0,0],
    [0,3,0,0,2],
    [1,1.5,0,2,0]
]
```

<!-- code_chunk_output -->

<div class=code-output> 

原图：
```mermaid 
graph LR; 
a[ A ] 
b[ B ] 
c[ C ] 
d[ D ] 
e[ E ] 
a ---|0.5| b 
a ---|1| e 
b ---|4| c 
b ---|3| d 
b ---|1.5| e 
d ---|2| e 
```
最小生成树：
```mermaid 
graph LR; 
a[ A ] 
b[ B ] 
c[ C ] 
d[ D ] 
e[ E ] 
a ---|0.5| b 
a ---|1| e 
b ---|4| c 
d ---|2| e 
```


<hr class=code-hr> average time: 0 ms


</div> 



<!-- /code_chunk_output -->

<br><br>

#### Prim 算法

Prim 算法适合复杂图

思路：
1. 将顶点分为未访问和已访问两个集合（使用 `visit` 数组标记）
2. 将第一个顶点加入已访问集合，遍历已访问集合，对于连接已访问集合中的顶点的最短的边（使用 `堆` 数据结构），若这条边的另一个顶点未访问，则加入已访问集合
3. 直到未访问集合为空

代码思路：

需要使用：visit 数组， 堆
1. 将点 0 加入已访问，并用 `i` 维护最新加入的结点
2. 对于最新加入的结点 `i`，将它的连接到所有未访问结点插入堆中
3. 取堆顶的边`(p1,p2)`，判断点 `p2` 是否已访问，若是，则丢弃重取
4. 若 `p2` 未访问，则边 `(p1,p2)` 为最终结果生成树的其中一条边，将点 `p2` 加入已访问，令 `i = p2`
5. 循环 234. 直到所有点已访问

```cpp {cmd=run continue=sf}
/* 边 */
template<class CostType>
class Edge{
public:
    int p1;
    int p2;
    CostType cost;

    Edge(int point1, int point2, CostType c):p1(point1), p2(point2), cost(c){}
};

/* 堆使用的比较函数 */
auto com = [](Edge<double> e1, Edge<double> e2)->bool{return e1.cost < e2.cost;};

/* Prim 算法 */
template<class Type>
Graph<Type, 0, 1> Prim(Graph<Type, 0, 1>& graph) {
    /* visit 数组初始化 */
    vector<bool> visit(graph.vertex.size(), false);
    /* 堆初始化 */
    Heap<Edge<double>, decltype(com)> edges(com);
    /* 结果图的临界矩阵 */
    vector<vector<double>> edgeRes(graph.vertex.size(), vector<double>(graph.vertex.size(), 0));

    /* 将点 0 标记为已访问，i 维护当前最新加入的边 */
    int i = 0;
    visit[i] = true;
    int n = graph.vertex.size() - 1;

    /* 开始选点 */
    while(n > 0) {
        /* 对于所有未访问的点 j，将边 i->j 加入堆 */
        for(int j = 0; j < visit.size(); ++j) {
            if(visit[j]) continue;
            if(graph.edge[i][j] > 0)
                edges.push(Edge<double>(i, j, graph.edge[i][j]));
        }

        /* 从堆中取出边 p1->p2 */
        Edge<double> e = edges.top();
        edges.pop();

        /* p1 肯定是已访问，判断 p2 是否访问，如果已访问，则为不需要的边，丢弃 */
        while(visit[e.p2]){
            e = edges.top();
            edges.pop();
        }

        /* 将点 p2 加入已访问集合 */
        i = e.p2;
        visit[i] = true;
        --n;
        edgeRes[e.p1][e.p2] = edgeRes[e.p2][e.p1] = e.cost;
    }

    Graph<Type, 0, 1> res(graph.vertex, edgeRes);
    return res;
}
```
```cpp {cmd=run continue}
//entry
modify_source = true;
Graph<string, 0, 1> g;
input >> g;
if(input) {
    output << "原图：\n" << g << "最小生成树：\n" << Prim(g);
}
//test
```
```cpp {cmd=run continue modify_source}
[A,B,C,D,E]
[
    [0,0.5,0,0,1],
    [0.5,0,4,3,1.5],
    [0,4,0,0,0],
    [0,3,0,0,2],
    [1,1.5,0,2,0]
]
```

<!-- code_chunk_output -->

<div class=code-output> 

原图：
```mermaid 
graph LR; 
a[ A ] 
b[ B ] 
c[ C ] 
d[ D ] 
e[ E ] 
a ---|0.5| b 
a ---|1| e 
b ---|4| c 
b ---|3| d 
b ---|1.5| e 
d ---|2| e 
```
最小生成树：
```mermaid 
graph LR; 
a[ A ] 
b[ B ] 
c[ C ] 
d[ D ] 
e[ E ] 
a ---|0.5| b 
a ---|1| e 
b ---|4| c 
d ---|2| e 
```


<hr class=code-hr> average time: 0 ms


</div> 



<!-- /code_chunk_output -->

<br><br><hr class=short>

### 最短路径

#### Floyd 算法

方法：动态规划

适用范围：任何图，但最短路必须存在（不能有负环）

实现：
1. 使用一个数组 `f[k][x][y]` 表示 仅通过结点 1 到 $k$，结点 $x$ 到结点 $y$ 的最短路径长度
2. 初始化base case `f[0][x][y]` 有以下取值：
   1. 当 x 直接与 y 相连时，x 与 y 的边权；
   2. 当 x 与 y 不直接相连时， $+\infty$ ;
   3. 当 x = y 时，0
3. 状态转移方程：`f[k][x][y] = min(f[k][x][y], f[k-1][x][k] + f[k-1][k][y])`

     ```cpp
     for(int k = 1; k < n; ++k){
         for(int x = 1; x < n; ++x){
             for(int y = 1; y < n; ++y){
                 f[k][x][y] = min(f[k][x][y], f[k-1][x][k] + f[k-1][k][y]);
             }
         }
     }
     ```

4. 优化：数组下标 k 对结果无影响，即将状态转移方程改为：`f[x][y] = min(f[x][y], f[x][k] + f[k][y])`

    ```cpp
    for(int k = 1; k < n; ++k){
         for(int x = 1; x < n; ++x){
             for(int y = 1; y < n; ++y){
                 f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
             }
         }
     }
    ```

时间复杂度：$O(n^3)$
空间复杂度：$O(n^2)$

<br><br>

#### Bellman-Ford 算法

方法：基于松弛（relax）操作

适用范围：支持负权

实现：
1. 假设起始结点为 $S$，任意结点 $u$，定义 `dist[u]` 为 $S$ 到 $u$ 的最短路径长度；
   定义松弛操作 `relax(u, v): dist[v] = min(dist[v], dist[u] + edge_len[u,v])`
2. 初始化：`dist[u] = edge_len(S, u)`
3. 


<br><br><br>


---
## 排序
<hr class=short>

### 快速排序

原理：

- 选择一个元素，将它放到合适的位置，使得左边的数都比它小，右边的数都比它大
- 对左边和右边递归调用快速排序

方法：

- 我称之为填挖法
- 随机选择一个划分元素，移到 a[0]，并使用变量 m 保存
- 维护两个指针 i, j，初始化 i = 0, j = size() - 1
- 当我们选择完划分元素 a[0] 后，a[0] 处（也是此时的a[0]）相当于是一个坑
- 此时，j 逆向遍历，将满足 a[j] < a[m] 的元素 a[j] 放到 坑处（a[i]），此时 a[j] 也相当于是一个坑
- 然后，i 正向遍历，将满足 a[i] > a[m] 的元素 a[i] 放到坑处（a[j]），此时 a[i] 再次成为了坑
- 重复遍历直到，i == j，将划分元素 m 放到 i==j 处 

代码：
```cpp {cmd=run continue=sf}
int partition(vector<int>& arr, int left, int right) {
    int m = arr[left];
    while (left < right) {
        while (m <= arr[right] && left < right) --right;
        arr[left] = arr[right];

        while (arr[left] <= m && left < right) ++left;
        arr[right] = arr[left];
    }
    arr[left] = m;
    return left;
}
void quickSort(vector<int>& arr, int left, int right) {
    if(left < right) {
        int r = partition(arr, left, right);
        quickSort(arr, r + 1, right);
        quickSort(arr, left, r - 1);
    }
}
```
```cpp {cmd=run continue hide}
//entry
vector<int> v;
input >> v;
if(input){
    quickSort(v, 0, v.size() - 1);
    output << v;
}
//test
```
```cpp {cmd=run continue}
[2,6,8,3,4,7,0,5,9,1]
```

<br><br>

##### 扩展

排序统计

输入：

    数组 a
    整数 k

输出：

    数组中第 k 小元素

思路：

使用快排的划分函数，将数组通过下标 `r` 分为两部分，左边元素都小于 `a[r]` ， 右边元素都大于 `a[r]`
当 `r == k` 时，`a[r]` 即为答案

代码


```cpp {cmd=run continue=sf}
/* 划分 */
int partition(vector<int>& arr, int left, int right) {
    int m = arr[left];
    while (left < right) {
        while (m <= arr[right] && left < right) --right;
        arr[left] = arr[right];

        while (arr[left] <= m && left < right) ++left;
        arr[right] = arr[left];
    }
    arr[left] = m;
    return left;
}
/* 随机选择划分元素 */
int RandPartition(vector<int>& arr, int left, int right) {
    int ran = rand() % (right + 1 - left) + left;
    swap(arr[left], arr[ran]);
    return partition(arr, left, right);
}
/* 选择第 k 小 */
int select(vector<int>& arr, int k) {
    int left = 0, right = arr.size() - 1;
    int r;
    --k;    /* 下标转换，因为第 k 小的元素排序最后下标其实是 k - 1 */
    while(true) {
        r = RandPartition(arr, left, right);
        if(r < k)
            left = r + 1;
        else if(r > k)
            right = r - 1;
        else
            break;
    }
    return arr[k];
}
```
```cpp {cmd=run continue hide}
//entry
vector<int> v;
int k;
input >> v >> k;
if(input) {
    output << select(v, k);
}
//test
```
```cpp {cmd=run continue}
[1,2,9,8,7,3,4,5,6,0] 3
```

<br><br><br>

---
## 数组
<hr class=short>

### Boyer-Moore 投票算法

适用情况：找出数组中的众数，众数个数大于 $\lfloor n/2 \rfloor$

思路：删除一对不相同的元素，不会影响最终结果，删除到最后剩下的一定是众数（因为思路是两两抵消，所以众数个数一定要多于数组的一半，否则获得的答案可能错误）

实现：

1. 维护一个候选众数 `candidate` 和它出现的次数 count
   
2. 初始化：count = 0
   
3. 遍历数组元素 `x` ：
   - 当 `count == 0` 时，令 `candidate = x`
   - 当 `x == candidate` 时，`++count`
   - 当 `x != candidate` 时，`--count`

4. 遍历结束后，`candidate` 即是整个数组的众数

代码：

```cpp{cmd=run continue=sf}
int majorityElement(vector<int>& nums) {
    int ans, count = 0;
    for(int i = 0; i < nums.size(); ++i){
        if(count == 0)
            ans = nums[i];
        if(ans == nums[i])
            ++count;
        else
            --count;
    }
    return ans;
}
```
```cpp{cmd=run continue hide}
//entry
vector<int> v;
input >> v;
if(input)
    cout << majorityElement(v);
//test
```
```cpp{cmd=run continue}
[1,1,1,1,2,2]
[2,2,1,1,1,2,2]
[3,2,3]
[1,1,1,2,2,3,4,5] //这个不行
```

<hr class=short>

### 前缀和与差分

#### 前缀和

前缀和即数组的前 `n` 项和

如 （建议前缀和数组下标从 1 开始，可以免除一些麻烦）
`s[0] = 0`
`s[1] = a[0]`
`s[2] = a[0] + a[1]`
...

<br>

#### 差分

差分与前缀和互为逆运算，即为通过前缀和数组 `s` 求原数组

方法： `a[i] = s[i] - s[i-1]`

<br><hr class=short>

#### 一维数组前缀和

适用范围：求数组区间 (l, r) 的和

方法：构造前缀和数组 s ，`s[r] - s[l]` 即为所求区间和（差分）

（求 a[0] 时为 s[1] - s[0] = a[0] - 0，这就是下标从 1 开始的好处，统一了差分的形式）

代码：迭代构造前缀和
```cpp {cmd=run continue=sf}
vector<int> prefix_sum(vector<int>& v) {
    vector<int> res(v.size() + 1);
    res[0] = 0;
    for (int i = 1; i < res.size(); ++i) {
        res[i] = res[i - 1] + v[i - 1];
    }
    return res;
}
```
```cpp {cmd=run continue hide}
//entry
vector<int> v;
input >> v;
if(input)
    cout << prefix_sum(v);
//test
```
```cpp {cmd=run continue}
[1,2,3,4,5,6]
```

<br><hr class=short>

#### 数组区间增量

> **leetcode 1109. 航班预订统计**
> 这里有 n 个航班，它们分别从 1 到 n 进行编号。
>
> 有一份航班预订表 bookings ，表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi] 意味着在从 firsti 到 lasti （包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。
> 
> 请你返回一个长度为 n 的数组 answer，其中 answer[i] 是航班 i 上预订的座位总数。
> 
>  
> 
> > 示例 1：
> > 输入：bookings = [ [1,2,10],[2,3,20],[2,5,25] ], n = 5
> > 输出：[10,55,45,25,25]
> > 解释：
> > |  航班编号  |   1   |   2   |   3   |   4   |   5   |
> > | :--------: | :---: | :---: | :---: | :---: | :---: |
> > | 预订记录 1 |  10   |  10   |   >   |       |       |
> > | 预订记录 2 |  [ ]()    |  20   |  20   |   >   |       |
> > | 预订记录 3 |  [ ]()    |  25   |  25   |  25   |  25   |
> > |  总座位数  |  10   |  55   |  45   |  25   |  25   |
> > 因此，answer = [10,55,45,25,25]
>

- 每个预定记录数组都可以看成是 `answer` 数组的一个区间增量

    bookings[0] = [1,2,10] 表示 answer 数组区间 [1,2] 增加 10
    bookings[1] = [2,3,20] 表示 answer 数组区间 [2,3] 增加 20
    bookings[2] = [2,5,25] 表示 answer 数组区间 [2,5] 增加 25

    <br>


- 将 `bookings` 转换为数组 `b`

    b[0] = [10,10,0,0,0]
    b[1] = [0,20,20,0,0]
    b[2] = [0,25,25,25,25]

    <br>

    `answer[i] = b[0][i] + b[1][i] + b[2][i]`

    <br>

    到这里暴力法应该很容易想到了

    <br>

- 对数组 `b` 进行差分（前缀和的逆运算）得到数组 `d`

    d[0] = [10,0,-10,0,0]
    d[1] = [0,20,0,-20,0]
    d[2] = [0,25,0,0,0]

    <br>

    差分数组求和后 dsum = [10,45,-10,-20,0]
    对 dsum 求前缀和得 answer = [10,55,45,25,25]

    <br>

    此处观察可知，题目 `bookings[0]` 数组给出了 区间 [1,2] = 10 ，
    可转换为 `d[0]` 中的 d[0][1] = 10, d[0][3] = -10

    因此 区间 (l,r) 的增量 x ，可以转换为 差分数组中的 d[l] = x, d[r+1] = -x

    <br>


    由此题可知 对数组集合 `s` （或多个数组）
    数组的求和 = 对每个数组差分后求和，再求前缀和

    <br>

    即
    $\sum{s} = P(\sum{D(s)})$
    P() 为求前缀和
    D() 为求差分

<br>
<br>
<br>

---
## 堆
<hr class=short>

### 堆的基本定义

堆是一种数据结构，它是一颗完全二叉树，其中`每个结点的值都小于其子结点的值`，称之为最小堆（小根堆），反之为最大堆（大根堆）

**堆与优先队列**

优先队列中的元素都有优先度，表示了元素与元素之间的关系，而优先队列是一种数据类型，优先队列并不是堆，但堆可以说是优先队列的一种实现方式

<br><hr class=short>

### 堆的实现

这里以最小堆为例

堆是一颗完全二叉树，其中每个结点值都小于其子结点值

堆的操作：

- 维护结点 `x` 使其在正确的位置：自底向上，判断 `x` 是否大于其父结点，若不满足，则与父结点交换，直到 `x` 为根结点或 `x` 大于其父结点
- 插入：插入到最右下结点的下一个位置 `end` （如果满了，就新加一行），然后维护结点 `end`
- 取顶点值：将顶点值与最后一个位置 `end` 的结点交换，然后删除顶点值(end处)，并自顶向下，若 `end` 比子结点大，则与最小的子结点交换，直到 `end` 为叶子或 `end` 比子结点小

此处就使用 `vector` 实现

```cpp {cmd=run}
//class
template<class Type, class Compare = std::less<Type>>
class Heap_Test{
protected:
    vector<Type> data;
    int end;     // end 指向末尾元素的后一个
    Compare com; // com 比较函数或函数对象，当 com(data1, data2) 返回 true 时，data1 比 data2 接近堆顶

    void adjust(int i) {
        if(i >= end) return;
        while(i > 0 && com(data[i], data[(i - 1) / 2])){
            swap(data[i], data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
public:
    Heap_Test():end(0){}
    Heap_Test(Compare compare):end(0), com(compare){}
    inline bool isEmpty(){return end == 0;}
    inline int size(){return end;}
    void insert(Type x) {
        if(end < data.size())
            data[end] = x;
        else
            data.push_back(x);
        ++end;
        adjust(end - 1);
    }
    void push(Type x) {insert(x);}
    Type top(){
        return data[0];
    }
    void pop(){
        --end;
        swap(data[0], data[end]);
        int i = 0;
        while (i < end) {
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            if (left < end && com(data[left], data[i]) || right < end && com(data[right], data[i]))
            {
                int min_d;
                if(right < end && com(data[right], data[left])) {
                    min_d = right;
                } else {
                    min_d = left;
                }
                swap(data[i], data[min_d]);
                i = min_d;
            } else {
                break;
            }
        }
    }
};

```
```cpp {cmd=run continue}
//use
Heap_Test<int> heap;
heap.push(9);
heap.push(7);
heap.push(6);
heap.push(1);
heap.push(2);
heap.push(3);
heap.push(5);
heap.push(4);
heap.push(8);


vector<int> v;
while(!heap.isEmpty()) {
    v.push_back(heap.top());
    heap.pop();
}
cout  << endl << v << endl;
```


<br>
<br>
<br>

---


