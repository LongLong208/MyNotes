数学基础

[TOC]

```cpp {cmd="cppal" id="start" hide}
//algorithm
class Solution{
public:
```

<br>

---

## 位运算

<br><hr width="60%">

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

### Bellman-Ford 算法

方法：基于松弛（relax）操作

适用范围：支持负权

实现：
1. 假设起始结点为 $S$，任意结点 $u$，定义 `dist[u]` 为 $S$ 到 $u$ 的最短路径长度；
   定义松弛操作 `relax(u, v): dist[v] = min(dist[v], dist[u] + edge_len[u,v])`
2. 初始化：`dist[u] = edge_len(S, u)`
3. 
