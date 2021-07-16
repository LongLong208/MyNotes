
### Algorithm prepare

---

<br>

随机数生成器

``` cpp {cmd="cppsl"}
srand(time(NULL));
cout << "今天做 " <<(rand()%100*100 | rand()%100 );
```

---

模板

```cpp {cmd="cppal"}
//algorithm
int algorithm(int n) {

}
```

```cpp {cmd="cppal" id="print" continue hide}
//entry
// 读一个int
int n = 0;
input >> n;
    if(input)
        cout << so.algorithm(n);

// 读一个数组
vector<int> cost;
int n;
input >> n;
while(input){
    cost.push_back(n);
    input >> n;
}
cout << so.algorithm(cost);

```

```cpp {cmd="cppal" continue="print"}
//test

```





---

测试

```cpp {cmd="cppal" id="m1"}
//algorithm
class Solution {
public:
    vector<int> algorithm(vector<int> v) {
        return v;
    }
};


Solution so;
```

```cpp {cmd="cppal" continue="m1" hide}
//entry
vector<int> n;
if(input >> n)
    cout << so.algorithm(n);
```

```cpp {cmd="cppal" continue}
//test
[20,30,40]
```

---

```cpp {cmd="cppsl"}
int *a = new int[10]{10, 11, 12};
cout << a[0] << ' ';
```

