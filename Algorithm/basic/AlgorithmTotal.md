

# 算法导论

[TOC]

## 算法

#### 插入排序

*$Insertion-Sort(A)$* A[1...n]

```C++
for j = 2 to A.length
	key = A[j]  
    // Insert A[j] into the sorted sequence A[1..j-1]
    i = j - 1
    while i > 0 && A[i] > key
        A[i+1] = A[i]
        i = i - 1
    A[i+1] = key
```

时间复杂度：

- 最好：$\Theta(n)$
- 平均：$\Theta(n^2)$
- 最坏：$\Theta(n^2)$

循环不变式：每次迭代前，$A[1..j-1]$ 为已排序的数组



---



#### 归并排序

*$Merge(A,p,q,r)$*

合并函数：将A数组中，$A[p..q]$ 和 $A[q+1..r]$ 合并

```C++
n1 = q + 1 - p
n2 = r + 1 - q + 1
### let L[1..n1 + 1] and R[1.. n2 + 1] be new arrays
for i = 1 to n1		// notice that i begins from 1
    L[i] = A[p + i - 1]
for j = 1 to n2
    R[j] = A[q + 1 + j - 1]
L[n1 + 1] = ∞		// 设置哨兵，合并时一旦遇到哨兵，即当前的堆已经合并完
R[n2 + 1] = ∞
i = 1
j = 1
for k = p to r
    if L[i] <= R[j]
        A[k] = L[i]
        i = i + 1
    else A[k] = R[j]
        j = j + 1
```

时间复杂度：$\Theta(n)$

循环不变式：$A[p..k-1]$ 包含了 $k-p$ 个最小元素



*$Merge-Sort(A,p,r)$*  归并排序

```C++
if p < r
    q = (int)(p + r) / 2
    Merge_Sort(A, p, q)
    Merge_Sort(A, q+1, r)
    Merge(A, p, q, r)
```

时间复杂度：$\Theta(n\log n)$



---



#### QuickSort

* divide and conquer

- sorts "in place"



1. Divide: Partition array into 2 subarrays around an pivot x

   $ elems in loewr subarray <= x <= elems in upper subarray

2. Conquer: sort the two subarrays

3. Combine: trivial

   

##### Normal QuickSort

*$Partition(A, p, q)$* // A[p...q]

```c++
x = A[p]
i = p
for j = p+i to q  // 不变式：i左边的都比x小
    if A[i] <= x
        i = i + 1
        exchange A[i] <-> A[j]
exchange A[p] <-> A[i]
return i
```



*$QuickSort(A, p, q)$*

```C++
if p < q
    r = Partition(A, p, q)
    QuickSort(A, p, r - 1)
    QuickSort(A, r + 1, q)
// 可优化，当p，q满足一定要求时
```

###### worst-case

input sorted or reverse sorted: one side of partition has no elems

$\begin{array}{}T(n) &= T(0) + T(n-1) + \Theta(n)\\&=\Theta(1)+T(n-1)+\Theta(n)\\&=T(n-1)+\Theta(n)\\&=\Theta(n^2)\end{array}$



###### best-case

Partition splits the array n/2 : n/2

$T(n)=2T(n/2)+\Theta(n)=\Theta(nlogn)$



 

##### Randomized QuickSort

* pivot on random elem
* 将首元素与随机元素交换，然后将交换后首元素作为pivot
* running time is independent of input ordering



###### indicator random variable

指示器随机变量$x_k$

$x_k=\begin{cases}1&,if\ partition\ generates\ k:n-k-1 \ split\\0&,othervise\end{cases}$





---



#### 矩阵乘法

##### 基础算法

设 A，B，C 都是 $n\times n$ 矩阵，则 $C=A\cdot B$

*$Square-Matrix-Multiply(A,B)$*

```C++
n = A.rows
### let C be a new n × n matrix
for i = 1 to n
    for j = 1 to n
        C[i][j] = 0
        for k = 1 to n
            C[i][j] = c[i][j] + A[i][k] * b[k][j]
return C
```

时间复杂度：$O(n^3)$



##### Strassen算法

