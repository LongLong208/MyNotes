<!-- @import "_pre.css" -->
<style>
*{
    font-family:consolas;
}
html body a code:hover{
    border:1px solid #83ee73;
}
html body h1{
    color:#cccccc;
    text-align:center;
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
html body em code{
    color: #66d9ef;
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


# 算法 {ignore}

<br>

## 自定义类解释

<hr class=short>

### Graph

图类

```cpp
template <
    class Type,
    bool direct = 0, 
    bool weight = 0,
    class CostType = int
> class Graph
```

`Type` : 点的名称的数据类型，如 *`string`*, *`int`* 等
`direct` : 为 0 时是无向图， 为 1 时是有向图
`weight` : 为 0 时是无权图， 为 1 时是有权图
`CostType` : 权值的数据类型，如 *`int`*, *`double`* 等

成员

*`vector<Type>`* `vertex` :  点集
*`vector<vector<CostType>>`* `edge` : 邻接矩阵


<br><hr class=short>

### Heap

堆（优先队列）

详见 [【堆】](#堆)

```cpp
template <
    class Type, 
    class Compare = std::less<Type> 
> class Heap
```

`Type` : 结点数据类型
`Compare` : 比较函数对象，用于维护堆的比较函数，当 `Compare(a, b)` 返回 *`true`* 时，`a` 更接近堆顶

成员：

`push(data)` : 将 `data` 插入堆中
`top()` : 返回堆顶元素，但不取出
`pop()` : 取出堆顶元素，但不返回


<br>
<br>
<br>

---

# 以下是笔记

---


<!-- @import "数论.md" -->
<!-- @import "几何.md" -->
<!-- @import "随机算法.md" -->
<!-- @import "位运算.md" -->
<!-- @import "数组.md" -->
<!-- @import "哈希表.md" -->
<!-- @import "堆.md" -->
<!-- @import "图.md" -->
<!-- @import "排序.md" -->

