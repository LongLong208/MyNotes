
## 打卡题记录

[TOC]

---

#### 275. H 指数 II <p align="right">-2021/7/11</p>

> 给定一位研究者论文被引用次数的数组（被引用次数是非负整数），数组已经按照 升序排列 。编写一个方法，计算出研究者的 h 指数。
> 
> h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）"

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

> 统计一个数字在排序数组中出现的次数。

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
---


#### 138. 复制带随机指针的链表 <p align="right">-2021/7/22</p>


> 给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
> 
> 构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。
> 
> 例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。
> 
> 返回复制链表的头节点。
> 
> 用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
> 
> val：一个表示 Node.val 的整数。
> random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
> 你的代码 只 接受原链表的头节点 head 作为传入参数。

 

示例 1：

![](https://i.loli.net/2021/07/22/KmSeADNbvofGUwZ.png)

输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]


提示：
> We can avoid using extra space for old node ---> new node mapping, by tweaking the > original linked list. Simply interweave the nodes of the old and copied list. For e.g.
> Old List: A --> B --> C --> D
> InterWeaved List: A --> A' --> B --> B' --> C --> C' --> D --> D'

思路：
构造链表 A --> A' --> B --> B' --> C --> C' --> D --> D' 其中 A' 与 A 的 val 相等
遍历链表 令 X'->random = X->random->next
分离链表 分离 A --> B --> C --> D 和 A' --> B' --> C' --> D'

```cpp {cmd="cppal" id="start" hide}
//algorithm
class Solution{
public:
```



```cpp {cmd="cppal" continue="start"}
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
Node* copyRandomList(Node* head) {
   Node* ans = NULL;
   if(head != NULL){
       Node* h = head;
       while(h){
           Node* temp = new Node(h->val);
           temp->next = h->next;
           h->next = temp;
           h = temp->next;
       }
       h = head;
       while(h){
           Node* copy = h->next;
           if(h->random != NULL)
               copy->random = h->random->next;
           else
               copy->random = NULL;
           h = copy->next;
       }
       ans = h = head->next;
       Node* hp = head;
       while(h->next){
           hp->next = h->next;
           h->next = hp->next->next;
           hp = hp->next;
           h = h->next;
       }
       hp->next = h->next = NULL;
   }
   return ans;
}
```
```cpp {cmd="cppal" continue hide}
};
Solution so;
//entry


//test
```
```cpp {cmd="cppal" hide}

```


---