1. 设 A，B，C 都是 $n\times n$ 矩阵，将它们分解为 $\frac{n}{2}\times\frac{n}{2}$ 的矩阵：$A=\begin{bmatrix}A_{11}&A_{12}\\A_{21}&A_{22}\end{bmatrix},B=\begin{bmatrix}B_{11}&B_{12}\\B_{21}&B_{22}\end{bmatrix},C=\begin{bmatrix}C_{11}&C_{12}\\C_{21}&C_{22}\end{bmatrix}$ ，花费时间 $O(1)$
2. 创建 10 个 $\frac{n}{2}\times\frac{n}{2}$ 矩阵 $S_1,S_2,\cdots,S_{10}$ ，花费时间 $O(n^2)$
4. 通过 $P_i$ 计算出 $C_{11},C_{12},C_{21},C_{22}$ ，花费时间 $O(n^2)$

细节：

第 2 步：

​	$\begin{array}{c|c} S_1=B_{12}-B_{22} & S_2=A_{11}+A_{12} & S_3=A_{21}+A_{22} & S_4=B_{21}-B_{11} & S_5=A_{11}+A_{22} \\ S_6=B_{11}+B_{22} & S_7=A_{12}-A_{22} & S_8=B_{21}+B_{22} & S_9=A_{11}-A_{21} & S_{10}=B_{11}+B_{12}\end{array}$

第 3 步：

​	$\begin{array}{c|c} P_1=A_{11}\cdot S_1 & P_2=S_2\cdot B_{22} & P_3=S_3\cdot B_{11} & P_4=A_{22}\cdot S_4 \\ P_5=S_5\cdot S_6 & P_6=S_7\cdot S_8&P_7=S_9\cdot S_{10}\end{array}$

第 4 步：

​	$\begin{array}{c|c}C_{11}=P_5+P_4-P_2+P_6 & C_{12}=P_1+P_2 & C_{21}=P_3+P_4 & C_{22}=P_5+P_1-P_3-P_7\end{array}$





递归式：$T(n)=7T(n/2)+\Theta(n^2)$

时间复杂度：$T(n)=\Theta(n^{log_27})=\Theta(n^{2.81})$

---



## 数学原理与概念

#### 循环不变式

循环不变式是循环执行过程中的某些定理，满足以下的性质

- 初始化：循环第一次迭代前，循环不变式为真
- 保持：如果某次迭代前循环不变式为真，那么下次迭代前它仍未真
- 终止：循环终止时，不变式提供了一个性质，有助于证明算法是正确的



---



#### 分治法

分治法在每层递归时都有三个步骤：

- **分解**原问题为若干子问题，子问题时原问题的规模较小实例
- **解决**子问题，递归地求解各子问题，然而若子问题规模足够小，则直接求解
- **合并**子问题的解，形成原问题的解



##### 递归式

$T(n)=\begin{cases} \Theta(1), &若n \le c \\ a T(n/b)+D(n)+C(n), &其他 \end{cases}$

其中：

$\begin{array}{} n&:问题规模 \\ c&:某常数 \\ a&:划分的子问题的数量 \\ n/b&:划分的子问题的规模\\ D(n)&:分解问题所需时间 \\ C(n)&:合并子问题的解所需时间\end{array}$



##### 主定理求解递归式

**主定理**：对于递归式：$T(n)=aT(n/b)+f(n),\ a\ge0,\ b>1$ ，有如下渐进界：

1. 若对某个常数 $\epsilon>0$ 有 $f(n)=O(n^{\log_ba-\epsilon})$ ，则 $T(n)=\Theta(n^{\log_ba})$
2. 若 $f(n)=\Theta(n^{\log_ba})$ ，则 $T(n)=\Theta(n^{\log_ba}\log n)$
3. 若对某个常数 $\epsilon>0$ 有 $f(n)=\Omega(n^{\log_ba+\epsilon})$ ，且对某个常数 $c<1$ 和所有足够大的 $n$ 有 $af(n/b)\le cf(n)$ ，则 $T(n)=\Theta(f(n))$

 

主定理的应用

当题目要求以某个复杂度的算法完成要求时，尝试构造对应的递归式 $aT(n/b), log_ba$ ，从而返回到情景中，构造对应的方法



---

