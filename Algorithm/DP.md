
## 动态规划

* 动态规划常常适用于有重叠子问题和最优子结构性质的问题，并且记录所有子问题的结果，因此动态规划方法所耗时间往往远少于朴素解法。

* 动态规划有自底向上和自顶向下两种解决问题的方式。自顶向下即记忆化递归，自底向上就是递推。

* 使用动态规划解决的问题有个明显的特点，一旦一个子问题的求解得到结果，以后的计算过程就不会修改它，这样的特点叫做无后效性，求解问题的过程形成了一张有向无环图。动态规划只解决每个子问题一次，具有天然剪枝的功能，从而减少计算量。


[TOC]


```cpp {cmd="cppal" id="start" hide}
//algorithm
class Solution{
public:
```



---

### 笔记

#### 动态规划代码框架

```py
# 初始化 base case
dp[0][0][...] = base
# 状态转·转移
for 状态1 in 状态1的所有取值:
    for 状态2 in 状态2的所有取值:
        for ...
            dp[状态1][状态2][...] = 求最值(选择1, 选择2, ...)
```



---

### 509. 斐波那契数

> 斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。

类似题目如

> * tribonacci ：$T_{(n)}=T_{(n-3)}+T_{(n-2)}+T_{(n-1)}$
> * 爬梯子



方法一：迭代
```cpp {cmd="cppal" id="fibm1"}
//algorithm
class Solution{
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        else if(n >= 2)
        {
            int n_2 = 0, n_1 = 1, n_;
            for(int i = 2; i <= n; ++i)
            {
                n_ = n_2 + n_1;
                n_2 = n_1;
                n_1 = n_;
            }
            return n_;
        }
        else return -1;
    }
};

Solution so;
```


方法二：带记忆的递归


```cpp {cmd="cppal" id="fibm2"}
//algorithm
class Solution{
public:
    static vector<int> v;
    Solution(){
        v[0] = 0;
        v[1] = 1;
    }
    int fib(int n){
        if(n < 0) return 0;
        else if(v[n] >= 0) return v[n];
        else if(v[n] < 0)
        {
            v[n] = fib(n - 1) + fib(n - 2);
            return v[n];
        }
        else return -1;
    }
};
vector<int> Solution::v = vector<int>(100, -1);
Solution so;
```

```cpp {cmd="cppal" continue="fibm2" hide}
//entry
int n = 0;
input >> n;
    if(input)
        cout << so.fib(n);
//test
```

```cpp {cmd="cppal" continue}
1
22
30
```

---

### 746. 使用最小花费爬楼梯

> 数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。
> 
> 每当你爬上一个阶梯你都要花费对应的体力值，一旦支付了相应的体力值，你就可以选择向上爬一个阶梯或者爬两个阶梯。
> 
> 请你找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。



```cpp {cmd="cppal" continue="start"}
vector<int> v;
vector<int> record;
int minCostClimbingStairs(vector<int>& cost) {
    v = vector<int>(cost);
    record = vector<int>(cost.size() + 1, -1);
    return recurve(cost.size());
}

int costv(int n){
    if(n < 0 && n >= v.size()) return 0;
    else return v[n];
}

int recurve(int n){
    if(n < 0)
        return 0;
    else if(record[n] >= 0)
        return record[n];
    else if(record[n] < 0){
        int path1 = recurve(n - 1) + costv(n - 1);
        int path2 = recurve(n - 2) + costv(n - 2);
        return record[n] = (path1 < path2 ? path1 : path2);
    }
    else return -1;
}
```

```cpp {cmd="cppal" continue hide}
};
Solution so;
//entry
vector<int> cost;
int n;
input >> n;
while(input){
    cost.push_back(n);
    input >> n;
}
cout << so.minCostClimbingStairs(cost);
//test
```

```cpp {cmd="cppal" continue}
1 100 1 1 1 100 1 1 100 1
```

---

### 198. 打家劫舍

> 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
> 
> 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。



