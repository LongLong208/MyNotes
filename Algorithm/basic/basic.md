数学基础

[TOC]

---

<br>

模板：

```markdown
---
## 新分类
<hr width="60%">
```

```cpp {cmd="cppal" id="start" hide}
//algorithm
class Solution{
public:
```

<br>

---
## 位运算
<hr width="60%">

### N进制转十进制

$720.5_{(8)} = \enspace ?$

$$
    720.5_{(8)} = 7×8^{2}+2×8^{1}+0×8^{0}+5×8^{−1} = 464.625
$$

<br><hr width="60%">

### 十进制转N进制

#### 整数转换

$50_{(10)} = \enspace ? _{(2)}$
    
$$
\begin {gather*}
50 \div 2 = 25 &余& 0  \\
25 \div 2 = 12 &余& 1  \\
12 \div 2 = 6 &余& 0  \\
6 \div 2 = 3 &余& 0 \\
3 \div 2 = 1 &余& 1 \\
1 \div 2 = 0 &余& 1 
\end {gather*}
$$

余数反向遍历： 1 1 0 0 1 0， 因此 $50_{(10)} = 110010_{(2)}$

<br><hr width="60%">

#### 小数转换

$0.6875_{(10)} = \enspace ? _{(2)}$

$$
\begin {gather*}
0.6875×2=1.375 &整数部分& 1 \\
0.375×2=0.75 &整数部分& 0\\
0.75×2=1.5 &整数部分& 1\\
0.5×2=1 &整数部分& 1\\
\end {gather*}
$$

整数部分正序遍历： 1 0 1 1，因此 $0.6875_{(10)} = 0.1011_{(2)}$

<br><hr width="60%">

### 位运算的性质

幂等律： | &（幂等于它本身）
交换律： | & ^
结合律： | & ^

分配律： | 对 &，| 对 &，& 对 ^（类比 乘法对加法）
德摩根率： $\sim(a~\&~b) = ~\sim a~ | ~ \sim b,~ ~ ~\sim(a~|~b) = ~\sim a~ \& ~ \sim b$
取反性质： $-1 =~ \sim 0,~ ~ ~-a = ~\sim (a-1)$

与运算性质： $a ~\&~ 0 = a,~ ~ ~a~\&~(-1)=a,~ ~ ~a~\&~(\sim a)=0$
或运算性质： $a~|~0=a,~ ~ ~a~|~(\sim a)=-1$
异或运算性质： $a ~\^{} ~ 0 = a,~ ~ ~a ~\^{} ~ (-1) = \sim a,~ ~ ~a~\^{}~a=0$

**其他性质：**
- $a ~\&~ (a−1)$ 可将 $a$ 的二进制表示中最后一个1 变成 0
- $a~\&~(-a)$ 结果为 只保留 $a$ 二进制中最后一个 1 ，其他全 0 （ $a ~\&~ (\sim(a-1))$ 等价）
- 让 $[a, b]$ 区间的所有数按位与，结果是如下形式的二进制字符串
  - 前面是：a 和 b 的公共前缀；后面补 0

<br><hr width="60%">

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

```cpp {cmd="cppal" continue="start"}
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
```cpp {cmd="cppal" continue hide}

};
Solution so;
//entry
int n;
input >> n;
if(n)
    cout<<so.grayCode(n);
