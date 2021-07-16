
## 动态规划

* 动态规划常常适用于有重叠子问题和最优子结构性质的问题，并且记录所有子问题的结果，因此动态规划方法所耗时间往往远少于朴素解法。

* 动态规划有自底向上和自顶向下两种解决问题的方式。自顶向下即记忆化递归，自底向上就是递推。

* 使用动态规划解决的问题有个明显的特点，一旦一个子问题的求解得到结果，以后的计算过程就不会修改它，这样的特点叫做无后效性，求解问题的过程形成了一张有向无环图。动态规划只解决每个子问题一次，具有天然剪枝的功能，从而减少计算量。

---

#### 509. 斐波那契数

斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。

类似题目如

* tribonacci ：$T_{(n)}=T_{(n-3)}+T_{(n-2)}+T_{(n-1)}$
* 爬梯子

```cpp {cmd="cppal" id="m1"}
//algorithm
// 方法一：迭代
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

```cpp {cmd="cppal" id="fib"}
//algorithm
// 方法二：带记忆的递归
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

```cpp {cmd="cppal" continue="fib" hide}
//entry
int n = 0;
input >> n;
    if(input)
        cout << so.fib(n);
```

```cpp {cmd="cppal" continue}
//test
1
22
30
```

---

#### 746. 使用最小花费爬楼梯

数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。

每当你爬上一个阶梯你都要花费对应的体力值，一旦支付了相应的体力值，你就可以选择向上爬一个阶梯或者爬两个阶梯。

请你找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。


> 来源：力扣（LeetCode）
> 链接：https://leetcode-cn.com/problems/min-cost-climbing-stairs
> 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```cpp {cmd="cppal" id="minCostClimbingStairs"}
//algorithm
class Solution {
public:
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
};

Solution so;
```

```cpp {cmd="cppal" continue="minCostClimbingStairs" hide}
//entry
vector<int> cost;
int n;
input >> n;
while(input){
    cost.push_back(n);
    input >> n;
}
cout << so.minCostClimbingStairs(cost);
```

```cpp {cmd="cppal" continue}
//test
1 100 1 1 1 100 1 1 100 1
```

---

#### 198. 打家劫舍

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```cpp {cmd="cppal" id="rob"}
//algorithm
class Solution {
public:
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
};

Solution so;
```

```cpp {cmd="cppal" continue="rob" hide}
//entry
vector<int> cost;
int n;
input >> n;
while(input){
    cost.push_back(n);
    input >> n;
}
cout << so.rob(cost);
```

```cpp {cmd="cppal" continue}
//test
2 7 9 3 1
```


---

#### 45. 跳跃游戏 II

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

假设你总是可以到达数组的最后一个位置。


我的思路
(此题不是动态规划)
![](https://i.loli.net/2021/07/12/wyHf6YNDM8t7nUu.png)