```cpp {cmd="cppal" continue="start"}
vector<int> record;
int rob(vector<int>& nums) {
    record = vector<int>(nums.size(), -1);
    return recurve(nums, nums.size() - 1);
}

int recurve(vector<int>& nums, int n){
    if(n < 0)   return 0;
    else if(record[n] >= 0)
        return record[n];
    else if(record[n] < 0)
    {
        int path1, path2;
        path1 = recurve(nums, n - 2) + nums[n];
        path2 = recurve(nums, n - 1);
        return record[n] = path1 > path2 ? path1 : path2;
    }
    else return -1;
}
```

```cpp {cmd="cppal" continue hide}
};

Solution so;
//entry
vector<int> cost;
int n;
input >> n;
while(input){
    cost.push_back(n);
    input >> n;
}
cout << so.rob(cost);
//test
```

```cpp {cmd="cppal" continue}
2 7 9 3 1
```


---

### 45. 跳跃游戏 II

> 给定一个非负整数数组，你最初位于数组的第一个位置。
> 
> 数组中的每个元素代表你在该位置可以跳跃的最大长度。
> 
> 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
> 
> 假设你总是可以到达数组的最后一个位置。


我的思路
(此题可以用贪心法)
![](https://i.loli.net/2021/07/12/wyHf6YNDM8t7nUu.png)



---


```cpp {cmd="cppal" continue="start"}
int jump(vector<int>& nums) {
    int maxd = 0, times = 0;
    int i = 0;                              
    // i表示当前所在下标
    while(i < nums.size() - 1){
        for(int j = 1; j <= nums[i]; ++j)  
        // j表示在i能跳的距离，i+j就是在i能跳到的点
        {
            // 看看当前能不能跳到终点
            if(i + j >= nums.size() - 1){
                maxd = nums.size() - 1;
                break;
            }
            // maxd 记录当前能跳的点中，能继续跳到的最远距离
            if(nums[i + j] + i + j > nums[maxd] + maxd)
                maxd = i + j;
        }
        ++times;
        i = maxd;
    }
    return times;
}

```

```cpp {cmd="cppal" continue hide}
};
Solution so;
//entry
vector<int> v;
if(input >> v)
    cout << so.jump(v);
//test
```

```cpp {cmd="cppal" continue}
[2,3,1,1,4]
```


---

### 53. 最大子序和
> 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

 

示例 1：

```
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```

我使用的分治法

```cpp {cmd="cppal" id="maxSubArraym1" continue="start"}
int maxSubArray(vector<int>& nums) {
    return divide(nums, 0, nums.size()-1);
}
int divide(vector<int>& nums, int left, int right){
    if(left == right)
        return nums[left];
    int mid = (left + right) / 2;
    int leftsum = divide(nums, left, mid);
    int rightsum = divide(nums, mid + 1, right);
    int midsum = midSum(nums, left, right);

    return max(leftsum, max(rightsum, midsum));
}

int midSum(vector<int>& nums, int left, int right){
    int l = (left + right) / 2, r, lmax, rmax, cur;
    r = l + 1;
    lmax = nums[l];
    rmax = nums[r];;
    cur = 0;
    while(l >= left){
        cur += nums[l];
        if(cur >= lmax)
            lmax = cur;
        --l;
    }
    cur = 0;
    while(r <= right){
        cur += nums[r];
        if(cur >= rmax)
            rmax = cur;
        ++r;
    }
    return max(lmax, max(rmax, lmax + rmax));
}
```

答案的动态规划

判断第i个是加入前面，还是独立

```cpp {cmd="cppal" id="maxSubArraym2" continue="start"}
int maxSubArray(vector<int>& nums) {
    int pre = 0, maxAns = nums[0];
    for (const auto &x: nums) {
        pre = max(pre + x, x);
        maxAns = max(maxAns, pre);
    }
    return maxAns;
}
```


```cpp {cmd="cppal" continue="maxSubArraym1" hide}
};
Solution so;
//entry
vector<int> v;
if(input >> v)
    cout << so.maxSubArray(v);
//test
```

```cpp {cmd="cppal" continue}
[4,-1,2,1]
```
