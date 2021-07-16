
## 打卡题记录

[TOC]

---

#### 275. H 指数 II <p align="right">-2021/7/11</p>

给定一位研究者论文被引用次数的数组（被引用次数是非负整数），数组已经按照 升序排列 。编写一个方法，计算出研究者的 h 指数。

h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）"


```cpp {cmd="cppal" id="m1"}
//algorithm
// 二分查找，中位数是最可能的h指数，然后再找最佳
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() - 1, mid = (left + right) / 2, lastMid = 0;
        bool last = false;

        while(left >= 0 && right < citations.size() && left <= right){
            if(citations[mid] >= citations.size() - mid)
            {
                last = true;
                lastMid = mid;
                right = mid - 1;
                mid = (left + right) / 2;
            } else {
                left = mid + 1;
                mid = (left + right) / 2;
            }
        }
        return last ? citations.size() - lastMid : 0;
    }
};


Solution so;
```

```cpp {cmd="cppal" continue="m1" hide}
//entry
vector<int> cost;
if(input >> cost)
    cout << so.hIndex(cost);
```

```cpp {cmd="cppal" continue}
//test
[0,1,3,5,6]
```

---

#### 剑指 Offer 53 - I. 在排序数组中查找数字 I <p align="right">-2021/7/16</p>
统计一个数字在排序数组中出现的次数。

示例:

```
输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
```

类似题目：
> * 34. 在排序数组中查找元素的第一个和最后一个位置

```cpp {cmd="cppal"}
//algorithm
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, false) - binarySearch(nums, target, true);
    }

    /* isLeft == true 时，寻找nums中 第一次出现target的下标
     * isLeft == false时，寻找nums中 第一次大于target的下标
     */
    int binarySearch(vector<int>& nums, int target, bool isLeft){
        int left = 0, right = nums.size() - 1, mid;
        int index = nums.size();
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] > target || isLeft && nums[mid] >= target){
                right = mid - 1;
                index = mid;
            } else {
                left = mid + 1;
            }
        }
        return index;
    }
};

Solution so;
```

```cpp {cmd="cppal" id="print" continue hide}
//entry
vector<int> v;
int target;
if(input >> v && input >> target)
    cout << so.search(v, target);

```

```cpp {cmd="cppal" continue="print"}
//test
[5,7,7,8,8,10] 8
[5,7,7,8,8,10] 6
```

