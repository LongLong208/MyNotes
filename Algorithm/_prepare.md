
## Algorithm prepare

---

[TOC]

<br>

---


### 随机数生成器

``` cpp {cmd="cppsl"}
srand(time(NULL));
cout << "今天做 " <<(rand()%100*100 | rand()%100 );
```

---


### 模板

<!-- ****************************************************************************! -->
<!-- *************************************************************************todo -->
<!-- ***************************************************************************** -->
<!-- ****************************************************************************? -->

```cpp {cmd="cppal" id="start" hide}
//algorithm
class Solution{
public:
```



```cpp {cmd="cppal" continue="start"}
void algorithm(){

}
```
```cpp {cmd="cppal" continue hide}
};
Solution so;
//entry


//test
```
```cpp {cmd="cppal"}
1
2
3
```


<!-- ****************************************************************************? -->
<!-- ***************************************************************************** -->
<!-- *************************************************************************todo -->
<!-- ****************************************************************************! -->


---

### 测试

```cpp {cmd="cppal" continue="start"}
int algorithm(vector<int>& nums) {
    int pre = 0, maxAns = nums[0];
    for (const auto &x: nums) {
        pre = max(pre + x, x);
        maxAns = max(maxAns, pre);
        cout << "pre:" << pre << " maxAns:" << maxAns << endl;
    }
    return maxAns;
}
```
```cpp {cmd="cppal" continue hide}
};
Solution so;
//entry
vector<int> n;
if(input >> n)
    cout << so.algorithm(n);
//test
```
```cpp {cmd="cppal" continue}
[-2,1,-3,4,-1,2,1,-5,4]
```

---