//test
```
```cpp {cmd="cppal" continue}
3
```

<br><hr width="60%">

### 状态压缩

状态压缩，顾名思义就是将多个值的状态压缩成一个数字。
具体而言，如果有 $n$ 个值，每个值有 2 种可能的状态，则状态总数有 $2^n$ 个，可以用一个 $n$ 位二进制数记录全部 $n$ 个状态的取值。





<br>

---
## 图
<hr width="60%">

### 并查集

* 一些定义：
    父结点：顶点的直接父亲结点。（自己也可以是自己的父结点）
    根结点：没有父节点的结点。（由于自己可以是自己的父结点，所以自己也可以是自己的根结点）

<br>

* 并查集基本思想：
    将一系列元素按照他们的关系合并到一系列集合中，并选取一个代表元素（父节点或根节点）。若查询两个元素间有无关系，则只需要返回他们各自的代表元素并比较，就能知道他们是否有关系（是否在同一个集合中）

<br>

* 并查集编程思想：
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

* 并查集两种实现方法

    - QuickFind 的并查集

        `root` 数组存放每个结点的根结点
        特点：
        
        - `find` : $O(1)$ ，直接返回的就是根结点
        - `union` : $O(n)$ ，需要将的其中一个的集合全部的根结点更新


        实现：
        `find(x)` : `return root[x]`

        `union(x, y)` :

        ```cpp
        rootY = find(y);
        if (find(x) != rootY)
            for(auto& i : root)
                if(i == rootY)
                    i = rootY;
        ```


    - QuickUnion 的并查集

        `root` 数组存放每个结点的父结点
        特点：
        
        - `find` : $O(n)$ ，需要寻找才能返回根结点
        - `union` : $O(1)$ ~ $O(n)$ ，只需要将的其中一个结点的父结点更新


        实现：
        `find(x)` : 
        ```cpp
        while (x != root[x])
            x = root[x]
        return x;
        ```

        `union(x, y)` :

        ```cpp
        rootX = find(x);
        rootY = find(y);
        if (rootX != rootY)
            root[rootY] = rootX;
        ```


<br><hr width="60%">

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

<br><hr width=60%>

#### Bellman-Ford 算法

方法：基于松弛（relax）操作

适用范围：支持负权

实现：
1. 假设起始结点为 $S$，任意结点 $u$，定义 `dist[u]` 为 $S$ 到 $u$ 的最短路径长度；
   定义松弛操作 `relax(u, v): dist[v] = min(dist[v], dist[u] + edge_len[u,v])`
2. 初始化：`dist[u] = edge_len(S, u)`
3. 


---

## 几何

<br><hr width="60%">

### 平面几何

#### 直线

##### 直线方程

一般式：$Ax+By+C=0$

斜截式：$y=kx+b$

截距式：$\frac{x}{a}+\frac{y}{b} = 1$

点斜式：$y-y_0=k(x-x_0)$

两点式：$\frac{x~-~x2}{x1-x2} = \frac{y~-~y2}{y1-y2}$

<hr width=20%>

##### 点到直线的距离

点 $(x_0, y_0)$ 到直线 $Ax+By+C=0$ 的距离

公式： $d=\frac{|Ax_0+By_0+C|}{\sqrt{A^2+B^2}}$

<br><hr width="60%">

#### 矩形

##### 矩形重叠问题

以 $[x1, y1, x2, y2]$ 的形式给出两个矩形 $rec1$, $rec2$ ，其中矩形的两边分别平行于 $x$ 轴和 $y$ 轴， $[x1, y1]$ 表示矩形左下角的点坐标， $[x2, y2]$ 表示矩形右上角坐标

问题：输入 $ax1, ay1, ax2, ay2, bx1, by1, bx2, by2$ ， 返回两个矩形是否重叠

思路：两个矩形重叠时，他们的 x 和 y 坐标范围有重叠

关键代码： 

```cpp 
ax1 < bx2 && bx1 < ax2 && ay1 < by2 && by1 < ay2
```

<hr width=20%>

##### 矩形重叠面积

矩形表示方式同上

问题：输入 $ax1, ay1, ax2, ay2, bx1, by1, bx2, by2$ ， 返回两个矩形的重叠面积

关键代码：

```cpp
(min(ax2, bx2) - max(ax1, bx1)) * (min(ay2, by2) - max(ay1, by1))
```

<br><hr width="60%">

#### 圆

##### 圆的方程

$(x-a)^2+(y-b)^2=r^2$

其中： 圆心坐标：$[a, b]$，半径：$r$
